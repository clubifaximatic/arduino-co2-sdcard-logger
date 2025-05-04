
#include <SD.h>

File logFile;

void setupSDCard(int ssPin) {
  println("Initializing SD card...");

  // ss pin is Output
  ssPin = ssPin;
  pinMode(ssPin, OUTPUT);
  
  // see if the card is present and can be initialized:
  if (!SD.begin(ssPin)) {
    error("SD card failed, or not present");
    return;
  }

  println("SD card initialized");
}

bool sdOpen(const char *fileName) {
  if (logFile) {
    return true;
  }

  logFile = SD.open(fileName, FILE_WRITE);

  return logFile;
}

bool sdWrite(const char *line) {
  if (!logFile) {
    return false;
  }

  logFile.write(line, sizeof(line));
  logFile.write("\r\n", 2);
  logFile.flush();

  return true;
}

// bool createFile() {
//   if (fileCreated) {
//     Serial.println("ready");
//     return true;
//   }
//   // 12345678
//   // 250405HH

//   // create a new file
//   char filename[] = "LOGGE_00.CSV";
//   for (uint8_t i = 0; i < 100; i++) {
//     filename[6] = i/10 + '0';
//     filename[7] = i%10 + '0';
//     if (!SD.exists(filename)) {
//       // only open a new file if it doesn't exist
//       logfile = SD.open(filename, FILE_WRITE); 
//       break;  // leave the loop!
//     }
//   }
  
//   if(!logfile) {
//     error("couldnt create file");
//   }
  
//   Serial.print("Logging to: ");
//   Serial.println(filename);
//   fileCreated = true;
//   return true;
// }
