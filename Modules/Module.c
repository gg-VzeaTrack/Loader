local Module = {}

local replicated = game:GetService('ReplicatedStorage')
local Cached = { Bring = {} }
local _ENV = (getgenv or getrenv or getfenv)()
local BRING_TAG: string = _ENV._Bring_Tag or `b{math.random(80, 2e4)}t`
_ENV._Bring_Tag = BRING_TAG
local Settings = { BringDistance = 285 }

local hookmetamethod = hookmetamethod or (function(...) return ... end)
local hookfunction = hookfunction or (function(...) return ... end)
local sethiddenproperty = sethiddenproperty or (function(...) return ... end)

function Module.IsAlive(model)
  local hum = model:FindFirstChildOfClass("Humanoid")
  return hum and hum.Health > 0
end
Module.BringEnemy = function(Target)
    if not (_B and Target and Target.Parent) then return end
    local hum = Target:FindFirstChild("Humanoid")
    local pp = Target.PrimaryPart
    if not (hum and pp and hum.Health > 0) then return end
    pcall(sethiddenproperty, plr, "SimulationRadius", math.huge)
    local name = Target.Name
    local basePos = PosMon
    local maxDist = 285
    local pulled = 0
    local limit = maxPull or 3
    local enemies = workspace.Enemies:GetChildren()
    for i = 1, #enemies do
        if pulled >= limit then break end
        local v = enemies[i]
        if v.Name ~= name or v.Name == "Blank Buddy" then continue end
        local vh = v:FindFirstChild("Humanoid")
        local vpp = v.PrimaryPart
        if not (vh and vpp and vh.Health > 0) then continue end
        if (vpp.Position - basePos).Magnitude <= maxDist then
            pulled += 1
            vpp.CFrame = CFrame.new(basePos)
            vpp.AssemblyLinearVelocity = Vector3.zero
            vpp.AssemblyAngularVelocity = Vector3.zero
            vh.WalkSpeed = 0
            vh.JumpPower = 0
        end
    end
end
local block = Instance.new("Part", workspace) block.Size = Vector3.new(1, 1, 1) block.Name = "Rip_Indra" block.Anchored = true block.CanCollide = false block.CanTouch = false block.Transparency = 1
local blockfind = workspace:FindFirstChild(block.Name) if blockfind and blockfind ~= block then blockfind:Destroy() end
task.spawn(function()while task.wait()do if block and block.Parent==workspace then if shouldTween then getgenv().OnFarm=true else getgenv().OnFarm=false end else getgenv().OnFarm=false end end end)
task.spawn(function()local a=game.Players.LocalPlayer;repeat task.wait()until a.Character and a.Character.PrimaryPart;block.CFrame=a.Character.PrimaryPart.CFrame;while task.wait()do pcall(function()if getgenv().OnFarm then if block and block.Parent==workspace then local b=a.Character and a.Character.PrimaryPart;if b and(b.Position-block.Position).Magnitude<=200 then b.CFrame=block.CFrame else block.CFrame=b.CFrame end end;local c=a.Character;if c then for d,e in pairs(c:GetChildren())do if e:IsA("BasePart")then e.CanCollide=false end end end else local c=a.Character;if c then for d,e in pairs(c:GetChildren())do if e:IsA("BasePart")then e.CanCollide=true end end end end end)end end)
Nearest = function(a)local b=a.Position;local c=math.huge;local d=math.huge;local e={}if World3 then e={["Mansion"]=Vector3.new(-12471,374,-7551),["Hydra"]=Vector3.new(5659,1013,-341),["Caslte On The Sea"]=Vector3.new(-5092,315,-3130),["Floating Turtle"]=Vector3.new(-12001,332,-8861),["Temple Of Time"]=Vector3.new(28286,14897,103)}elseif World2 then e={["Flamingo Mansion"]=Vector3.new(-317,331,597),["Flamingo Room"]=Vector3.new(2283,15,867),["Cursed Ship"]=Vector3.new(923,125,32853),["Zombie Island"]=Vector3.new(-6509,83,-133)}elseif World1 then e={["Sky Island 1"]=Vector3.new(-4652,873,-1754),["Sky Island 2"]=Vector3.new(-7895,5547,-380),["Under Water Island"]=Vector3.new(61164,5,1820),["Under Water Island Entrace"]=Vector3.new(3865,5,-1926)}end;local f={}for g,h in pairs(e)do f[g]=(h-b).Magnitude end;for g,h in pairs(f)do if h<c then c=h;d=h end end;local i;for g,h in pairs(f)do if h<=c then i=e[g]end end;local j=(b-Root.Position).Magnitude;if d<=j then return i end end
Module.T = function(target)
  local character = plr.Character
  if not character or not character:FindFirstChild("HumanoidRootPart") then return end
  local rootPart = character.HumanoidRootPart
  local distance = (target.Position - rootPart.Position).Magnitude
  if distance <= 300 then Root.CFrame = target end
  local tweenInfo = TweenInfo.new(distance / TwSpeed, Enum.EasingStyle.Linear)
  local tween = game:GetService("TweenService"):Create(block, tweenInfo, {CFrame = target})
  if Nearest(target) then pcall(function() tween:Cancel() end) _R("requestEntrance",Nearest(target)) block.CFrame = Root.CFrame end
  if not Root:FindFirstChild("BodyClip") then local Noclip = Instance.new("BodyVelocity") Noclip.Name = "BodyClip" Noclip.Parent = Root Noclip.MaxForce = Vector3.new(100000,100000,100000) Noclip.Velocity = Vector3.new(0,0,0) end        
  if not plr.Character:FindFirstChild('highlight') then local Test = Instance.new('Highlight') Test.Name = "highlight" Test.Enabled = true Test.FillColor = Color3.fromRGB(0,204,255) Test.OutlineColor = Color3.fromRGB(255,255,255) Test.FillTransparency = 0.5 Test.OutlineTransparency = 0.2 Test.Parent = plr.Character end
  for _,v in pairs(plr.Character:GetDescendants()) do if v:IsA("BasePart") then v.CanCollide = false end end
  if _G.Y_Position then Root.CFrame = CFrame.new(Root.CFrame.X, target.Y, Root.CFrame.Z) end
  if plr.Character.Humanoid.Sit == true then block.CFrame = CFrame.new(block.Position.X, target.Y, block.Position.Z) end  
  tween:Play()
  task.spawn(function() while tween.PlaybackState == Enum.PlaybackState.Playing do if not shouldTween then tween:Cancel() break end task.wait() end end)
