 /********UNIVERSITY OF MANCHESTER SCHOOL OF EE&E*****************/
 /*********FOURTH YEAR PROJECT: ROBOT ORCHESTRA*******************/
 
 /*Test code for stepper motors playing Baba Black Sheep
 * Written by: Francesco Fumagalli
 * email: francesco.fum@gmail.com
 */

/*CONNECTIONS:
 * DRIVER       ARDUINO       STEPPER
 * 2A                         motor coil 2
 * 1A                         motor coil 1
 * 2B                         motor coil 2
 * 1B                         motor coil 2
 * Vdd            +5V
 * GND            GND
 * STEP           3
 * DIRECTION      4
 * MS1            5
 * MS2            6
 * MS3            7
 * SLEEP-RST
 * ENABLE         8
 */




#define DIR  4
#define EN   8
#define STEP 3
#define MS1  5
#define MS2  6
#define MS3  7

//frequency of notes
#define G 6271.93
#define A 7040
#define B 7902.13
#define C 4186.01
#define D 4698.63
#define E 5274.04
#define F 5587.65
long unsigned int Time;
unsigned int timeArray[] = {1000}; //1sec
//float noteArray[] ={G,G,D,D,E,E,E,E,D,C,C,B,B,A,A,G,D,D,D,C,C,B,B,B,A,G,D,D,D,C,C,C,C,B,B,B,A,G,G,D,D,E,E,E,E,D,C,C,B,B,A,A,G};
float noteArray[] ={D,D,E,D,G,F,D,D,E,D,A,G,D,D,B,G,F,E,C,C,B,G,A,G};//happy birthday
float noteTime[] ={1.384614,0.1153845,0.076923,0.5769225,0.076923,0.076923,0.076923,0.5769225,0.076923,0.076923,0.076923,0.1153845,0.076923,0.076923,0.076923,0.076923,0.076923,0.5384610000000001,0.1153845,0.076923,0.5769225,0.076923,0.076923,0.076923,0.5769225,0.076923,0.076923,0.076923,0.1153845,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.0048076875,0.1153845,0.076923,0.0048076875,0.0048076875,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.076923,0.0048076875,0.1153845,0.076923,0.0048076875,0.0048076875,0.076923,0.076923,0.076923,0.076923};
 
void setup() {
pinMode(DIR,OUTPUT);
pinMode(EN,OUTPUT);
pinMode(STEP,OUTPUT);
pinMode(MS1,OUTPUT);
pinMode(MS2,OUTPUT);
pinMode(MS3,OUTPUT);

Serial.begin(9600);
Serial.println("Starting...");

digitalWrite(EN,LOW); //enable the driver

//full step 0,0,0
//truth table in datasheet
digitalWrite(MS1,LOW);
digitalWrite(MS2,LOW);
digitalWrite(MS3,LOW);
digitalWrite(DIR,HIGH);
}

void loop() {

for(int i=0;i<(sizeof(noteArray)/sizeof(float));i++){
unsigned long Time=millis();
while((millis()-Time)<500){
    note(noteArray[i]); //play middle C for x amount of time 
}
}
while(1);
}



void note(float frequency){
  
  float period =(1/frequency); //calculate the period
  period = ((period/2)*1E6); //divide the period by two and convert into second
  digitalWrite(STEP,HIGH);
  delayMicroseconds(period); //use microseconds instead of milliseconds for higher resolution
  digitalWrite(STEP,LOW);
  delayMicroseconds(period);  
  
}

