
local MainScene = class("MainScene", cc.load("mvc").ViewBase)

function MainScene:onCreate()
    print("Sample Startup")

    local label = cc.Label:createWithSystemFont("QUIT", "sans", 32)
    local quit = cc.MenuItemLabel:create(label)
    quit:onClicked(function()
        os.exit(0)
    end)
    local size = label:getContentSize()
    local menu = cc.Menu:create(quit)
    menu:setPosition(display.right - size.width / 2 - 16, display.bottom + size.height / 2 + 16)
    self:addChild(menu)

    self:setupTestMenu()
end

function MainScene:setupTestMenu()
    -- sdkbox.PluginFirebase:init()

    -- base setting


    local item1 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Load Interstitial (ad2)", "sans", 28))
    item1:onClicked(function()
        print("Load Interstitial (ad2)")
    end)

    local item2 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Show Interstitial (ad2)", "sans", 28))
    item2:onClicked(function()
        print("Show Interstitial (ad2)")
    end)

    local menu = cc.Menu:create(item1, item2)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
