#include <iostream>
#include <cstdio>
#include <memory>
#include <array>
#include <fstream>
#include <sstream>
#include <vector>

int counter = 1;

std::string exec(const char* cmd)
{
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) 
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) 
    {
        result += buffer.data();
    }
    return result;
}

std::string writeMemoryInfoToFile()
{
    std::string memoryInfo = exec("sudo dmidecode --type memory");
    std::ofstream file("memory_info.txt");
    file << "Memory Information:\n" << memoryInfo << std::endl;
    file.close();

    return "memory_info.txt";
}

void removeLeadingSpaces(std::string& str)
{
    size_t pos = 0;
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (!std::isspace(str.at(i))) 
        {
            pos = i;
            break;
        }
    }
    str = str.substr(pos);
}

std::string GetFirstWord(const std::string& line)
{   
    std::string word;
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

void deleteFile(const std::string& filename)
{
    std::string command = "rm -f " + filename; // создаем строку команды для удаления файла
    int result = std::system(command.c_str()); // вызываем команду через системный вызов
}

void printMatchingLines(const std::vector<std::string>& lineStarts, const std::vector<std::string>& ignoredStarts, const std::string& filename) 
{
    std::ifstream file(filename);
    if (file.is_open()) 
    {   
        std::cout << "#" << counter << ":" << std::endl;
        std::string line;
        std::string prevLine;
        while (std::getline(file, line)) 
        {
            removeLeadingSpaces(line);
            bool isIgnored = false;
            for (const std::string& start : ignoredStarts) 
            {
                if (line.compare(0, start.length(), start) == 0) {
                    isIgnored = true;
                    break;
                }
            }
            if (isIgnored) 
            {
                continue;
            }
            for (const std::string& start : lineStarts) 
            {
                if (line.compare(0, start.length(), start) == 0) 
                {
                    if (GetFirstWord(prevLine) == "Serial")
                    {   
                        std::cout << std::endl;
                        counter++;
                        std::cout << "#" << counter << ":" << std::endl;
                    }
                    prevLine = line;
                    std::cout << line << std::endl;
                    break;
                }
            }
        }
        file.close();
    } 
    else { std::cerr << "Unable to open file: " << filename << std::endl; }
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
    "Serial Number: "
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
    deleteFile("memory_info.txt");

    return 0;
}