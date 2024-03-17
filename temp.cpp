#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

std::string GetWord(const std::string& line)
{   
    std::string word;
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

void ChangetoValidOutput(std::string& line)
{
    std::string word;
    float number;
    std::istringstream iss(line);
    iss >> word >> number;
    number /= 1048576;
    if (word == "MemTotal:") { std::cout << "Total Memory: " << number << " Gb" << std::endl; }
    else if (word == "MemFree:") { std::cout << "Free Memory: " << number << " Gb" << std::endl; }
    else { std::cout << word << number * 1024 << " Mb" << std::endl; }
}

void GeneralRamParametres(const std::string& path, std::vector<std::string>& Needs)
{
    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line))
    {   
        for (const std::string& start : Needs)
        {
            if (GetWord(line).compare(0, start.length(), start) == 0)
            {
                ChangetoValidOutput(line);
                break;
            }
        }
    }
    file.close();
}

int main(void)
{
    const std::string path = "/proc/meminfo";
    std::vector<std::string> Needs = 
    {
        "MemTotal:",
        "MemFree:",
        "Buffers:",
        "Cached:"
    };
    GeneralRamParametres(path, Needs);

    return 0;
}