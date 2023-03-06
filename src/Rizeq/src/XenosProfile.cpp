#include "XenosProfile.h"

namespace RQ {

	std::string XenosProfile::Build() {
		return std::string("<XenosConfig>\n"
			"	<imagePath>" + imagePath + "</imagePath>\n"
			"	<manualMapFlags>" + manualMapFlags + "</manualMapFlags>\n"
			"	<procName>" + procName + "</procName>\n"
			"	<hijack>" + hijack + "</hijack>\n"
			"	<unlink>" + unlink + "</unlink>\n"
			"	<erasePE>" + erasePE + "</erasePE>\n"
			"	<close>" + close + "</close>\n"
			"	<krnHandle>" + krnHandle + "</krnHandle>\n"
			"	<injIndef>" + injIndef + "</injIndef>\n"
			"	<processMode>" + processMode + "</processMode>\n"
			"	<injectMode>" + injectMode + "</injectMode>\n"
			"	<delay>" + delay + "</delay>\n"
			"	<period>" + period + "</period>\n"
			"	<skip>" + skip + "</skip>\n"
			"	<procCmdLine/>\n"
			"	<initRoutine/>\n"
			"	<initArgs/>\n"
			"</XenosConfig>");
	}

	XenosProfile XenosProfile::SetDllPath(std::string path) {
		imagePath = path;
		return *this;
	}
	XenosProfile XenosProfile::SetManualMapFlags(std::string flags) {
		manualMapFlags = flags;
		return *this;
	}
	XenosProfile XenosProfile::SetTargetPath(std::string process_name) {
		procName = process_name;
		return *this;
	}
	XenosProfile XenosProfile::SetHijack(std::string value) {
		hijack = value;
		return *this;
	}
	XenosProfile XenosProfile::SetUnlink(std::string value) {
		unlink = value;
		return *this;
	}
	XenosProfile XenosProfile::SetErasePE(std::string value) {
		erasePE = value;
		return *this;
	}
	XenosProfile XenosProfile::SetClose(std::string value) {
		close = value;
		return *this;
	}
	XenosProfile XenosProfile::SetKrnHandle(std::string handle) {
		krnHandle = handle;
		return *this;
	}
	XenosProfile XenosProfile::SetInjIndef(std::string value) {
		injIndef = value;
		return *this;
	}
	XenosProfile XenosProfile::SetProcessMode(std::string process_mode) {
		processMode = process_mode;
		return *this;
	}
	XenosProfile XenosProfile::SetInjectMode(std::string inject_mode) {
		injectMode = inject_mode;
		return *this;
	}
	XenosProfile XenosProfile::SetDelayMs(std::string delay_in_ms) {
		delay = delay_in_ms;
		return *this;
	}
	XenosProfile XenosProfile::SetPeriod(std::string value) {
		period = value;
		return *this;
	}
	XenosProfile XenosProfile::SetSkip(std::string value) {
		skip = value;
		return *this;
	}
}