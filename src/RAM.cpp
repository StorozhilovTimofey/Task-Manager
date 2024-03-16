#include <string>
#include <array>
#include <cstdio>
#include <memory>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

#include "RAM.h"

std::string RAM::exec(const char* cmd)
{
    std::array<char, 128> buffer; // Массив для чтения вывода выполненной команды
    std::string result; // Результат выполнения команды
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose); // Умный указатель для управления процессом, выполняющим команду
    if (!pipe) // Проверка открытия процесса
    {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) // Чтение строк из процесса в буфер
    {
        result += buffer.data();
    }
    return result;
}

void RAM::createFile()
{
    std::string memoryInfo = exec("sudo dmidecode --type memory"); // Запуск процесса
    std::ofstream file(filePath);
    file << "Memory Information:\n" << memoryInfo << std::endl;
    file.close();
}

void RAM::removeLeadingSpaces(std::string& str)
{
    size_t pos = 0;
    for (size_t i = 0; i < str.length(); i++) 
    {
        if (!std::isspace(str.at(i))) // Проверка на пробел
        {
            pos = i; // Если не пробел, то позиция обновляется значением индекса
            break;
        }
    }
    str = str.substr(pos); // Обрезание начала строки до pos
}

std::string RAM::GetFirstWord(const std::string& line)
{   
    std::string word; // Результат
    for (char ch : line)
    {
        if (ch == ' ') { return word; }
        else { word += ch; }
    }
    return word;
}

void RAM::deleteFile()
{
    std::string command = "rm -f " + filePath;
    int result = std::system(command.c_str());
}

void RAM::printMatchingLines() 
{
    std::ifstream file(filePath);
    if (file.is_open()) 
    {   
        std::cout << "#" << counter << ":" << std::endl;
        std::string line;
        std::string prevLine; // Нужная для более корректного вывода
        while (std::getline(file, line)) 
        {
            removeLeadingSpaces(line);
            bool isIgnored = false; // Флаг, определяющий попадание строки в один из векторов
            for (const std::string& start : ignoredStarts) 
            {
                if (line.compare(0, start.length(), start) == 0) {
                    isIgnored = true;
                    break;
                }
            }
            if (isIgnored) { continue; } 
            for (const std::string& start : lineStarts) 
            {
                if (line.compare(0, start.length(), start) == 0) 
                {
                    if (GetFirstWord(prevLine) == "Serial") // Кусок "корректного" вывода
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
    else { std::cerr << "Unable to open file: " << filePath << std::endl; }
}