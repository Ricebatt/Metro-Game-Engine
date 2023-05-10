#include "pch.h"
#include "Image.h"

namespace Metro
{
	Image::Image(const std::string& imageFile)
	{
	}

	Image::Image(std::string&& imageFile)
	{
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