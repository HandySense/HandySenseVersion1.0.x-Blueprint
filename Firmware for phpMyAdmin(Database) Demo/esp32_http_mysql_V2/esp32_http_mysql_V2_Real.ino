/*-----------        Open innovation (DEMO)     -----------------*/

/*-----------                                    ----------------*/

#include <Arduino.h>
#include <Wire.h>                                                       // ใช้ library ของ Arduino
#include <WiFi.h>                                                       // library ของ Wire ใช้เป็น potocol ในการอ่านค่าเซ็นเซอร์ต่าง ๆ 
#include <HTTPClient.h>                                                 // library ของ HTTPClient ใช้ในการรับ-ส่ง กับ Web server ผ่าน HTTP potocol
#include <WiFiManager.h>                                                // library ของ WiFiManager ใช้ในการเชื่อมต่อกับอินเตอร์แบบ Wifi 
#include <Ticker.h>                                                     // library ของ Ticker ใช้ในการแสดงสถานะการทำงานของ LED ขณะเชื่อมต่อ Wifi (ไม่จำเป็นต้องใช่ก็ได้)
#include <BH1750.h>                                                     // library ของ BH1750 ใช้ในการอ่านค่าความสว่างในหน่วย Lux
#include "Adafruit_SHT31.h"                                             // library ของ Adafruit_SHT31 ใช้ในการอ่านค่าอุณหภูมิและความชื้นในอากาศ          

Ticker ticker;                                                          // ประกาศตัวแปรชนิด Ticker ชื่อ ticker
WiFiManager wifiManager;                                                // ประกาศตัวแปรชนิด WiFiManager ชื่อ wifiManager

#define Soil_moisture_sensorPin A0                                      // เป็นการกำหนดให้ขา (PIN) A0 แทนด้วยคำว่า Soil_moisture_sensorPin
// ความหมายคือเวลาใช้ (PIN) A0 ก็สามารถใช้ชื่อดังกล่าวได้

#ifndef LED_BUILTIN                                                      
#define LED_BUILTIN 13                                                  // ESP32 DOES NOT DEFINE LED_BUILTIN
#endif
int LED = LED_BUILTIN;

//const char* serverName = "http://domainName(IP)/parttofile/postdatasensor.php";  // servername for post data http potocol

Adafruit_SHT31 sht31 = Adafruit_SHT31();                                // ประกาศตัวแปรชนิด Adafruit_SHT31 ชื่อ sht31 สำหรับเก็บค่าจากฟังก์ชัน Adafruit_SHT31() ซึ่งคือค่าอุณหภูมิและความชื้นในอากาศ
float Temp_C, Hum_RH;                                                   // ประกาศตัวแปรชนิด float ชื่อ Temp_C (ค่าอุณหภูมิในหน่วยเซลเซียล), Hum_RH (ค่าความชื้นอากาศในหน่วย %RH)

BH1750 lightMeter;                                                      // ประกาศตัวแปรชนิด BH1750 ชื่อ lightMeter
float Brightness_lux;                                                   // ประกาศตัวแปรชนิด float ชื่อ Brightness_lux

float sensorValue_soil_moisture = 0.00;                                 // ประกาศตัวแปรชนิด float ชื่อ sensorValue_soil_moisture  ต้องการเก็บค่าเป็นจุดทศนิยม
float voltageValue_soil_moisture = 0.00;                                // ประกาศตัวแปรชนิด float ชื่อ voltageValue_soil_moisture
float percent_soil_moisture = 0.00;                                     // ประกาศตัวแปรชนิด float ชื่อ percent_soil_moisture

unsigned long previousMillis = 0;                                       // ประกาศตัวแปรชนิด unsigned long ชื่อ previousMillis
const long interval = 10000;                                            // ประกาศตัวแปรชนิด const long ชื่อ interval // Update: 10sec [Factory]

float Soil_Min = 20.00, Soil_Max = 60.00;                               // ประกาศตัวแปรชนิด float ชื่อ Soil_Min = 25.00 เพื่อกำหนดค่าความชื้นดินต่ำสุด, Soil_Max = 75.00 เพื่อกำหนดค่าความชื้นดินสูงสุด
String Pump_status, Light_status = "ON";                                // ประกาศตัวแปรชนิด String ชื่อ Pump_status, Light_status = "ON" สำหรับเก็บค่าสถานะการทำทำงานของปั้น้ำและหลอดไฟ

void tick() {                                                           // ฟังก์ชันแสดงสถานะการเชื่อมต่อ Wifi ของ LED
  digitalWrite(LED, !digitalRead(LED));                                 // set pin to the opposite state
}

