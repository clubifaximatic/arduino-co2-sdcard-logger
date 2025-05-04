

void error(String str) {
  error(str.c_str());
}

void error(char *str)
{
  Serial.print("ERROR: ");
  Serial.println(str);
  
  // red LED indicates error
  digitalWrite(PIN_ERROR, HIGH);
  
  // infinite loop
  while(true) {
    delay(10);
  }
}

void flashProgress(bool ok) {
  digitalWrite(PIN_PROGRESS, HIGH);

  if (ok) {
    delay(250);
  } else {
    delay(100);
    digitalWrite(PIN_PROGRESS, LOW);
    delay(100);
    digitalWrite(PIN_PROGRESS, HIGH);
    delay(100);
  }

  digitalWrite(PIN_PROGRESS, LOW);
}
