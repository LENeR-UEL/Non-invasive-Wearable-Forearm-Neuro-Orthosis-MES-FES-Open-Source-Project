
//Proj_MES-FES_Interface - Version 1.1 arduino UNO/Nano 20 May 2022 
#include <Arduino.h>
#include <ArduinoJson.h>
#include <math.h>
#include <filters.h> // available in: https://github.com/MartinBloedorn/libFilter
char blueToothVal; 

//MES
float  MValue=0; //MES - Myo Electrical Signal
float Voltage;
float x = 0;
float slider = 16; // Difficult to App inventor (16%)
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
float filteredval21=0;
float filteredval22=0;
float filteredval23=0;
float filteredval24=0;
float filteredval25=0;
float filteredval26=0;
float filteredval27=0;
float filteredval28=0;
float filteredval29=0;
float filteredval30=0;
float filteredval31=0;
float filteredval32=0;
float filteredval33=0;
float filteredval34=0;
float filteredval35=0;
float filteredval36=0;
float filteredval37=0;
float filteredval38=0;
float filteredval39=0;
float filteredval40=0;
float filteredval41=0;
float filteredval42=0;
float filteredval43=0;
float filteredval44=0;
float filteredval45=0;
float filteredval46=0;
float filteredval47=0;
float filteredval48=0;
float filteredval49=0;
float filteredval50=0;

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
const float sampling_time = 0.01; //Sampling time in seconds.
IIR::ORDER  order  = IIR::ORDER::OD3; // Butterworth - Oder (OD1 to OD4)
IIR::TYPE typeHP =  IIR::TYPE::HIGHPASS;
Filter fHP(f1, sampling_time, order, typeHP); //configure high pass filter (40 Hz)
Filter fLP(f2, sampling_time, order); //configure low pass filter (10 Hz)

//FES
float th = 2000; //Initial Threshold - to do not trigger
int dutyvalue=1; //Initial PWM - FES intensity
int flag =0; 
int cont =1; 
int time_on=121; //initial FES time (1s)
float Tfreq = 50000; //20Hz - to FES rise time

void setup()
{
digitalWrite(13, HIGH);
delay(1000);   
digitalWrite(13, LOW);  
delay(1000);
digitalWrite(5, HIGH);
delay(1000);  
digitalWrite(5, LOW);  
delay(1000);
digitalWrite(6, HIGH);
delay(1000);   
digitalWrite(6, LOW);  
 
MValue = (analogRead(A0)); //MES
pinMode(13, OUTPUT); //LED red
pinMode(5, OUTPUT); //LED blue
pinMode(6, OUTPUT); //LED green
Serial.begin(9600); //Initialize Serial Monitor

//FES to H bridge
pinMode(9,OUTPUT); //FES_1
pinMode(10,OUTPUT); //FES_2
}

