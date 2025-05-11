#include <ShiftRegister74HC595.h>

#include "definitions.h"

long nextTicTime = READ_PERiOD_MS;

void setup() {
  setupSerial(BAUDS);
  setupCO2();
  setupRTC();
  setupSDCard(PIN_SELECT_SDCARD);
  setupMicrophone(PIN_MICROPHONE);
  setupLightSensor(PIN_LIGHT_SENSOR);

  println("* Fetchng RTC time");
  char *fileName = rtcUniqueFileName();

  println("* Opening file", fileName);
  if (!sdOpen(fileName)) {
    error("SDCard error: failed open " + String(fileName));
    return;
  }
}

void loop() {
  long now = millis();

  if (nextTicTime < now) {
    return;
  }

  process();
  nextTicTime += READ_PERiOD_MS;
}

void process() {
  if (!co2Read()) {
    return;
  }

  String line = sampleData();
  writeLine(line);

  println(line);
}

String sampleData() {
  String line = String(rtcUnixtime()) + "," +
                String(co2Value()) + "," +
                String(co2Temperature()) + "," +
                String(co2Humidity()) + "," +
                String(microRead()) + "," +
                String(lightRead());

  return line;
}

void writeLine(String line) {
    bool ok = sdWrite(line.c_str());
    flashProgress(ok);

    println(line.c_str());
}
