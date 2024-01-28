#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"
 
namespace RustedJar {
	class RJ_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#define LOG_RJ_TRACE(...)	::RustedJar::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LOG_RJ_INFO(...)	::RustedJar::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LOG_RJ_WARN(...)	::RustedJar::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LOG_RJ_ERROR(...)	::RustedJar::Log::GetCoreLogger()->error(__VA_ARGS__)

#define LOG_TRACE(...)		::RustedJar::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)		::RustedJar::Log::GetClientLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)		::RustedJar::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		::RustedJar::Log::GetClientLogger()->error(__VA_ARGS__)