void MES_00() //read samples
{
MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval1 = fLP.filterIn(Voltage);
filteredval1 = fHP.filterIn(filteredval1);
filteredval1 =abs(filteredval1);
filteredval1 =filteredval1*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval2 = fLP.filterIn(Voltage);
filteredval2 = fHP.filterIn(filteredval2);
filteredval2 =abs(filteredval2);
filteredval2 =filteredval2*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval3 = fLP.filterIn(Voltage);
filteredval3 = fHP.filterIn(filteredval3);
filteredval3 =abs(filteredval3);
filteredval3 =filteredval3*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval4 = fLP.filterIn(Voltage);
filteredval4 = fHP.filterIn(filteredval4);
filteredval4 =abs(filteredval4);
filteredval4 =filteredval4*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval5 = fLP.filterIn(Voltage);
filteredval5 = fHP.filterIn(filteredval5);
filteredval5 =abs(filteredval5);
filteredval5 =filteredval5*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval6 = fLP.filterIn(Voltage);
filteredval6 = fHP.filterIn(filteredval6);
filteredval6 =abs(filteredval6);
filteredval6 =filteredval6*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval7 = fLP.filterIn(Voltage);
filteredval7 = fHP.filterIn(filteredval7);
filteredval7 =abs(filteredval7);
filteredval7 =filteredval7*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval8 = fLP.filterIn(Voltage);
filteredval8 = fHP.filterIn(filteredval8);
filteredval8 =abs(filteredval8);
filteredval8 =filteredval8*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval9 = fLP.filterIn(Voltage);
filteredval9 = fHP.filterIn(filteredval9);
filteredval9 =abs(filteredval9);
filteredval9 =filteredval9*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval10 = fLP.filterIn(Voltage);
filteredval10 = fHP.filterIn(filteredval10);
filteredval10 =abs(filteredval10);
filteredval10 =filteredval10*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval11 = fLP.filterIn(Voltage);
filteredval11 = fHP.filterIn(filteredval11);
filteredval11 =abs(filteredval11);
filteredval11 =filteredval11*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval12 = fLP.filterIn(Voltage);
filteredval12 = fHP.filterIn(filteredval12);
filteredval12 =abs(filteredval12);
filteredval12 =filteredval12*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval13 = fLP.filterIn(Voltage);
filteredval13 = fHP.filterIn(filteredval13);
filteredval13 =abs(filteredval13);
filteredval13 =filteredval13*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval14 = fLP.filterIn(Voltage);
filteredval14 = fHP.filterIn(filteredval14);
filteredval14 =abs(filteredval14);
filteredval14 =filteredval14*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval15 = fLP.filterIn(Voltage);
filteredval15 = fHP.filterIn(filteredval15);
filteredval15 =abs(filteredval15);
filteredval15 =filteredval15*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval16 = fLP.filterIn(Voltage);
filteredval16 = fHP.filterIn(filteredval16);
filteredval16 =abs(filteredval16);
filteredval16 =filteredval16*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval17 = fLP.filterIn(Voltage);
filteredval17 = fHP.filterIn(filteredval17);
filteredval17 =abs(filteredval17);
filteredval17 =filteredval17*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval18 = fLP.filterIn(Voltage);
filteredval18 = fHP.filterIn(filteredval18);
filteredval18 =abs(filteredval18);
filteredval18 =filteredval18*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval19 = fLP.filterIn(Voltage);
filteredval19 = fHP.filterIn(filteredval19);
filteredval19 =abs(filteredval19);
filteredval19 =filteredval19*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval20 = fLP.filterIn(Voltage);
filteredval20 = fHP.filterIn(filteredval20);
filteredval20 =abs(filteredval20);
filteredval20 =filteredval20*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval21 = fLP.filterIn(Voltage);
filteredval21 = fHP.filterIn(filteredval21);
filteredval21 =abs(filteredval21);
filteredval21 =filteredval21*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval22 = fLP.filterIn(Voltage);
filteredval22 = fHP.filterIn(filteredval22);
filteredval22 =abs(filteredval22);
filteredval22 =filteredval22*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval23 = fLP.filterIn(Voltage);
filteredval23 = fHP.filterIn(filteredval23);
filteredval23 =abs(filteredval23);
filteredval23 =filteredval23*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval24 = fLP.filterIn(Voltage);
filteredval24 = fHP.filterIn(filteredval24);
filteredval24 =abs(filteredval24);
filteredval24 =filteredval24*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval25 = fLP.filterIn(Voltage);
filteredval25 = fHP.filterIn(filteredval25);
filteredval25 =abs(filteredval25);
filteredval25 =filteredval25*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval26 = fLP.filterIn(Voltage);
filteredval26 = fHP.filterIn(filteredval26);
filteredval26 =abs(filteredval26);
filteredval26 =filteredval26*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval27 = fLP.filterIn(Voltage);
filteredval27 = fHP.filterIn(filteredval27);
filteredval27 =abs(filteredval27);
filteredval27 =filteredval27*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval28 = fLP.filterIn(Voltage);
filteredval28 = fHP.filterIn(filteredval28);
filteredval28 =abs(filteredval28);
filteredval28 =filteredval28*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval29 = fLP.filterIn(Voltage);
filteredval29 = fHP.filterIn(filteredval29);
filteredval29 =abs(filteredval29);
filteredval29 =filteredval29*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval30 = fLP.filterIn(Voltage);
filteredval30 = fHP.filterIn(filteredval30);
filteredval30 =abs(filteredval30);
filteredval30 =filteredval30*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval31 = fLP.filterIn(Voltage);
filteredval31 = fHP.filterIn(filteredval31);
filteredval31 =abs(filteredval31);
filteredval31 =filteredval31*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval32 = fLP.filterIn(Voltage);
filteredval32 = fHP.filterIn(filteredval32);
filteredval32 =abs(filteredval32);
filteredval32 =filteredval32*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval33 = fLP.filterIn(Voltage);
filteredval33 = fHP.filterIn(filteredval33);
filteredval33 =abs(filteredval33);
filteredval33 =filteredval33*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval34 = fLP.filterIn(Voltage);
filteredval34 = fHP.filterIn(filteredval34);
filteredval34 =abs(filteredval34);
filteredval34 =filteredval34*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval35 = fLP.filterIn(Voltage);
filteredval35 = fHP.filterIn(filteredval35);
filteredval35 =abs(filteredval35);
filteredval35 =filteredval35*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval36 = fLP.filterIn(Voltage);
filteredval36 = fHP.filterIn(filteredval36);
filteredval36 =abs(filteredval36);
filteredval36 =filteredval36*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval37 = fLP.filterIn(Voltage);
filteredval37 = fHP.filterIn(filteredval37);
filteredval37 =abs(filteredval37);
filteredval37 =filteredval37*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval38 = fLP.filterIn(Voltage);
filteredval38 = fHP.filterIn(filteredval38);
filteredval38 =abs(filteredval38);
filteredval38 =filteredval38*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval39 = fLP.filterIn(Voltage);
filteredval39 = fHP.filterIn(filteredval39);
filteredval39 =abs(filteredval39);
filteredval39 =filteredval39*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval40 = fLP.filterIn(Voltage);
filteredval40 = fHP.filterIn(filteredval40);
filteredval40 =abs(filteredval40);
filteredval40 =filteredval40*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval41 = fLP.filterIn(Voltage);
filteredval41 = fHP.filterIn(filteredval41);
filteredval41 =abs(filteredval41);
filteredval41 =filteredval41*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval42 = fLP.filterIn(Voltage);
filteredval42 = fHP.filterIn(filteredval42);
filteredval42 =abs(filteredval42);
filteredval42 =filteredval42*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval43 = fLP.filterIn(Voltage);
filteredval43 = fHP.filterIn(filteredval43);
filteredval43 =abs(filteredval43);
filteredval43 =filteredval43*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval44 = fLP.filterIn(Voltage);
filteredval44 = fHP.filterIn(filteredval44);
filteredval44 =abs(filteredval44);
filteredval44 =filteredval44*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval45 = fLP.filterIn(Voltage);
filteredval45 = fHP.filterIn(filteredval45);
filteredval45 =abs(filteredval45);
filteredval45 =filteredval45*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval46 = fLP.filterIn(Voltage);
filteredval46 = fHP.filterIn(filteredval46);
filteredval46 =abs(filteredval46);
filteredval46 =filteredval46*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval47 = fLP.filterIn(Voltage);
filteredval47 = fHP.filterIn(filteredval47);
filteredval47 =abs(filteredval47);
filteredval47 =filteredval47*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval48 = fLP.filterIn(Voltage);
filteredval48 = fHP.filterIn(filteredval48);
filteredval48 =abs(filteredval48);
filteredval48 =filteredval48*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval49 = fLP.filterIn(Voltage);
filteredval49 = fHP.filterIn(filteredval49);
filteredval49 =abs(filteredval49);
filteredval49 =filteredval49*100;
delay(1);

MValue = (analogRead(A0)); 
Voltage = ((((5.0/ 1024.0) *(MValue))));
float filteredval50 = fLP.filterIn(Voltage);
filteredval50 = fHP.filterIn(filteredval50);
filteredval50 =abs(filteredval50);
filteredval50 =filteredval50*100;
delay(1);

//10ms average -  build AWL to calculate the threshold
MES01 = (filteredval1+filteredval2+filteredval3+filteredval4+filteredval5+filteredval6+filteredval7+filteredval8+filteredval9+filteredval10)/10;   

//10ms average -  build AWL to calculate the threshold
MES02 = (filteredval11+filteredval12+filteredval13+filteredval14+filteredval15+filteredval16+filteredval17+filteredval18+filteredval19+filteredval20)/10; 

//10ms average -  build AWL to calculate the threshold
MES03 = (filteredval21+filteredval22+filteredval23+filteredval24+filteredval25+filteredval26+filteredval27+filteredval28+filteredval29+filteredval30)/10; 

//10ms average -  build AWL to calculate the threshold
MES04 = (filteredval31+filteredval32+filteredval33+filteredval34+filteredval35+filteredval36+filteredval37+filteredval38+filteredval39+filteredval40)/10; 

//10ms average -  build AWL to calculate the threshold
MES05 = (filteredval41+filteredval42+filteredval43+filteredval44+filteredval45+filteredval46+filteredval47+filteredval48+filteredval49+filteredval50)/10; 
  
MES01 = MES01*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES02 = MES02*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES03 = MES03*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES04 = MES04*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted
MES05 = MES05*10; //inserted 2022 - if use other EMG sensor, the gain must be adjusted

//MES_X - create average 50ms (like root mean square)
MES_X = (MES01+MES02+MES03+MES04+MES05)/5;
}

