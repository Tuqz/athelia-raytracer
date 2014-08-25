#pragma once
#include <memory>
#include <iostream>
#include "ray.h"
#include "vector.h"

namespace athl 
{
	typedef Ray (*CallbackExecFn)
	(
		const std::shared_ptr<void> &,
		const Ray &,
		const Vector &
	);
	class Callback 
	{
	public:
		Callback(CallbackExecFn runner, const std::shared_ptr<void> &data);
		Ray invoke(const Ray &ray, const Vector &pos) const;
	private:
		const CallbackExecFn runner;
		const std::shared_ptr<void> data;
	};
}
