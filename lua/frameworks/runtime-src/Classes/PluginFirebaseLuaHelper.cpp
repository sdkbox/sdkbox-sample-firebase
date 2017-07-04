
#include "PluginFirebaseLuaHelper.h"
#include "PluginFirebase/PluginFirebase.h"
#include "SDKBoxLuaHelper.h"


static int lua_createTable(lua_State* L, const std::map<std::string, int>& map) {
    lua_newtable(L);

    std::map<std::string, int>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushinteger(L, it->second);
        lua_settable(L, -3);
        it++;
    }

    return 1;
}

static int lua_createTable(lua_State* L, const std::map<std::string, std::string>& map) {
    lua_newtable(L);

    std::map<std::string, std::string>::const_iterator it = map.begin();
    while (it != map.end()) {
        lua_pushstring(L, it->first.c_str());
        lua_pushstring(L, it->second.c_str());
        lua_settable(L, -3);
        it++;
    }

    return 1;
}


static int lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, int>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

static int lua_setTable(lua_State* L, int table, const std::string& name, const std::map<std::string, std::string>& map) {
    if (table < 0) {
        table = lua_gettop(L) + table + 1;
    }
    lua_pushstring(L, name.c_str());
    lua_createTable(L, map);
    lua_rawset(L, table);

    return 0;
}

int lua_PluginFirebaseLua_constants(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    if (lua_istable(L,-1)) {
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
        lua_setTable(L, -1, "Event", enums);

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
        lua_setTable(L, -1, "Param", enums);

    }
    lua_pop(L, 1);

    return 1;
}

int extern_PluginFirebase(lua_State* L) {
    if (NULL == L) {
        return 0;
    }

    lua_PluginFirebaseLua_constants(L);

    return 1;
}

int getOrCreateTabel(lua_State *L, const char* name) {
    lua_pushstring(L, name);                    // m name
    lua_rawget(L, -2);                          // m m[name]
    if (!lua_istable(L, -1)) {
        //create new sdkbox.name
        lua_pop(L, 1);                          // m
        lua_newtable(L);                        // m t
        lua_pushstring(L, name);                // m t name
        lua_pushvalue(L, -2);                   // m t name t
        lua_rawset(L, -4);                      // m t  (now t is m[name])
    }

    return 1;
}

TOLUA_API int register_all_PluginFirebaseLua_helper(lua_State* L) {
    tolua_module(L,"sdkbox",0);
    tolua_beginmodule(L,"sdkbox");              // m
    getOrCreateTabel(L, "firebase");
    getOrCreateTabel(L, "Analytics");

    extern_PluginFirebase(L);

    lua_pop(L, 2); //pop firebase Analytics
    tolua_endmodule(L);

    return 1;
}


