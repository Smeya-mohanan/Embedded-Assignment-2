const int LED_green = 22;
const int buttonpin1 = 21;
int buttonstate1 = 0;
void setup()
{
  pinMode (LED_green, OUTPUT);
  pinMode (buttonpin1, INPUT);
}
void loop()
{
  buttonstate1 =digitalRead(buttonpin1);
  if(buttonstate1 ==1)
  {digitalWrite(LED_green, HIGH);
  }
  else
  {digitalWrite(LED_green, LOW);
  }
}