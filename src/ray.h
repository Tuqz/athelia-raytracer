#pragma once
#include "vector.h"
#include "colour.h"

namespace athl
{
	class Ray
	{
	public:
		Ray(const Vector &position, const Vector &direction, const Colour &colour);
		double intersects_AABB(const Vector &origin, double size) const;
	private:
		const Vector position, direction, inverse_direction;
		const Colour colour;
	};
}
