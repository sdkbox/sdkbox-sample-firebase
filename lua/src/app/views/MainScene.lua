
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
    sdkbox.firebase.Analytics:init()

    local item1 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Log Event", "sans", 28))
    item1:onClicked(function()
        local evt = {
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456',
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456',
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456',
            [sdkbox.firebase.Analytics.Param.kFIRParameterPrice] = '123.4'
            }
        sdkbox.firebase.Analytics:logEvent(sdkbox.firebase.Analytics.Event.kFIREventViewItem, evt)
        print("Log Event")
    end)

    local item2 = cc.MenuItemLabel:create(
        cc.Label:createWithSystemFont("Log Custom Event", "sans", 28))
    item2:onClicked(function()
        local evt = {
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemID] = 'id123456',
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemName] = 'name123456',
            [sdkbox.firebase.Analytics.Param.kFIRParameterItemCategory] = 'category123456',
            customKey = 'custom value'
            }
        sdkbox.firebase.Analytics:logEvent("customEvent", evt)
        print("Log Custom Event")
    end)

    local menu = cc.Menu:create(item1, item2)
    menu:alignItemsVerticallyWithPadding(24)
    self:addChild(menu)
end

return MainScene
