%module athelia
%{
    #include "vector.h"
    #include "ray.h"
    #include "callback.h"
	struct LuaDatum
    {
		Lua_State *state;
		int key;
	};
	Ray run_callback(void *data, Ray ray, Vector pos)
    {
        auto ldata = static_cast<struct LuaDatum *>(data);
		auto state = ldata->state;
        auto key = ldata->key;
		lua_rawgeti(state, LUA_REGISTRYINDEX, key);
        lua_pushlightuserdata(state, &ray);
    }
%}

%include "vector.h"
%include "ray.h"

int make_callback(lua_State *state)
{
	int key = luaL_ref(state, LUA_REGISTRYINDEX);
    auto data = new LuaDatum({.state = state, .key = key});
    auto cb = new athl::Callback(run_callback, data);
    lua_pushlightuserdata(state, cb);
    return 1;
}
