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
        // sdkbox.PluginFirebase.init();

        var item1 = new cc.MenuItemLabel(new cc.LabelTTF("Load Interstitial (ad2)", "sans", 28), function() {
            cc.log("Load Interstitial (ad2)");
        });

        var item2 = new cc.MenuItemLabel(new cc.LabelTTF("Show Interstitial (ad2)", "sans", 28), function() {
            cc.log("Show Plugin Firebase interstitial (ad2)");
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
