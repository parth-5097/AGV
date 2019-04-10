#include <RH_ASK.h>
//#include <SPI.h> // Not actualy used but needed to compile

RH_ASK driver(2000,3);

void setup()
{
  pinMode(A0, OUTPUT);

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
      int i;
      // Message with a good checksum received, dump it.
      Serial.print("Message: ");
      int l=strlen(buf);
     int p=0;
     String st="";
     for(p=0;p<l-9;p++){
     //Serial.println((char)buf[p]);
     st=st+(char)buf[p];
     }  
     Serial.println(st);       
       if(st=="1")
     {
        analogWrite(A0,255); 

     }
    }
}
