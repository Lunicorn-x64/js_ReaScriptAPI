#ifndef JS_REASCRIPTAPI_STDAFX
#define JS_REASCRIPTAPI_STDAFX

#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_NONSTDC_NO_DEPRECATE 1

#include <cstdio>
#include <string>
#include <cstdlib>
#include <errno.h>
#include <map>
#include <set>
#include <utility>
#include <cstdint>

#define REAPERAPI_IMPLEMENT
//#define REAPERAPI_MINIMAL // Only load the API functions #define'd by REAPERAPI_WANT_... This lowers the size of the dll by about 30kb, which isn't really worth the trouble.
//#define REAPERAPI_WANT_plugin_register
//#define REAPERAPI_WANT_MIDIEditor_GetMode
//#define REAPERAPI_WANT_SetExtState
//#define REAPERAPI_WANT_time_precise
//#define REAPERAPI_WANT_all 50 lice functions...
#define LICE_PROVIDED_BY_APP
#define SWELL_PROVIDED_BY_APP

// reaper_plugin_functions.h #include's reaper_plugin.h, which in turn #include's either windows.h or swell.h, depending on platform.
// So probably only necessary to #include reaper_plugins_functions.h
#include "reaper_plugin_functions.h" 
#ifdef _WIN32
// #include windows.h is not necessary
#include <windowsx.h>
#define WINAPI __stdcall
#else
#define WINAPI
#endif
// WARNING: REAPER has a handful of UNDOCUMENTED API functions that are not declared in reaper_plugin_functions.h, so must declare here:
BOOL(WINAPI *CoolSB_GetScrollInfo)(HWND hwnd, int nBar, LPSCROLLINFO lpsi);
int (WINAPI *CoolSB_SetScrollInfo)(HWND hwnd, int nBar, LPSCROLLINFO lpsi, BOOL fRedraw);
int (WINAPI *CoolSB_SetScrollPos)(HWND hwnd, int nBar, int nPos, BOOL fRedraw);
void(*AttachWindowTopmostButton)(HWND hwnd);
void(*AttachWindowResizeGrip)(HWND hwnd);
BOOL(WINAPI *RemoveXPStyle)(HWND hwnd, int rm);

#include "js_ReaScriptAPI_namespace.h"
#include "js_ReaScriptAPI.h"
#include "js_ReaScriptAPI_vararg.h"
#include "js_ReaScriptAPI_def.h"

#endif