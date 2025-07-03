// กำหนดขา GPIO ตามที่คุณใช้
const int segmentPins[7] = {5, 17, 16, 4, 0, 2, 15};

// รูปแบบ segment a-g สำหรับเลข 0–9
const byte digits[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
  for (int num = 0; num < 10; num++) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], digits[num][i]);
    }
    delay(1000); // รอ 1 วินาที
  }
}
