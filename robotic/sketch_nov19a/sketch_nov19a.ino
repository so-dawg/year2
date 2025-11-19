#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Weeeewonder Coffee";
const char* password = "12345678";

// CallMeBot Settings
String phoneNumber = "+85590629967";  
String apiKey = "6909699";            

void setup() {
  Serial.begin(115200);

  // Connect WiFi
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
  }
  Serial.println("\nWiFi Connected!");

  // Test WhatsApp message
  sendWhatsApp("Hello! This is a test message from ESP32.");
}

void loop() {}

void sendWhatsApp(String message) {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    String encodedMsg = urlEncode(message);

    String url = "https://api.callmebot.com/whatsapp.php?phone=" 
                  + phoneNumber + "&text=" + encodedMsg 
                  + "&apikey=" + apiKey;

    Serial.println("Request URL:");
    Serial.println(url);

    http.begin(url);
    int httpCode = http.GET();

    Serial.print("HTTP Response: ");
    Serial.println(httpCode);

    if (httpCode > 0) {
      String payload = http.getString();
      Serial.println("Reply:");
      Serial.println(payload);
    }

    http.end();
  }
}

// URL Encoder
String urlEncode(String str) {
  String encoded = "";
  char c;
  char buf[3];
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (isalnum(c)) {
      encoded += c;
    } else if (c == ' ') {
      encoded += "%20";
    } else {
      sprintf(buf, "%%%02X", c);
      encoded += buf;
    }
  }
  return encoded;
}
