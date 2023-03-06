#include "rizeq.h"

int main(const int argc, char* argv[])
{

	//  D:\Steam\steamapps\common\Grand Theft Auto V\altvinstall\altv.exe
	//	Plan:
	//		start xenos state waiting for gta (later B(l)ackBone or platform specific injector)
	//		start altv or game to inject i.e. vanilla for example
	//		inject dll start gui tinker with data
	const std::string altv_path = R"(D:\Steam\steamapps\common\Grand Theft Auto V\altvinstall\altv.exe)";

	const std::string xenos_file_name	= "Xenos64.exe";
	const std::string profile_file_name	= ".dat";

	const std::string current_dir = rq::GetAbsPathToParentDirAsString(argv[0]);

	const std::string path_to_xenos	= current_dir + xenos_file_name;
	const std::string path_to_dll	= current_dir + "Injected.dll";

	std::string path_to_target = R"(D:\Steam\steamapps\common\Grand Theft Auto V\GTA5.exe)"; // current_dir + "dummjy.exe";

	if (argc > 1) {
		path_to_target = argv[1];
	}

	const auto xenos_profile = rq::XenosProfile()
	                           .SetDllPath(path_to_dll)
	                           .SetTargetPath(path_to_target)
	                           .SetProcessMode("2")
	                           .SetDelayMs("1000");

	const auto path_to_profile = rq::CreateFileWithText
	(
		current_dir,
		profile_file_name,
		xenos_profile.Build()
	);
	
	const std::string options = "--run " + path_to_profile;

	// query start which
	bool answered = false;
	while (!answered) {

		if (std::cin.fail()) {
			std::cin.clear();
#define ________placeholder max
#undef max
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
#define max ________placeholder
			continue;
		}
		int input;
		std::cout << "Please enter a number\n(1) vanilla\n(2) altv\n";
		std::cin >> input; // Read input from the user
		switch (input) {
		case 1:
			std::cout << "vanilla is currently not supported" << std::endl;
			break;
		case 2:
			std::cout << "Starting altv..." << std::endl;
			rq::StartProcess(altv_path, "", rq::GetAbsPathToParentDirAsString(altv_path));
			answered = true;
			break;
		default:
			std::cout << "Invalid input. Please try again." << std::endl;
			break;
		}
	}

	const auto info = rq::StartProcess(path_to_xenos, options, current_dir);

	if (info.success) {
		std::cout << "Process created with ID " << info.dw_process_id << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(2));
		rq::DeleteFileByString(path_to_profile);
	}
	else {
		std::cout << "Failed to create process: " << GetLastError() << std::endl;
	}

	// ask
	
}


namespace rq {

	StartProcessInfo StartProcess(const std::string& path, std::string args, const std::string& working_directory) {

		STARTUPINFO info = { sizeof(info) };
		PROCESS_INFORMATION process_info;

		args = " " + args;
		const bool success = static_cast<bool>(CreateProcess(
			path.c_str(),
			const_cast<LPSTR>(args.c_str()),
			NULL,
			NULL,
			FALSE,
			0,
			NULL,
			working_directory.c_str(),
			&info,
			&process_info
		));
		return StartProcessInfo{
			success,
			process_info.hProcess,
			process_info.hThread,
			process_info.dwProcessId,
			process_info.dwThreadId
		};
	}

	std::string GetAbsPathToParentDirAsString(const std::string& input) {
		const auto parent = std::filesystem::path(input).parent_path();
		return std::filesystem::absolute(parent).string() + "\\";
	}

	std::string CreateFileWithText(const std::string& path, const std::string& name, const std::string& data) {
		std::filesystem::create_directories(path);
		const std::filesystem::path file_path = std::filesystem::path(path) / std::filesystem::path(name);

		if (std::ofstream file(file_path, std::ios::out | std::ios::trunc); file.is_open()) {
			file << data;
			std::cout << "File with data created successfully at " << file_path << std::endl;
			return file_path.string();
		}
		else {
			std::cerr << "Error creating file with data at " << file_path << std::endl;
			return "";
		}
	}

	void DeleteFileByString(const std::string& path) {
		const auto file_path = std::filesystem::path(path);

		if (exists(file_path)) {
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
