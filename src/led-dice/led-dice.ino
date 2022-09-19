#define led1 2    // LED1 is connected to pin 2
#define led2 3    // LED2 is connected to pin 3
#define led3 4    // LED3 is connected to pin 4
#define led3 4    // LED3 is connected to pin 4
#define led4 5    // LED4 is connected to pin 5
#define led5 6    // LED5 is connected to pin 6
#define led6 7    // LED6 is connected to pin 7

#define button 8  // Button is connected to pin 8

int ledPin[] = {led1, led2, led3, led4, led5, led6}; // Array of LED pins
int ledPinLength = sizeof(ledPin) / sizeof(ledPin[0]); // Length of the array

int buttonState = 0; // Variable to store the button state

void setup() {
   // Start serial port at 9600 bps.
   Serial.begin(9600);

   // Set all LED pins to output.
   for (int i = 0; i < ledPinLength; i++) {
      pinMode(ledPin[i], OUTPUT);
   }

   // Set button pin to input.
   pinMode(button, INPUT);
}

/**
  * Return an integer between 1 and 6.
  * You know just like a dice.
  */
int rollDice() {
   return 1 + random() % 6;
}

/**
  * Basic animation to show the dice is rolling.
  * It powers all LEDs on one by one.
  * Then it powers all LEDs off one by one.
  */
void rollDiceAnimation() {
   for (int i = 0; i < ledPinLength; i++) {
      digitalWrite(ledPin[i], HIGH);
      delay(100);
   }

   for (int i = 0; i < ledPinLength; i++) {
      digitalWrite(ledPin[i], LOW);
      delay(100);
   }
}

/**
  * Turn on the LED for the given dice number (1-6).
  * @param dice: the number genereated by `rollDice()`.
  */
void powerLEDs(int dice) {
   for (int i = 0; i < dice; i++) {
      digitalWrite(ledPin[i], HIGH);
      delay(100);
   }
}

/**
  * Turn off all LEDs.
  */
void powerLEDsOff() {
   for (int i = 0; i < ledPinLength; i++) {
      digitalWrite(ledPin[i], LOW);
   }
}

void loop() {
   // Read the button state.
   buttonState = digitalRead(button);

   // If the button is pressed, roll the dice.
   if (buttonState == HIGH) {
      powerLEDsOff();
      rollDiceAnimation();
      int dice = rollDice();
      powerLEDs(dice);
   }
}

