#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "GeneralRAMParams.h"

ControllerGRAM::ControllerGRAM(IViewGRAM::IVptr view, IModelGRAM::IMptr model) :
    view(view), model(model)
{
}

void ControllerGRAM::Launch()
{
    std::vector<std::string> result = model->GRAMparams(path, needs);
    view->ShowGeneralParams(result);
}

std::string ModelGRAM::FirstWord(const std::string& line)
{
    std::string word;
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

std::vector<std::string> ModelGRAM::GRAMparams(const std::string& path, const std::vector<std::string>& needs)
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
                std::string validLine = PrettyData(line);
                result.push_back(validLine);
                break;
            }
        }
    }
    file.close();
    return result;
}

std::string ModelGRAM::PrettyData(std::string& line)
{   
    std::string result;
    std::string word;
    float number;
    std::istringstream iss(line);
    iss >> word >> number;
    number /= 1048576;
    if (word == "MemTotal:") 
    {   

        result = "Total Memory: " + ConvertFloatToString(number) + " GB";
        return result;
    }
    else if (word == "MemFree:") 
    {   
        result = "Free Memory: " + ConvertFloatToString(number) + " GB";
        return result;
    }
    else
    {   
        number *= 1024;
        result = word + " " + ConvertFloatToString(number) + " MB";
        return result;
    }
}

std::string ModelGRAM::ConvertFloatToString(float& number)
{   
    
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

void ViewGRAM::ShowGeneralParams(const std::vector<std::string>& params)
{
    for (const std::string& line : params)
    {
        std::cout << line << std::endl;
    }
}