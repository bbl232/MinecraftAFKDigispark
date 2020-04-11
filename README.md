# MinecraftAFKDigispark
A couple of simple arduino sketches for a digispark that can mine mob farms or auto fishers

There are two sketches here. One for a digispark with a momentary button added between pins 0 and 2 for mode switching and one that toggles modes between power cycles.

`MouseWithToggle.ino`
This sketch, when burned onto a digispark will alternate between power cycles between emulating a mouse left clicking every 1 second and a mouse holding the right click. This is useful for attackng mobs at a farm with left click or fishing at an auto fisher with right click.
When both the power and builtin leds are on, it is in right clicking mode. When only the power led is on, it is in left clicking mode.


`MouseWithButton.ino`
This sketch, when burned onto a digispark with a momentary switch between pins 0 and 2 will alternate with at button press between emulating a mouse left clicking every 1 second, a mouse holding right click button down, and an idle state. This is useful for attackng mobs at a farm with left click or fishing at an auto fisher with right click.
When the builtin led is pulsing in a sine wave, it is in idle mode. When the builtin LED is solid on it is in right clicking mode, and when it is flashing briefly it is in left clicking mode.
