#include "pch.h"
#include "MetroEvents.h"

namespace Metro
{
	KeyPressed::KeyPressed(int kCode): mKeyCode(kCode)
	{

	}

	int KeyPressed::GetKeyCode() const
	{
		return mKeyCode;
	}

	KeyReleased::KeyReleased(int kCode): mKeyCode(kCode)
	{
	}

	int KeyReleased::GetKeyCode() const
	{
		return mKeyCode;
	}
}