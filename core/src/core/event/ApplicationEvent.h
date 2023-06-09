#pragma once
#include "_Core.h"
#include "utility.h"

#include "event/Event.h"
//WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
//AppTick, AppUpdate, AppRender,

namespace core {
	class WindowCloseEvent final : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowClose)
	};

	class WindowResizeEvent final : public Event
	{
	private:
		unsigned int width, height;

	public:
		WindowResizeEvent() = default;
		WindowResizeEvent(const unsigned int width, const unsigned int height)
			: width(width), height(height) { }

		inline unsigned int getWidth() const { return width; }
		inline unsigned int getHeight() const { return height; }

		std::string ToString() const override
		{
			std::stringstream string;
			string << "WindowResizeEvent width: " << width << " height: " << height;
			return string.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryApplication)
		EVENT_CLASS_TYPE(WindowResize)
	};

	class AppTickEvent final : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppUpdateEvent final : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class AppRenderEvent final : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}