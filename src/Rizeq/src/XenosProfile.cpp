#include "XenosProfile.h"

namespace rq {

	std::string XenosProfile::Build() const {
		return std::string("<XenosConfig>\n"
			"	<imagePath>" + m_image_path + "</imagePath>\n"
			"	<manualMapFlags>" + m_manual_map_flags + "</manualMapFlags>\n"
			"	<procName>" + m_proc_name + "</procName>\n"
			"	<hijack>" + m_hijack + "</hijack>\n"
			"	<unlink>" + m_unlink + "</unlink>\n"
			"	<erasePE>" + m_erase_pe + "</erasePE>\n"
			"	<close>" + m_close + "</close>\n"
			"	<krnHandle>" + m_krn_handle + "</krnHandle>\n"
			"	<injIndef>" + m_inj_indef + "</injIndef>\n"
			"	<processMode>" + m_process_mode + "</processMode>\n"
			"	<injectMode>" + m_inject_mode + "</injectMode>\n"
			"	<delay>" + m_delay + "</delay>\n"
			"	<period>" + m_period + "</period>\n"
			"	<skip>" + m_skip + "</skip>\n"
			"	<procCmdLine/>\n"
			"	<initRoutine/>\n"
			"	<initArgs/>\n"
			"</XenosConfig>");
	}


	XenosProfile XenosProfile::SetDllPath(const std::string& path) {
		m_image_path = path;
		return *this;
	}

	XenosProfile XenosProfile::SetManualMapFlags(const std::string& flags) {
		m_manual_map_flags = flags;
		return *this;
	}

	XenosProfile XenosProfile::SetTargetPath(const std::string& process_name) {
		m_proc_name = process_name;
		return *this;
	}

	XenosProfile XenosProfile::SetHijack(const std::string& value) {
		m_hijack = value;
		return *this;
	}

	XenosProfile XenosProfile::SetUnlink(const std::string& value) {
		m_unlink = value;
		return *this;
	}

	XenosProfile XenosProfile::SetErasePe(const std::string& value) {
		m_erase_pe = value;
		return *this;
	}

	XenosProfile XenosProfile::SetClose(const std::string& value) {
		m_close = value;
		return *this;
	}

	XenosProfile XenosProfile::SetKrnHandle(const std::string&& handle) {
		m_krn_handle = handle;
		return *this;
	}

	XenosProfile XenosProfile::SetInjIndef(const std::string& value) {
		m_inj_indef = value;
		return *this;
	}

	XenosProfile XenosProfile::SetProcessMode(const std::string& process_mode) {
		m_process_mode = process_mode;
		return *this;
	}

	XenosProfile XenosProfile::SetInjectMode(const std::string& inject_mode) {
		m_inject_mode = inject_mode;
		return *this;
	}

	XenosProfile XenosProfile::SetDelayMs(const std::string& delay_in_ms) {
		m_delay = delay_in_ms;
		return *this;
	}

	XenosProfile XenosProfile::SetPeriod(const std::string& value) {
		m_period = value;
		return *this;
	}

	XenosProfile XenosProfile::SetSkip(const std::string& value) {
		m_skip = value;
		return *this;
	}
}