#include <U8g2lib.h>
#include <Wire.h>

#define TRIG D5
#define ECHO D6
#define RELAY D7

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0);

long duration;
int distance;
int level;

int tankHeight = 40;   // tank height in cm

long readDistance()
{
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  return duration * 0.034 / 2;
}

void setup()
{
  Serial.begin(115200);

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(RELAY, OUTPUT);

  digitalWrite(RELAY, HIGH);  // motor OFF initially

  u8g2.begin();
}

void loop()
{
  distance = readDistance();

  // Convert distance to water level %
  level = map(distance, tankHeight, 5, 0, 100);
  level = constrain(level, 0, 100);

  // Motor Control
  if(level < 30)
    digitalWrite(RELAY, LOW);   // Motor ON

  if(level > 90)
    digitalWrite(RELAY, HIGH);  // Motor OFF

  // OLED display
  u8g2.clearBuffer();

  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(15,10,"Water Motor Switch");

  u8g2.setCursor(10,35);
  u8g2.print("Level: ");
  u8g2.print(level);
  u8g2.print("%");

  u8g2.setCursor(10,55);
  u8g2.print("Motor: ");

  if(digitalRead(RELAY)==LOW)
    u8g2.print("ON");
  else
    u8g2.print("OFF");

  u8g2.sendBuffer();

  delay(1000);
}