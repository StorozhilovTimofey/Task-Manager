#pragma once

#include <string>
#include <vector>


class RAM
{
public:
    std::string exec(const char* cmd);
    void createFile();
    void removeLeadingSpaces(std::string& str);
    std::string GetFirstWord(const std::string& line);
    void deleteFile();
    void printMatchingLines();
private:
    const std::vector<std::string> lineStarts = 
    {
    "Size: ", 
    "Type: ",
    "Speed: ",
    "Manufacturer: ",
    "Serial Number: "
    };
    const std::vector<std::string> ignoredStarts = 
    {
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
    };
    const std::string filePath = "memory_info.txt";
    int counter = 1;
};