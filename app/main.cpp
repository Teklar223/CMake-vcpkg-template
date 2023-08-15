#include <iostream>
#include <fstream>
#include "Document.h"
#include <windows.h>
#include <cstdio>
#include <fcntl.h>
#include <io.h>

void RedirectIOToConsole() {
    if (AttachConsole(ATTACH_PARENT_PROCESS)==false) return;

    HANDLE ConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    int SystemOutput = _open_osfhandle(intptr_t(ConsoleOutput), _O_TEXT);

    // check if output is a console and not redirected to a file
    if(isatty(SystemOutput)==false) return; // return if it's not a TTY

    FILE *COutputHandle = _fdopen(SystemOutput, "w");

    // Get STDERR handle
    HANDLE ConsoleError = GetStdHandle(STD_ERROR_HANDLE);
    int SystemError = _open_osfhandle(intptr_t(ConsoleError), _O_TEXT);
    FILE *CErrorHandle = _fdopen(SystemError, "w");

    // Get STDIN handle
    HANDLE ConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    int SystemInput = _open_osfhandle(intptr_t(ConsoleInput), _O_TEXT);
    FILE *CInputHandle = _fdopen(SystemInput, "r");

    //make cout, wcout, cin, wcin, wcerr, cerr, wclog and clog point to console as well
    std::ios::sync_with_stdio(true);

    // Redirect the CRT standard input, output, and error handles to the console
    freopen_s(&CInputHandle, "CONIN$", "r", stdin);
    freopen_s(&COutputHandle, "CONOUT$", "w", stdout);
    freopen_s(&CErrorHandle, "CONOUT$", "w", stderr);

    //Clear the error state for each of the C++ standard stream objects.
    std::wcout.clear();
    std::cout.clear();
    std::wcerr.clear();
    std::cerr.clear();
    std::wcin.clear();
    std::cin.clear();
}

int main()
{
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

    return 0;
}

// https://stackoverflow.com/questions/13871617/winmain-and-main-in-c-extended
// https://learn.microsoft.com/en-us/windows/win32/api/winbase/nf-winbase-winmain
int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
    //RedirectIOToConsole(); // https://stackoverflow.com/questions/60328079/piping-console-output-from-winmain-when-running-from-a-console
    std::cout << "HELLO WORLD" << std::endl;
    printf("Hello World\n");
    std::ofstream MyFile("HELLOWORLD.txt");
    MyFile << "Files can be tricky, but it is fun enough!";
    MyFile.close();
    return main();
}
