#pragma once

#include <string>
#include <vector>

// Данные процессора
struct CPUData
{
    std::string cpu; //Строка, обозначающая имя процессора.
    size_t user; //Количество времени, которое процессор потратил на выполнение пользовательских задач.
    size_t nice; //Количество времени, которое процессор потратил на выполнение задач с приоритетом nice.
    size_t system; //Количество времени, которое процессор потратил на выполнение системных задач.
    size_t idle; //Количество времени, которое процессор простаивал и не выполнял никаких задач.
    size_t iowait; //Количество времени, которое процессор ожидал завершения операций ввода-вывода.
    size_t irq; //Количество времени, которое процессор потратил на обработку прерываний от аппаратуры.
    size_t softirq; //Количество времени, которое процессор потратил на обработку программных прерываний.
    size_t steal; //Количество времени, которое процессор потратил на ожидание доступа к виртуальным процессорам в виртуализированной среде.
    size_t guest; //Подсчитывает время, затраченное на работу виртуального ЦП для гостевых операционных систем под управлением ядра Linux.
    size_t guest_nice; //Количество времени, которое процессор потратил на выполнение приятных задач в режиме гостя.
    // (Приятных значит задач с низком приоритетом, ОС выдаст меньше процессорного времени под такие задачи)
};

class CPU
{
public:
    //Позволяет оценить загруженность процессора и его ядер с интервалом в millisecond в течение second_of_show секунд
    void ShowCPULoad2(int64_t millisecond, int64_t second_of_show);

    //Позволяет оценить загруженность процессора и его ядер с интервалом в millisecond в течение second_of_show секунд
    void ShowCPUOperation(int64_t millisecond_of_show);

    // Функция для получения температуры процессора
    double getCpuTemperature();

    // Функция для чтения текущей частоты процессора из файла /proc/cpuinfo
    std::string getCurrentCpuFrequency();
private:
    // Считывает файл "/proc/stat", и берет нужную информацию о процессоре и ядрах
    std::vector<CPUData> CPUdata_info();

    // //Основываясь на информации о состоянии ядра процессора рассчитает его загруженность
    long double CPUload(CPUData& start, CPUData& end);

    // Позволяет оценить загруженность процессора и его ядер с промежутком в millisecond милисекунд
    void ShowCPULoad1(int64_t millisecond);
};