end
function Module.GetNearest()
    local plr = game.Players.LocalPlayer
    local char = plr.Character
    local hrp = char and char:FindFirstChild("HumanoidRootPart")
    if not hrp then return nil end
    local nearest, dist = nil, math.huge
    for _, v in ipairs(workspace.Enemies:GetChildren()) do
        local ehrp = v:FindFirstChild("HumanoidRootPart")
        if ehrp and Module.IsAlive(v) then
            local d = (ehrp.Position - hrp.Position).Magnitude
            if d <= 5000 and d < dist then
                dist = d
                nearest = v
            end
        end
    end
    return nearest
end
function Module.Hop()
    local PlaceID = game.PlaceId
	local AllIDs = {}
	local foundAnything = ""
	local actualHour = os.date("!*t").hour
	local Deleted = false
	function TPReturner()
		local Site;
		if foundAnything == "" then
			Site = game.HttpService:JSONDecode(game:HttpGet('https://games.roblox.com/v1/games/' .. PlaceID .. '/servers/Public?sortOrder=Asc&limit=100'))
		else
			Site = game.HttpService:JSONDecode(game:HttpGet('https://games.roblox.com/v1/games/' .. PlaceID .. '/servers/Public?sortOrder=Asc&limit=100&cursor=' .. foundAnything))
		end
		local ID = ""
		if Site.nextPageCursor and Site.nextPageCursor ~= "null" and Site.nextPageCursor ~= nil then
			foundAnything = Site.nextPageCursor
		end
		local num = 0;
		for i,v in pairs(Site.data) do
			local Possible = true
			ID = tostring(v.id)
			if tonumber(v.maxPlayers) > tonumber(v.playing) then
				for _,Existing in pairs(AllIDs) do
					if num ~= 0 then
						if ID == tostring(Existing) then
							Possible = false
						end
					else
						if tonumber(actualHour) ~= tonumber(Existing) then
							local delFile = pcall(function()
								AllIDs = {}
								table.insert(AllIDs, actualHour)
							end)
						end
					end
					num = num + 1
				end
				if Possible == true then
					table.insert(AllIDs, ID)
					wait()
					pcall(function()
						wait()
						game:GetService("TeleportService"):TeleportToPlaceInstance(PlaceID, ID, game.Players.LocalPlayer)
					end)
					wait(4)
				end
			end
		end
	end
	function Teleport() 
		while true do task.wait()
			pcall(function()
				TPReturner()
				if foundAnything ~= "" then
					TPReturner()
				end
			end)
		end
	end
	Teleport()
end
function Module.Rejoin()
    local ts = game:GetService("TeleportService")
    local p = game:GetService("Players").LocalPlayer
	ts:Teleport(game.PlaceId, p)
