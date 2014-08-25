#pragma once

namespace athl
{
	class Colour
	{
	public:
		float red, green, blue, intensity;
		Colour(float red, float green, float blue, float intensity);
		Colour operator *(const Colour &blend) const;
	};
}
