#include "RAM.h"
#include "GeneralRAM.h"

int main(void)
{
    RAM example;
    example.createFile();
    example.printMatchingLines();
    example.deleteFile();

    GeneralRAM sameexample;
    sameexample.PrettyOutput();
    sameexample.GeneralRamParametres();

    return 0;
}