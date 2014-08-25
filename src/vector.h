#pragma once

namespace athl
{
	class Vector
	{
	public:
		Vector(double value);
		Vector(double x, double y, double z);
		double x, y, z;
		Vector operator +(const Vector &vector) const;
		Vector operator -(const Vector &vector) const;
		Vector operator *(double scalar) const;

		double dot(const Vector &vector) const;
		Vector cross(const Vector &vector) const;

		double size() const;
		double magnitude() const;
	};
}
