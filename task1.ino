const int LED_green = 22;
const int buttonpin1 = 21;
void setup()
{
  pinMode(LED_green, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(LED_green, HIGH);
  delayMicroseconds(5000);
  digitalWrite(LED_green, LOW);
  delay(1000);
}