end
function Module.HopLowestPlayer()
    local TeleportService = game:GetService("TeleportService")
    local HttpService = game:GetService("HttpService")
    local Servers = "https://games.roblox.com/v1/games/" .. game.PlaceId .. "/servers/Public?sortOrder=Asc&limit=100"
    local Server, Next = nil, nil
    local function ListServers(cursor)
    local Raw = game:HttpGet(Servers .. ((cursor and "&cursor=" .. cursor) or ""))
    return HttpService:JSONDecode(Raw)
    end
    repeat
        local Servers = ListServers(Next)
        Server = Servers.data[math.random(1, (#Servers.data / 3))]
        Next = Servers.nextPageCursor
    until Server
    if Server.playing < Server.maxPlayers and Server.id ~= game.JobId then
        TeleportService:TeleportToPlaceInstance(game.PlaceId, Server.id, game.Players.LocalPlayer)
    end
end
function Module.TeleportNewDungeon()
    local TeleportService = game:GetService("TeleportService")
    local HttpService = game:GetService("HttpService")
    local placeId = 73902483975735
    local ServersURL = "https://games.roblox.com/v1/games/" .. placeId .. "/servers/Public?sortOrder=Asc&limit=100"
    local function ListServers(cursor)
        local url = ServersURL
        if cursor then url = url .. "&cursor=" .. cursor end
        local raw = game:HttpGet(url)
        return HttpService:JSONDecode(raw)
    end
    local serversData = ListServers(nil)
    if #serversData.data > 0 then
        local server = serversData.data[math.random(1, #serversData.data)]
        TeleportService:TeleportToPlaceInstance(placeId, server.id, game.Players.LocalPlayer)
    else
        warn("No servers!")
    end
end
function Module.GetNextDoor()
    if game.PlaceId ~= 73902483975735 then return end
    local latest = nil
    for i = 1, 15 do
        if workspace.Map.Dungeon:FindFirstChild(tostring(i)) then
            latest = i
        end
    end
    if latest and latest > 1 then
        local prev = workspace.Map.Dungeon[tostring(latest - 1)]
        local exit = prev and prev:FindFirstChild("ExitTeleporter")
        if exit and exit:FindFirstChild("Root") then
            game.Players.LocalPlayer.Character.HumanoidRootPart.CFrame = exit.Root.CFrame
        end
    end
end
function Module.GetBones()
    if workspace.Enemies:FindFirstChild("Reborn Skeleton") or workspace.Enemies:FindFirstChild("Living Zombie") or workspace.Enemies:FindFirstChild("Demonic Soul") or workspace.Enemies:FindFirstChild("Posessed Mummy") then
        return true
    end
    return false
end
function Module.Process(Value)
    if Value == 'EliteHunter' then
        local cache = nil
        if not cache then cache = replicated.Remotes.CommF_:InvokeServer("EliteHunter","Progress")end
        local value = string.match(cache, "%d+")
        return value
    end
    if Value == 'SpyChecker' then
        local cache = nil
        if not cache then cache = replicated.Remotes.CommF_:InvokeServer("InfoLeviathan","1")end
        local value = string.match(cache, "%d+")
        return value
    end
    if Value == 'Katakuri' then
        local cache = nil
        if not cache then cache = replicated.Remotes.CommF_:InvokeServer("CakePrinceSpawner")end
        local value = string.match(cache, "%d+")
        return value
    end
    if Value == 'Bones' then
        local InventoryCache = nil
        local LastUpdate = 0
        local function UpdateInventory()
            if tick() - LastUpdate > 3 then
                InventoryCache = replicated.Remotes.CommF_:InvokeServer("getInventory")
                LastUpdate = tick()
            end
        end
        local function GetM(Name)
            UpdateInventory()
            for _, tab in pairs(InventoryCache or {}) do
                if type(tab) == "table" and tab.Type == "Material" and tab.Name == Name then
                    return tab.Count
                end
            end
            return 0
        end
        return GetM('Bones')    
    end        
    return false
end
function Module.LowCPU()
  local decalsyeeted = true
  local g = game
  local w = g.Workspace
  local l = g.Lighting
  local t = w.Terrain
  t.WaterWaveSize = 0
  t.WaterWaveSpeed = 0
  t.WaterReflectance = 0
  t.WaterTransparency = 0
  l.GlobalShadows = false
  l.FogEnd = 9e9
  l.Brightness = 0
  settings().Rendering.QualityLevel = "Level01"
  for i, v in pairs(g:GetDescendants()) do
    if v:IsA("Part") or v:IsA("Union") or v:IsA("CornerWedgePart") or v:IsA("TrussPart") then
      v.Material = "Plastic"
      v.Reflectance = 0
    elseif v:IsA("Decal") or v:IsA("Texture") and decalsyeeted then
      v.Transparency = 1
    elseif v:IsA("ParticleEmitter") or v:IsA("Trail") then
      v.Lifetime = NumberRange.new(0)
    elseif v:IsA("Explosion") then
      v.BlastPressure = 1
      v.BlastRadius = 1
    elseif v:IsA("Fire") or v:IsA("SpotLight") or v:IsA("Smoke") or v:IsA("Sparkles") then
      v.Enabled = false
    elseif v:IsA("MeshPart") then
      v.Material = "Plastic"
      v.Reflectance = 0
      v.TextureID = 10385902758728957
    end
  end
  for i, e in pairs(l:GetChildren()) do
    if e:IsA("BlurEffect") or e:IsA("SunRaysEffect") or e:IsA("ColorCorrectionEffect") or e:IsA("BloomEffect") or e:IsA("DepthOfFieldEffect") then
      e.Enabled = false
    end
  end
end

return Module
