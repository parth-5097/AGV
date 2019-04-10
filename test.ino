#include <RH_ASK.h>
//#include <SPI.h> // Not actualy used but needed to compile
String tags[]={"1","2"};

RH_ASK driver;


#include "SPI.h" 
#include "MFRC522.h"

#define SS_PIN 10 
#define RST_PIN 9 
//#define SP_PIN 8

MFRC522 rfid(SS_PIN, RST_PIN);

MFRC522 :: MIFARE_Key key;
void setup()
{
   SPI.begin();
  rfid.PCD_Init();
    Serial.begin(9600);  // Debugging only
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
     Serial.println("hh");
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      int l=strlen(buf);
     int p=0;
     String st="";
     for(p=0;p<l;p++){
     //Serial.println((char)buf[p]);
     st=st+(char)buf[p];
     }  
     Serial.println(st);  
//     while(tags[st.toInt()]!=st);
      while(true)
      {
        if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
          continue;

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
  for (byte i = 0; i <4; i ++) {
    strID +=
    (rfid.uid.uidByte[i] <0x10? "0" : "" ) +
    String (rfid.uid.uidByte[i], HEX) +
    (i != 3? ":" : "" );
  }
  strID.toUpperCase();

  // When this part is reached, the strID variable will store the UID of the tag. 
  // Can be used at all, such as importing to IF for the tube 
  // LED to be on or off. 
  Serial.print("Tap card key : ");
  Serial.println(strID);

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
  break;//send signal to stop motors
      }
          
    }
}
