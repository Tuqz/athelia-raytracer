#include "colour.h"
using namespace athl;

Colour::Colour(float red, float green, float blue, float intensity)
	: red(red), green(green), blue(blue), intensity(intensity)
{}

Colour Colour::operator *(const Colour &blend) const
{
	return
	{
		.red = (red + blend.red) / 2,
		.green = (green + blend.green) / 2,
		.blue = (blue + blend.blue) / 2,
		.intensity = intensity * blend.intensity
	};
}
