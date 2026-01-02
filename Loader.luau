for _,u in ipairs({
 "https://raw.githubusercontent.com/gg-VzeaTrack/Loader/main/Modules/FastAttack.c",
 "https://raw.githubusercontent.com/gg-VzeaTrack/Loader/main/Modules/GameData.c",
 "https://raw.githubusercontent.com/gg-VzeaTrack/Loader/main/Modules/Module.c",
 "https://raw.githubusercontent.com/gg-VzeaTrack/Loader/main/Modules/QuestData.c"
}) do
 pcall(function() loadstring(game:HttpGet(u))() end)
end
