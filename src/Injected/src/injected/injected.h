#pragma once
#include <pch.h>

namespace ij {

    void OnAttach(HMODULE h_module);
    void OnDetach(HMODULE h_module);

    DWORD WINAPI ThreadFunc(LPVOID lpParam);
}