void configModeCallback (WiFiManager *myWiFiManager) {                 // ฟังก์ชันแสดงสถานะการเชื่อมต่อ Wifi
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());                // if you used auto generated SSID, print it
  ticker.attach(0.2, tick);                                            // entered config mode, make led toggle faster
}

void Wire_init() {                                                     // ประกาศการเริ่มใช้งาน Wire และ serial print
  Serial.begin(115200);
  Wire.begin();
}

void Connect_wifi() {                                                 // ฟังก์ชันเชื่อมต่อ Wifi
  WiFi.mode(WIFI_STA);                                                
  wifiManager.setAPCallback(configModeCallback);
  wifiManager.setTimeout(120);                                        // รอการเชื่อมต่อ wifi ภายใน 120 วินาท // กำหนดเองได้ี 
  if (!wifiManager.autoConnect("Open innovation")) {                  // กรณีมีการเชื่อต่อ wifi ใหม่
    WiFi.mode(WIFI_OFF);
    Serial.println("failed to connect and hit timeout");
    delay(3000);
  }
}

void SHT31_sensor_init() {                                            // เริ่มใช้งาน Temp and Hum sensor (SHT31)
  Serial.print("SHT31 Init"); Serial.print(" ,\t");
  if (! sht31.begin(0x44)) {                                          // Set to 0x45 for alternate i2c addr
    Serial.print("Couldn't find SHT31"); Serial.print(" ,\t");
    while (1) delay(1);
  }
}

void BH1750_sensor_init() {                                          // เริ่มใช้งาน Brightness sensor
  lightMeter.begin();
  Serial.print(F("BH1750 Init")); Serial.print(" ,\t"); Serial.println();
}
 
void set_pinmode() {                                                // ประกาศใช้งาน PinMode ที่ได้กำหนดด้านบน
  pinMode(Soil_moisture_sensorPin, INPUT);
  pinMode(LED, OUTPUT);
  ticker.attach(0.6, tick);
}

void setup() {                                                     // สั่งให้ทุกอย่างทำงานใน Void setup เพื่อเริ่มการทำงาน
  Wire_init();
  Connect_wifi();
  SHT31_sensor_init();
  BH1750_sensor_init();
}

void loop() {
  get_value_temp_hum();                                           // เก็บค่าอุณหภูมิและความชื้นในอากาศ
  get_value_lux_sensor();                                         // เก็บค่าความสว่าง
  get_value_soil_moisture_sensor();                               // เก็บค่าความชื้นในดิน

                                                                  // นำค่าความชื้นในดินมาเปรียบเทียบ
  if (percent_soil_moisture >= Soil_Max) {                        // ถ้าเปอร์เซ็นความชื้นในดินที่อ่านได้ >= ค่ามากที่สุดที่กำหนดไว้
    Pump_status = "OFF";                                          // ให้ปิดปั้มน้ำ
  } else if (percent_soil_moisture <= Soil_Min) {                 // ถ้าเปอร์เซ็นความชื้นในดินที่อ่านได้ <= ค่าน้อยที่สุดที่กำหนดไว้  
    Pump_status = "ON";                                           // ให้เปิดปั้มน้ำ
  }
                                                                  // กำหนดเวลาส่งข้อมูลขึ้นบน database ทุก ๆ 10 วินาที (time-stamp)
  unsigned long currentMillis = millis();                         // ประกาศตัวแปร currentMillis ในนี้เพราะต้องใช้แค่ในฟังก์ชันนี้ให้ = เวลา ณ ตอนนี้ (เก็บแค่ค่า มิลลิวินาที)
  if (currentMillis - previousMillis >= interval) {               // ถ้าเวลาที่เก็บ - เวลาที่เก็บก่อนหน้านี้(อดีต) = เวลาที่กำหนดไว้เพื่อให้ส่งข้อมูลแล้ว
    previousMillis = currentMillis;                               // ให้เวลาก่อนหน้า(อดีต) = เวลา ณ ตอนนี้
    if (WiFi.status() == WL_CONNECTED) {                          // ถ้ามีการเชื่อมต่อ wifi 
      HTTP_POST_DATA();                                           // ส่งข้อมูลขึ้น database
    }
    else {
      Serial.println("WiFi Disconnected");
    }
  }
  print_data_monitor();                                           // ปริ้นค่าออกมาดูทาง Serial monitor ของ Arduino 
}

