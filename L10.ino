#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <dht11.h>
dht11 DHT11;
Adafruit_SSD1306 display(128, 64, &Wire, -1);
void setup() {
  Serial.begin(115200);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) for(;;); 
  delay(2000);
  display.setTextColor(WHITE);
}
void loop() {
  delay(5000);
  DHT11.read(4); 
  float t = DHT11.temperature;
  float h = DHT11.humidity;
  if (isnan(h) || isnan(t)) Serial.println("Failed to read from DHT sensor !");
  Serial.print("Humidity (%)"); Serial.println(h, 2);
  Serial.print("Temperature (C):"); Serial.println(t, 2);
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0, 0);  display.print("Temperature");
  display.setCursor(0, 35); display.print("Humidity");
  display.setTextSize(2);
  display.setCursor(0, 10); display.print(t); display.print(" ");
  display.setTextSize(1);   display.cp437(true); display.write(167);
  display.setTextSize(2);   display.print("C");
  display.setCursor(0, 45); display.print(h); display.print("%");
  display.display();
}
