#include "LogManager/LogManager.h"


namespace Sonic
{

	std::shared_ptr<spdlog::logger> LogManager::sonicLogger;
	std::shared_ptr<spdlog::logger> LogManager::userLogger;

	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> LogManager::sonicConsoleSink;
	std::shared_ptr<spdlog::sinks::stdout_color_sink_mt> LogManager::userConsoleSink;

	void LogManager::Initialize()
	{
		spdlog::info("Log manager: initializing...");

		sonicConsoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		userConsoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		if (!sonicConsoleSink)
		{
			spdlog::critical("Log manager: Failed to initialize sonicConsoleSink");
		}
		if (!userConsoleSink)
		{
			spdlog::critical("Log manager: Failed to initialize userConsoleSink");
		}
		else
		{
			spdlog::info("Log manager: Successfully initialized sonicConsoleSink and userConsoleSink");
		}
		

		sonicLogger = std::make_shared<spdlog::logger>("sonicLogger", sonicConsoleSink);
		userLogger = std::make_shared<spdlog::logger>("userLogger", userConsoleSink);
		if (!sonicLogger)
		{
			spdlog::critical("Log manager: Failed to initialize sonicLogger");
		}
		if (!userLogger)
		{
			spdlog::critical("Log manager: Failed to initialize userConsoleLogger");
		}
		else
		{
			spdlog::info("Log manager: Successfully initialized sonicLogger and userLogger");
		}
	}

}