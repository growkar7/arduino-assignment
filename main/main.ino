const int LED_PIN = LED_BUILTIN;  // built-in LED, usually pin 13

void blink(int times, int delayMs) {
  for (int i = 0; i < times; i++) {
    digitalWrite(LED_PIN, HIGH);
    delay(delayMs);
    digitalWrite(LED_PIN, LOW);
    delay(delayMs);
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  blink(3, 500);  // test call, the menu will replace this later
  delay(2000);
}
