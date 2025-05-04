
int microPin;

void setupMicrophone(int pin) {
  println("Initializing Microphone...");
  
  microPin = pin;
  pinMode(microPin, INPUT);

  println("Microphone initialized");
}

int microRead() {
  return analogRead(microPin);
}