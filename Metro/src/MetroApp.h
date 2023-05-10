#pragma once

#include "pch.h"
#include "MetroUtil.h"

constexpr int FPS{ 60 };

namespace Metro
{
	class METRO_API MetroApp
	{
	public:
		void virtual OnUpdate() = 0;

		void Run();


	private:
		std::chrono::milliseconds mFrameDurarion{ std::chrono::milliseconds{1000} / FPS };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};
}
