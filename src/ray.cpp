#include <algorithm>
#include "ray.h"
using namespace athl;

Ray::Ray(const Vector &position, const Vector &direction)
:
	position(position),
	direction(direction),
	inverse_direction(1 / direction.x, 1 / direction.y, 1 / direction.z)
{}

double Ray::intersects_box(const Vector &min, double box_size)
{
	Vector max = min + Vector({box_size, box_size, box_size});

	double x_1 = (min.x - position.x) * inverse_direction.x;
	double x_2 = (max.x - position.x) * inverse_direction.x;

	double y_1 = (min.y - position.y) * inverse_direction.y;
	double y_2 = (max.y - position.y) * inverse_direction.y;

	double z_1 = (min.z - position.z) * inverse_direction.z;
	double z_2 = (max.z - position.z) * inverse_direction.z;

	auto t_limits = std::minmax({x_1, x_2, y_1, y_2, z_1, z_2});
	if(t_limits.first < t_limits.second && t_limits.first > 0)
		return t_limits.first;
	else
		return 0.0;
}
