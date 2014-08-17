#include <lua.h>
#include <lauxlib.h>
#include "lua/test.h"

static const luaL_Reg athelia[] = 
{
	{.name = "test", .func = athl_lua_test}, 
	{.name = NULL, .func = NULL}
};

int luaopen_athelia(lua_State *state)
{
	luaL_openlib(state, "athelia", athelia, 0);
	return 1;
}
