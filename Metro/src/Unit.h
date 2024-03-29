#pragma once

#include "MetroUtil.h"
#include "Image.h"
#include "RendererTypes.h"

namespace Metro
{
	class METRO_API Unit
	{
	public:
		Unit(const std::string& image, ScreenCoord coords);
		Unit(std::string&& image, ScreenCoord coords);

		int GetWidth() const;
		int GetHeight() const;
		int GetVelo() const;

		ScreenCoord GetCoords() const;
		void SetCoords(ScreenCoord newCoords);
		void SetVelo(int amount);
		void UpdateYVelo(int amount);
		void UpdateXCoord(int amount);
		void UpdateYCoord(int amount);

	private:
		Image mImage;
		ScreenCoord mPosition;
		int mVelo;

		friend class Renderer;
		friend METRO_API bool UnitsOverlap(const Unit& a, const Unit& b);
	};

	METRO_API bool UnitsOverlap(const Unit& a, const Unit& b);

}