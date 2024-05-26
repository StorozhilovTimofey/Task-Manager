#include <fstream>
#include <sstream>
#include <iostream>

#include "ModelData.h"


namespace
{
//! \brief Выводимые параметры
const std::vector<std::string> lineStarts =
{
    "Size: ",
    "Type: ",
    "Speed: ",
    "Manufacturer: ",
    "Serial Number: "
};

//! \brief Параметры пустых слотов оперативной памяти, которые игнорируются
const std::vector<std::string> ignoredStarts =
{
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
};

//! \brief Путь до файла с данными по оперативной памяти
const std::string filePath = "memory_info.txt";

//! \brief Счетчик модулей ram
int counter = 1;

//! \brief Возвращает первое слово в строке
std::string FirstWord(const std::string& line)
{
    std::string word;
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}


std::string ConvertFloatToString(float& number)
{
    std::ostringstream oss;
    oss << number;
    return oss.str();
}

//! \brief Меняте вывод на более понятный
std::string PrettyData(std::string& line)
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

//! \brief Запускает ввод консольной команды для обнаружения данных ram
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


void RemoveLeadingSpaces(std::string& line)
{
    size_t pos = 0;
    for (size_t i = 0; i < line.length(); i++)
    {
        if (!std::isspace(line.at(i)))
        {
            pos = i;
            break;
        }
    }
    line = line.substr(pos);
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


std::string readFromFile(const std::string &filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}


std::vector<std::string> GetFileLine(std::string &line, std::string prevLine, std::vector<std::string> result)
{
    for (const std::string& elem : lineStarts)
    {
        if (line.compare(0, elem.length(), elem) == 0)
        {
            if (GetFirstWord(prevLine) == "Serial")
            {
                counter++;
                result.push_back("\n#" + std::to_string(counter) + ":");
            }
            prevLine = line;
            result.push_back(line);
            break;
        }
    }
    return result;
}
} // end namespace


std::vector<std::string> ModelData::getRamGeneral(const std::string& path,
                                                  const std::vector<std::string>& needs)
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


void ModelData::CreateFile()
{
    std::string memoryInfo = exec("sudo dmidecode --type memory");
    std::ofstream file(filePath);
    file << "Memory Information:\n" << memoryInfo << std::endl;
    file.close();
}


void ModelData::DeleteFile()
{
    std::string command = "rm -f " + filePath;
    int result = std::system(command.c_str());
}


std::vector<std::string> ModelData::getRamSpecific()
{
    std::vector<std::string> result;
    result.push_back("\n#" + std::to_string(counter) + ":");
    std::ifstream file(filePath);
    if (file.is_open())
    {
        std::string line;
        std::string prevLine;
        while (std::getline(file, line))
        {
            RemoveLeadingSpaces(line);
            bool isIgnored = false;
            for (const std::string& elem : ignoredStarts)
            {
                if(line.compare(0, elem.length(), elem) == 0)
                {
                    isIgnored = true;
                    break;
                }
            }
            if (isIgnored) { continue; }
            result = GetFileLine(line, prevLine, result);
        }
        file.close();
    }
    else { std::cerr << "Unable to open file: " << filePath << std::endl; }

    return result;
}


double ModelData::getCurrentCpuFrequency()
{
    std::ifstream cpuinfoFile("/proc/cpuinfo");
    if (!cpuinfoFile.is_open())
    {
        std::cerr << "Failed to open /proc/cpuinfo" << std::endl;
        return -1; // ~ "Error"
    }

    std::string line;
    while (std::getline(cpuinfoFile, line))
    {
        if (line.find("cpu MHz") != std::string::npos)
        {
            size_t colonPos = line.find(':');
            if (colonPos != std::string::npos)
            {
                std::string frequencyStr = line.substr(colonPos + 1);
                size_t firstDigitPos = frequencyStr.find_first_of("0123456789");
                if (firstDigitPos != std::string::npos)
                {
                    return std::stod(frequencyStr.substr(firstDigitPos));
                }
            }
        }
    }

    return 0; // ~ "Unknown"
}


double ModelData::getCpuTemperature()
{
    std::string tempStr = readFromFile("/sys/class/thermal/thermal_zone0/temp");
    if (tempStr.empty())
    {
        std::cerr << "Failed to read CPU temperature" << std::endl;
        return -1.0;
    }
    double temp;
    std::stringstream(tempStr) >> temp;
    return temp / 1000.0;
}


std::vector<double> ModelData::getCpuParametres()
{
    std::vector<double> result = {getCurrentCpuFrequency(), getCpuTemperature()};
    return result;
}