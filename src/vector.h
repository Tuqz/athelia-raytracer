#pragma once

struct AthlVector
{
	double x, y, z;
};

struct AthlVector athl_vector_add
(
	struct AthlVector one,
	struct AthlVector two
);
struct AthlVector athl_vector_subtract
(
	struct AthlVector one,
	struct AthlVector two
);
struct AthlVector athl_vector_multiply
(
	double scalar,
	struct AthlVector vector
);
double athl_vector_dot
(
	struct AthlVector one,
	struct AthlVector two
);
struct AthlVector athl_vector_cross
(
	struct AthlVector one,
	struct AthlVector two
);
double athl_vector_size
(
	struct AthlVector vector
);
double athl_vector_magnitude
(
	struct AthlVector vector
);
