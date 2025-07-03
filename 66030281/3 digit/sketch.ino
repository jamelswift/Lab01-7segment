// ขา segment a-g
const int segmentPins[7] = {5, 17, 16, 4, 0, 2, 15};

// ขาควบคุมแต่ละหลัก (Digit select) → active LOW (ถ้า common cathode)
const int digitPins[3] = {18, 19, 21};

// รูปแบบ segment a–g สำหรับตัวเลข 0–9
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

int count = 0;  // ตัวเลขที่จะแสดง
unsigned long lastUpdate = 0;

void setup() {
  for (int i = 0; i < 7; i++) pinMode(segmentPins[i], OUTPUT);
  for (int i = 0; i < 3; i++) pinMode(digitPins[i], OUTPUT);

  // ปิดทุกหลักเริ่มต้น
  for (int i = 0; i < 3; i++) digitalWrite(digitPins[i], HIGH);
}

void loop() {
  unsigned long currentMillis = millis();

  // นับเลขใหม่ทุก 1000ms
  if (currentMillis - lastUpdate >= 1000) {
    lastUpdate = currentMillis;
    count = (count + 1) % 1000;  // นับ 0–999 วน
  }

  // แสดงตัวเลขปัจจุบัน
  displayNumber(count);
}

void displayNumber(int number) {
  int digitsToShow[3] = {
    number / 100,             // หลักร้อย
    (number / 10) % 10,       // หลักสิบ
    number % 10               // หลักหน่วย
  };

  // สลับการแสดงผลแต่ละหลักอย่างรวดเร็ว (Multiplex)
  for (int i = 0; i < 3; i++) {
    setSegments(digitsToShow[i]);
    digitalWrite(digitPins[i], LOW);   // เปิดหลักที่ i
    delay(5);                          // แสดงผลสั้นๆ
    digitalWrite(digitPins[i], HIGH);  // ปิดหลัก
  }
}

void setSegments(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digits[num][i]);
  }
}
