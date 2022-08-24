/*
  ISR FOR READING AVAILABLE DATA FROM THE ESP MODULE.
  THIS ISR GETS CALLED WHEN GPIO2 OF THE ESP GOES HIGH.
  WHICH IT DOES ONLY WHEN IT HAS TRANSMITTED SOMETHING.
  READ THE INCOMING BYTES.
*/

void USARTavailable() {

  String MESSAGE = "";
  while (Serial3.available()) {
    MESSAGE = MESSAGE + (char) Serial3.read();
  }
  if (MESSAGE.startsWith("PLAY")) {
    ACTION = 1;
    TRACK = MESSAGE.substring(4);
  
  }
  else if (MESSAGE.startsWith("STOP")) {
    ACTION = 2;
    TRACK = "";
  }
  else if (MESSAGE.startsWith("listTracks")) {
    ACTION = 3;
    TRACK = "";
  }
}

