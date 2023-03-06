#pragma once
#include <string>
namespace rq {

	struct XenosProfile {

		std::string Build() const;

		XenosProfile SetDllPath(const std::string& path);
		XenosProfile SetManualMapFlags(const std::string& flags);
		XenosProfile SetTargetPath(const std::string& process_name);
		XenosProfile SetHijack(const std::string& value);
		XenosProfile SetUnlink(const std::string& value);
		XenosProfile SetErasePe(const std::string& value);
		XenosProfile SetClose(const std::string& value);
		XenosProfile SetKrnHandle(const std::string&& handle);
		XenosProfile SetInjIndef(const std::string& value);
		XenosProfile SetProcessMode(const std::string& process_mode);
		XenosProfile SetInjectMode(const std::string& inject_mode);
		XenosProfile SetDelayMs(const std::string& delay_in_ms);
		XenosProfile SetPeriod(const std::string& value);
		XenosProfile SetSkip(const std::string& value);
	private:
		std::string m_image_path;
		std::string m_manual_map_flags = "0";
		std::string m_proc_name;
		std::string m_hijack = "0";
		std::string m_unlink = "0";
		std::string m_erase_pe = "0";
		std::string m_close = "0";
		std::string m_krn_handle = "0";
		std::string m_inj_indef = "0";
		std::string m_process_mode = "0";
		std::string m_inject_mode = "0";
		std::string m_delay = "0";
		std::string m_period = "0";
		std::string m_skip = "0";

	};
}