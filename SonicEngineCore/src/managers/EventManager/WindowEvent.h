#pragma once

#include "EventManager\EventManagerMacros.h"
#include "EventManager\EventBase.h"


namespace Sonic
{
	// implementing all functions will be a little cumbersome work,
	// thus macro help me with that

	class WindowResizeEvent : public EventBase
	{
	public:
		WindowResizeEvent(unsigned int new_width, unsigned int new_height)
			:w_width(new_width), w_height(new_height)
		{}

		inline unsigned int GetNewWidth() const { return w_width; }
		inline unsigned int GetNewHeight() const { return w_height; }

		EVENT_TYPE_PART(WindowResize);
		EVENT_CATEGORY_PART(WindowCategory);

	private:
		unsigned int w_width = 0, w_height = 0;
	};


}