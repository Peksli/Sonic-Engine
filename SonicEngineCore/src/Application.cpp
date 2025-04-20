#include "Application.h"
#include "LogManager\LogManager.h"
#include "EventManager\WindowEvent.h"
#include "math\Constants.h"


namespace Sonic
{

	void Application::run()
	{
		LogManager::Initialize();

		WindowResizeEvent w_resize(500, 500);

		SONIC_INFO("PI: {0}", Math::pi);
		SONIC_INFO("Hello from Sonic");
		SONIC_INFO("New window width: {0}", w_resize.GetNewWidth());
	}

}