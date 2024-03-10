#include <fstream>
#include <sstream>
#include <vector>
#include <unistd.h>
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>

#include "CP_lib.h"

int main() 
{   
    CPU test;
    test.ShowCPULoad2(50, 3);

    return 0;
}