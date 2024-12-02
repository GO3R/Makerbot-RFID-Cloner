

//These switches and buttons are connected with +5v to one leg (COM connection) 
//and the other leg is connected to GND with a 10kOhm resistor. 
//This leg is also connected to the respective pin

const int button1 = 2;          // "write "switch pin
const int button2 = 3;          // "read" switch pin
const int button3 = 4;          // "start" pushbutton pin
const int button4 = 5;          // "reset fill level" switch pin
//_____________________________________________________________________________

// DO NOT CHANGE
bool clearBlocks = false;       // The blocks are not set to 0 by default
bool lastClearBlocks = false;   // Saves the previous status
bool lastbuttonState1 = false;  // Saves the previous status
//_____________________________________________________________________________

//These LEDs are connected with the anode to the analog pins. 
//The cathode gets a 220 Ohm resistor, which is then connected to GND

const int ledStatus = A0;       // Status LED
const int ledRead = A1;         // Read LED
const int ledWrite = A2;        // Write LED
const int ledFill = A3;         // Fill spool LED
const int ledFail = A4;         // Something went wrong LED
//_____________________________________________________________________________

// variables will change automatically. DO NOT CHANGE
int buttonState1 = 0;           // Variable for reading the pushbutton status
int buttonState2 = 0;           // Variable for reading the pushbutton status
int buttonState3 = 0;           // Variable for reading the pushbutton status
//_____________________________________________________________________________

// RFID                     ___________________________________________________
#include <PN5180.h>
#include <PN5180ISO15693.h>
#define PN5180_NSS  10
#define PN5180_BUSY 9
#define PN5180_RST  7
PN5180ISO15693 nfc(PN5180_NSS, PN5180_BUSY, PN5180_RST);

uint8_t uid[8];                 // UID from RFID-Tags
uint8_t blockSize;              // Blocksize in Bytes
uint8_t numBlocks;              // Number of blocks from tag
uint8_t readBuffer[128];        // Storage for read data
bool dataRead = false;          // Flag whether data has been read
uint8_t newUid[8];              // UID from new RFID-Tag

// RFID                     ___________________________________________________

void setup() {
  Serial.begin(115200);

  pinMode(button1, INPUT);      // switch "WRITE"
  pinMode(button2, INPUT);      // switch "READ"
  pinMode(button3, INPUT);      // Taster "START"
  pinMode(button4, INPUT);      // switch for clearing block 18,19 and 20 (reset fill level of spool)

  pinMode(ledStatus, OUTPUT);   // Status LED
  pinMode(ledRead, OUTPUT);     // RFID tag reading
  pinMode(ledWrite, OUTPUT);    // RFID tag writing
  pinMode(ledFill, OUTPUT);     // reset fill level of spool (LED on = true)
  pinMode(ledFail, OUTPUT);     // Something went wrong

  nfc.begin();
  nfc.reset();
  nfc.setupRF();

  LEDBlink();                   // start animation
}

void loop() {
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  clearBlocks = digitalRead(button4) == HIGH;


// Fill spool button        ___________________________________________________
  if (clearBlocks != lastClearBlocks) {
    if (clearBlocks) {
      Serial.println("Fill Spool");
      digitalWrite(ledFill, HIGH);
    } else {
      Serial.println("don't change spool mass");
      digitalWrite(ledFill, LOW);
    }
    lastClearBlocks = clearBlocks;  // Update the saved status
  }
// Fill spool button        ___________________________________________________


// Select read or write     ___________________________________________________
  if (buttonState1 != lastbuttonState1) {
    if (buttonState1) {
      Serial.println("READ");
      digitalWrite(ledRead, HIGH);
      digitalWrite(ledWrite, LOW);
    } else {
      Serial.println("WRITE");
      digitalWrite(ledWrite, HIGH);
      digitalWrite(ledRead, LOW);
    }
    lastbuttonState1 = buttonState1;  // Update the saved status
  }
// Select read or write     ___________________________________________________


// Read RFID button         ___________________________________________________
  if (buttonState1 == HIGH && buttonState3 == HIGH) {
    digitalWrite(ledFail, LOW);
    digitalWrite(ledStatus, LOW);

    Serial.println("Reading in 2");
    LEDBlinkSequence(ledRead);
    Serial.println("Reading in 1");
    LEDBlinkSequence(ledRead);

    Serial.println("Reading...");
    digitalWrite(ledRead, HIGH);
    readRFID();
  }
// Read RFID button         ___________________________________________________


// Write RFID button        ___________________________________________________
  if (buttonState2 == HIGH && buttonState3 == HIGH) {
    if (!dataRead) {
      digitalWrite(ledFail, HIGH);
      Serial.println("No data read yet! Please read first.");
      return;
    }

    if (!detectNewTag()) {
      digitalWrite(ledFail, HIGH);
      Serial.println("No new RFID tag detected! Please try again.");
      return;
    }

    digitalWrite(ledFail, LOW);
    digitalWrite(ledStatus, LOW);

    Serial.println("Writing in 2");
    LEDBlinkSequence(ledWrite);
    Serial.println("Writing in 1");
    LEDBlinkSequence(ledWrite);

    Serial.print("Writing... Clear blocks: ");
    digitalWrite(ledWrite, HIGH);
    writeRFID(clearBlocks);  // Schreibe mit dem Zustand des Schalters
  }
}
// Write RFID button        ___________________________________________________


