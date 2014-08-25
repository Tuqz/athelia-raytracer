#include "voxel.h"
using namespace athl;

Voxel::Voxel(const Callback &callback)
	: callback(callback)
{}

Ray Voxel::do_intersection(const Ray &ray, const Vector &pos) const
{
	return callback.invoke(ray, pos);
}
