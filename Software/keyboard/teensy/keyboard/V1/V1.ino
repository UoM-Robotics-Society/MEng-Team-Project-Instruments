//int noteStatus [] = {1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1};
//int note [] = {45, 52, 59, 60, 59, 52, 60, 45, 50, 50, 50, 48, 50, 48, 41, 48, 55, 55, 48, 57, 50, 41, 50, 50, 57, 48, 50, 45, 48, 52, 59, 60, 59, 52, 60, 45, 50, 50, 50};
//float timings [] = {3.75, 0.31, 0.31, 0.31, 0.03, 0.10, 0.34, 0, 0.16, 0.17, 0.14, 0.09, 0.03, 0.26, 0.02, 0.31, 0.31, 0.28, 0, 0.03, 0, 0.01, 0.59, 0.03, 0.01, 0.31, 0.03, 0.01, 0.31, 0.03, 0.60, 0.03, 0.28, 0.31, 0.31, 0.03, 0.10, 0.34, 0};

int noteStatus [] = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
int note [] = {24, 25, 26, 27, 28, 24, 25, 26, 27, 28};
float timings [] = {3, 2, 1, 2, 1, 2, 3, 4, 5, 1};

int current [] = {0, 0, 0, 0, 0, 0, 0, 0};
byte shift[8];
//----------------------------------------//

//Pin connected to latch pin (ST_CP) of 74HC595
const int latchPin = 1;
//Pin connected to clock pin (SH_CP) of 74HC595
const int clockPin = 2;
////Pin connected to Data in (DS) of 74HC595
const int dataPin = 0;

int currentIndex = 0;
int timingsIndex = 0;
long delayInSeconds;
int timingsLength;
int statusIndex;
int shiftIndex = 0;
int maxShiftRegister = 1;
float timingDelay;
//----------------------------------------//

//uint64_t solenoids = 0b0000000011111111000000001111111100000000111111110000000011111111;
uint8_t solenoids = 0b00000000;
//---------------------------------------//

void setup() {
  // put your setup code here, to run once:

  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);
  timingsLength = sizeof(timings) / sizeof(float); //gets the length of the timing array
  //Serial.println(timings[timingsLength]);
  //Serial.println(lengthN);
  timingsIndex = 0;
  //  Serial.println("Before change: ");
  //  print16(solenoids);
  //  bitWrite(solenoids, 14, 1);
  //  Serial.println("After change: ");
  //  print16(solenoids);
  //  digitalWrite(latchPin,0);
  //shift[0] = solenoids;
  //shift[1] = solenoids >> 8;
  //shiftOut(dataPin, clockPin, LSBFIRST, shift[1]);
  //shiftOut(dataPin, clockPin, LSBFIRST, shift[0]);
  shiftOut(dataPin, clockPin, LSBFIRST, solenoids);
  Serial.println("reset");
  //  print8(shift[1]);
  //  print8(shift[0]);
  //  digitalWrite(latchPin,1);
}

void loop() {
  if (timingsIndex <= timingsLength) {
    delayInSeconds = timings[timingsIndex] * 1000;              //convert the delay time to ms
    delay(delayInSeconds);              //delay by ms
    Serial.println("delay: ");
    Serial.println(delayInSeconds);           // reset the currentIndex to zero so that the first note is written to the first element in this loop
    currentIndex = 0;
    current[currentIndex] = note[timingsIndex] - 24;            //convert the note number to the bit number in the solenoids variable
    Serial.println("Current note: ");
    Serial.println(current[currentIndex]);
    Serial.println("Solenoids before change: ");
    print8(solenoids);
    bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);//writes to the specific bit number of the solenoid variable turning it on or off
    Serial.println("Solenoids after change: ");
    print8(solenoids);
    timingsIndex++;         //increases the timingIndex by one to check the next note
    Serial.println("timingsIndex: ");
    Serial.println(timingsIndex);
    Serial.println("timingsLength: ");
    Serial.println(timingsLength);
    //------------------------------------------------------------------//

    for (timingsIndex; timingsIndex < timingsLength; timingsIndex++) {          //checks the next timing to see whether it is a zero or not
      if (timings[timingsIndex] == 0) {          //if it is a zero then change the bit for that particular note to a high or low
        current[currentIndex] = note[timingsIndex] - 24;
        bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);
        Serial.println("loop: ");
        Serial.println(timingsIndex);
        print8(solenoids);
      }
      else {
        break;          //if it isn't a zero then break out of the for loop
      }
    }
    //-----------------------------------------------------------------//

    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, LSBFIRST, solenoids);         //writes to the shift registers byte by byte
    Serial.print("print pattern ");
    print8(solenoids);
    digitalWrite(latchPin, 1);

    //  shiftIndex = 0;        //set the shiftIndex to zero to get ready to form all of the bytes
    //  shift[shiftIndex] = solenoids;
    //  shiftIndex++;
    //  for (shiftIndex; shiftIndex < maxShiftRegister; shiftIndex++) {              //forms the bytes for each of the shift registers by moving bytes of the solenoid variables down in bytes
    //    shift[shiftIndex] = (solenoids >> 8);
    //  }
    //  shiftIndex = 0;           //resets the shiftIndex to get it ready to write to the shift registers
    //  digitalWrite(latchPin, 0);            //sets the latch low so none of the bits change while writing
    //  for (shiftIndex; shiftIndex < maxShiftRegister; shiftIndex++) {
    //    shiftOut(dataPin, clockPin, LSBFIRST, shift[shiftIndex]);         //writes to the shift registers byte by byte
    //    Serial.print("shift ");
    //    Serial.println(shiftIndex);
    //    print8(shift[shiftIndex]);
    //  }
    //  //  shiftOut(dataPin,clockPin,MSBFIRST, shift[shiftIndex]);
    //  digitalWrite(latchPin, 1);          //sets latch high to shift all of the solenoids
    //-----------------------------------------------------------------//
    Serial.println("");
  }
}

void print16(uint16_t myByte) {
  for (uint16_t mask = 0x8000; mask; mask >>= 1) {
    if (mask  & myByte)
      Serial.print('1');
    else
      Serial.print('0');
  }
  Serial.println("");
}

void print8(byte myByte) {
  for (byte mask = 0x80; mask; mask >>= 1) {
    if (mask  & myByte)
      Serial.print('1');
    else
      Serial.print('0');
  }
  Serial.println("");
}
