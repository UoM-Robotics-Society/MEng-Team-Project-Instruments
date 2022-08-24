
void downloadT(volatile uint32_t timeArray[], String track) {

  String Track = track + "/time.dat";
  
  myFile = SD.open(Track.c_str());
  if (myFile) {
    uint16_t timeArraycounter = 0;
    while (myFile.available() > 0) {
      uint32_t time_ = 0;
      time_ = time_ << (myFile.read() << 24);
      time_ = time_ | (myFile.read() << 16);
      time_ = time_ | (myFile.read() << 8);
      time_ = time_ |  myFile.read();
      timeArray[timeArraycounter] = time_;
      timeArraycounter++;
    }
  }
  else {
    Serial.println("Failed to open file.");
  }
  myFile.close();
}

