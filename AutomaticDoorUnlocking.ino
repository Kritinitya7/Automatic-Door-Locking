#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 10
#define RST_PIN 3

MFRC522 rfid(SS_PIN, RST_PIN);
Servo doorServo;

const int buzzerPin = 7;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  doorServo.attach(9);     // Servo signal pin
  doorServo.write(0);      // Door locked

  pinMode(buzzerPin, OUTPUT);

  Serial.println("RFID Door Lock System Ready");
}

void loop() {

  // Wait for RFID card
  if (!rfid.PICC_IsNewCardPresent())
    return;

  if (!rfid.PICC_ReadCardSerial())
    return;

  Serial.print("Card UID: ");

  for (byte i = 0; i < rfid.uid.size; i++) {
    Serial.print(rfid.uid.uidByte[i], HEX);
    Serial.print(" ");
  }

  Serial.println();

  bool authorized = false;

  // Authorized Card 1 : 03 58 AB A4
  if (rfid.uid.uidByte[0] == 0x03 &&
      rfid.uid.uidByte[1] == 0x58 &&
      rfid.uid.uidByte[2] == 0xAB &&
      rfid.uid.uidByte[3] == 0xA4) {
    authorized = true;
  }

  // Authorized Card 2 : C1 BD 6A 05
  if (rfid.uid.uidByte[0] == 0xC1 &&
      rfid.uid.uidByte[1] == 0xBD &&
      rfid.uid.uidByte[2] == 0x6A &&
      rfid.uid.uidByte[3] == 0x05) {
    authorized = true;
  }

  if (authorized) {

    Serial.println("Access Granted");
    Serial.println("Door Opening");

    tone(buzzerPin, 1000, 300);
    delay(500);

    doorServo.write(90);   // Unlock
    delay(5000);

    Serial.println("Door Closing");

    doorServo.write(0);    // Lock
    delay(1000);

  } else {

    Serial.println("Access Denied");

    for (int i = 0; i < 3; i++) {
      tone(buzzerPin, 1000, 200);
      delay(300);
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}