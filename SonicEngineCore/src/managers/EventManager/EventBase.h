#pragma once

#include "Managers/EventManager/EventManagerMacros.h"

#include <string>


namespace Sonic
{
	// Thanks TheCherno for this macro
	enum class EventType
	{
		None = 0,
		WindowResize, WindowClose, WindowMove,
		KeyPressed, KeyReleased,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum class EventCategory
	{
		WindowCategory	 =   BIT(0),
		InputCategory	 =	 BIT(1),
		KeyboardCategory =	 BIT(2),
		MouseCategory	 =   BIT(3)
	};

	class EventBase
	{
	public:
		virtual EventType GetEventType() const = 0;
		virtual EventCategory GetEventCategory() const = 0;
		virtual const char* GetEventNameCStyle() const = 0;
		virtual std::string GetEventNameString() const = 0;

		bool handled = false;
	};

}