#include "HelloWorldScene.h"

USING_NS_CC;

#include <vector>
#include <string>

#include "PluginFirebase/PluginFirebase.h"

using namespace std;

/******************
 * Show logs
 ******************/
std::vector<std::string> msgbuf;
static void showMsg(const std::string& msg) {
    Label *label = dynamic_cast<Label*>(Director::getInstance()->getNotificationNode());
    if (label == nullptr) {
        auto size = Director::getInstance()->getWinSize();
        label = Label::createWithSystemFont("test", "arial", 16);
        label->setAnchorPoint(Vec2(0,0));
        label->setTextColor(Color4B(0, 255, 0, 255));
        label->setPosition(10, size.height*0.1);
        Director::getInstance()->setNotificationNode(label);
    }

    msgbuf.push_back(msg);
    if (msgbuf.size() > 10) {
        msgbuf.erase(msgbuf.cbegin());
    }

    std::string text = "";
    for (int i = 0; i < msgbuf.size(); i++) {
        stringstream buf;
        buf << i << " " << msgbuf[i] << "\n";
        text = text + buf.str();
    }

    label->setString(text);
}

/******************
 * Firebase sample
 ******************/
Scene* HelloWorld::createScene() {
    // 'scene' is an autorelease object
    auto scene = Scene::create();

    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init() {
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() ) {
        return false;
    }

    showMsg("Sample Startup");

    // add logo
    auto winsize = Director::getInstance()->getWinSize();
    auto logo = Sprite::create("Logo.png");
    auto logoSize = logo->getContentSize();
    logo->setPosition(Vec2(logoSize.width / 2,
                           winsize.height - logoSize.height / 2));
    addChild(logo);

    // add quit button
    auto label = Label::createWithSystemFont("QUIT", "sans", 32);
    auto quit = MenuItemLabel::create(label, [](Ref*){
        exit(0);
    });
    auto labelSize = label->getContentSize();
    quit->setPosition(Vec2(winsize.width / 2 - labelSize.width / 2 - 16,
                           -winsize.height / 2 + labelSize.height / 2 + 16));
    addChild(Menu::create(quit, NULL));

    // add test menu
    createTestMenu();

    return true;
}

void HelloWorld::createTestMenu() {
    // sdkbox::PluginFirebase::init();

    testDemograpicFunctions();

    auto menu = Menu::create();

    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Log Event", "arial", 24), [](Ref*){
        showMsg("Log Event");
        std::map<std::string, std::string> params;
        params[sdkbox::Firebase::Analytics::kFIRParameterItemID] = "id123456";
        params[sdkbox::Firebase::Analytics::kFIRParameterItemName] = "name123456";
        params[sdkbox::Firebase::Analytics::kFIRParameterItemCategory] = "category123456";
        params[sdkbox::Firebase::Analytics::kFIRParameterPrice] = "123.4";
        
        sdkbox::Firebase::Analytics::logEvent(sdkbox::Firebase::Analytics::kFIREventViewItem, params);
    }));
    
    menu->addChild(MenuItemLabel::create(Label::createWithSystemFont("Log Custom Event", "arial", 24), [](Ref*){
        showMsg("Log Custom Event");
        std::map<std::string, std::string> params;
        params[sdkbox::Firebase::Analytics::kFIRParameterItemID] = "id654321";
        params[sdkbox::Firebase::Analytics::kFIRParameterPrice] = "99.0";
        params["custom_key"] = "custom_value";
        
        sdkbox::Firebase::Analytics::logEvent("custom_event", params);
    }));

    menu->alignItemsVerticallyWithPadding(10);
    addChild(menu);
}

void HelloWorld::testDemograpicFunctions() {
//    sdkbox::Firebase::Analytics::init();
    sdkbox::Firebase::Analytics::setUserID("sdkbox_inter_test");
    sdkbox::Firebase::Analytics::setUserProperty("favorite_food", "hot pot");
    sdkbox::Firebase::Analytics::setScreenName("login", "");
}

