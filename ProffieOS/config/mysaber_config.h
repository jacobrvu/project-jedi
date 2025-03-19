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
// config.h for ProffieOS
// Make sure this is included in your ProffieOS installation

// Define blade configurations for ProffieOS
BladeConfig blades[] = {
  // LED1 strip as first blade - simple on/off (no PWM)
  { bladePin, CONFIGARRAY(simple_blade) },
  
  // LED2 strip as second blade - simple on/off (no PWM)
  { blade2Pin, CONFIGARRAY(simple_blade) },
  
  // LED3-5 for motors (using PWM capability of blade pins)
  { blade3Pin, CONFIGARRAY(simple_pwm_blade) },
  { blade4Pin, CONFIGARRAY(simple_pwm_blade) },
  { blade5Pin, CONFIGARRAY(simple_pwm_blade) },
  
  // LED6 for servo
  { blade6Pin, CONFIGARRAY(simple_pwm_blade) },
};

// Define preset configurations
Preset presets[] = {
  // Use our custom SpinningLightsaberProp for all presets
  { "SpinActivated", "tracks/track1.wav", &style_charging, "Spinning Activation Mode"},
};

// Use our custom prop
#define PROP_CLASS SpinningLightsaberProp
#define PROP_TYPE ProffieOSPropHandle<PROP_CLASS>

#define MOTION_TIMEOUT 60 * 15 * 1000  // 15 minutes before motion timeout
#define IDLE_OFF_TIME 60 * 10 * 1000   // 10 minutes idle before powering down

#endif // CONFIG_H

#ifdef CONFIG_PRESETS
Preset presets[] = {
  {"Skywalker", "tracks/venus.wav", 
  StyleNormalPtr<CYAN, WHITE, 300, 800>(), "Ignition" }
};


// BladeConfig blades[] = {
//  { 0, WS281XBladePtr<144, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(), CONFIGARRAY(presets) },
// };
// #endif

// #ifdef CONFIG_BUTTONS
// Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
// // Button AuxButton(BUTTON_AUX, auxPin, "aux");
// #endif

// #ifdef CONFIG_TOP
// #include "proffieboard_v3_config.h"
// #define NUM_BLADES 1
// #define NUM_BUTTONS 1
// #define VOLUME 1000
// const unsigned int maxLedsPerStrip = 144;
// #define CLASH_THRESHOLD_G 1.0
// #define ENABLE_AUDIO
// #define ENABLE_MOTION
// #define ENABLE_WS2811
// #define ENABLE_SD
// #endif



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

BladeConfig blades[] = {
 { 0, SimpleBladePtr<myLED, NoLED, NoLED, NoLED, bladePowerPin1, bladePowerPin2, bladePowerPin3, bladePowerPin4>(), 
 CONFIGARRAY(presets)}
//  {255, SimpleBladePtr<CreeXPE2WhiteTemplate<0>, NoLED, NoLED, NoLED, bladePowerPin5, -1, -1, -1>()}
};
#endif
// CONFIGARRAY(presets) 
// SimpleBladePtr<LED1, LED2, LED3, LED4, pin1, pin2, pin3, pin4>

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
#endif
