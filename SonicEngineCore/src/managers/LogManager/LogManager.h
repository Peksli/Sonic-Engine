#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>


namespace Sonic
{

	class LogManager
	{
	public:
		static std::shared_ptr<spdlog::logger> sonicLogger;
		static std::shared_ptr<spdlog::logger> userLogger;

		static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> sonicConsoleSink;
		static std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> userConsoleSink;

		static void Initialize();
	};

}


// Sonic Engine macro
#define SONIC_TRACE(...)		Sonic::LogManager::sonicLogger->trace(__VA_ARGS__)
#define SONIC_DEBUG(...)		Sonic::LogManager::sonicLogger->debug(__VA_ARGS__)
#define SONIC_INFO(...)			Sonic::LogManager::sonicLogger->info(__VA_ARGS__)
#define SONIC_WARN(...)			Sonic::LogManager::sonicLogger->warn(__VA_ARGS__)
#define SONIC_ERROR(...)		Sonic::LogManager::sonicLogger->error(__VA_ARGS__)
#define SONIC_CRITICAL(...)		Sonic::LogManager::sonicLogger->critical(__VA_ARGS__)


// User (Editor) macro
#define USER_TRACE(...)			Sonic::LogManager::userLogger->trace(__VA_ARGS__)
#define USER_DEBUG(...)			Sonic::LogManager::userLogger->debug(__VA_ARGS__)
#define USER_INFO(...)			Sonic::LogManager::userLogger->info(__VA_ARGS__)
#define USER_WARN(...)			Sonic::LogManager::userLogger->warn(__VA_ARGS__)
#define USER_ERROR(...)			Sonic::LogManager::userLogger->error(__VA_ARGS__)
#define USER_CRITICAL(...)		Sonic::LogManager::userLogger->critical(__VA_ARGS__)