local AMAX: boolean = true
local BMAX: boolean = false

local CCMAX: string = {}
local ZMAX
local TMAX
local EMAX
ZMAX = print
TMAX = warn
EMAX = error

CCMAX.D = (function(...) return(...) end)
local D = {}
D[1] = "EVIL"
D[2] = "BloxFruit_Beta.luau"
D[3] = "BladeBall_Beta.luau"

return {
  AMAX,
  BMAX,
  ZMAX,
  TMAX,
  EMAX,
  CCMAX,
}
