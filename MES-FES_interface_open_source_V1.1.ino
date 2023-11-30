//Proj_MES-FES_Interface - Version 1.1 arduino UNO/Nano 30 Nov 2023 using bitalino sensor and tilt sensor//
//if upload error, use in linux terminal sudo chmod a+rw /dev/ttyUSB0
//https://github.com/Joao-Pedro-ML/TCC/blob/main/Refactored/Refactored.ino

#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include <filters.h> // available in: https://github.com/MartinBloedorn/libFilter
char blueToothVal; 

// tilt sensor
int tilt = 12; // tilt sensor - adjust the sensitivity in embedded potentiometer 
int FSR = A6; // FSR sensor 
//MES
float MValue = 0;  //MES - Myo Electrical Signal
float Voltage;
float x = 0;
float difficult = 16;  // Difficult to App inventor (16%)
float filteredval[50];


float MES01=0;
float MES02=0;
float MES03=0;
float MES04=0;
float MES05=0;

float MES_X=0; 
float MES1=0;
float MES2=0;
float MESth=0;

float MES_001A=0;
float MES_001B=0;
float MES_002A=0;
float MES_002B=0;

//MES Filter
const float f2   = 40.0;  //Cutoff frequency in Hz
const float f1   = 10.0;  //Cutoff frequency in Hz
const float sampling_time = 0.001; //Sampling time in seconds.
IIR::ORDER  order  = IIR::ORDER::OD3; // Butterworth - Oder (OD1 to OD4)
IIR::TYPE typeHP =  IIR::TYPE::HIGHPASS;
Filter fHP(f1, sampling_time, order, typeHP); //configure high pass filter (40 Hz)
Filter fLP(f2, sampling_time, order); //configure low pass filter (10 Hz)

//FES
float th = 2000; //Initial Threshold - to do not trigger
int intensity=1; //Initial PWM - FES intensity
int flag =0; 
int cont =1; 
int time_on=121; //initial FES time (1s)
float Tfreq = 50000; //20Hz - to FES rise time

void setup() {
  MValue = (analogRead(A0));  //MES
  pinMode(12, INPUT);
  pinMode(6, OUTPUT);  //LED red
  
  FSR = (analogRead(A6));  //FSR
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);
  delay(1000);
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);


Serial.begin(9600); //Initialize Serial Monitor

//FES to H bridge
pinMode(9,OUTPUT); //FES_1
pinMode(10,OUTPUT); //FES_2
}


void MES_00()  //read samples
{
  for (int i = 0; i < 50; i++) {
    MValue = (analogRead(A0));
    Voltage = ((((3.3 / 1024.0) * (MValue))));
    filteredval[i] = fLP.filterIn(Voltage);
    filteredval[i] = fHP.filterIn(filteredval[i]);
    filteredval[i] = abs(filteredval[i]);
    filteredval[i] = filteredval[i] * 100;
    delay(1);
  }


 //10ms average -  build AWL to calculate the threshold
  MES01 = (filteredval[0] + filteredval[1] + filteredval[2] + filteredval[3] + filteredval[4] + filteredval[5] + filteredval[6] + filteredval[7] + filteredval[8] + filteredval[9]) / 10;

  //10ms average -  build AWL to calculate the threshold
  MES02 = (filteredval[10] + filteredval[11] + filteredval[12] + filteredval[13] + filteredval[14] + filteredval[15] + filteredval[16] + filteredval[17] + filteredval[18] + filteredval[19]) / 10;

  //10ms average -  build AWL to calculate the threshold
  MES03 = (filteredval[20] + filteredval[21] + filteredval[22] + filteredval[23] + filteredval[24] +  filteredval[25] + filteredval[26] + filteredval[27] + filteredval[28] + filteredval[29]) / 10;

  //10ms average -  build AWL to calculate the threshold
  MES04 = (filteredval[30] + filteredval[31] + filteredval[32] + filteredval[33] + filteredval[34] + filteredval[35] + filteredval[36] + filteredval[37] + filteredval[38] + filteredval[39]) / 10;

  //10ms average -  build AWL to calculate the threshold
  MES05 = (filteredval[40] + filteredval[41] + filteredval[42] + filteredval[43] + filteredval[44] + filteredval[45] + filteredval[46] + filteredval[47] + filteredval[48] + filteredval[49]) / 10;

MES01 = MES01*1; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES02 = MES02*1; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES03 = MES03*1; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES04 = MES04*1; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES05 = MES05*1; //inserted 2022 - if use other EMG sensor, the gain must be adjusted

//MES_X - create average 50ms (like root mean square)
MES_X = (MES01+MES02+MES03+MES04+MES05)/10; //must be adjusted to each MES sensor.
//JJJ sensor divide 100, Bitalino sensor divide 1.
// values must be between 1 and 3 during rest and greater than 10 during contraction.

tilt = digitalRead(12);
}

