#include "PluginFirebaseJS.hpp"
#include "PluginFirebase/PluginFirebase.h"
#include "SDKBoxJSHelper.h"
#include "sdkbox/Sdkbox.h"


#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
        JS::RootedObject proto(cx, typeClass->proto.ref());
        JS::RootedObject parent(cx, typeClass->parentProto.ref());
#else
        JS::RootedObject proto(cx, typeClass->proto.get());
        JS::RootedObject parent(cx, typeClass->parentProto.get());
#endif
        JS::RootedObject _tmp(cx, JS_NewObject(cx, typeClass->jsclass, proto, parent));

        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        AddObjectRoot(cx, &pp->obj);
        args.rval().set(OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    args.rval().setBoolean(true);
    return true;
}
#else
template<class T>
static bool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    JS::RootedValue initializing(cx);
    bool isNewValid = true;
    if (isNewValid)
    {
        TypeTest<T> t;
        js_type_class_t *typeClass = nullptr;
        std::string typeName = t.s_name();
        auto typeMapIter = _js_global_type_map.find(typeName);
        CCASSERT(typeMapIter != _js_global_type_map.end(), "Can't find the class type!");
        typeClass = typeMapIter->second;
        CCASSERT(typeClass, "The value is null.");

        JSObject *_tmp = JS_NewObject(cx, typeClass->jsclass, typeClass->proto, typeClass->parentProto);
        T* cobj = new T();
        js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
        JS_AddObjectRoot(cx, &pp->obj);
        JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));
        return true;
    }

    return false;
}

static bool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return false;
}

static bool js_is_native_obj(JSContext *cx, JS::HandleObject obj, JS::HandleId id, JS::MutableHandleValue vp)
{
    vp.set(BOOLEAN_TO_JSVAL(true));
    return true;
}
#endif
#elif defined(JS_VERSION)
template<class T>
static JSBool dummy_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    TypeTest<T> t;
    T* cobj = new T();
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    assert(p);
    JSObject *_tmp = JS_NewObject(cx, p->jsclass, p->proto, p->parentProto);
    js_proxy_t *pp = jsb_new_proxy(cobj, _tmp);
    JS_SET_RVAL(cx, vp, OBJECT_TO_JSVAL(_tmp));

    return JS_TRUE;
}

static JSBool empty_constructor(JSContext *cx, uint32_t argc, jsval *vp) {
    return JS_FALSE;
}
#endif
JSClass  *jsb_sdkbox_Firebase_Analytics_class;
JSObject *jsb_sdkbox_Firebase_Analytics_prototype;

