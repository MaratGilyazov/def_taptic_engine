#pragma once
#if defined(DM_PLATFORM_IOS)

enum ImpactStyle
{
    IMPACT_LIGHT,
    IMPACT_MEDIUM,
    IMPACT_HEAVY,

    //NOTIFICATION_SUCCESS,
    //NOTIFICATION_WARNING,
    //NOTIFICATION_ERROR,
};

extern bool TapticEngine_IsSupported();
extern void TapticEngine_Impact(ImpactStyle style);

#endif