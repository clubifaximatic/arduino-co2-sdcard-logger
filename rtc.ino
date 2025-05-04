
#include "RTClib.h"

#define ENABLE_RTC false;

// define the Real Time Clock object
RTC_DS1307 rtc; 

void setupRTC() {
  println("Initializing RTC...");

  Wire.begin();
  if (!rtc.begin()) {
    error("RTC failed");
    return;
  }

  Serial.println("RTC initialized");
}

long rtcUnixtime() {
  DateTime now = rtc.now();

  Serial.print(now.hour());
  Serial.print(":");
  Serial.println(now.minute());
  Serial.print(".");
  Serial.println(now.second());

  return now.unixtime();
}

/*
 * use "yyMMddHH"
 */
char *rtcUniqueFileName() {
  char fileName[13];

  DateTime now = rtc.now();
  sprintf (fileName, "%2d%2d%2d%2d.csv", "%s \0", now.year() - 2000, 
                                                  now.month(),
                                                  now.day(),
                                                  now.hour());

  return fileName;
}

void time() {
  DateTime now;

  // delay for the amount of time we want between readings
  delay(1000);
  
  // From Arduino
  uint32_t m = millis();
  Serial.print(m);         // milliseconds since start
  Serial.print(", ");  

  // From RTC
  now = rtc.now();
  Serial.print(now.unixtime()); // seconds since 2000
  Serial.print(", ");
  Serial.print(now.year(), DEC);
  Serial.print("/");
  Serial.print(now.month(), DEC);
  Serial.print("/");
  Serial.print(now.day(), DEC);
  Serial.print(" ");
  Serial.print(now.hour(), DEC);
  Serial.print(":");
  Serial.print(now.minute(), DEC);
  Serial.print(":");
  Serial.print(now.second(), DEC);

  Serial.println();
}
