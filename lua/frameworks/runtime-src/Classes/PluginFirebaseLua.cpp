#include "PluginFirebaseLua.hpp"
#include "PluginFirebase/PluginFirebase.h"
#include "SDKBoxLuaHelper.h"
#include "sdkbox/Sdkbox.h"



int lua_PluginFirebaseLua_Analytics_setUserProperty(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.firebase.Analytics:setUserProperty");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.firebase.Analytics:setUserProperty");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_setUserProperty'", nullptr);
            return 0;
        }
        sdkbox::Firebase::Analytics::setUserProperty(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:setUserProperty",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_setUserProperty'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFirebaseLua_Analytics_setUserID(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 1)
    {
        std::string arg0;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.firebase.Analytics:setUserID");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_setUserID'", nullptr);
            return 0;
        }
        sdkbox::Firebase::Analytics::setUserID(arg0);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:setUserID",argc, 1);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_setUserID'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFirebaseLua_Analytics_logEvent(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::map<std::string, std::string> arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.firebase.Analytics:logEvent");
        ok &= luaval_to_std_map_string_string(tolua_S, 3, &arg1, "sdkbox.firebase.Analytics:logEvent");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_logEvent'", nullptr);
            return 0;
        }
        sdkbox::Firebase::Analytics::logEvent(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:logEvent",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_logEvent'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFirebaseLua_Analytics_init(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_init'", nullptr);
            return 0;
        }
        bool ret = sdkbox::Firebase::Analytics::init();
        tolua_pushboolean(tolua_S,(bool)ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:init",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_init'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFirebaseLua_Analytics_setScreenName(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 2)
    {
        std::string arg0;
        std::string arg1;
        ok &= luaval_to_std_string(tolua_S, 2,&arg0, "sdkbox.firebase.Analytics:setScreenName");
        ok &= luaval_to_std_string(tolua_S, 3,&arg1, "sdkbox.firebase.Analytics:setScreenName");
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_setScreenName'", nullptr);
            return 0;
        }
        sdkbox::Firebase::Analytics::setScreenName(arg0, arg1);
        lua_settop(tolua_S, 1);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:setScreenName",argc, 2);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_setScreenName'.",&tolua_err);
#endif
    return 0;
}
int lua_PluginFirebaseLua_Analytics_getVersion(lua_State* tolua_S)
{
    int argc = 0;
    bool ok  = true;

#if COCOS2D_DEBUG >= 1
    tolua_Error tolua_err;
#endif

#if COCOS2D_DEBUG >= 1
    if (!tolua_isusertable(tolua_S,1,"sdkbox.firebase.Analytics",0,&tolua_err)) goto tolua_lerror;
#endif

    argc = lua_gettop(tolua_S) - 1;

    if (argc == 0)
    {
        if(!ok)
        {
            tolua_error(tolua_S,"invalid arguments in function 'lua_PluginFirebaseLua_Analytics_getVersion'", nullptr);
            return 0;
        }
        std::string ret = sdkbox::Firebase::Analytics::getVersion();
        tolua_pushcppstring(tolua_S,ret);
        return 1;
    }
    luaL_error(tolua_S, "%s has wrong number of arguments: %d, was expecting %d\n ", "sdkbox.firebase.Analytics:getVersion",argc, 0);
    return 0;
#if COCOS2D_DEBUG >= 1
    tolua_lerror:
    tolua_error(tolua_S,"#ferror in function 'lua_PluginFirebaseLua_Analytics_getVersion'.",&tolua_err);
#endif
    return 0;
}
static int lua_PluginFirebaseLua_Analytics_finalize(lua_State* tolua_S)
{
    printf("luabindings: finalizing LUA object (Analytics)");
    return 0;
}

int lua_register_PluginFirebaseLua_Analytics(lua_State* tolua_S)
{
    tolua_usertype(tolua_S,"sdkbox.firebase.Analytics");
    tolua_cclass(tolua_S,"Analytics","sdkbox.firebase.Analytics","",nullptr);

    tolua_beginmodule(tolua_S,"Analytics");
        tolua_function(tolua_S,"setUserProperty", lua_PluginFirebaseLua_Analytics_setUserProperty);
        tolua_function(tolua_S,"setUserID", lua_PluginFirebaseLua_Analytics_setUserID);
        tolua_function(tolua_S,"logEvent", lua_PluginFirebaseLua_Analytics_logEvent);
        tolua_function(tolua_S,"init", lua_PluginFirebaseLua_Analytics_init);
        tolua_function(tolua_S,"setScreenName", lua_PluginFirebaseLua_Analytics_setScreenName);
        tolua_function(tolua_S,"getVersion", lua_PluginFirebaseLua_Analytics_getVersion);
    tolua_endmodule(tolua_S);
    std::string typeName = typeid(sdkbox::Firebase::Analytics).name();
    g_luaType[typeName] = "sdkbox.firebase.Analytics";
    g_typeCast["Analytics"] = "sdkbox.firebase.Analytics";
    return 1;
}
TOLUA_API int register_all_PluginFirebaseLua(lua_State* tolua_S)
{
	tolua_open(tolua_S);

	std::stringstream ss("sdkbox.firebase");
    std::vector<std::string> nsvec;
    std::string item;
    while (std::getline(ss, item, '.')) {
        nsvec.push_back(item);
    }
    int nsLen = nsvec.size();
    item = nsvec.front();
    nsvec.erase(nsvec.begin());

    tolua_module(tolua_S, item.c_str(), 0);
    tolua_beginmodule(tolua_S, item.c_str());

    while (nsvec.size() > 0) {
        item = nsvec.front();
        nsvec.erase(nsvec.begin());
        lua_pushstring(tolua_S, item.c_str()); // m name
        lua_rawget(tolua_S, -2);             // m value
        if (!lua_istable(tolua_S, -1)) {
            lua_pop(tolua_S, 1);             // m
            lua_newtable(tolua_S);           // m t
            lua_pushstring(tolua_S, item.c_str()); // m t name
            lua_pushvalue(tolua_S, -2);      // m t name t
            lua_rawset(tolua_S, -4);         // m t
        }
    }

	lua_register_PluginFirebaseLua_Analytics(tolua_S);

	if (nsLen > 1) {
        lua_pop(tolua_S, nsLen - 1); // m
    }
	tolua_endmodule(tolua_S);

	sdkbox::setProjectType("lua");
	return 1;
}

