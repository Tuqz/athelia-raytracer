#include <algorithm>
#include <limits>
#include "ray.h"
using namespace athl;

Ray::Ray(const Vector &position, const Vector &direction, const Colour &colour)
:
	position(position),
	direction(direction),
	inverse_direction(1 / direction.x, 1 / direction.y, 1 / direction.z),
	colour(colour)
{}

double Ray::intersects_AABB(const Vector &origin, double size) const
{
	Vector max = origin + Vector(size);

	double x1 = (origin.x - position.x) * inverse_direction.x;
	double x2 = (max.x - position.x) * inverse_direction.x;
	double xmax = std::max(x1, x2), xmin = std::min(x1, x2);

	double y1 = (origin.y - position.y) * inverse_direction.y;
	double y2 = (max.y - position.y) * inverse_direction.y;
	double ymax = std::max(y1, y2), ymin = std::min(y1, y2);

	double z1 = (origin.z - position.z) * inverse_direction.z;
	double z2 = (max.z - position.z) * inverse_direction.z;
	double zmax = std::max(z1, z2), zmin = std::min(z1, z2);

	double tmax = std::min({xmax, ymax, zmax});
	double tmin = std::max({xmin, ymin, zmin});

	if(tmax > 0 && tmax > tmin)
		return tmin > 0 ? tmin : tmax;
	else
		return std::numeric_limits<double>::infinity();
}
