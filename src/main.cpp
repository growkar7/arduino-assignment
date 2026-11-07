#include <Arduino.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

void calculateSum();
void calculateMultiplication();


void showMenu() {
  Serial.println();
  Serial.println("===== MENU =====");
  Serial.println("1 = Calculate Sum");
  Serial.println("2 = Multiplication");
  Serial.print("Choose an option: ");
}


char readChoice() {
  while (true) {
    while (Serial.available() == 0) {
      // wait for input
    }
    char c = Serial.read();
    if (c != '\n' && c != '\r' && c != ' ') {
      return c;
    }
  }
}


void handleChoice(char choice) {
  Serial.println(choice);

  switch (choice) {
    case '1':
      calculateSum();
      break;
    case '2':
      calculateMultiplication();
      break;
    default:
      Serial.println("Invalid choice, please type 1 or 2.");
      break;
  }
}

void setup() {
  Serial.begin(9600);
  while (!Serial) {
   
  }
}

void loop() {
  showMenu();
  char choice = readChoice();
  handleChoice(choice);
}


static long readSumNumber(const char *prompt) {
  Serial.println(prompt);

  String input;
  while (true) {
    const int character = Serial.read();
    if (character < 0) {
      delay(10);
      continue;
    }

    if (character != '\r' && character != '\n') {
      input += static_cast<char>(character);
      continue;
    }

    input.trim();
    if (input.length() == 0) {
      // Ignore blank lines, including the Enter left by readChoice().
      continue;
    }

    const char *start = input.c_str();
    char *end = nullptr;
    errno = 0;
    const long number = strtol(start, &end, 10);
    if (end != start && *end == '\0' && errno != ERANGE) {
      return number;
    }

    Serial.println("Invalid input. Enter a whole number:");
    input = "";
  }
}

void calculateSum() {
  const long first = readSumNumber("Enter the first number:");
  const long second = readSumNumber("Enter the second number:");

  if ((second > 0 && first > LONG_MAX - second) ||
      (second < 0 && first < LONG_MIN - second)) {
    Serial.println("The sum is outside the supported range.");
    return;
  }

  Serial.print("Sum: ");
  Serial.println(first + second);
}

void calculateMultiplication() {
  Serial.println("[Multiplication not implemented yet - member 4]");
}
