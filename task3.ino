
const int PulseIN = 2;      
float ONCycle;              
float OFFCycle;             
float T;                    
int F;                      
          
void setup()
{
  pinMode(PulseIN, INPUT);
  Serial.begin(9600);
}
void loop()
{
 ONCycle = pulseIn(PulseIN, HIGH);
 OFFCycle = pulseIn(PulseIN, LOW);
  T = ONCycle + OFFCycle;
  F = 1000000 / T;                    
  Serial.print("Frequency = ");
  Serial.print(F);
  delay(1000);
}