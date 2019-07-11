#include <dmsdk/sdk.h>

#if defined(DM_PLATFORM_IOS)
#include "tapticengine.h"
#include "UIKit/UIKit.h"

@interface TapticEnginePlugin : NSObject{
}
+ (TapticEnginePlugin*) shared;
- (void) impact:(UIImpactFeedbackStyle) strength;
+ (BOOL) isSupport;
@end

@interface TapticEnginePlugin ()
@property (nonatomic, strong) NSArray<UIImpactFeedbackGenerator*>* impactGenerators;
@end

@implementation TapticEnginePlugin

static TapticEnginePlugin * _shared;

+ (TapticEnginePlugin*) shared {
    @synchronized(self) {
        if(_shared == nil) {
            _shared = [[self alloc] init];
        }
    }
    return _shared;
}

- (id) init {
    if (self = [super init])
    {        
        self.impactGenerators = @[
             [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleLight],
             [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleMedium],
             [[UIImpactFeedbackGenerator alloc] initWithStyle:UIImpactFeedbackStyleHeavy],
        ];
        for(UIImpactFeedbackGenerator* impact in self.impactGenerators) {
            [impact prepare];
        }
    }
    return self;
}

- (void) dealloc {
    self.impactGenerators = NULL;
}

- (void) impact:(UIImpactFeedbackStyle)style {
    [self.impactGenerators[(int) style] impactOccurred];
}

+ (BOOL) isSupport {
    if ([UINotificationFeedbackGenerator class]) {
        return YES;
    }
    return NO;
}

@end

bool TapticEngine_IsSupported() {
    return [TapticEnginePlugin isSupport];
}

void TapticEngine_Impact(int strength) {
	if (strength < 0) {
		strength = 0;
	}
	if (strength > 2) {
		strength = 2;
	}
    [[TapticEnginePlugin shared] impact:(UIImpactFeedbackStyle) strength];
}

#endif
