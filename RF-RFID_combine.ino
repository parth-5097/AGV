#include "SPI.h"
#include "MFRC522.h"
#include <VirtualWire.h>

#define SS_PIN 10
#define RST_PIN 9
//#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522 :: MIFARE_Key key;

void setup () {
  Serial.begin(9600);
  Serial.println("Listening");
  vw_setup(2000);
  vw_set_rx_pin(3);
  vw_rx_start();

  SPI.begin();

}

void loop () {
  byte message[VW_MAX_MESSAGE_LEN];
  byte messageLength = VW_MAX_MESSAGE_LEN;
  if (vw_get_message(message, &messageLength))
  {
    for (int i = 0; i < messageLength; i++)
    {
      Serial.write(message[i]);
    }
    Serial.println();


    /*while (true) {
       if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
         continue ;

       // Serial.print (F ("PICC type:"));
       MFRC522 :: PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
       // Serial.println (rfid.PICC_GetTypeName (piccType));

       // Check is the PICC of Classic MIFARE type
       if (piccType != MFRC522 :: PICC_TYPE_MIFARE_MINI &&
           piccType != MFRC522 :: PICC_TYPE_MIFARE_1K &&
           piccType != MFRC522 :: PICC_TYPE_MIFARE_4K) {
         Serial.println(F("Your tag is not of type MIFARE Classic."));
         continue ;
       }

       String strID = "" ;
       for (byte i = 0; i < 4; i ++) {
         strID +=
           (rfid.uid.uidByte[i] < 0x10 ? "0" : "" ) +
           String (rfid.uid.uidByte[i], HEX) +
           (i != 3 ? ":" : "" );
       }
       strID.toUpperCase();

       // When this part is reached, the strID variable will store the UID of the tag.
       // Can be used at all, such as importing to IF for the tube
       // LED to be on or off.
       Serial.print("Tap card key : ");
       Serial.println(strID);

       rfid.PICC_HaltA();
       rfid.PCD_StopCrypto1();
      }*/

  }
}
