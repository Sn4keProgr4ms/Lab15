#include <oled-wing-adafruit.h>

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