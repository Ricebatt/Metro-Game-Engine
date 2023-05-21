#pragma once

#include "MetroUtil.h"

namespace Metro
{
	class METRO_API KeyPressed
	{
	public:
		KeyPressed(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class METRO_API KeyReleased
	{
	public:
		KeyReleased(int kCode);

		int GetKeyCode() const;

	private:
		int mKeyCode;
	};

	class METRO_API WindowClosed
	{

	};
}