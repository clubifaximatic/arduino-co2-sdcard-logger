#include <Adafruit_SCD30.h>

/**
Pinout
/--------\
|        |- VIN
|        |- GND
|        |- SCL / TX
|        |- SDA / RX
|        |- (RDY)
|        |- (PWM)
|        |- (SEL)
|        |
|        |
|        |
\--------/
**/


Adafruit_SCD30  scd30;

long temperature;
long humidity;
long co2;

void setupCO2() {
  println("Initializing CO2 sensor...");

  if (!scd30.begin()) {
    error("CO2 sensor failed");
    return;
  }
  println("CO2 sensor initialized");
  println("Measurement_Interval_(s)", scd30.getMeasurementInterval()); 
}

bool co2Read() {
  if (!scd30.dataReady()){
    return false;
  }

  if (!scd30.read()) { 
    Serial.println("Error reading sensor data"); 
    return false; 
  }

  temperature = scd30.temperature;
  humidity = scd30.relative_humidity;
  co2 = scd30.CO2;

  return true;
}

long co2Value() {
  return co2;
}

long co2Temperature() {
  return temperature;
}

long co2Humidity() {
  return humidity;
}
