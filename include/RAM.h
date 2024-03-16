#pragma once

#include <string>
#include <vector>


class RAM
{
public:
    std::string exec(const char* cmd); // Выполняет команду в терминале и возвращает результат в виде строки
    void createFile(); // Создает временный файл, в который будет записан вывод
    void removeLeadingSpaces(std::string& str); // // Удаляет пробелы перед первым словом в строке (чтобы проще было обрабатывать)
    std::string GetFirstWord(const std::string& line); // Возвращает первое слово в строке
    void deleteFile(); // Удаляет временный файл
    void printMatchingLines(); // Вывод нужных данных

    // Вектор для хранения начал строк, данные по которым нужны
    const std::vector<std::string> lineStarts = 
    {
    "Size: ", 
    "Type: ",
    "Speed: ",
    "Manufacturer: ",
    "Serial Number: "
    };
    // Вектор, нужный для игнорирования фальшивих данных
    const std::vector<std::string> ignoredStarts = 
    {
    "Size: No Module Installed",
    "Type: Unknown",
    "Speed: Unknown",
    "Manufacturer: Not Specified",
    "Serial Number: Not Specified"
    };
    const std::string filePath = "memory_info.txt"; // Временный файл
    int counter = 1; // Нумерация плашек ОП
};