// LED blinking sequence    ___________________________________________________
void LEDBlinkSequence(int ledPin) {
  for (int i = 0; i < 2; i++) {
    digitalWrite(ledPin, HIGH);
    delay(250);
    digitalWrite(ledPin, LOW);
    delay(250);
  }
}
// LED blinking sequence    ___________________________________________________


// readRFID funtion         ___________________________________________________
void readRFID() {
  
  ISO15693ErrorCode rc = nfc.getInventory(uid);
  if (ISO15693_EC_OK != rc) {
    Serial.println(F("Error in getInventory."));
    digitalWrite(ledFail, HIGH);
    return;
  }

  Serial.print(F("Inventory successful, UID="));
  for (int i = 0; i < 8; i++) {
    Serial.print(uid[7 - i], HEX); // LSB is first
    if (i < 7) Serial.print(":");
    digitalWrite(ledStatus, HIGH);
  }
  Serial.println();

  rc = nfc.getSystemInfo(uid, &blockSize, &numBlocks);
  if (ISO15693_EC_OK != rc) {
    Serial.println(F("Error in getSystemInfo."));
    digitalWrite(ledFail, HIGH);
    return;
  }

  Serial.print(F("System Info: blockSize="));
  Serial.print(blockSize);
  Serial.print(F(", numBlocks="));
  Serial.println(numBlocks);

  // Read all blocks
  for (int block = 0; block < numBlocks; block++) {
    rc = nfc.readSingleBlock(uid, block, &readBuffer[block * blockSize], blockSize);
    if (ISO15693_EC_OK != rc) {
      Serial.print(F("Error reading block #"));
      Serial.println(block);
      digitalWrite(ledFail, HIGH);
      return;
    }

    Serial.print(F("Block #"));
    Serial.print(block);
    Serial.print(": ");

    // Output in Hex
    for (int i = 0; i < blockSize; i++) {
      if (readBuffer[block * blockSize + i] < 16) Serial.print("0");
      Serial.print(readBuffer[block * blockSize + i], HEX);
      Serial.print(" ");
    }

    // Output in ASCII
    Serial.print(" | ASCII: ");
    for (int i = 0; i < blockSize; i++) {
      char c = readBuffer[block * blockSize + i];
      if (isprint(c)) {
        Serial.print(c);
      } else {
        Serial.print('.');
      }
    }
    Serial.println();
  }

  dataRead = true; // Mark data as read
}
// readRFID funtion         ___________________________________________________


// detectNewTag             ___________________________________________________
bool detectNewTag() {
  // Carry out a new inventory 
  ISO15693ErrorCode rc = nfc.getInventory(newUid);
  if (ISO15693_EC_OK != rc) {
    return false; // No new tag recognized
  }

  // Check whether the new tag has a different UID
  for (int i = 0; i < 8; i++) {
    if (uid[i] != newUid[i]) {
      digitalWrite(ledStatus, HIGH);
      return true; // new tag recognized
    }
  }

  digitalWrite(ledFail, HIGH);
  return false; // Same tag as before
 
}
// detectNewTag             ___________________________________________________


// writeRFID funtion        ___________________________________________________
void writeRFID(bool clearBlocks) {
  for (int block = 0; block < numBlocks; block++) {
    uint8_t data[blockSize];

    // Copy data for the current block
    for (int i = 0; i < blockSize; i++) {
      if (clearBlocks && (block == 18 || block == 19 || block == 20)) {
        data[i] = 0; // Setze Blöcke 18, 19 und 20 auf 0
      } else {
        data[i] = readBuffer[block * blockSize + i];
      }
    }

    // write block
    ISO15693ErrorCode rc = nfc.writeSingleBlock(newUid, block, data, blockSize);
    if (ISO15693_EC_OK != rc) {
      Serial.print(F("Error writing block #"));
      Serial.println(block);
      digitalWrite(ledFail, HIGH);
      return;
    }

    Serial.print(F("Wrote block #"));
    Serial.print(block);
    Serial.print(": ");

    // Output in Hex
    for (int i = 0; i < blockSize; i++) {
      if (data[i] < 16) Serial.print("0");
      Serial.print(data[i], HEX);
      Serial.print(" ");
    }

    // Output in ASCII
    Serial.print(" | ASCII: ");
    for (int i = 0; i < blockSize; i++) {
      char c = data[i];
      if (isprint(c)) {
        Serial.print(c);
      } else {
        Serial.print('.');
      }
    }
    Serial.println();
  }

  Serial.println("Writing completed!");
  digitalWrite(ledStatus, HIGH);
}
// writeRFID funtion        ___________________________________________________


// LED start animation      ___________________________________________________
void LEDBlink() {
  digitalWrite(ledStatus, HIGH);
  delay(100);
  digitalWrite(ledRead, HIGH);
  delay(100);
  digitalWrite(ledWrite, HIGH);
  delay(100);
  digitalWrite(ledFill, HIGH);
  delay(100);
  digitalWrite(ledFail, HIGH);
  delay(100);
  digitalWrite(ledFail, LOW);
  delay(100);
  digitalWrite(ledFill, LOW);
  delay(100);
  digitalWrite(ledWrite, LOW);
  delay(100);
  digitalWrite(ledRead, LOW);
  delay(100);
  digitalWrite(ledStatus, LOW);
}
// LED start animation      ___________________________________________________
