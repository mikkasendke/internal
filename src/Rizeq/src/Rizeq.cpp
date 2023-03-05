#include <iostream>
#include <windows.h>

int main()
{
	std::cout << "Hello World!\n";
	TCHAR buffer[MAX_PATH] = { 0 };
	GetModuleFileName(NULL, buffer, MAX_PATH);
	std::cout << buffer << "\n";

	const char* config = "";
	const char* options = " --run D:\\projects\\spielzeug\\gta-internal\\bin\\windows\\x86_64-Debug\\profile";
	char* lpOptions = new char[strlen(options) + 1];
	strcpy_s(lpOptions, strlen(options) + 1, options);
	std::cout << "options: " << options << std::endl;
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	BOOL success = CreateProcess(
		"D:\\projects\\spielzeug\\gta-internal\\bin\\windows\\x86_64-Debug\\Xenos64.exe",
		lpOptions,
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

	delete[] lpOptions;
}