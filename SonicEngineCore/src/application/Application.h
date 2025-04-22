#pragma once
#include "math\Constants.h"

namespace Sonic
{

	class Application
	{
	public:
		Application(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(const Application&) = delete;
		Application& operator=(Application&&) = delete;

		Application() = default;
		virtual ~Application() = default;

		void run();
	};

}