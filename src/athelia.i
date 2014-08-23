%module athelia
%{
	#include "vector.h"
	#include "ray.h"
	#include "callback.h"
	class LuaDatum
	{
	public:
		lua_State *state;
		int key;
	};
	athl::Ray run_callback(void *data, athl::Ray ray, athl::Vector pos)
	{
		auto ldata = static_cast<struct LuaDatum *>(data);
		auto state = ldata->state;
		auto key = ldata->key;
		lua_rawgeti(state, LUA_REGISTRYINDEX, key);
		swig_type_info *rayType = SWIG_TypeQuery("Ray *");
		SWIG_NewPointerObj(state, &ray, rayType, 1);
		swig_type_info *vecType = SWIG_TypeQuery("Vector *");
		SWIG_NewPointerObj(state, &pos, vecType, 1);
		lua_pcall(state, 2, 1, 0);
		athl::Ray *result = static_cast<athl::Ray *>(lua_touserdata(state, -1));
		return *result;
	}
%}

%include "vector.h"
%include "ray.h"

%{
int make_callback(lua_State *state)
{
	int key = luaL_ref(state, LUA_REGISTRYINDEX);
	LuaDatum *data = operator new(sizeof(LuaDatum));
	data->state = state;
	data->key = key;
	auto cb = new athl::Callback(run_callback, data);
	lua_pushlightuserdata(state, cb);
	return 1;
}
%}
