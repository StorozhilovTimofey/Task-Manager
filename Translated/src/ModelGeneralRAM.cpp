#include <string>
#include <vector>
#include <fstream>

#include "ModelGeneralRAM.h"

std::string ModelGeneralRAM::FirstWord(const std::string& line)
{
    std::string word;
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

std::vector<std::string> ModelGeneralRAM::GeneralRAMParams(const std::string& path, const std::vector<std::string>& needs)
{
    std::ifstream file(path);
    std::string line;
    std::vector<std::string> result;
    while (std::getline(file, line))
    {
        for (const std::string& start : needs)
        {
            if (FirstWord(line).compare(0, start.length(), start) == 0)
            {
                result.push_back(line);
                break;
            }
        }
    }
    file.close();
    return result;
}