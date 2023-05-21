#include "pch.h"
#include "Image.h"
#include "OpenGLCode/OpenGLImage.h"

namespace Metro
{
	Image::Image(const std::string& imageFile)
	{
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{imageFile} };
	}

	Image::Image(std::string&& imageFile)
	{
		mImplementation = std::unique_ptr<ImplImage>{ new OpenGLImage{std::move(imageFile)} };
	}

	void Image::Activate()
	{
		mImplementation->Activate();
	}

	int Image::GetWidth() const
	{
		return 0;
	}

	int Image::GetHeight() const
	{
		return 0;
	}
}