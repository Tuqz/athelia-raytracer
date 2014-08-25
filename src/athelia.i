%module athelia
%{
	#include <memory>
	#include "vector.h"
	#include "colour.h"
	#include "ray.h"
	#include "callback.h"
	#include "voxel.h"
	#include "octree.h"
	class LuaDatum
	{
	public:
		lua_State *state;
		int key;
	};
	athl::Ray run_callback(const std::shared_ptr<void> &raw_data, const athl::Ray &ray, const athl::Vector &pos)
	{
		auto data = std::static_pointer_cast<LuaDatum>(raw_data);
		lua_rawgeti(data->state, LUA_REGISTRYINDEX, data->key);
		swig_type_info *rayType = SWIG_TypeQuery("athl::Ray *");
		SWIG_NewPointerObj(data->state, &ray, rayType, 0);
		swig_type_info *vecType = SWIG_TypeQuery("athl::Vector *");
		SWIG_NewPointerObj(data->state, &pos, vecType, 0);
		lua_pcall(data->state, 2, 1, 0);
		auto result = *static_cast<athl::Ray *>(lua_touserdata(data->state, -1));
		lua_pop(data->state, 1);
		return result;
	}
	int make_callback(lua_State *state)
	{
		int key = luaL_ref(state, LUA_REGISTRYINDEX);
		std::shared_ptr<void> data(new LuaDatum({.state = state, .key = key}));
		swig_type_info *callbackType = SWIG_TypeQuery("athl::Callback *");
		auto cb = new athl::Callback(run_callback, data);
		SWIG_NewPointerObj(state, cb, callbackType, 1);
		return 1;
	}
%}

%native(make_callback) int make_callback(lua_State *state);
%include "vector.h"
%include "colour.h"
%include "ray.h"
%include "callback.h"
%include "voxel.h"
%include "octree.h"
