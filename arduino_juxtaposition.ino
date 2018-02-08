#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("What does an Diego do? A compuer thing? ");
}

void loop() {
lcd.scrollDisplayLeft();
    // wait a bit:
    delay(369);
}
