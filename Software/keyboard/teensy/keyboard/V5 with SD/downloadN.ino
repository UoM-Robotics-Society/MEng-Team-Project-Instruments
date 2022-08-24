/*
 * DON'T CHANGE THIS CODE.  
 */
void downloadN(volatile uint32_t noteArray[], String track) {

  String Track = track + "/notes.dat";
  Serial.println(Track);
  myFile = SD.open(Track.c_str());
  if (myFile) {
    uint16_t noteArraycounter = 0;
    while (myFile.available() > 0) {
      uint32_t note_ = 0;
      note_ = note_ << (myFile.read() << 24);
      note_ = note_ | (myFile.read() << 16);
      note_ = note_ | (myFile.read() << 8);
      note_ = note_ |  myFile.read();
      noteArray[noteArraycounter] = note_;
      noteArraycounter++;
    }
  }
  else {
    Serial.println("Failed to open file");
  }
  myFile.close();
}

