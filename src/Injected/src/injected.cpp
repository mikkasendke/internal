#include <pch.h>
#include "injected.h"
#include <injected/windows_helper.h>

namespace ij {

    void OnAttach(const HMODULE h_module) {
        DWORD proc_id = windows_helper::GetProcessIdFromModule(h_module);
        CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
    }

    void OnDetach(HMODULE h_module) {
        FreeConsole();
    }
    DWORD WINAPI ThreadFunc(LPVOID lpParam)
    {
        std::this_thread::sleep_for(std::chrono::seconds(15));
        AllocConsole();
        // redirect standard input/output/error streams to the console
        freopen("CONIN$", "r", stdin);
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        for (int i = 0; i < 1000000; i++)
        {
            std::cout << "Here I am " << i << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
        return 1;
    }
}