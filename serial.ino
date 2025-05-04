

void setupSerial(int bauds) {
  Serial.begin(bauds);
  // wait for serial
  while (!Serial) {
    delay(10);
  }

  Serial.println("Serial initialized");
}

void println(String message) {
  println(message.c_str());
}

void println(const char *message) {
  Serial.println(message);
}

void println(const char *message, const long value) {
  Serial.print(message);
  Serial.print(":");
  Serial.println(value);
}

void println(const char *message, const char *value) {
  Serial.print(message);
  Serial.print(":");
  Serial.println(value);
}
