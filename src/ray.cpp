#include <limits>
#include "ray.h"
using namespace athl;

Ray::Ray(const Vector &position, const Vector &direction)
:
	position(position),
	direction(direction),
	inverse_direction(1 / direction.x, 1 / direction.y, 1 / direction.z)
{}
