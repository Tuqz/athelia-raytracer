#include "callback.h"
using namespace athl;

Callback::Callback(CallbackExecFn runner, const std::shared_ptr<void> &data) 
	: runner(runner), data(data)
{}

Ray Callback::invoke(const Ray &ray, const Vector &pos) const
{
	return runner(data, ray, pos);
}
