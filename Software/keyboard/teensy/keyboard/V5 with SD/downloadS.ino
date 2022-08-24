
void downloadS(volatile uint32_t statusArray[], String track) {

  String Track = track + "/status.dat";
  Serial.println(Track);
  myFile = SD.open(Track.c_str());
  if (myFile) {
    uint16_t statusArraycounter = 0;
    while (myFile.available() > 0) {
      uint32_t status_ = 0;
      status_ = status_ << (myFile.read() << 24);
      status_ = status_ | (myFile.read() << 16);
      status_ = status_ | (myFile.read() << 8);
      status_ = status_ |  myFile.read();
      statusArray[statusArraycounter] = status_;
      statusArraycounter++;
    }
  }

  else {
    Serial.println("Failed to open file");
  }
  myFile.close();
}

