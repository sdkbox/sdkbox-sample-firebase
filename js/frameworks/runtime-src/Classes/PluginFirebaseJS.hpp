#ifndef __PluginFirebaseJS_h__
#define __PluginFirebaseJS_h__

#include "jsapi.h"
#include "jsfriendapi.h"


extern JSClass  *jsb_sdkbox_Firebase_Analytics_class;
extern JSObject *jsb_sdkbox_Firebase_Analytics_prototype;

#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JS::HandleObject global);
void register_all_PluginFirebaseJS(JSContext* cx, JS::HandleObject obj);
#else
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JSObject* global);
void register_all_PluginFirebaseJS(JSContext* cx, JSObject* obj);
#endif

bool js_PluginFirebaseJS_Analytics_constructor(JSContext *cx, uint32_t argc, jsval *vp);
void js_PluginFirebaseJS_Analytics_finalize(JSContext *cx, JSObject *obj);
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setUserProperty(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setUserProperty(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_init(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setScreenName(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setScreenName(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_getVersion(JSContext *cx, uint32_t argc, jsval *vp);
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_getVersion(JSContext *cx, uint32_t argc, jsval *vp);
#endif
#endif

