/*
 * 
 * All the resources for this project: https://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */
 
#include <SPI.h>
#include <MFRC522.h>
 
#define SS_PIN 9 //You know the real one
#define RST_PIN 10 //You know the real one
MFRC522 mfrc522(SS_PIN, RST_PIN);  
 
void setup() 
{
  Serial.begin(9600);   
  SPI.begin();      
  mfrc522.PCD_Init();  
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 
{
  /*// Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }*/
  //Serial.print(&(mfrc522.uid));//real
  //Serial.print(mfrc522.uid.uidByte[0] < 0x10 ? " 0" : " ");
  //Serial.print(mfrc522.uid.uidByte[0], HEX);
  //Show UID on serial monitor
  /*
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  */
} 