void fes_r(){
for (float Tfreq = 50000; Tfreq >= 25000; Tfreq=Tfreq-937.5) //Rise 20Hz to 40Hz
{ 
digitalWrite(6, HIGH); //red led on 
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW);
delayMicroseconds(10); //interpulse 10us off time
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-intensity)-(intensity));  
}//Serial.print("RISE");
}

void fes_on()
{
Tfreq = 25000; //keep frequency in 40Hz
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW);
delayMicroseconds(10); //interpulse 10us off time
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-intensity)-(intensity));  
} 

void fes_d(){
for (float Tfreq = 25000; Tfreq >= 50000; Tfreq=Tfreq+937.5) //Decay 40Hz to 20Hz
{
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); //interpulse 10us off time
delayMicroseconds(10);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(intensity);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-intensity)-(intensity));  

}//Serial.print("DECAY");
digitalWrite(6, LOW);}

void loop()
{ 
 
if(Serial.available())
{blueToothVal=Serial.read();}

//MES1 - RMS-100ms
MES_00();
MES_001A=MES_X;//50ms
MES_00();
MES_001B=MES_X;//50ms
MES1=(MES_001A+MES_001B)/2;

//MES2 - RMS-100ms
MES_00();
MES_002A=MES_X;//50ms
MES_00();
MES_002B=MES_X;//50ms
MES2=(MES_002A+MES_002B)/2;
FSR = (analogRead(A6));  //FSR

//configure moving threshold 
th = (1+(difficult/100)); 
MESth=th*MES1; 

//check "impedance" - if MES1 > 10, the red led will be on to warning about the impedance
if (MES1 > 10)
{digitalWrite(6, HIGH);
delay(50);
digitalWrite(6, LOW);
delay(50);}//LED red
else {digitalWrite(6, LOW);}//LED red

Serial.print(MESth);
Serial.print(" ");
Serial.println(MES2);
Serial.print(" ");
Serial.println(FSR);




if (MES2 >= MESth && MES2 <= 60 && flag==1 && MESth > 0.3 && MES2 >= 0.36 && tilt == 0)//01/17/2023 REMOVED "&& MES2 <= 2*MESth"
{

//digitalWrite(6, LOW);//LED red - off
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.write('p');//To App inventor
Serial.end();
//FES rise time
{
fes_r();
flag=1;
}
//FES on time
while (flag==1 && cont<=time_on)
{
fes_on();
cont++;
}
//Serial.print("ON");
//FES decay time
if (cont>=time_on)
{
{
fes_d();
flag=0;
time_on=time_on;
cont=1;
}}digitalWrite(6, LOW); //red led off
Serial.begin(9600);
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
MES2 = 0;
MES01 = 0 ;
MES02 = 0;
MES03 = 0;
MES04 = 0;
MES05 = 0;
delay(4000); //Do not remove, or the FES interference will create an infinity loop.
}

//PWM increase
if (blueToothVal=='v' && flag==0)
{intensity=intensity+15; // keep 5 to great amplifier and 100 to small. 
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//PWM decrease
if (blueToothVal=='c' && flag==0)
{intensity=intensity-15; // keep 5 to great amplifier and 100 to small. 
if(intensity <=4)
{intensity= 1;}
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//PWM STOP
if (blueToothVal=='x' && flag==0)
{intensity=1;
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//ON time increase
if (blueToothVal=='d' && flag==0)
{time_on += 120;
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//ON time decrease
if (blueToothVal=='s' && flag==0)
{time_on -= 120;
if (time_on <= 119)
{time_on = 121;}
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//difficult increase
if (blueToothVal=='g' && flag==0)
{difficult +=1; //adjusted to post stroke subject
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//difficult decrease
if (blueToothVal=='f' && flag==0)
{difficult -=1;
if (difficult <= 1)
{difficult = 1;}
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}
}//end
