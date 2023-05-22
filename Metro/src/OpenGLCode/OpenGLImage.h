#pragma once

#include "pch.h"
#include "../ImplImage.h"

namespace Metro
{
	class OpenGLImage : public ImplImage
	{
	public:
		OpenGLImage(const std::string& imageFile);
		OpenGLImage(std::string&& imageFile);
		~OpenGLImage();

		virtual void Activate() override;

		virtual int GetWidth() override;
		virtual int GetHeight() override;
	private:
		int mWidth{ 0 };
		int mHeight{ 0 };
		int mnrChannels{ 0 };
		unsigned int texture1;

	};
}