void HTTP_POST_DATA() {                                           // ฟังก์ชันส่งข้อมูลขึ้นบน database
  HTTPClient http;                                                // ประกาศตัวแปรชนิด HTTPClient ชื่อ http
  http.begin(serverName);                                         // เรียกการเชื่อมต่อกับ serverName ที่ได้กำหนดไว้ตั้งแต่ต้น
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");  // เป็นการกำหนด Header ของ http potocol ถ้าต้องส่งในรูปแบบของ text ให้กำหนดแบบนี้ 
  String httpRequestData = "&Temperature_C=" + String(Temp_C) + "&Humidity_RH="             // ส่งค่าที่ต้องการส่งขึ้นไป 
                           + String(Hum_RH) + "&Soil_moisture_PC=" + String(percent_soil_moisture)
                           + "&Brightness_LUX=" + String(Brightness_lux) + "&Soil_Min=" + String(Soil_Min)
                           + "&Soil_Max=" + String(Soil_Max) + "&Pump_status=" + String(Pump_status)
                           + "&Light_status=" + String(Light_status) + "";
  // Serial.print("httpRequestData: ");Serial.println(httpRequestData);

  int httpResponseCode = http.POST(httpRequestData);                            // .POST คือการส่งข้อมูลไปยัง URL หรือ serverName ที่กำหนดไว้
  if (httpResponseCode > 0) {                                                   // ถ้ากลับเป็น Code 200 สามารถเชื่อต่อกับ serverName ได้
    Serial.println();
    Serial.print("HTTP Response code: ");
    Serial.print(httpResponseCode);
    Serial.println(" OK, sent data to completed.");
    Serial.println();
  }
  else {                                                                       // กรณีไม่ใช่ Code 200 
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
    Serial.println();
  }
  http.end();
}

void get_value_temp_hum() {                                                   // ฟังก์ชั่นอ่านค่า TempAndHum sensor (SHT31)
  Temp_C = sht31.readTemperature();
  Hum_RH = sht31.readHumidity();
}

void get_value_lux_sensor() {                                                 // ฟังก์ชั่นอ่านค่า Lux_sensor (BH1750)
  Brightness_lux = lightMeter.readLightLevel();
}

void get_value_soil_moisture_sensor() {                                       // ฟังก์ชั่นอ่านค่า Soil_Moisture_Sensor
  sensorValue_soil_moisture = analogRead(Soil_moisture_sensorPin);            // อ่านค่า Analog Pin A0 
                                                                              // ทำ ADC แปลงเป็น Voltage
  voltageValue_soil_moisture = (sensorValue_soil_moisture * 3.3) / (4095.00); // V = (Analog Pin A0 x(คูณ) 3.3(Vref))/4095.00(12 bit คือความละเอียดในการค่า Analog)
  percent_soil_moisture  = ((-50) * voltageValue_soil_moisture) + 100;        // ทำสมการเส้นตรง y = mx + c
  if (percent_soil_moisture <= 0) {                                           // ถ้าเปอร์เซ็น <= 0 % กรณีอ่านค่าที่ติดลบ หรือ ไม่ได้เชื่อมต่อเซ็นเซอร์ 
    percent_soil_moisture = 0;                                                // ให้เปอร์เซ็น = 0 %
  }
  else if (percent_soil_moisture >= 100) {                                    // ถ้าเปอร์เซ็น >= 100 %
    percent_soil_moisture = 100;                                              // ให้เปอร์เซ็น = 100 %
  }
}

void print_data_monitor() {                                                   // ฟังก์ชันปริ้นค่ามาแสดงผ่าน Serial monitor ของ Arduino 
  Serial.print("Temp_C: "); Serial.print(Temp_C); Serial.print(" *C,\t");
  Serial.print("Hum_RH: "); Serial.print(Hum_RH); Serial.print(" %,\t");
  Serial.print("Brightness: "); Serial.print(Brightness_lux); Serial.print(" Lux,\t");
  //Serial.print("Sensor Analog Value: "); Serial.print(sensorValue_soil_moisture); Serial.print(",\t");
  //Serial.print("Voltage Value: "); Serial.print(voltageValue_soil_moisture); Serial.print(" V,\t");
  Serial.print("Moisture Level: "); Serial.print(percent_soil_moisture); Serial.print(" %\t");
  Serial.println();
  Serial.print("Soil Min: "); Serial.print(Soil_Min); Serial.print(" %,\t");
  Serial.print("Soil Max: "); Serial.print(Soil_Max); Serial.print(" %,\t");
  Serial.print("Pump_status: "); Serial.print(Pump_status); Serial.print(",\t");
  Serial.print("Light_status: "); Serial.print(Light_status); Serial.print("\t");
  Serial.println();
  delay(1000);
}
