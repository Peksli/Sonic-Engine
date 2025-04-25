#include "Application/Application.h"
#include "Managers/LogManager/LogManager.h"
#include "Managers/EventManager/WindowEvent.h"
#include "Math/Constants.h"
#include "Utils/Utils.h"

#include <string>


namespace Sonic
{

	void Application::run()
	{
		LogManager::Initialize();

		WindowResizeEvent w_resize(500, 500);

		SONIC_INFO("PI: {0}", Math::pi);
		SONIC_INFO("Hello from Sonic");
		SONIC_INFO("New window width: {0}", w_resize.GetNewWidth());

		std::string str{ "first, second, first, third, one, two" };
		getFrequencyWordVec(str);
	}

}