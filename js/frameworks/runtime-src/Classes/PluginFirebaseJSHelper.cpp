#include "PluginFirebaseJSHelper.h"
#include "PluginFirebase/PluginFirebase.h"
#include "SDKBoxJSHelper.h"


#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void firebase_set_constants(JSContext* cx, const JS::RootedObject& obj, const std::string& name, const std::map<std::string, std::string>& params)
#else
void firebase_set_constants(JSContext* cx, JSObject* obj, const std::string& name, const std::map<std::string, std::string>& params)
#endif
{
    jsval val = sdkbox::std_map_string_string_to_jsval(cx, params);

    JS::RootedValue rv(cx);
    rv = val;
#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
    JS_SetProperty(cx, obj, name.c_str(), rv);
#else
    JS_SetProperty(cx, obj, name.c_str(), rv.address());
#endif
}

#if defined(MOZJS_MAJOR_VERSION) and MOZJS_MAJOR_VERSION >= 26
void firebase_register_constants(JSContext* cx, const JS::RootedObject& obj)
#else
void firebase_register_constants(JSContext* cx, JSObject* obj)
#endif
{
    std::map<std::string, std::string> enums;
    enums.clear();
    enums.insert(std::make_pair("kFIREventAddPaymentInfo", "add_payment_info"));
    enums.insert(std::make_pair("kFIREventAddToCart", "add_to_cart"));
    enums.insert(std::make_pair("kFIREventAddToWishlist", "add_to_wishlist"));
    enums.insert(std::make_pair("kFIREventAppOpen", "app_open"));
    enums.insert(std::make_pair("kFIREventBeginCheckout", "begin_checkout"));
    enums.insert(std::make_pair("kFIREventEarnVirtualCurrency", "earn_virtual_currency"));
    enums.insert(std::make_pair("kFIREventEcommercePurchase", "ecommerce_purchase"));
    enums.insert(std::make_pair("kFIREventGenerateLead", "generate_lead"));
    enums.insert(std::make_pair("kFIREventJoinGroup", "join_group"));
    enums.insert(std::make_pair("kFIREventLevelUp", "level_up"));
    enums.insert(std::make_pair("kFIREventLogin", "login"));
    enums.insert(std::make_pair("kFIREventPostScore", "post_score"));
    enums.insert(std::make_pair("kFIREventPresentOffer", "present_offer"));
    enums.insert(std::make_pair("kFIREventPurchaseRefund", "purchase_refund"));
    enums.insert(std::make_pair("kFIREventSearch", "search"));
    enums.insert(std::make_pair("kFIREventSelectContent", "select_content"));
    enums.insert(std::make_pair("kFIREventShare", "share"));
    enums.insert(std::make_pair("kFIREventSignUp", "sign_up"));
    enums.insert(std::make_pair("kFIREventSpendVirtualCurrency", "spend_virtual_currency"));
    enums.insert(std::make_pair("kFIREventTutorialBegin", "tutorial_begin"));
    enums.insert(std::make_pair("kFIREventTutorialComplete", "tutorial_complete"));
    enums.insert(std::make_pair("kFIREventUnlockAchievement", "unlock_achievement"));
    enums.insert(std::make_pair("kFIREventViewItem", "view_item"));
    enums.insert(std::make_pair("kFIREventViewItemList", "view_item_list"));
    enums.insert(std::make_pair("kFIREventViewSearchResults", "view_search_results"));
    firebase_set_constants(cx, obj, "Event", enums);

    enums.clear();
    enums.insert(std::make_pair("kFIRParameterAchievementID", "achievement_id"));
    enums.insert(std::make_pair("kFIRParameterCharacter", "character"));
    enums.insert(std::make_pair("kFIRParameterContentType", "content_type"));
    enums.insert(std::make_pair("kFIRParameterCoupon", "coupon"));
    enums.insert(std::make_pair("kFIRParameterCurrency", "currency"));
    enums.insert(std::make_pair("kFIRParameterDestination", "destination"));
    enums.insert(std::make_pair("kFIRParameterEndDate", "end_date"));
    enums.insert(std::make_pair("kFIRParameterFlightNumber", "flight_number"));
    enums.insert(std::make_pair("kFIRParameterGroupID", "group_id"));
    enums.insert(std::make_pair("kFIRParameterItemCategory", "item_category"));
    enums.insert(std::make_pair("kFIRParameterItemID", "item_id"));
    enums.insert(std::make_pair("kFIRParameterItemLocationID", "item_location_id"));
    enums.insert(std::make_pair("kFIRParameterItemName", "item_name"));
    enums.insert(std::make_pair("kFIRParameterLevel", "level"));
    enums.insert(std::make_pair("kFIRParameterLocation", "location"));
    enums.insert(std::make_pair("kFIRParameterNumberOfNights", "number_of_nights"));
    enums.insert(std::make_pair("kFIRParameterNumberOfPassengers", "number_of_passengers"));
    enums.insert(std::make_pair("kFIRParameterNumberOfRooms", "number_of_rooms"));
    enums.insert(std::make_pair("kFIRParameterOrigin", "origin"));
    enums.insert(std::make_pair("kFIRParameterPrice", "price"));
    enums.insert(std::make_pair("kFIRParameterQuantity", "quantity"));
    enums.insert(std::make_pair("kFIRParameterScore", "score"));
    enums.insert(std::make_pair("kFIRParameterSearchTerm", "search_term"));
    enums.insert(std::make_pair("kFIRParameterShipping", "shipping"));
    enums.insert(std::make_pair("kFIRParameterSignUpMethod", "sign_up_method"));
    enums.insert(std::make_pair("kFIRParameterStartDate", "start_date"));
    enums.insert(std::make_pair("kFIRParameterTax", "tax"));
    enums.insert(std::make_pair("kFIRParameterTransactionID", "transaction_id"));
    enums.insert(std::make_pair("kFIRParameterTravelClass", "travel_class"));
    enums.insert(std::make_pair("kFIRParameterValue", "value"));
    enums.insert(std::make_pair("kFIRParameterVirtualCurrencyName", "virtual_currency_name"));
    firebase_set_constants(cx, obj, "Param", enums);
}