#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setUserProperty(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFirebaseJS_Analytics_setUserProperty : Error processing arguments");
        sdkbox::Firebase::Analytics::setUserProperty(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_setUserProperty : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setUserProperty(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::Firebase::Analytics::setUserProperty(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFirebaseJS_Analytics_setUserID : Error processing arguments");
        sdkbox::Firebase::Analytics::setUserID(arg0);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_setUserID : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setUserID(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 1) {
        std::string arg0;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::Firebase::Analytics::setUserID(arg0);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::map<std::string, std::string> arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= sdkbox::jsval_to_std_map_string_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFirebaseJS_Analytics_logEvent : Error processing arguments");
        sdkbox::Firebase::Analytics::logEvent(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_logEvent : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_logEvent(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::map<std::string, std::string> arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= sdkbox::jsval_to_std_map_string_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::Firebase::Analytics::logEvent(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        bool ret = sdkbox::Firebase::Analytics::init();
        jsval jsret = JSVAL_NULL;
        jsret = BOOLEAN_TO_JSVAL(ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_init : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_init(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        bool ret = sdkbox::Firebase::Analytics::init();
        jsval jsret;
        jsret = BOOLEAN_TO_JSVAL(ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_setScreenName(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    bool ok = true;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, args.get(0), &arg0);
        ok &= jsval_to_std_string(cx, args.get(1), &arg1);
        JSB_PRECONDITION2(ok, cx, false, "js_PluginFirebaseJS_Analytics_setScreenName : Error processing arguments");
        sdkbox::Firebase::Analytics::setScreenName(arg0, arg1);
        args.rval().setUndefined();
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_setScreenName : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_setScreenName(JSContext *cx, uint32_t argc, jsval *vp)
{
    jsval *argv = JS_ARGV(cx, vp);
    JSBool ok = JS_TRUE;
    if (argc == 2) {
        std::string arg0;
        std::string arg1;
        ok &= jsval_to_std_string(cx, argv[0], &arg0);
        ok &= jsval_to_std_string(cx, argv[1], &arg1);
        JSB_PRECONDITION2(ok, cx, JS_FALSE, "Error processing arguments");
        sdkbox::Firebase::Analytics::setScreenName(arg0, arg1);
        JS_SET_RVAL(cx, vp, JSVAL_VOID);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
bool js_PluginFirebaseJS_Analytics_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    JS::CallArgs args = JS::CallArgsFromVp(argc, vp);
    if (argc == 0) {
        std::string ret = sdkbox::Firebase::Analytics::getVersion();
        jsval jsret = JSVAL_NULL;
        jsret = std_string_to_jsval(cx, ret);
        args.rval().set(jsret);
        return true;
    }
    JS_ReportError(cx, "js_PluginFirebaseJS_Analytics_getVersion : wrong number of arguments");
    return false;
}
#elif defined(JS_VERSION)
JSBool js_PluginFirebaseJS_Analytics_getVersion(JSContext *cx, uint32_t argc, jsval *vp)
{
    if (argc == 0) {
        std::string ret = sdkbox::Firebase::Analytics::getVersion();
        jsval jsret;
        jsret = std_string_to_jsval(cx, ret);
        JS_SET_RVAL(cx, vp, jsret);
        return JS_TRUE;
    }
    JS_ReportError(cx, "wrong number of arguments");
    return JS_FALSE;
}
#endif


void js_PluginFirebaseJS_Analytics_finalize(JSFreeOp *fop, JSObject *obj) {
    CCLOGINFO("jsbindings: finalizing JS object %p (Analytics)", obj);
    js_proxy_t* nproxy;
    js_proxy_t* jsproxy;

#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JSContext *cx = ScriptingCore::getInstance()->getGlobalContext();
    JS::RootedObject jsobj(cx, obj);
    jsproxy = jsb_get_js_proxy(jsobj);
#else
    jsproxy = jsb_get_js_proxy(obj);
#endif

    if (jsproxy) {
        nproxy = jsb_get_native_proxy(jsproxy->ptr);

        sdkbox::Firebase::Analytics *nobj = static_cast<sdkbox::Firebase::Analytics *>(nproxy->ptr);
        if (nobj)
            delete nobj;

        jsb_remove_proxy(nproxy, jsproxy);
    }
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JS::HandleObject global) {
    jsb_sdkbox_Firebase_Analytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_Firebase_Analytics_class->name = "Analytics";
    jsb_sdkbox_Firebase_Analytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_Firebase_Analytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_Firebase_Analytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_Firebase_Analytics_class->finalize = js_PluginFirebaseJS_Analytics_finalize;
    jsb_sdkbox_Firebase_Analytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        JS_PSG("__nativeObj", js_is_native_obj, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_PS_END
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserProperty", js_PluginFirebaseJS_Analytics_setUserProperty, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFirebaseJS_Analytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFirebaseJS_Analytics_logEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFirebaseJS_Analytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setScreenName", js_PluginFirebaseJS_Analytics_setScreenName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginFirebaseJS_Analytics_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_Firebase_Analytics_prototype = JS_InitClass(
        cx, global,
        JS::NullPtr(), // parent proto
        jsb_sdkbox_Firebase_Analytics_class,
        dummy_constructor<sdkbox::Firebase::Analytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "Analytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
#if (SDKBOX_COCOS_JSB_VERSION >= 2)
    JS::RootedObject proto(cx, jsb_sdkbox_Firebase_Analytics_prototype);
    jsb_register_class<sdkbox::Firebase::Analytics>(cx, jsb_sdkbox_Firebase_Analytics_class, proto, JS::NullPtr());
#else
    TypeTest<sdkbox::Firebase::Analytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_Firebase_Analytics_class;
        p->proto = jsb_sdkbox_Firebase_Analytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
#endif
}
#else
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_Firebase_Analytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_Firebase_Analytics_class->name = "Analytics";
    jsb_sdkbox_Firebase_Analytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->delProperty = JS_DeletePropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_Firebase_Analytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_Firebase_Analytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_Firebase_Analytics_class->finalize = js_PluginFirebaseJS_Analytics_finalize;
    jsb_sdkbox_Firebase_Analytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    static JSPropertySpec properties[] = {
        {"__nativeObj", 0, JSPROP_ENUMERATE | JSPROP_PERMANENT, JSOP_WRAPPER(js_is_native_obj), JSOP_NULLWRAPPER},
        {0, 0, 0, JSOP_NULLWRAPPER, JSOP_NULLWRAPPER}
    };

    static JSFunctionSpec funcs[] = {
        JS_FS_END
    };

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserProperty", js_PluginFirebaseJS_Analytics_setUserProperty, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFirebaseJS_Analytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFirebaseJS_Analytics_logEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFirebaseJS_Analytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setScreenName", js_PluginFirebaseJS_Analytics_setScreenName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginFirebaseJS_Analytics_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_Firebase_Analytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_Firebase_Analytics_class,
        dummy_constructor<sdkbox::Firebase::Analytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
//  bool found;
//FIXME: Removed in Firefox v27
//  JS_SetPropertyAttributes(cx, global, "Analytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::Firebase::Analytics> t;
    js_type_class_t *p;
    std::string typeName = t.s_name();
    if (_js_global_type_map.find(typeName) == _js_global_type_map.end())
    {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->jsclass = jsb_sdkbox_Firebase_Analytics_class;
        p->proto = jsb_sdkbox_Firebase_Analytics_prototype;
        p->parentProto = NULL;
        _js_global_type_map.insert(std::make_pair(typeName, p));
    }
}
#endif
#elif defined(JS_VERSION)
void js_register_PluginFirebaseJS_Analytics(JSContext *cx, JSObject *global) {
    jsb_sdkbox_Firebase_Analytics_class = (JSClass *)calloc(1, sizeof(JSClass));
    jsb_sdkbox_Firebase_Analytics_class->name = "Analytics";
    jsb_sdkbox_Firebase_Analytics_class->addProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->delProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->getProperty = JS_PropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->setProperty = JS_StrictPropertyStub;
    jsb_sdkbox_Firebase_Analytics_class->enumerate = JS_EnumerateStub;
    jsb_sdkbox_Firebase_Analytics_class->resolve = JS_ResolveStub;
    jsb_sdkbox_Firebase_Analytics_class->convert = JS_ConvertStub;
    jsb_sdkbox_Firebase_Analytics_class->finalize = js_PluginFirebaseJS_Analytics_finalize;
    jsb_sdkbox_Firebase_Analytics_class->flags = JSCLASS_HAS_RESERVED_SLOTS(2);

    JSPropertySpec *properties = NULL;

    JSFunctionSpec *funcs = NULL;

    static JSFunctionSpec st_funcs[] = {
        JS_FN("setUserProperty", js_PluginFirebaseJS_Analytics_setUserProperty, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setUserID", js_PluginFirebaseJS_Analytics_setUserID, 1, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("logEvent", js_PluginFirebaseJS_Analytics_logEvent, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("init", js_PluginFirebaseJS_Analytics_init, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("setScreenName", js_PluginFirebaseJS_Analytics_setScreenName, 2, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FN("getVersion", js_PluginFirebaseJS_Analytics_getVersion, 0, JSPROP_PERMANENT | JSPROP_ENUMERATE),
        JS_FS_END
    };

    jsb_sdkbox_Firebase_Analytics_prototype = JS_InitClass(
        cx, global,
        NULL, // parent proto
        jsb_sdkbox_Firebase_Analytics_class,
        dummy_constructor<sdkbox::Firebase::Analytics>, 0, // no constructor
        properties,
        funcs,
        NULL, // no static properties
        st_funcs);
    // make the class enumerable in the registered namespace
    JSBool found;
    JS_SetPropertyAttributes(cx, global, "Analytics", JSPROP_ENUMERATE | JSPROP_READONLY, &found);

    // add the proto and JSClass to the type->js info hash table
    TypeTest<sdkbox::Firebase::Analytics> t;
    js_type_class_t *p;
    uint32_t typeId = t.s_id();
    HASH_FIND_INT(_js_global_type_ht, &typeId, p);
    if (!p) {
        p = (js_type_class_t *)malloc(sizeof(js_type_class_t));
        p->type = typeId;
        p->jsclass = jsb_sdkbox_Firebase_Analytics_class;
        p->proto = jsb_sdkbox_Firebase_Analytics_prototype;
        p->parentProto = NULL;
        HASH_ADD_INT(_js_global_type_ht, type, p);
    }
}
#endif
#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginFirebaseJS(JSContext* cx, JS::HandleObject obj) {
    // Get the ns
    JS::RootedObject ns(cx);
    get_or_create_js_obj(cx, obj, "sdkboxfirebase", &ns);

    js_register_PluginFirebaseJS_Analytics(cx, ns);

    sdkbox::setProjectType("js");
}
#else
void register_all_PluginFirebaseJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    JS::RootedValue nsval(cx);
    JS::RootedObject ns(cx);
    JS_GetProperty(cx, obj, "sdkboxfirebase", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkboxfirebase", nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginFirebaseJS_Analytics(cx, obj);

    sdkbox::setProjectType("js");
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginFirebaseJS(JSContext* cx, JSObject* obj) {
    // first, try to get the ns
    jsval nsval;
    JSObject *ns;
    JS_GetProperty(cx, obj, "sdkboxfirebase", &nsval);
    if (nsval == JSVAL_VOID) {
        ns = JS_NewObject(cx, NULL, NULL, NULL);
        nsval = OBJECT_TO_JSVAL(ns);
        JS_SetProperty(cx, obj, "sdkboxfirebase", &nsval);
    } else {
        JS_ValueToObject(cx, nsval, &ns);
    }
    obj = ns;

    js_register_PluginFirebaseJS_Analytics(cx, obj);

    sdkbox::setProjectType("js");
}
#endif