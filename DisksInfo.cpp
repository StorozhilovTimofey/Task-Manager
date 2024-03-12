#include <iostream>
#include <vector>
#include <fstream>
#include <sys/statvfs.h>

void printDiskSpaceInfo() 
{
    std::vector<std::string> diskPaths = {"/"}; // Пути до дисков
    int diskNumber = 1; // Номер диска (для вывода)

    for (const auto &path : diskPaths) // Цикл по всем дискам
    {
        struct statvfs buffer {}; // Хранит статистику файловой системы
        // Функция statvfs для получение информации о файловой системе и buffer для сохранения
        if (statvfs(path.c_str(), &buffer) == 0) // Если успешно, то расчитываем данные
        {
            unsigned long long mbytes = (buffer.f_frsize * buffer.f_blocks) / (1024 * 1024);
            unsigned long long mbytes_free = (buffer.f_bsize * buffer.f_bfree) / (1024 * 1024);
            unsigned long long mbytes_available = (buffer.f_frsize * buffer.f_bavail) / (1024 * 1024);
            unsigned long long mbytes_used = mbytes - mbytes_free;

            std::cout << "Disc #" << diskNumber << ": " << path << std::endl;
            std::cout << "Total space: " << mbytes << " MB" << std::endl;
            std::cout << "Used space: " << mbytes_used << " MB" << std::endl;
            std::cout << "Free space: " << mbytes_free << " MB" << std::endl;
            std::cout << "Available space: " << mbytes_available << " MB" << std::endl;
            std::cout << "--------------------------------------------" << std::endl;

            diskNumber++;
        }
        else 
        {
            std::cerr << "Error when retrieving disk information: " << path << std::endl;
        }
    }
}


int main(void)
{
    std::cout << "Disks info: " << std::endl;
    std::cout << "--------------------------------------------" << std::endl;
    printDiskSpaceInfo();

    return 0;
}