#include <iostream>
#include <fstream>
#include "Document.h"
#include <windows.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>



int main()
{
    std::cout << "HELLO WORLD" << std::endl;

    std::ofstream MyFile("HELLOWORLD.txt");
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();
    
    Document doc
    {
        "Sam",
        std::time(nullptr),
        "Delivering cargos",
        "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor"
                " incididunt ut labore et dolore magna aliqua.\nUt enim ad minim veniam, quis nostrud"
                " exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat."
    };

    doc.print(std::cout);

    //return 0;
}
