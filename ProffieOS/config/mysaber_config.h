#ifdef CONFIG_TOP
#include "proffieboard_v3_config.h"
#define NUM_BLADES 6
#define NUM_BUTTONS 1
#define VOLUME 2300
const unsigned int maxLedsPerStrip = 144;
#define CLASH_THRESHOLD_G 8.0
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#endif

#ifdef CONFIG_PROPS
#include "../props/saber.h"
#include "../props/saber_fett263_buttons.h"
#include "../props/spinning_lightsaber.h"  // Include our custom prop
#endif

#ifdef CONFIG_PRESETS
Preset presets[] = {
  {"Skywalker", "tracks/venus.wav", 
  StyleNormalPtr<CYAN, WHITE, 300, 800>(), "Ignition" }
};

// Use our custom prop
#define PROP_CLASS SpinningLightsaberProp
#define PROP_TYPE ProffieOSPropHandle<PROP_CLASS>

#define MOTION_TIMEOUT 60 * 15 * 1000  // 15 minutes before motion timeout
#define IDLE_OFF_TIME 60 * 10 * 1000   // 10 minutes idle before powering down

struct myLED {
    static constexpr float MaxAmps = 1;
    static constexpr float MaxVolts = 15; 
    static constexpr float P2Amps= 0.5;
    static constexpr float P2Volts = 7.5;
    static constexpr float R = 0;
    static const int Red = 0;
    static const int Green = 0;
    static const int Blue = 255;
};

struct myMotor {
    static constexpr float MaxAmps = 1;
    static constexpr float MaxVolts = 15; 
    static constexpr float P2Amps= 0.5;
    static constexpr float P2Volts = 7.5;
    static constexpr float R = 0;
    static const int Red = 0;
    static const int Green = 0;
    static const int Blue = 0;
};

BladeConfig blades[] = {
 { 0, SimpleBladePtr<myLED, NoLED, NoLED, NoLED, bladePowerPin1, -1, -1, -1>(), 
SimpleBladePtr<myLED, NoLED, NoLED, NoLED, bladePowerPin2, -1, -1, -1>(),
SimpleBladePtr<myMotor, NoLED, NoLED, NoLED, bladePowerPin3, -1, -1, -1>(),
SimpleBladePtr<myMotor, NoLED, NoLED, NoLED, bladePowerPin4, -1, -1, -1>(),
SimpleBladePtr<myMotor, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>(),
ServoBladePtr<bladePowerPin6>(),
 CONFIGARRAY(presets)}
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif
