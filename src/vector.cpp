#include <cmath>
#include "vector.h"
using namespace athl;

Vector Vector::operator +(const Vector &vector) const
{
	return
	{
		.x = x + vector.x,
		.y = y + vector.y,
		.z = z + vector.z
	};
}

Vector Vector::operator -(const Vector &vector) const
{
	return
	{
		.x = x + vector.x,
		.y = y + vector.y,
		.z = z + vector.z
	};
}

Vector Vector::operator *(double scalar) const
{
	return
	{
		.x = scalar * x,
		.y = scalar * y,
		.z = scalar * z
	};
}

double Vector::dot(const Vector &vector) const
{
	return x * vector.x + y * vector.y + z * vector.z;
}

Vector Vector::cross(const Vector &vector) const
{
	return
	{
		.x = y * vector.z - z * vector.y,
		.y = z * vector.x - x * vector.z,
		.z = x * vector.y - y * vector.x
	};
}

double Vector::size() const
{
	return x * x + y * y + z * z;
}

double Vector::magnitude() const
{
	return std::sqrt(size());
}
