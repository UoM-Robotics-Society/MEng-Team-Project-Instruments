void print16(uint16_t myByte) {
  for (uint16_t mask = 0x8000; mask; mask >>= 1) {
    if (mask  & myByte)
      Serial.print('1');
    else
      Serial.print('0');
  }
  Serial.println("");
}
