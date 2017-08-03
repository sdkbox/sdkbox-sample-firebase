#ifndef __PluginFirebaseJS_h__
#define __PluginFirebaseJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginFirebaseJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JSObject* global);
void register_all_PluginFirebaseJS(JSContext* cx, JSObject* obj);
#endif
#endif

