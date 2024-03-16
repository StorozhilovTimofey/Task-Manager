#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <fstream>
#include <sstream>
#include <vector>

std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

std::string writeMemoryInfoToFile()
{
    // Execute the dmidecode command to retrieve memory information
    std::string memoryInfo = exec("sudo dmidecode --type memory");

    // Write the memory information to a new file
    std::ofstream file("memory_info.txt");
    file << "Memory Information:\n" << memoryInfo << std::endl;
    file.close();

    // Return the file path
    return "memory_info.txt";
}

void removeLeadingSpaces(std::string& str) 
{
    size_t pos = 0;
    
    // Находим первый непробельный символ
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isspace(str.at(i))) {
            pos = i;
            break;
        }
    }
    
    // Удаляем все пробелы до первого непробельного символа
    str = str.substr(pos);
}

void printMatchingLines(const std::vector<std::string>& lineStarts, const std::vector<std::string>& ignoredStarts, const std::string& filename) {
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            removeLeadingSpaces(line);
            bool isIgnored = false;
            for (const std::string& start : ignoredStarts) {
                if (line.compare(0, start.length(), start) == 0) {
                    isIgnored = true;
                    break;
                }
            }
            if (isIgnored) {
                continue;
            }
            for (const std::string& start : lineStarts) 
            {
                if (line.compare(0, start.length(), start) == 0) 
                {
                    std::cout << line << std::endl;
                    break;
                }
            }
        }
        file.close();
    } else {
        std::cerr << "Unable to open file: " << filename << std::endl;
    }
}

int main()
{
    // Write memory information to a new file and get the file path
    std::string filePath = writeMemoryInfoToFile();
    std::vector<std::string> Allowed = 
    {
    "Size: ", 
    "Type: ",
     "Speed: ",
      "Manufacturer: ",
       "Serial Number: ",
    };
    std::vector<std::string> Exception = 
    {
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
    };
    printMatchingLines(Allowed, Exception, filePath);

    return 0;
}
