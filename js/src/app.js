var HelloWorldLayer = cc.Layer.extend({
    sprite: null,
    ctor: function() {
        //////////////////////////////
        // 1. super init first
        this._super();

        cc.log("Sample Startup")

        this.createTestMenu();

        var winsize = cc.winSize;

        var logo = new cc.Sprite("res/Logo.png");
        var logoSize = logo.getContentSize();
        logo.x = logoSize.width / 2;
        logo.y = winsize.height - logoSize.height / 2;
        this.addChild(logo);

        var quit = new cc.MenuItemLabel(new cc.LabelTTF("QUIT", "sans", 32), function() {
            cc.log("QUIT");
        });
        var menu = new cc.Menu(quit);
        var size = quit.getContentSize();
        menu.x = winsize.width - size.width / 2 - 16;
        menu.y = size.height / 2 + 16;
        this.addChild(menu);

        return true;
    },

    createTestMenu: function() {
        sdkbox.firebase.Analytics.init();

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("Log Event", "sans", 28), function() {
            const evt = {}
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456';
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456';
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456';
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterPrice] = '123.4';
            sdkbox.firebase.Analytics.logEvent(sdkbox.firebase.Analytics.Event.kFIREventViewItem, evt);
            cc.log("Log Custom Event");
        });

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("Log Custom Event", "sans", 28), function() {
            const evt = {}
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456';
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456';
            evt[sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456';
            evt['customKey'] = 'custom value';
            sdkbox.firebase.Analytics.logEvent("customEvent", evt);
            cc.log("log custom event");
        });

        var winsize = cc.winSize;
        var menu = new cc.Menu(item1, item2);
        menu.x = winsize.width / 2;
        menu.y = winsize.height / 2;
        menu.alignItemsVerticallyWithPadding(20);
        this.addChild(menu);
    }
});

var HelloWorldScene = cc.Scene.extend({
    onEnter: function() {
        this._super();
        var layer = new HelloWorldLayer();
        this.addChild(layer);
    }
});
