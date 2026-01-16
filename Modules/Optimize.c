local Fluent = loadstring(game:HttpGet("https://raw.githubusercontent.com/Overgustx2/Modules/refs/heads/main/V2.lua"))()
local SaveManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/dawid-scripts/Fluent/master/Addons/SaveManager.lua"))()
local InterfaceManager = loadstring(game:HttpGet("https://raw.githubusercontent.com/dawid-scripts/Fluent/master/Addons/InterfaceManager.lua"))()

local OTM = {};
local Funcs = {};

OTM.ToggleC = function(Section, MainTitle, Title, Description, Default)
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

return OTM