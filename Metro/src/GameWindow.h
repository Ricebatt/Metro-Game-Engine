#pragma once

#include "pch.h"
#include "MetroUtil.h"
#include "WindowImplementation.h"


namespace Metro
{
	class METRO_API GameWindow
	{
	public:
		static void Init();
		static std::unique_ptr<GameWindow>& GetWindow();

		static void CreateWindow(int width, int height, const std::string& windowName);
		static void CreateWindow(int width, int height, std::string&& windowName);

		static void SwapBuffers();
		static void PollEvents();

		static int GetWidth();
		static int GetHeight();

		~GameWindow();
	private:
		GameWindow();
		inline static std::unique_ptr<GameWindow> mInstance{ nullptr };

		WindowImplementation* mImplementation{ nullptr };


	};
}