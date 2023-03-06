#include "rizeq.h"

int main(int argc, char* argv[])
{

	//  D:\Steam\steamapps\common\Grand Theft Auto V\altvinstall\altv.exe
	//	Plan:
	//		start xenos state waiting for gta (later B(l)ackBone or plattform specific injector)
	//		start altv or game to inject i.e. vanilla for example
	//		inject dll start gui tinker with data

	std::string current_dir = RQ::GetAbsPathToParentDirAsString(argv[0]);

	std::string xenos_file_name		= "resources.dll";
	std::string profile_file_name	= ".dat";

	std::string path_to_xenos	= current_dir + xenos_file_name;
	std::string path_to_dll		= current_dir + "Injected.dll";
	std::string path_to_target	= current_dir + "dummjy.exe";

	if (argc > 1) {
		path_to_target = argv[1];
	}

	auto xenos_profile = RQ::XenosProfile()
		.SetDllPath(path_to_dll)
		.SetTargetPath(path_to_target)
		.SetProcessMode("1")
		.SetDelayMs("1000");

	RQ::CreateFileWithText(current_dir, profile_file_name, xenos_profile.Build());

	std::string path_to_profile = current_dir + profile_file_name;
	std::string options = "--run " + path_to_profile;

	auto info = RQ::StartProcess(path_to_xenos, options);
	if (info.success)
	{
		std::cout << "Process created with ID " << info.dwProcessId << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(10));
		RQ::DeleteFileByString(path_to_profile);
	}
	else
	{
		std::cout << "Failed to create process: " << GetLastError() << std::endl;
	}
}


namespace RQ {

	StartProcessInfo StartProcess(std::string path, std::string args) {

		STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION processInfo;

		args = " " + args;
		bool success = (bool)CreateProcess(
			path.c_str(),
			const_cast<LPSTR>(args.c_str()),
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			NULL,
			&info,
			&processInfo
		);
		return StartProcessInfo{
			success,
			processInfo.hProcess,
			processInfo.hThread,
			processInfo.dwProcessId,
			processInfo.dwThreadId
		};
	}

	std::string GetAbsPathToParentDirAsString(std::string input) {
		std::filesystem::path first_path = input;
		std::filesystem::path parent = first_path.parent_path();
		return std::filesystem::absolute(parent).string() + "\\";
	}


	void CreateFileWithText(std::string path, std::string name, std::string data) {
		std::filesystem::create_directories(path);
		std::filesystem::path file_path = std::filesystem::path(path) / std::filesystem::path(name);

		std::ofstream file(file_path, std::ios::out | std::ios::trunc);

		if (file.is_open()) {
			file << data;

			std::cout << "File with data created successfully at " << file_path << std::endl;
		}
		else {
			std::cerr << "Error creating file with data at " << file_path << std::endl;
		}
	}

	void DeleteFileByString(std::string path) {
		std::filesystem::path file_path = std::filesystem::path(path);

		if (std::filesystem::exists(file_path)) {
			if (std::filesystem::remove(file_path)) {
				std::cout << "File " << file_path << " deleted successfully." << std::endl;
			}
			else {
				std::cerr << "Error deleting file " << file_path << std::endl;
			}
		}
		else {
			std::cerr << "File " << file_path << " does not exist." << std::endl;
		}
	}
}
