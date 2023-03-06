#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <thread>

#include "XenosProfile.h"

namespace RQ {
	struct StartProcessInfo {
		bool success;
		HANDLE hProcess;
		HANDLE hThread;
		DWORD dwProcessId;
		DWORD dwThreadId;
	};
	StartProcessInfo StartProcess(std::string path, std::string args);
	std::string GetAbsPathToParentDirAsString(std::string input);
	void CreateFileWithText(std::string path, std::string name, std::string data);
	void DeleteFileByString(std::string path);
}