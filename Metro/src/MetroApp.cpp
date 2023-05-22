#include "pch.h"
#include "MetroApp.h"

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "stb_image.h"

#include "Renderer.h"
#include "Shader.h"
#include "Image.h"
#include "GameWindow.h"


namespace Metro
{
	MetroApp::MetroApp()
	{
		GameWindow::Init();
		GameWindow::CreateWindow(1000, 500, "Test Name");

		SetWindowCloseCallback([this]() {DefaultWindowCloseHandler(); });
	}

	void MetroApp::Run()
	{
		mNextFrameTime = std::chrono::steady_clock::now();

		while (!mGameWindowShouldClose)
		{

			OnUpdate();

			std::this_thread::sleep_until(mNextFrameTime);

			Metro::GameWindow::SwapBuffers();
			Metro::GameWindow::PollEvents();
			

			mNextFrameTime = std::chrono::steady_clock::now() + mFrameDurarion;
		}
	}

	void MetroApp::SetKeyPressedCallback(std::function<void(const KeyPressed&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(callbackFunc);
	}

	void MetroApp::SetKeyReleasedCallback(std::function<void(const KeyReleased&)> callbackFunc)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(callbackFunc);
	}

	void MetroApp::SetWindowCloseCallback(std::function<void()> callbackFunc)
	{
		GameWindow::GetWindow()->SetWindowCloseCallback(callbackFunc);
	}

	void MetroApp::DefaultWindowCloseHandler()
	{
		mGameWindowShouldClose = true;
	}
}
