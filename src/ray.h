#pragma once
#include "vector.h"

namespace athl
{
	class Ray
	{
	public:
		Ray(const Vector &position, const Vector &direction);
		double intersects_box(const Vector &min, double box_size);
		const Vector position, direction;
	private:
		Vector inverse_direction;
	};
}
