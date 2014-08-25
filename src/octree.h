#pragma once
#include <array>
#include "vector.h"
#include "voxel.h"

namespace athl
{
	class Octree
	{
		Octree();
		~Octree();
		void insert(const Voxel &voxel, const Vector &position, int depth);
		const Voxel *lookup(const Vector &target, int depth) const;
		void remove(const Vector &target, int depth);
	private:
		Octree(const Vector &position, double size);
		Octree(const Vector &position, const Voxel &data);
		int find_octant(const Vector &target) const;
		Vector octant_position(int offset) const;
		const Vector position;
		const double size;
		const bool is_leaf;
		union OctreeData
		{
			Voxel *leaf;
			std::array<Octree *, 8> branches;
		} data;
	};
}
