#include "octree.h"
#include <algorithm>
using namespace athl;

Octree::Octree()
	: Octree(Vector(0), 1.0)
{}

Octree::~Octree()
{
	if(is_leaf)
		delete data.leaf;
	else
		for(auto branch : data.branches)
			delete branch;
}

Octree::Octree(const Vector &position, double size)
	: position(position), size(size), is_leaf(false), data {.branches = {nullptr}}
{}

Octree::Octree(const Vector &position, const Voxel &data)
	: position(position), size(0.0), is_leaf(true), data {.leaf = new Voxel(data)}
{}

void Octree::insert(const Voxel &voxel, const Vector &target, int depth)
{
	if(is_leaf)
		return;

	int octant = find_octant(target);
	if(depth < 1)
	{
		if(!data.branches[octant])
			data.branches[octant] = new Octree(octant_position(octant), voxel);
	}
	else
	{
		if(!data.branches[octant])
			data.branches[octant] = new Octree(octant_position(octant), size / 2);
		data.branches[octant]->insert(voxel, target, --depth);
	}
}

const Voxel *Octree::lookup(const Vector &target, int depth) const
{
	if(is_leaf && depth < 1)
		return data.leaf;

	int octant = find_octant(target);
	if(!is_leaf && depth >= 1 && data.branches[octant])
		return data.branches[octant]->lookup(target, --depth);

	return nullptr;
}

void Octree::remove(const Vector &target, int depth)
{
	if(is_leaf)
	{
		if(depth < 1)
		{
			delete data.leaf;
			data.leaf = nullptr;
		}
	}
	else
	{
		if(depth >= 1)
		{
			int octant = find_octant(position);
			if(data.branches[octant])
				data.branches[octant]->remove(target, --depth);

			for(auto &branch : data.branches)
			{
				if(branch)
				{
					if(branch->is_leaf && !branch->data.leaf)
					{
						delete branch;
						branch = nullptr;
					}
					else if(!branch->is_leaf && std::none_of
					(
						branch->data.branches.begin(),
						branch->data.branches.end(),
						[](Octree *o) { return o; }
					))
					{
						delete branch;
						branch = nullptr;
					}
				}
			}
		}
	}
}

int Octree::find_octant(const Vector &target) const
{
	Vector halfway
	(
		position.x + size / 2,
		position.y + size / 2,
		position.z + size / 2
	);
	return (halfway.z <= target.z) << 2
		| (halfway.y <= target.y) << 1
		| (halfway.x <= target.x) << 0;
}

Vector Octree::octant_position(int offset) const
{
	Vector units(!!(offset & 4), !!(offset & 2), !!(offset & 1));
	return units * (size / 2) + position;
}
