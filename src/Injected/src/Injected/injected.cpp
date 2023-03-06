#include <pch.h>
#include "injected.h"
#include <injected/windows_helper.h>

namespace IJ {

    void OnAttach(HMODULE hModule) {
        DWORD procId = WindowsHelper::GetProcessIdFromModule(hModule);

        std::cout << "Here I am" << std::endl;

    }

    void OnDetach(HMODULE hModule) {

    }
}