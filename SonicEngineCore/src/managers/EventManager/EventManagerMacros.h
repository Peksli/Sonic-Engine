#pragma once

#define BIT(x) (1 << (x))

// will be using for implemeting part which is corresponding 
// to methods which gives us event type info
#define EVENT_TYPE_PART(type) \
		virtual EventType GetEventType() const override { return EventType::##type; } \
		virtual const char* GetEventNameCStyle() const override { return #type; } \
		virtual std::string GetEventNameString() const override { return #type; }
		
// will be using for implemeting part which is corresponding 
// to method which gives us event category info (for example keyboard event is the 
// input event and also keyboard event)
#define EVENT_CATEGORY_PART(category) \
		virtual EventCategory GetEventCategory() const override { return EventCategory::##category; }