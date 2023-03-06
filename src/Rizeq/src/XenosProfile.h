#pragma once
#include <string>
namespace RQ {

	struct XenosProfile {
	public:
		std::string Build();

		XenosProfile SetDllPath(std::string path);
		XenosProfile SetManualMapFlags(std::string flags);
		XenosProfile SetTargetPath(std::string process_name);
		XenosProfile SetHijack(std::string value);
		XenosProfile SetUnlink(std::string value);
		XenosProfile SetErasePE(std::string value);
		XenosProfile SetClose(std::string value);
		XenosProfile SetKrnHandle(std::string handle);
		XenosProfile SetInjIndef(std::string value);
		XenosProfile SetProcessMode(std::string process_mode);
		XenosProfile SetInjectMode(std::string inject_mode);
		XenosProfile SetDelayMs(std::string delay_in_ms);
		XenosProfile SetPeriod(std::string value);
		XenosProfile SetSkip(std::string value);
	private:
		std::string imagePath = "";
		std::string manualMapFlags = "0";
		std::string procName = "";
		std::string hijack = "0";
		std::string unlink = "0";
		std::string erasePE = "0";
		std::string close = "0";
		std::string krnHandle = "0";
		std::string injIndef = "0";
		std::string processMode = "0";
		std::string injectMode = "0";
		std::string delay = "0";
		std::string period = "0";
		std::string skip = "0";

	};
}