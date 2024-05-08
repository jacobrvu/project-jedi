// MOTOR CODE WITH DEBOUNCING
#define MOTOR_IN1 D9
#define MOTOR_IN2 D10
#define FORWARD_SWITCH D2
#define BACKWARD_SWITCH D3

int lastForwardState = HIGH;      // Last state of the forward switch
int lastBackwardState = HIGH;     // Last state of the backward switch
unsigned long lastDebounceTime = 0;  // Last time the output pin was toggled
unsigned long debounceDelay = 50;    // Debounce time in milliseconds

void setup() {
  Serial.begin(9600);
  pinMode(MOTOR_IN1, OUTPUT);
  pinMode(MOTOR_IN2, OUTPUT);
  pinMode(FORWARD_SWITCH, INPUT_PULLUP);
  pinMode(BACKWARD_SWITCH, INPUT_PULLUP);
}

void loop() {
  int readingForward = digitalRead(FORWARD_SWITCH);
  int readingBackward = digitalRead(BACKWARD_SWITCH);

  if (readingForward != lastForwardState) {
    lastDebounceTime = millis();  // Reset the debouncing timer
  }

  if (readingBackward != lastBackwardState) {
    lastDebounceTime = millis();  // Reset the debouncing timer
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state.

    // Only act if the state has changed:
    if (readingForward == LOW) {
      digitalWrite(MOTOR_IN1, LOW);
      digitalWrite(MOTOR_IN2, HIGH);
      Serial.print("fow");
    } else if (readingBackward == LOW) {
      digitalWrite(MOTOR_IN1, HIGH);
      digitalWrite(MOTOR_IN2, LOW);
      Serial.print("back");
    } else {
      digitalWrite(MOTOR_IN1, LOW);
      digitalWrite(MOTOR_IN2, LOW);
      Serial.print("nothing");
    }
  }

  lastForwardState = readingForward;
  lastBackwardState = readingBackward;
}
