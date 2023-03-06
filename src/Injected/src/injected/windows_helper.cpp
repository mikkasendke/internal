#include <pch.h>
#include "windows_helper.h"

namespace windows_helper {
    DWORD GetProcessIdFromModule(const HMODULE h_module)
    {
        TCHAR sz_module[MAX_PATH];
        DWORD dw_process_id = 0;

        // Get the full path of the DLL.
        if (GetModuleFileName(h_module, sz_module, MAX_PATH))
        {
            // Create a toolhelp snapshot of all processes in the system.
            const HANDLE h_snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
            if (h_snapshot != INVALID_HANDLE_VALUE)
            {
                PROCESSENTRY32 pe32;
                pe32.dwSize = sizeof(PROCESSENTRY32);

                // Iterate through the processes in the snapshot.
                if (Process32First(h_snapshot, &pe32))
                {
                    do
                    {
                        // Create a module snapshot of the current process.
                        const HANDLE h_module_snapshot = CreateToolhelp32Snapshot(
	                        TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, pe32.th32ProcessID);

                        if (h_module_snapshot != INVALID_HANDLE_VALUE)
                        {
                            MODULEENTRY32 me32;
                            me32.dwSize = sizeof(MODULEENTRY32);

                            // Iterate through the modules in the snapshot.
                            if (Module32First(h_module_snapshot, &me32))
                            {
                                do
                                {
                                    // Compare the full path of the current module with the full path of the DLL.
                                    if (_tcscmp(sz_module, me32.szExePath) == 0)
                                    {
                                        // The current process loaded the DLL, so set the process ID.
                                        dw_process_id = pe32.th32ProcessID;
                                        break;
                                    }
                                } while (Module32Next(h_module_snapshot, &me32));
                            }

                            // Close the module snapshot.
                            CloseHandle(h_module_snapshot);
                        }
                    } while (Process32Next(h_snapshot, &pe32));
                }

                // Close the process snapshot.
                CloseHandle(h_snapshot);
            }
        }

        return dw_process_id;
    }
}