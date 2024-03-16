#include "RAM.h"

int main(void)
{
    RAM example;
    example.createFile();
    example.printMatchingLines();
    example.deleteFile();

    return 0;
}