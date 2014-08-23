#pragma once
#include "ray.h"
#include "vector.h"

namespace athl 
{
	typedef Ray (*Runner)(void *, Ray, Vector);
	class Callback 
	{
	public:
		Callback(Runner runner, void *data);
		Ray run(Ray ray, Vector pos) const;
		~Callback();
	private:
		const Runner runner;
		void *data;
	};
}
