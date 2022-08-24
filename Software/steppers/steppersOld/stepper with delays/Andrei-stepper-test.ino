/*     Simple Stepper Motor Control Exaple Code
 *      
 *  by Dejan Nedelkovski, www.HowToMechatronics.com
 *  
 */
// defines pins numbers
const int stepPin = 3; 
const int dirPin = 4; 

/*define musical notes
 * ex:  c2 frequency = 65.41 Hz
 * c2 period = 1/65.41
 * half period = (1/65.41)/2 = 0.007644 seconds = 7644 mciroseconds
 * 
 * taken mostly from an assignmnet in year 2, 
 * still unsure about the half period reason
 */

const int c0 = 30581;
const int d0 = 27247;
const int e0 = 24271;
const int f0 = 22904;
const int g0 = 20408;
const int a0 = 18181;
const int b0 = 16196;

const int c1 = 15290;
const int d1 = 13620;
const int e1 = 12135;
const int f1 = 11454;
const int g1 = 10204;
const int a1 = 9090;
const int b1 = 8098;

const int c2 = 7644;
const int d2 = 6810;
const int e2 = 6067;
const int f2 = 5726;
const int g2 = 5102;
const int a2 = 4545;
const int b2 = 4049;

const int c3 = 3822;
const int d3 = 3405;
const int e3 = 3033;
const int f3 = 2683;
const int g3 = 2551;
const int a3 = 2272;
const int b3 = 2024;

const int c4 = 1911;
const int d4 = 1702;
const int e4 = 1517;
const int f4 = 1432;
const int g4 = 1275;
const int a4 = 1136;
const int b4 = 1002;

const int c5 = 955;
const int d5 = 852;
const int e5 = 758;
const int f5 = 716;
const int g5 = 638;
const int a5 = 568;
const int b5 = 506;

const int c6 = 478;
const int d6 = 425;
const int e6 = 379;
const int f6 = 358;
const int g6 = 319;
const int a6 = 284;
const int b6 = 253;

const int c7 = 239;
const int d7 = 213;
const int e7 = 190;
const int f7 = 179;
const int g7 = 159;
const int a7 = 142;
const int b7 = 127;

const int c8 = 119;
const int d8 = 106;
const int e8 = 95;
const int f8 = 89;
const int g8 = 80;
const int a8 = 71;
const int b8 = 63;




 
void setup() {
  // Sets the two pins as Outputs
  pinMode(stepPin,OUTPUT); 
  pinMode(dirPin,OUTPUT);
}


void loop() {


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(c6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(c6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(d6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(d6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(e6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(e6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(f6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(f6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(g6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(g6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(a6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(a6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(b6);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(b6);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(c7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(c7);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(d7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(d7);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(e7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(e7);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(f7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(f7);    
  }
    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(g7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(g7);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(a7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(a7);    
  }


    for(int x = 0; x < 1500; x++) {
    digitalWrite(stepPin,HIGH);
    delayMicroseconds(b7);
    digitalWrite(stepPin,LOW);
    delayMicroseconds(b7);    
  }
  
  
  
 }


 




