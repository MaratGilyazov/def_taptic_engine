# TapticEngine

This is a small native extension for [Defold engine](http://www.defold.com) which allows to use [iOS Taptic Engine](https://developer.apple.com/documentation/uikit/uifeedbackgenerator).

## Installation

You can use the DefTapticEngine extension in your own project by adding this project as a [Defold library dependency](http://www.defold.com/manuals/libraries/).
Open your game.project file and in the dependencies field under project add:

>https://github.com/MaratGilyazov/def_taptic_engine/archive/master.zip
## Example
```lua
if (taptic_engine and taptic_engine.isSupported()) then
  
  taptic_engine.impact(taptic_engine.IMPACT_LIGHT)
  taptic_engine.impact(taptic_engine.IMPACT_MEDIUM)
  taptic_engine.impact(taptic_engine.IMPACT_HEAVY)
  
  taptic_engine.notification(taptic_engine.NOTIFICATION_SUCCESS)
  taptic_engine.notification(taptic_engine.NOTIFICATION_WARNING)
  taptic_engine.notification(taptic_engine.NOTIFICATION_ERROR)
  
  taptic_engine.selection()

else
  --do something else
end
```

## LUA Api
#### taptic_engine.isSupported()
Returns bool flag saying if taptic engine is supprorted
#### taptic_engine.impact(int style)
Call Taptic Engine Impact feedback with given style - one of 3 constants: taptic_engine.IMPACT_LIGHT, taptic_engine.IMPACT_MEDIUM, taptic_engine.IMPACT_HEAVY
#### taptic_engine.notification(int type)
Call Taptic Engine Notification feedback with given type - one of 3 constants: taptic_engine.NOTIFICATION_SUCCESS, taptic_engine.NOTIFICATION_WARNING, taptic_engine.NOTIFICATION_ERROR
#### taptic_engine.selection()
Call Taptic Engine Selection feedback

## Notes
#### taptic_engine.isSupported() 
Right now this does not seem working correctly and returns "true" even on iPhone5, but it's not breaking; there is no safe way to check if taptic is supported)
#### prepare() 
There is API to "prepare" taptic engine for further feedback calls, in actual implementation it's called once on first call to any of taptic_engine methods and there is no way to controll it manually

iOS part is based on [iOS TAPTIC Engine Bridge for Unity](https://github.com/asus4/unity-taptic-plugin) by Koki Ibukuro