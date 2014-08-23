#include "callback.h"
using namespace athl;

Callback::Callback(Runner runner, void *data) 
	: runner(runner), data(data)
{}

Ray Callback::run(Ray ray, Vector pos) const
{
	return runner(data, ray, pos);
}

Callback::~Callback()
{
	operator delete(data);
}
