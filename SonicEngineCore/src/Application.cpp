#include "Application.h"
#include "LogManager\LogManager.h"


namespace Sonic
{

	void Application::run()
	{
		LogManager::Initialize();
		SONIC_INFO("Hello from Sonic");
	}

}