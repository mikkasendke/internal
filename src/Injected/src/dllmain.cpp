#include <pch.h>
#include <injected/injected.h>

BOOL APIENTRY DllMain(const HMODULE h_module,
                      const DWORD  ul_reason_for_call,
                      LPVOID /*lp_reserved*/
) {

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        ij::OnAttach(h_module);
        break;
    case DLL_PROCESS_DETACH:
        ij::OnDetach(h_module);
        break;

	default: 
        break;;
    }

    return TRUE;
}