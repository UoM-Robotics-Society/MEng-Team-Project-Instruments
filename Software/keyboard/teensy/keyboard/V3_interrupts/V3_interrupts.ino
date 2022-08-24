int noteStatus [] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
int note [] = {24, 25, 26, 27, 28, 24, 25, 31, 26, 27, 28};
float timings [] = {1000000, 2000000, 0, 1000000, 2000000, 0, 1000000, 2000000, 1000000, 2000000, 1000000};
int current [] = {0, 0, 0, 0, 0, 0, 0, 0};
byte shift[8];
//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 1;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 2;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 0;
int currentIndex = 0;
int timingsIndex = 0;
int timingsLength;
int shiftIndex = 0;
int maxShiftRegister = 1;
float timingDelay;
//uint64_t solenoids = 0b0000000011111111000000001111111100000000111111110000000011111111;
uint8_t solenoids = 0b00000000;
IntervalTimer keyboard1;
//---------------------------------------//

void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  timingsLength = sizeof(timings) / sizeof(float); //gets the length of the timing array
  timingsIndex = 0;
  shiftOut(dataPin, clockPin, LSBFIRST, solenoids);
  Serial.println("reset");
  keyboard1.begin(pressKey, timings[timingsIndex]);
}

void pressKey () {
  if (timingsIndex <= timingsLength) {
    currentIndex = 0;
    current[currentIndex] = note[timingsIndex] - 24;            //convert the note number to the bit number in the solenoids variable
    bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);//writes to the specific bit number of the solenoid variable turning it on or off
    timingsIndex++;         //increases the timingIndex by one to check the next note
    for (timingsIndex; timingsIndex < timingsLength; timingsIndex++) {          //checks the next timing to see whether it is a zero or not
      if (timings[timingsIndex] == 0) {          //if it is a zero then change the bit for that particular note to a high or low
        current[currentIndex] = note[timingsIndex] - 24;
        bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);
      }
      break;          //if it isn't a zero then break out of the for loop
    }
  }
  digitalWrite(latchPin, 0);
  shiftOut(dataPin, clockPin, LSBFIRST, solenoids);         //writes to the shift registers byte by byte
  digitalWrite(latchPin, 1);
  keyboard1.update(timings[timingsIndex]);
  Serial.println("");
}

void loop() {
}
