#pragma once

#include "pch.h"
#include "MetroUtil.h"
#include "ImplImage.h"

namespace Metro
{
	class METRO_API Image
	{
	public:
		Image(const std::string& imageFile);
		Image(std::string&& imageFile);

		void Activate();

		int GetWidth() const;
		int GetHeight() const;


	private:
		std::unique_ptr<ImplImage> mImplementation{ nullptr };



	};
}
