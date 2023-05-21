#pragma once

#include "pch.h"
#include "MetroUtil.h"
#include "MetroEvents.h"

constexpr int FPS{ 60 };

namespace Metro
{
	class METRO_API MetroApp
	{
	public:
		void virtual OnUpdate() = 0;

		MetroApp();

		void Run();

		void SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc);
		void SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc);
		void SetWindowCloseCallback(std::function<void()> callbackFunc);

	private:
		std::chrono::milliseconds mFrameDurarion{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	
		bool mGameWindowShouldClose{ false };

		void DefaultWindowCloseHandler();
	};
}
