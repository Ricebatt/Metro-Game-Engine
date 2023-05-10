#pragma once

namespace Metro
{
	class ImplImage
	{
	public:
		virtual void Activate() = 0;

		virtual int GetWidth() = 0;
		virtual int GetHeight() = 0;

		virtual ~ImplImage() {};
	};
}