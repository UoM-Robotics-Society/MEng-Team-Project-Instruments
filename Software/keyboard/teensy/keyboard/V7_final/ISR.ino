void ISR()
{
  //  printNotes();
  bitWrite(solenoids, (pnoteArray[count] - 24), pstatusArray[count]);
  count = count + 1;
  //  printNotes();

  while (ptimeArray[count] == 0) {
    bitWrite(solenoids, (pnoteArray[count] - 24), pstatusArray[count]);
    count = count + 1;
        printNotes();
  }
//
//  //  Serial.print("After:  ");
//  //  printNotes();
  myTimer.update(ptimeArray[count]);

  shiftIndex = 0;
  while (shiftIndex < 8) {
    solenoidsCopy = solenoids >> (8 * shiftIndex);
    shift[shiftIndex] = solenoidsCopy;
    //    print64(solenoidsCopy);
    //    print8(shift[shiftIndex]);
    digitalWrite(latchPin, 0);
    shiftOut(dataPin, clockPin, MSBFIRST, shift[shiftIndex]);
    digitalWrite(latchPin, 1);
    shiftIndex = shiftIndex + 1;
  }
  //  Serial.println("Executed");
  //  Serial.println("*******************************************");
}

