/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/admin/Desktop/Remys_Labs/Lab15/src/Lab15.ino"
#include <oled-wing-adafruit.h>

void setup();
void loop();
void resetDisplay();
#line 3 "/Users/admin/Desktop/Remys_Labs/Lab15/src/Lab15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;

void setup()
{
  display.setup();
  pinMode(D5, INPUT);
  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();
  resetDisplay();
  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    display.print("Watchdog Reset");
  }
  else
  {
    display.print("Normal Reset");
  }
  display.display();
}

void loop()
{
  display.loop();
  if (digitalRead(D5))
  {
    Watchdog.refresh();
  }
}

void resetDisplay()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}