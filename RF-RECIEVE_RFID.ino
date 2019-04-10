#include <RH_ASK.h>
#include <SPI.h> // Not actualy used but needed to compile
#include "MFRC522.h"

#define SS_PIN 10 
#define RST_PIN 9 
//#define SP_PIN 8

String tags[]={":3A:DE:1F","04:2A:85:0A","F2:E0:DF:5D","C6:FE:2F:1A","52:2A:F8:99"};

MFRC522 rfid(SS_PIN, RST_PIN);


MFRC522 :: MIFARE_Key key;

RH_ASK driver(2000,3);

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
    Serial.begin(9600);  // Debugging only
    SPI.begin();
    rfid.PCD_Init();
    if (!driver.init())
         Serial.println("init failed");
}

void loop()
{
    uint8_t buf[12];
    analogWrite(A0,255); 
    uint8_t buflen = sizeof(buf);
    if (driver.recv(buf, &buflen)) // Non-blocking
    {
      analogWrite(A0,0); 
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      int l=strlen(buf);
     int p=0;
     String st="";
     for(p=0;p<l-3;p++){
     //Serial.println((char)buf[p]);
     st=st+(char)buf[p];
     }  
     Serial.println(st);       
      /* if(st=="1")
     {
        analogWrite(A0,255); 

     }*/
  while(1){
         if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
     {continue;}

  // Serial.print (F ("PICC type:"));
  MFRC522 :: PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println (rfid.PICC_GetTypeName (piccType));

  // Check is the PICC of Classic MIFARE type 
  if (piccType != MFRC522 :: PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522 :: PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522 :: PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    continue; 
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
  int i1=st[0]-48;
  if(tags[i1]==strID)
  {
    Serial.println("gaadi ukna mangata");
    analogWrite(A0,255);
    //analogWrite(A1,255);
    //analogWrite(A4,255); 
    //delay(500);
    //analogWrite(A4,0);
   raisemotor(); 
    delay(5000);
    
    break;
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
 }
    analogWrite(A0,0);

   while(1){
         if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial())
     {continue;}

  // Serial.print (F ("PICC type:"));
  MFRC522 :: PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  // Serial.println (rfid.PICC_GetTypeName (piccType));

  // Check is the PICC of Classic MIFARE type 
  if (piccType != MFRC522 :: PICC_TYPE_MIFARE_MINI &&
    piccType != MFRC522 :: PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522 :: PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    continue; 
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
  int i1=st[1]-48;
  if(tags[i1]==strID)
  {
    Serial.println("gaadi ukna mangata");
    analogWrite(A0,255); 
    /*analogWrite(A5,255); 
    delay(500);
    analogWrite(A5,0); */
    delay(5000);
    break;
  }
  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
 }
}
}
void raisemotor(){
    Serial.println("Hella");
    analogWrite(A1,255);
    analogWrite(A4,255); 
    delay(500);
    analogWrite(A4,0);
  }
