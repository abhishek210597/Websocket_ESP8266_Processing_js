#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>

// Replace with your network credentials
const char* ssid = "RPI4_NITK";
const char* password = "RPI4NITK";

// Create a WebSocket server on port 81
WebSocketsServer webSocket = WebSocketsServer(8000);

// Analog input pins
const int analogPin1 = A0;
// const int analogPin2 = A1;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Start the WebSocket server
  webSocket.begin();
  //webSocket.onEvent(webSocketEvent);
}

void loop() {
  // Handle WebSocket communication
  webSocket.loop();

  // Read analog values
  int analogValue1 = analogRead(analogPin1);
  //int analogValue2 = analogRead(analogPin2);

  // Prepare the data to send
  String data = String(analogValue1);

  // Send data to all connected WebSocket clients
  webSocket.broadcastTXT(data);

  // Send data every 5 seconds
  delay(10);
}
