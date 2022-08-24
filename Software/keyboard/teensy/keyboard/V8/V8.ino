#include <SD.h>
#include <SPI.h> //not nneeded

#define bitSet(value, bit) ((value) |= (1ULL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1ULL << (bit)))
#define bitWrite(value, bit, bitvalue) (bitvalue ? bitSet(value, bit) : bitClear(value, bit))

File SDhandler;
IntervalTimer timer;

volatile uint32_t *ptimeArray; //time array pointer
volatile uint32_t *pnoteArray; //note array pointer
volatile uint32_t *pstatusArray; //status array pointer
volatile  uint16_t count = 0;
volatile int Size = 0;


volatile uint16_t value1;
volatile uint64_t solenoids = 0b0000000000000000000000000000000000000000000000000000000000000000;
volatile uint64_t solenoidsCopy;
int shiftIndex = 0;
const int latchPin = 1; //Pin connected to latch pin (ST_CP) of 74HC595
const int clockPin = 2; //Pin connected to clock pin (SH_CP) of 74HC595
const int dataPin = 0; //Pin connected to Data in (DS) of 74HC595
byte shift[8];

//the teensy must be connected to the rightmost shift register. That is the first one.
int ACTION;
String TRACK;
uint64_t _time =0;//DELETE IN FINAL VERSION
void setup()
{
  //****SETUP FOR MQTT*********//
  pinMode(3, INPUT);
  Serial3.begin(115200); //begin Serial on pins 7(Rx) 8(Tx) used to comm. with esp
  Serial.begin(230400);  //begin Serial to transmit to monitor.
  while (!Serial); //remember to comment this
  delay(500);
  while (Serial3.available() > 0) {
    Serial.println(Serial3.read());//flush the serial buffer to clear any random data
  }
  Serial.println("Teensy starting...");
  attachInterrupt(3, USARTavailable, RISING); //configure interrupt for usart.
  //****SETUP FOR OTHER HARDWARE *****//
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  initSD();
  interrupts();
  //*******************************
}

void loop()
{
  
  switch (ACTION) {
    case 1: //play case
      ACTION = 0;
      playTrack(TRACK);
      break;

    case 3: //list tracks casE
      ACTION = 0;
      listTracks();
      break;
  }
  delay(500);//DELETE IN FINAL VERSION  
  /*******************************/
  /* this section can be used to control
     LEDs or other visual effects.
     Or to do anything else. however,when in play mode
     the code gets stuck in a while loop inside playTrack,
     so add any effects needed when the song is being played there.
  */
  /*****************************/
}


