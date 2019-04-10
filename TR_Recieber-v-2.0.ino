#include <VirtualWire.h>
const int ledPin = 9;
const int datain = A0;
void setup()
{
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(datain);
  vw_setup(2000);
  pinMode(ledPin, OUTPUT);
  vw_rx_start();
  Serial.begin(9600);
}
void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if (vw_get_message(buf, &buflen))
  {
    Serial.println((char)*buf);
    if (buf[0] == '1')
    {
      Serial.println("kkkk");
      digitalWrite(ledPin, HIGH);
    }
    if (buf[0] == '0')
    { Serial.println("ooo");
      digitalWrite(ledPin, LOW);
    }
  }
}
