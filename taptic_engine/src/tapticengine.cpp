#define EXTENSION_NAME TapticEngine
#define LIB_NAME "TapticEngine"
#define MODULE_NAME "taptic_engine"

#define DLIB_LOG_DOMAIN LIB_NAME
#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "tapticengine.h"

static int isSupported(lua_State* L) {
    bool status = TapticEngine_IsSupported();
    lua_pushboolean(L, status);
    return 1;
}

static int impact(lua_State* L) {
    ImpactStyle style = (ImpactStyle) luaL_checkint(L, 1);
    TapticEngine_Impact(style);
    return 0;
}

static int notification(lua_State* L) {
    NotificationType type = (NotificationType) luaL_checkint(L, 1);
    TapticEngine_Notification(type);
    return 0;
}

static int selection(lua_State* L) {
    TapticEngine_Selection();
    return 0;
}

static const luaL_reg Module_methods[] =
{
    {"isSupported", isSupported},
    {"impact", impact},
    {"notification", notification},
    {"selection", selection},
    {0, 0}
};

static void LuaInit(lua_State* L)
{
    int top = lua_gettop(L);
    luaL_register(L, MODULE_NAME, Module_methods);

#define SETCONSTANT(name) \
        lua_pushnumber(L, (lua_Number) name); \
        lua_setfield(L, -2, #name);\

    SETCONSTANT(IMPACT_LIGHT)
    SETCONSTANT(IMPACT_MEDIUM)
    SETCONSTANT(IMPACT_HEAVY)

    SETCONSTANT(NOTIFICATION_SUCCESS)
    SETCONSTANT(NOTIFICATION_WARNING)
    SETCONSTANT(NOTIFICATION_ERROR)

#undef SETCONSTANT

    lua_pop(L, 1);
    assert(top == lua_gettop(L));
}

dmExtension::Result AppInitializeTaptic(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeTaptic(dmExtension::Params* params)
{
    LuaInit(params->m_L);
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeTaptic(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeTaptic(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#else // unsupported platforms

dmExtension::Result AppInitializeTaptic(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result InitializeTaptic(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result AppFinalizeTaptic(dmExtension::AppParams* params)
{
    return dmExtension::RESULT_OK;
}

dmExtension::Result FinalizeTaptic(dmExtension::Params* params)
{
    return dmExtension::RESULT_OK;
}

#endif


DM_DECLARE_EXTENSION(EXTENSION_NAME, LIB_NAME, AppInitializeTaptic, AppFinalizeTaptic, InitializeTaptic, 0, 0, FinalizeTaptic)
