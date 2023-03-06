#include <iostream>
#include <windows.h>
#include <string>

int main()
{
    //	plan
    //		start xenos state waiting for gta (later B(l)ackBone or plattform specific injector)
    //		start altv or game to inject i.e. vanilla for example
    //		inject dll start gui tinker with data

    // D:\Steam\steamapps\common\Grand Theft Auto V\altvinstall\altv.exe
    std::cout << "Hello World!\n";
    //TCHAR buffer[MAX_PATH] = { 0 };
    //GetModuleFileName(NULL, buffer, MAX_PATH);
    //std::cout << buffer << "\n";
    std::string pathToDll;
    std::string pathToProfile = "D:\\projects\\spielzeug\\gta-internal\\bin\\windows\\x86_64-Debug\\profile";
    std::string pathToXenos = "D:\\projects\\spielzeug\\gta-internal\\bin\\windows\\x86_64-Debug\\Xenos64.exe";

    //const char* options = " --run";
    //char* lpOptions = new char[strlen(options) + 1];
    //strcpy_s(lpOptions, strlen(options) + 1, options);
    //std::cout << "options: " << options << std::endl;

    std::string options = " --run " + pathToProfile;

    STARTUPINFO info = { sizeof(info) };
    PROCESS_INFORMATION processInfo;
    
    BOOL success = CreateProcess(
        pathToXenos.c_str(),
        const_cast<LPSTR>(options.c_str()),
        NULL,
        NULL,
        FALSE,
        0,
        NULL,
        NULL,
        &info,
        &processInfo
    );
    if (success)
    {
        std::cout << "Process created with ID " << processInfo.dwProcessId << std::endl;
    }
    else
    {
        std::cout << "Failed to create process: " << GetLastError() << std::endl;
    }
}