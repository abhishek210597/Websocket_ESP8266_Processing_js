import websockets.*;
import java.util.Date;
import java.text.SimpleDateFormat;

WebsocketClient cl;
String serverURL = "ws://192.168.140.96:8000"; // Replace with the IP address of your ESP8266
SimpleDateFormat sdf = new SimpleDateFormat("HH:mm:ss");

void setup() {
  size(400, 400);
  background(255);
  cl = new WebsocketClient(this, serverURL);
}

void draw() {
  // Continuously listen for messages
  //cl.listen();
}

void webSocketEvent(String message) {
   
  println("Received: " + message);
  String[] fields = message.split(",");

}
