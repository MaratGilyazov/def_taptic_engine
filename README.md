# DefTapticEngine

This is small native extension for [Defold engine](http://www.defold.com) which allows to use [iOS Taptic Engine](https://developer.apple.com/documentation/uikit/uifeedbackgenerator) (currently only [Impact](https://developer.apple.com/documentation/uikit/uiimpactfeedbackgenerator) feature implemented).

## Installation

You can use the DefTapticEngine extension in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/).
Open your game.project file and in the dependencies field under project add:

>https://github.com/MaratGilyazov/def_taptic_engine/archive/master.zip
## Example
```lua
if (taptic_engine and taptic_engine.isSupported()) then
  -- impact strength can be one of 3 values: 0 -> light, 1 -> medium, 2 -> heavy
  strength = 0 
  taptic_engine.impact(strength)
else
  --do something else
end
```

## LUA Api
#### taptic_engine.isSupported()
Is feature supprorted (actually, right now this does not seem working correctly and returns "true" even on iPhone5, but it's not breaking; there is no safe way to check if taptic is supported)
#### defreview.impact(int strength)
Call Taptic Engine impact with given strength (style): 0 -> light, 1 -> medium, 2 -> heavy