#include <Ticker.h>
const int ledPin = 22;                    // I have a LED on pin 22
const int buttonpin1 = 21;               // I have a push button on pin 21
const int PulseIN = 2;                  //pulse counter pin   
const int potPin = 34;                 //potentiometer pin
const int analog_pin = 33;   
int buttonstate1 = 0;
int potValue = 0;
int counter=0;
int average_analog_in = 0;             //averaging an analog value
int average;
int error_code=0;
float T;                              // offcycle+oncycle
int F;                               //frequency =1/T
float OnCycle;                      //on cycle variable
float OffCycle;                    //off cycle variable
float frequency;
float analog_in_array[]={0,0,0,0};

void CycleF()
{
  counter++;
  if( counter % 18  )loop;              //from assignment 1 
  if( counter % 200 )task2;            //converted to Milliseconds
  if( counter % 1000)task3;
  if( counter % 42)task4;
  if( counter % 42)task5;
  if( counter % 100)task6;
  if( counter % 333)task7;            // task7 has both task7 & task8 
  if( counter % 5000)task9;
}
void setup()
{
  pinMode(ledPin, OUTPUT);       
  pinMode (buttonpin1, INPUT);
  pinMode(PulseIN, INPUT);
  pinMode(analog_pin, INPUT);
  Serial.begin(9600);                  //baud rate value
  task2();
  task3();
  task4();
  task5();
  task6();
  task7();
  task9();
}
void loop()
{ digitalWrite(ledPin, HIGH);                    //task1
  delayMicroseconds(50);
  digitalWrite(ledPin, LOW);
  delay(500);
}
void task2()                                    //task2
{buttonstate1 = digitalRead(buttonpin1);
  if(buttonstate1 ==1)
  {digitalWrite(ledPin, HIGH);}
  else
  {digitalWrite(ledPin, LOW);}
}
void task3()                                   //task3
{OnCycle = pulseIn(PulseIN, HIGH, 10000);
  OffCycle = pulseIn(PulseIN, LOW, 10000);
  T = OnCycle + OffCycle;
  if(T==0)
  {frequency=0;}
  else
  {F = 1000000 / T;}                   
  Serial.print("Frequency = ");
  Serial.print(F);
}
void task4()                                  //task4
{potValue = analogRead(potPin);
  analog_in_array[4]=analog_pin;
  for(int i=0; i<4;i++)
  {analog_in_array[i]=analog_in_array[i+1];}
  Serial.println(potValue);
}
void task5()                                 //task5
{average=0;
  for(int i=0;i<4;i++)
  {average=average+analog_in_array[i];}
  average_analog_in=average/4;
}
void task6()                                //task6
{for(int i=0;i<1000;i++)
{asm volatile("nop\n\t"::);}
}
void task7()                               //task7 & task8
{int n=0;
  int error_code= 0;
  for (int i =0;i<n; i++)
  {average_analog_in += analogRead(analog_pin); }
   average_analog_in =average_analog_in/n;
   if(average_analog_in> 4095/2)
   {error_code =1;
     digitalWrite(ledPin, HIGH);}
     else
     {error_code =0;
     digitalWrite(ledPin, LOW);}
} 
void task9()                                //task9
{Serial.print("error_code");
   Serial.print(error_code);
   Serial.print(",");
   Serial.print("frequency");
   Serial.print(frequency);
   Serial.print(",");
   Serial.print("average_analog_in");
   Serial.print(average_analog_in);
   Serial.print(",");
}
  