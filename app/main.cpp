#include <iostream>
#include <fstream>
#include "Document.h"
#include <windows.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>

void RedirectIOToConsole() {
    // via https://stackoverflow.com/questions/60328079/piping-console-output-from-winmain-when-running-from-a-console
    // AND ChatGPT!
    if (AttachConsole(ATTACH_PARENT_PROCESS) == false) return;

    // Redirect the C++ standard output handle to the console
    freopen("CONOUT$", "w", stdout);

    // Make cout point to the console as well
    std::ios::sync_with_stdio(true);

    // Clear the error state for the C++ standard stream object
    std::cout.clear();
}

int main()
{
    //RedirectIOToConsole(); // https://stackoverflow.com/questions/60328079/piping-console-output-from-winmain-when-running-from-a-console
    std::cout << "HELLO WORLD" << std::endl;
    printf("Hello World\n");
    //std::ofstream MyFile("HELLOWORLD.txt");
    //MyFile << "Files can be tricky, but it is fun enough!";
    //MyFile.close();
    /*
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
    */
    return 0;
}

// https://stackoverflow.com/questions/13871617/winmain-and-main-in-c-extended
// https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
/*
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    return main();
}
*/
