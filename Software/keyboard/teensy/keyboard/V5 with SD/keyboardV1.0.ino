/*
 * 
 * THIS SOFTWARE WORKS WITH TEENSY 3.5
 * TO ADD YOUR INSTRUMENT EDIT void ISR() FUNCTION BELOW.
 * DATA FROM THE SD CARD IS DOWNLOADED AUTOMATICALLY. THE DATA GIVEN TO THE USER IS THE FOLLOWING:
 *        - noteArray: AN ARRAY OF ALL THE NOTES IN THE SONG THAT NEED TO BE PLAYED, IN THE ORDER THAT THEY NEED TO BE PLAYED. USES MIDI NOTATION TO REPRESENT NOTES.
 *        - timeArray: AN ARRAY OF ALL THE NOTES IN THE SONG THAT NEED TO BE PLAYED, USES MIDI NOTATION
 *        - statusArray: AN ARRAY OF ALL 1s AND 0s, IF '1' PLAY THE NOTE IF '0' RELEASE THE NOTE. 
 * DON'T CHANGE ANY OF THE OTHER FUNCTIONS OTHER THAN void setup(), void loop(); AND void ISR()
 * email: francesco.fum@gmai.com
 * 
 * 
 */

#include <SD.h>
#include <SparkFun_MiniGen.h>
//#include <SPI.h>

File myFile;
IntervalTimer myTimer;
volatile uint32_t *ptimeArray; //time array pointer
volatile uint32_t *pnoteArray; //note array pointer
volatile uint32_t *pstatusArray; //status array pointer
volatile  uint16_t count = 0; //keeps track of element in array
volatile uint16_t Size = 0; //not needed




void ISR() {
  
/*   HOW TO USE THE ISR:
 *   TO ACCESS AN ELEMENT IN THE THREE ARRAYS USE: 
 *        *(pstatusArray + count)    
 *        *(ptimeArray + count)
 *        *(pnoteArray + count)
 *         - THE VALUE OF COUNT IS SET TO ZERO INITIALLY. WHEN THE SONG REACHES THE END COUNT IS AUTOMATICALLY RESET TO 0, FOR A NEW SONG TO BE PLAYED
 *         - THE VALUE OF COUNT CORRESPONDS TO THE ELEMENT IN THE ARRAY THAT YOU WANT TO ACCESS.
 *           FOR EXAMPLE, IF YOU WANT TO ACCESS THE 5TH ELEMENT OF THE NOTE ARRAY YOU SHOULD WRITE: 
 *                   *(pnoteArray + count) WHICH RETURNS THE VALUE IN THAT ELEMENT. 
 *         -  TO UPDATE THE TIMER USE myTimer.update((*(ptimeArray + count)));  
 *         -  IF YOU WANT TO SKIP THE NEXT TIME YOU WOULD USE: myTimer.update((*(ptimeArray + count + 1))); WHICH WOULD SKIP HE NEXT TIME NEXT TIME
 *         -  DON'T FORGET TO UPDATE THE COUNT, E.G COUNT++ TO MOVE TO THE NEXT SONG/NOTE/TIME 
 */

 /*
  * UNCOMMENT THE FOLLOWING SECTION FOR DEBUGGING. IT WILL PRINT ALL THE NOTES/TIMES/STATUS FOR A GIVEN SONG
  */
  //*********************ISR PRINT STUFF************************
  //playnote(frequencies[*(pnoteArray+count)]);
  // Serial.print(frequencies[*(pnoteArray+count)]);
  // Serial.print("     ");
  // Serial.print(*(ptimeArray+count));
  // Serial.print("     ");
  // Serial.println(*(pstatusArray+count));
  // count++;

//***********************************************************

 //**********************U S E R     C O D E     S T A R T************************************************************************************************************
          












 //************************U S E R     C O D E     E N D************************************************************************************************************
}


void setup()
{

  Serial.begin(9600);
  //while (!Serial);
  initSD(); //INITIATE SD FOR TEENSY 3.5 
  
}

void loop()
{
  String __track = "GoTv1";
  myFile = SD.open(__track.c_str()); //open GoT file or any other file 
  if (myFile) {
    Serial.println("file opened successfully.");
    //Create the three arrays with correct sizes
    volatile uint32_t timeArray[(myFile.size() / 4)]; 
    volatile uint32_t noteArray[(myFile.size() / 4)];
    volatile uint32_t statusArray[(myFile.size() / 4)];

    ptimeArray = timeArray; //pointer to the time array
    pnoteArray = noteArray; //pointer to note array
    pstatusArray = statusArray; //pointer to status array

    downloadT(timeArray, __track.c_str());
    downloadN(noteArray, __track.c_str());
    downloadS(statusArray, __track.c_str());
    // printData(timeArray, noteArray, statusArray); //PRINT THE DATA FOR DEUBUGGING PURPOSES
    myTimer.begin(ISR, 100); // DEFAULT START TIME, ISR IS THE FUNCTION TO BE CALLED WHEN INTERRUPT GOES OFF
    myTimer.update(timeArray[0]);
    interrupts();
  }
  else {
    Serial.println("error opening file.");
  }
  if (count > (myFile.size() / 4)) { //if the end of the song has been reached, stop.
    //noInterrupts();
    count = 0;
    myTimer.end();
    /* 
     *  Write user code to stop the hardware
     */
    Serial.println("Done.");
  }

}


