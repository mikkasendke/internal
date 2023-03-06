#include <pch.h>
#include "windows_helper.h"

namespace WindowsHelper {
    DWORD GetProcessIdFromModule(HMODULE hModule)
    {
        TCHAR szModule[MAX_PATH];
        DWORD dwProcessId = 0;

        // Get the full path of the DLL.
        if (GetModuleFileName(hModule, szModule, MAX_PATH))
        {
            // Create a toolhelp snapshot of all processes in the system.
            HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
            if (hSnapshot != INVALID_HANDLE_VALUE)
            {
                PROCESSENTRY32 pe32;
                pe32.dwSize = sizeof(PROCESSENTRY32);

                // Iterate through the processes in the snapshot.
                if (Process32First(hSnapshot, &pe32))
                {
                    do
                    {
                        // Create a module snapshot of the current process.
                        HANDLE hModuleSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pe32.th32ProcessID);
                        if (hModuleSnapshot != INVALID_HANDLE_VALUE)
                        {
                            MODULEENTRY32 me32;
                            me32.dwSize = sizeof(MODULEENTRY32);

                            // Iterate through the modules in the snapshot.
                            if (Module32First(hModuleSnapshot, &me32))
                            {
                                do
                                {
                                    // Compare the full path of the current module with the full path of the DLL.
                                    if (_tcscmp(szModule, me32.szExePath) == 0)
                                    {
                                        // The current process loaded the DLL, so set the process ID.
                                        dwProcessId = pe32.th32ProcessID;
                                        break;
                                    }
                                } while (Module32Next(hModuleSnapshot, &me32));
                            }

                            // Close the module snapshot.
                            CloseHandle(hModuleSnapshot);
                        }
                    } while (Process32Next(hSnapshot, &pe32));
                }

                // Close the process snapshot.
                CloseHandle(hSnapshot);
            }
        }

        return dwProcessId;
    }
}