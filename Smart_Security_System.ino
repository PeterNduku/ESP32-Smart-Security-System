#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

// ===============================
// PINS
// ===============================
const int LDR_PIN = 13;
const int IR_PIN = 12;
const int RED_LED = 25;
const int GREEN_LED = 26;

// ===============================
// STATE
// ===============================
bool previousIntrusion = false;

void setup() {

  Serial.begin(115200);

  pinMode(LDR_PIN, INPUT);
  pinMode(IR_PIN, INPUT);

  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);

  // Start in secure state
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);

  // Bluetooth
  SerialBT.begin("SMART_SECURITY");

  Serial.println("SMART SECURITY SYSTEM");
  Serial.println("Monitoring continuously...");

  SerialBT.println("================================");
  SerialBT.println("       SMART SECURITY");
  SerialBT.println("================================");
  SerialBT.println("SYSTEM SECURE");
  SerialBT.println("Monitoring active...");
}

// ===============================
// MAIN LOOP
// ===============================
void loop() {

  // Read sensors continuously
  int ldrValue = digitalRead(LDR_PIN);
  int irValue = digitalRead(IR_PIN);

  // Your confirmed sensor logic
  bool dark = (ldrValue == HIGH);
  bool movement = (irValue == LOW);

  // Intrusion condition
  bool intrusion = dark && movement;

  // ===============================
  // PHYSICAL LEDs
  // ===============================

  if (intrusion) {

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);

  } 
  else {

    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  // ===============================
  // ONLY SEND BLUETOOTH WHEN STATE CHANGES
  // ===============================

  // Intruder just detected
  if (intrusion && !previousIntrusion) {

    Serial.println("INTRUSION DETECTED!");

    SerialBT.println();
    SerialBT.println("################################");
    SerialBT.println("      !!! INTRUSION !!!");
    SerialBT.println("################################");
    SerialBT.println("ALARM: ACTIVE");
    SerialBT.println("ROOM: DARK");
    SerialBT.println("MOVEMENT: DETECTED");
    SerialBT.println("################################");
  }

  // Intruder has left
  if (!intrusion && previousIntrusion) {

    Serial.println("INTRUSION CLEARED");

    SerialBT.println();
    SerialBT.println("================================");
    SerialBT.println("       INTRUSION CLEARED");
    SerialBT.println("================================");
    SerialBT.println("SYSTEM SECURE");
    SerialBT.println("ALARM: OFF");
    SerialBT.println("================================");
  }

  // Remember current state
  previousIntrusion = intrusion;

  // Keep monitoring very frequently
  delay(50);
}
