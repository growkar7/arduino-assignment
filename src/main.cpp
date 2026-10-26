#include <Arduino.h>

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


void calculateSum() {
  Serial.println("[Sum not implemented yet - member 3]");
}

void calculateMultiplication() {
  Serial.println("[Multiplication not implemented yet - member 4]");
}
