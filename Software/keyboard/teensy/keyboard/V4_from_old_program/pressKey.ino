void pressKey() {
  //  delayInSeconds = timings[timingsIndex] * 1000;              //convert the delay time to ms
  //  delay(delayInSeconds);              //delay by ms
  Serial.println("In the ISR");
  Serial.println("TimingsIndex: ");
  Serial.println(timingsIndex); ;
  //  Serial.println("delay: ");
  //  Serial.println(delayInSeconds);           // reset the currentIndex to zero so that the first note is written to the first element in this loop
  currentIndex = 0;
  current[currentIndex] = note[timingsIndex] - 24;            //convert the note number to the bit number in the solenoids variable
  Serial.println("Current note: ");
  Serial.println(current[currentIndex]);
  Serial.println("Solenoids before change: ");
  print16(solenoids);
  bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);//writes to the specific bit number of the solenoid variable turning it on or off
  Serial.println("Solenoids after change: ");
  print16(solenoids);
  timingsIndex++;         //increases the timingIndex by one to check the next note
  Serial.println("timingsIndex: ");
  Serial.println(timingsIndex);
  Serial.println("timingsLength: ");
  Serial.println(timingsLength);
  for (timingsIndex; timingsIndex < timingsLength; timingsIndex++) {          //checks the next timing to see whether it is a zero or not
    if (timings[timingsIndex] == 0) {          //if it is a zero then change the bit for that particular note to a high or low
      current[currentIndex] = note[timingsIndex] - 24;
      bitWrite(solenoids, current[currentIndex], noteStatus[timingsIndex]);
      Serial.println("loop: ");
      Serial.println(timingsIndex);
      print16(solenoids);
    }
    else {
      break;          //if it isn't a zero then break out of the for loop
    }
  }
  shiftIndex = 0;        //set the shiftIndex to zero to get ready to form all of the bytes
  shift[shiftIndex] = solenoids;
  shiftIndex++;
  for (shiftIndex; shiftIndex < maxShiftRegister; shiftIndex++) {              //forms the bytes for each of the shift registers by moving bytes of the solenoid variables down in bytes
    shift[shiftIndex] = (solenoids >> 8);
  }
  shiftIndex = 0;           //resets the shiftIndex to get it ready to write to the shift registers
  digitalWrite(latchPin, 0);            //sets the latch low so none of the bits change while writing
  for (shiftIndex; shiftIndex < maxShiftRegister; shiftIndex++) {
    shiftOut(dataPin, clockPin, LSBFIRST, shift[shiftIndex]);         //writes to the shift registers byte by byte
    Serial.print("shift ");
    Serial.println(shiftIndex);
    print8(shift[shiftIndex]);
  }
  //  shiftOut(dataPin,clockPin,MSBFIRST, shift[shiftIndex]);
  digitalWrite(latchPin, 1);          //sets latch high to shift all of the solenoids
  //-----------------------------------------------------------------//
  Serial.println("");
  if (timingsIndex > timingsLength) {
    keyboard1.end();
  }
  delayInSeconds = timings[timingsIndex] * 1000000;
  keyboard1.update(delayInSeconds);
}
