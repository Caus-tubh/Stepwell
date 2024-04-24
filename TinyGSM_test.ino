// JC borewell device
// GSM code
//int Node_ID = 2023;
//const char server[] = "api.thingspeak.com";
//const char resource[] = "https://api.thingspeak.com/update?";
// const char resource[] = "https://api.thingspeak.com/update?";
//String apiKeyValue = "C2GY17LE4BOLY0UQ";
//String apiKeyValue = "OCCUNIBL0FRRN794";
//String apiKeyValue = "7GDYOQXM4ELKD47A";
//const int port = 80;
// const char apn[] = "cmnet";
int sent_status = 0;

#define APN "cmnet"
#define PORT 80
#define SERVER "api.thingspeak.com"
#define RESOURCE "https://api.thingspeak.com/update?"
#define API "C2GY17LE4BOLY0UQ"
#define SerialAT Serial
#define TINY_GSM_MODEM_SIM800
// Modem is SIM800
#define TINY_GSM_RX_BUFFER 1024  // Set RX buffer to 1Kb
#include <Wire.h>
#include <TinyGsmClient.h>

TinyGsm modem(SerialAT);


TinyGsmClient client(modem);

unsigned long int reset_time = millis();

void setup() {
  // Declaring PinModes
  SerialAT.begin(9600);
  modem.restart();
//  #if TINY_GSM_USE_GPRS
//  // Unlock your SIM card with a PIN if needed
//  if (GSM_PIN && modem.getSimStatus() != 3) { modem.simUnlock(GSM_PIN); }
//  #endif
}

//void send_data(float Distance_S) {
//  if (!client.connect(SERVER, PORT)) {
////    SerialMon.println(" fail");
//  } else {
////    SerialMon.println(" OK");
////    SerialMon.println("Performing HTTP POST request...");
//    String httpRequestData = "GET https://api.thingspeak.com/update?api_key=C2GY17LE4BOLY0UQ&field1=" + String(Distance_S) + "";
//    //      String httpRequestData = "api_key=Z0X571KLJ5J5GPGB&field4=75321";
////    client.print(String("POST ") + RESOURCE + " HTTP/1.1\r\n");
////    client.print(String("Host: ") + SERVER + "\r\n");
////    client.println("Connection: close");
////    client.println("Content-Type: application/x-www-form-urlencoded");
////    client.print("Content-Length: ");
////    client.println(httpRequestData.length());
//    client.println();
//    client.println(httpRequestData);
//    client.println();
//    delay(100);
//
////    unsigned long timeout = millis();
////    while (client.connected() && millis() - timeout < 10000L) {
////      while (client.available()) {
////        String line = client.readStringUntil('\n');
////        if (line.substring(0, 14).equals("Status: 200 OK")) {
////          sent_status = 1;
////        }
////        timeout = millis();
////      }
////    }
////    delay(1000);
//    client.stop();
//    delay(2000);
//  }
//}

void loop() {
    sent_status = 0;
    delay(500);
    modem.gprsConnect(APN);
    modem.waitForNetwork(600000L);
    if (client.connect(SERVER, PORT)){
      String httpRequestData = "GET https://api.thingspeak.com/update?api_key=C2GY17LE4BOLY0UQ&field1=" + String(1000) + "";
      client.println(httpRequestData);
      delay(1000);
      client.stop();
  //    send_data(100);
      delay(1000);
    }
    modem.gprsDisconnect();
    delay(30 * 1000);
}
