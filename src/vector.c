#include "vector.h"
#include <math.h>

struct AthlVector athl_vector_add
(
	struct AthlVector one,
	struct AthlVector two
)
{
	struct AthlVector result =
	{
		.x = one.x + two.x,
		.y = one.y + two.y,
		.z = one.z + two.z
	};
	return result;
}

struct AthlVector athl_vector_subtract
(
	struct AthlVector one,
	struct AthlVector two
)
{
	struct AthlVector result =
	{
		.x = one.x - two.x,
		.y = one.y - two.y,
		.z = one.z - two.z
	};
	return result;
}


struct AthlVector athl_vector_multiply
(
	double scalar,
	struct AthlVector vector
)
{
	struct AthlVector result =
	{
		.x = scalar * vector.x,
		.y = scalar * vector.y,
		.z = scalar * vector.z
	};
	return result;
}

double athl_vector_dot
(
	struct AthlVector one,
	struct AthlVector two
)
{
	return one.x * two.x + one.y * two.y + one.z * two.z;
}

struct AthlVector athl_vector_cross
(
	struct AthlVector one,
	struct AthlVector two
)
{
	struct AthlVector result =
	{
		.x = one.y * two.z - one.z * two.y,
		.y = one.z * two.x - one.x * two.z,
		.z = one.x * two.y - one.y * two.x
	};
	return result;
}

double athl_vector_size
(
	struct AthlVector vector
)
{
	return vector.x * vector.x + vector.y * vector.y + vector.z * vector.z;
}

double athl_vector_magnitude
(
	struct AthlVector vector
)
{
	return sqrt(athl_vector_size(vector));
}