void fes_r(){
for (float Tfreq = 50000; Tfreq >= 25000; Tfreq=Tfreq-937.5) //Rise 20Hz to 40Hz
{ 
digitalWrite(6, HIGH); //green led on 
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW);
delayMicroseconds(10); //interpulse 10us off time
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-dutyvalue)-(dutyvalue));  
}//Serial.print("RISE");
}

void fes_on()
{
Tfreq = 25000; //keep frequency in 40Hz
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW);
delayMicroseconds(10); //interpulse 10us off time
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-dutyvalue)-(dutyvalue));  
} 

void fes_d(){
for (float Tfreq = 25000; Tfreq >= 50000; Tfreq=Tfreq+937.5) //Decay 40Hz to 20Hz
{
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); //interpulse 10us off time
delayMicroseconds(10);
digitalWrite(10, HIGH);
digitalWrite(9, LOW);
delayMicroseconds(dutyvalue);
digitalWrite(9, LOW); 
digitalWrite(10, LOW); 
delayMicroseconds((Tfreq-dutyvalue)-(dutyvalue));  

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

//configure moving threshold 
th = (1+(slider/100)); 
MESth=th*MES1; 

//check "impedance" - if MES1 > 10, the red led will be on to warning about the impedance
if (MES1 > 10)
{digitalWrite(13, HIGH);}//LED red
else {digitalWrite(13, LOW);}//LED red

Serial.print(MESth);
Serial.print(" ");
Serial.println(MES2);

if (MES2 >= MESth && MES2 <= 100 && flag==0 && MES2 <= 10*MESth && MESth > 0.1 && MES2 >= 3 )//01/04/2022
{
digitalWrite(13, LOW);//LED red - off
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
}}digitalWrite(6, LOW); //green led off
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
Serial.write('o');//To App inventor
MES2 = 0;
delay(4000); 
}

//PWM increase
if (blueToothVal=='v' && flag==0)
{dutyvalue=dutyvalue+100; // keep 5 to great amplifier and 100 to small. 
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//PWM decrease
if (blueToothVal=='c' && flag==0)
{dutyvalue=dutyvalue-100; // keep 5 to great amplifier and 100 to small. 
if(dutyvalue <=4)
{dutyvalue= 1;}
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//PWM STOP
if (blueToothVal=='x' && flag==0)
{dutyvalue=1;
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//ON time increase
if (blueToothVal=='d' && flag==0)
{time_on += 120;
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//ON time decrease
if (blueToothVal=='s' && flag==0)
{time_on -= 120;
if (time_on <= 119)
{time_on = 121;}
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//slider increase
if (blueToothVal=='g' && flag==0)
{slider +=1; //adjusted to post stroke subject
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}

//slider decrease
if (blueToothVal=='f' && flag==0)
{slider -=1;
if (slider <= 1)
{slider = 1;}
digitalWrite(5, HIGH); //blue led
delay(50);
digitalWrite(5, LOW);
blueToothVal=0;}
}//end
