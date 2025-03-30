#include <Arduino.h>

#define POT_PIN 34   // Chân đọc tín hiệu từ Potentiometer (ADC)
#define LED_PIN 4    // Chân LED (PWM)

void setup() {
  Serial.begin(115200);

  pinMode(POT_PIN, INPUT);
  
  // Cấu hình PWM cho LED trên kênh 0, tần số 5000Hz, độ phân giải 8-bit
  ledcSetup(0, 5000, 8);
  ledcAttachPin(LED_PIN, 0);
}

void loop() {
  int potValue = analogRead(POT_PIN);   // Đọc giá trị từ biến trở (0-4095)
  int brightness = map(potValue, 0, 4095, 0, 255);  // Chuyển đổi về 0-255

  Serial.print("Potentiometer: ");
  Serial.print(potValue);
  Serial.print(" | LED Brightness: ");
  Serial.println(brightness);

  ledcWrite(0, brightness);  // Điều khiển độ sáng LED bằng PWM

  delay(100);
}
