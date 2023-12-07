//Proj_MES-FES_Interface - Version 1.1 arduino UNO/Nano 07 Dez 2023 using bitalino sensor and tilt sensor
//No buffer to MES
#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include <filters.h> // available in: https://github.com/MartinBloedorn/libFilter
char blueToothVal; 

// tilt sensor
int tilt = 12; // tilt sensor - adjust the sensitivity in embedded potentiometer 

//MES
float MValue=0; //MES - Myo Electrical Signal
float Voltage;
float x = 0;
float difficult = 16; // Difficult to App inventor (16%)
float filteredval=0;
float filteredval1=0;
float filteredval2=0;
float filteredval3=0;
float filteredval4=0;
float filteredval5=0;
float filteredval6=0;
float filteredval7=0;
float filteredval8=0;
float filteredval9=0;
float filteredval10=0;
float filteredval11=0;
float filteredval12=0;
float filteredval13=0;
float filteredval14=0;
float filteredval15=0;
float filteredval16=0;
float filteredval17=0;
float filteredval18=0;
float filteredval19=0;
float filteredval20=0;



float MES01=0;
float MES02=0;


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
const float sampling_time = 0.01; //Sampling time in seconds.
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

void setup()
{
MValue = (analogRead(A0)); //MES
pinMode(12, INPUT);
pinMode(6, OUTPUT); //LED red
  
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

void MES_00() //read samples
{
MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval1 = fLP.filterIn(Voltage);
filteredval1 = fHP.filterIn(filteredval1);
filteredval1 =abs(filteredval1);
filteredval1 =filteredval1*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval2 = fLP.filterIn(Voltage);
filteredval2 = fHP.filterIn(filteredval2);
filteredval2 =abs(filteredval2);
filteredval2 =filteredval2*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval3 = fLP.filterIn(Voltage);
filteredval3 = fHP.filterIn(filteredval3);
filteredval3 =abs(filteredval3);
filteredval3 =filteredval3*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval4 = fLP.filterIn(Voltage);
filteredval4 = fHP.filterIn(filteredval4);
filteredval4 =abs(filteredval4);
filteredval4 =filteredval4*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval5 = fLP.filterIn(Voltage);
filteredval5 = fHP.filterIn(filteredval5);
filteredval5 =abs(filteredval5);
filteredval5 =filteredval5*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval6 = fLP.filterIn(Voltage);
filteredval6 = fHP.filterIn(filteredval6);
filteredval6 =abs(filteredval6);
filteredval6 =filteredval6*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval7 = fLP.filterIn(Voltage);
filteredval7 = fHP.filterIn(filteredval7);
filteredval7 =abs(filteredval7);
filteredval7 =filteredval7*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval8 = fLP.filterIn(Voltage);
filteredval8 = fHP.filterIn(filteredval8);
filteredval8 =abs(filteredval8);
filteredval8 =filteredval8*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval9 = fLP.filterIn(Voltage);
filteredval9 = fHP.filterIn(filteredval9);
filteredval9 =abs(filteredval9);
filteredval9 =filteredval9*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval10 = fLP.filterIn(Voltage);
filteredval10 = fHP.filterIn(filteredval10);
filteredval10 =abs(filteredval10);
filteredval10 =filteredval10*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval11 = fLP.filterIn(Voltage);
filteredval11 = fHP.filterIn(filteredval11);
filteredval11 =abs(filteredval11);
filteredval11 =filteredval11*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval12 = fLP.filterIn(Voltage);
filteredval12 = fHP.filterIn(filteredval12);
filteredval12 =abs(filteredval12);
filteredval12 =filteredval12*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval13 = fLP.filterIn(Voltage);
filteredval13 = fHP.filterIn(filteredval13);
filteredval13 =abs(filteredval13);
filteredval13 =filteredval13*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval14 = fLP.filterIn(Voltage);
filteredval14 = fHP.filterIn(filteredval14);
filteredval14 =abs(filteredval14);
filteredval14 =filteredval14*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval15 = fLP.filterIn(Voltage);
filteredval15 = fHP.filterIn(filteredval15);
filteredval15 =abs(filteredval15);
filteredval15 =filteredval15*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval16 = fLP.filterIn(Voltage);
filteredval16 = fHP.filterIn(filteredval16);
filteredval16 =abs(filteredval16);
filteredval16 =filteredval16*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval17 = fLP.filterIn(Voltage);
filteredval17 = fHP.filterIn(filteredval17);
filteredval17 =abs(filteredval17);
filteredval17 =filteredval17*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval18 = fLP.filterIn(Voltage);
filteredval18 = fHP.filterIn(filteredval18);
filteredval18 =abs(filteredval18);
filteredval18 =filteredval18*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval19 = fLP.filterIn(Voltage);
filteredval19 = fHP.filterIn(filteredval19);
filteredval19 =abs(filteredval19);
filteredval19 =filteredval19*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((3.3/ 1024.0) *(MValue))));
float filteredval20 = fLP.filterIn(Voltage);
filteredval20 = fHP.filterIn(filteredval20);
filteredval20 =abs(filteredval20);
filteredval20 =filteredval20*100;
delay(1);


//10ms average -  build AWL to calculate the threshold
MES01 = (filteredval1+filteredval2+filteredval3+filteredval4+filteredval5+filteredval6+filteredval7+filteredval8+filteredval9+filteredval10)/10;   

//10ms average -  build AWL to calculate the threshold
MES02 = (filteredval11+filteredval12+filteredval13+filteredval14+filteredval15+filteredval16+filteredval17+filteredval18+filteredval19+filteredval20)/10; 
  
MES01 = MES01*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES02 = MES02*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted



//MES_X - create average 20ms (like root mean square)
MES_X = (MES01+MES02)/10; //must be adjusted to each MES sensor.

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

//MES1 - RMS-40ms
MES_00();
MES_001A=MES_X;//20ms
MES_00();
MES_001B=MES_X;//20ms
MES1=(MES_001A+MES_001B)/2;

//MES2 - RMS-40ms
MES_00();
MES_002A=MES_X;//20ms
MES_00();
MES_002B=MES_X;//20ms
MES2=(MES_002A+MES_002B)/2;

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



if (MES2 >= MESth && MES2 <= 60 && flag==0 && MESth > 3 && MES2 >= 3 && tilt == 0)//01/17/2023 REMOVED "&& MES2 <= 2*MESth"
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
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
MES2 = 0;
delay(4000); //Do not remove, or the FES interference will create an infinity loop.
}

//PWM increase
if (blueToothVal=='v' && flag==0)
{intensity=intensity+25; // keep 5 to great amplifier and 100 to small. 
digitalWrite(6, HIGH); //red led
delay(50);
digitalWrite(6, LOW);
blueToothVal=0;}

//PWM decrease
if (blueToothVal=='c' && flag==0)
{intensity=intensity-25; // keep 5 to great amplifier and 100 to small. 
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


