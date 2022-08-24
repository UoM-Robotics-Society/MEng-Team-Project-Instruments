#include <SD.h>
#define bitSet(value, bit) ((value) |= (1ULL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1ULL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

File myFile;
IntervalTimer myTimer;

volatile uint32_t *ptimeArray; //time array pointer
volatile uint32_t *pnoteArray; //note array pointer
volatile uint32_t *pstatusArray; //status array pointer
volatile  uint16_t count = 0;
volatile uint16_t value1;
volatile uint64_t solenoids = 0b0000000000000000000000000000000000000000000000000000000000000000;
volatile uint64_t solenoidsCopy;
int shiftIndex = 0;
const int latchPin = 1; //Pin connected to latch pin (ST_CP) of 74HC595
const int clockPin = 2; //Pin connected to clock pin (SH_CP) of 74HC595
const int dataPin = 0; //Pin connected to Data in (DS) of 74HC595
byte shift[8];

//the teensy must be connected to the rightmost shift register. That is the first one.

void setup()
{
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
  initSD();
  interrupts();
  //*******************************
}

void loop()
{
  myFile = SD.open("GoTBin"); //open GoT file
  if (myFile) {
    Serial.println("file opened successfully.");
    volatile uint32_t timeArray[(myFile.size() / 4)]; //614 length
    volatile uint32_t noteArray[(myFile.size() / 4)];
    volatile uint32_t statusArray[(myFile.size() / 4)];

    ptimeArray = timeArray;
    pnoteArray = noteArray;
    pstatusArray = statusArray;

    downloadT(timeArray, "GoTBin");
    downloadN(noteArray, "GOTBin");
    downloadS(statusArray, "GoTBin");
    //     printData(timeArray, noteArray, statusArray);

    myTimer.begin(ISR, 1000000);
    myTimer.update(timeArray[0]);

  }
  else {
    Serial.println("error opening file.");
  }
  if (count > 614) {
    //    noInterrupts();
    myTimer.end();
    //Serial.println(count);
    Serial.println("Done.");
  }
  while (1) {
  }
}


