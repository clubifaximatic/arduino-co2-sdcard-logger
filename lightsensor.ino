
int lightPin;

void setupLightSensor(int pin) {
  println("Initializing LightSensor...");
  
  lightPin = pin;
  pinMode(lightPin, INPUT);

  println("LightSensor initialized");
}

int lightRead() {
  return analogRead(lightPin);
}