#if defined(MOZJS_MAJOR_VERSION)
#if MOZJS_MAJOR_VERSION >= 33
void register_all_PluginFirebaseJS_helper(JSContext* cx, JS::HandleObject global) {
    JS::RootedValue firVal(cx);
    JS::RootedObject firObj(cx);
    JS_GetProperty(cx, global, "sdkboxfirebase", &firVal);
    if (JSVAL_VOID != firVal) {
        JS::RootedObject sbObj(cx);
        sdkbox::getJsObjOrCreat(cx, global, "sdkbox", &sbObj);
        JS_SET_PROPERTY(cx, sbObj, "firebase", firVal);
        JS_DeleteProperty(cx, global, "sdkboxfirebase");
        JS_ValueToObject(cx, firVal, &firObj);
    } else {
        sdkbox::getJsObjOrCreat(cx, global, "sdkbox.firebase", &firObj);
    }

    JS::RootedObject anaObj(cx);
    sdkbox::getJsObjOrCreat(cx, firObj, "Analytics", &anaObj);

    firebase_register_constants(cx, anaObj);
}
#else
void register_all_PluginFirebaseJS_helper(JSContext* cx, JSObject* global) {
    JSObject* firObj;
    JS_GetProperty(cx, global, "sdkboxfirebase", &firObj);
    if (JSVAL_VOID != firObj) {
        JSObject* sbObj;
        sdkbox::getJsObjOrCreat(cx, global, "sdkbox", &sbObj);
        JS_SET_PROPERTY(cx, sbObj, "firebase", firVal);
        JS_DeleteProperty(cx, global, "sdkboxfirebase");
    } else {
        sdkbox::getJsObjOrCreat(cx, global, "sdkbox.firebase", &firObj);
    }

    JSObject* anaObj;
    sdkbox::getJsObjOrCreat(cx, firObj, "Analytics", &anaObj);
    firebase_register_constants(cx, firObj);
}
#endif
#elif defined(JS_VERSION)
void register_all_PluginFirebaseJS_helper(JSContext* cx, JSObject* global) {
    jsval pluginVal;
    JSObject* pluginObj;
    pluginVal = sdkbox::getJsObjOrCreat(cx, global, "sdkbox.firebase", &pluginObj);

    firebase_register_constants(cx, pluginObj);
}
#endif
