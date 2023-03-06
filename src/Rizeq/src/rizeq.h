#pragma once
#include <iostream>
#include <windows.h>
#include <string>
#include <filesystem>
#include <fstream>
#include <thread>

#include "XenosProfile.h"

namespace rq {
	struct StartProcessInfo {
		bool success;
		HANDLE h_process;
		HANDLE h_thread;
		DWORD dw_process_id;
		DWORD dw_thread_id;
	};

	StartProcessInfo StartProcess(const std::string& path, std::string args, const std::string& working_directory);

	std::string GetAbsPathToParentDirAsString(const std::string& input);
	std::string CreateFileWithText(const std::string& path, const std::string& name, const std::string& data);
	void DeleteFileByString(const std::string& path);
}