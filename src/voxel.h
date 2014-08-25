#pragma once
#include "callback.h"

namespace athl
{
	class Voxel
	{
	public:
		Voxel(const Callback &callback);
		Ray do_intersection(const Ray &ray, const Vector &pos) const;
	private:
		const Callback callback;
	};
}
