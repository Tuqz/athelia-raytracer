#pragma once
#include "vector.h"

namespace athl
{
	class Ray
	{
	public:
		Ray(const Vector &position, const Vector &direction);
		const Vector position, direction;
	private:
		Vector inverse_direction;
	};
}
