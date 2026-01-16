local Fluent = loadstring(game:HttpGet("https://raw.githubusercontent.com/Overgustx2/Modules/refs/heads/main/V2.lua"))()
local SaveManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/dawid-scripts/Fluent/master/Addons/SaveManager.lua"))()
local InterfaceManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/dawid-scripts/Fluent/master/Addons/InterfaceManager.lua"))()
--local Window = Fluent:CreateWindow({Title = "Astral Hub [ Free Access ]",SubTitle = "Blox Fruit",TabWidth = 155,Size = UDim2.fromOffset(485, 370),Acrylic = false,Theme = "Dark",MinimizeKey = Enum.KeyCode.End})
local Tabs = {}
--[[Tabs.Main = Window:AddTab({Title = "Tab Generals", Icon = ""})
Tabs.Settings = Window:AddTab({Title = "Tab Settings", Icon = ""})
Tabs.Melee = Window:AddTab({Title = "Tab Fighting Style", Icon = ""})
Tabs.Quests = Window:AddTab({Title = "Tab Items Quest", Icon = ""})
if World3 then
  Tabs.SeaEvent = Window:AddTab({Title = "Tab Sea Event", Icon = ""})
  Tabs.Mirage = Window:AddTab({Title = "Tab Mirage + Trials V4", Icon = ""})
  Tabs.Drago = Window:AddTab({Title = "Tab Drago Dojo", Icon = ""})
  Tabs.Prehistoric = Window:AddTab({Title = "Tab Volcano Event", Icon = ""})
end
Tabs.Raids = Window:AddTab({Title = "Tab Dungeon", Icon = ""})
Tabs.Combat = Window:AddTab({Title = "Tab PVP + Visuals", Icon = ""})
Tabs.Travel = Window:AddTab({Title = "Tab Travelling", Icon = ""})
Tabs.Fruit = Window:AddTab({Title = "Tab Fruits", Icon = ""})
Tabs.Shop = Window:AddTab({Title = "Tab Shop", Icon = ""})
Tabs.Misc = Window:AddTab({Title = "Tab Miscellanea", Icon = ""})
]]

local Funcs = {}

LabelC = function(Section, Text)
  return Section:AddSection(Text)
end

ToggleC = function(Section, MainTitle, Title, Description, Default)
    local runningTask
    _G[MainTitle] = Default or false

    Section:AddToggle(MainTitle, {
        Title = Title or "nil toggle",
        Description = Description or "nil description",
        Default = Default or false,
        Callback = function(Value)
            _G[MainTitle] = Value

            if runningTask then
                task.cancel(runningTask)
                runningTask = nil
            end

            if Value and Funcs[MainTitle] then
                runningTask = task.spawn(function()
                    while _G[MainTitle] do
                        pcall(Funcs[MainTitle])
                        task.wait(0.15)
                    end
                end)
            end
        end
    })
end

--[[
LabelC(Tabs.Main, 'Generals')
ToggleC(Tabs.Main, 'TEST', 'Auto Farm', '', false, _G.TEST)

Funcs['TEST'] = function()
    print("Auto Farm Tick")
end
]]