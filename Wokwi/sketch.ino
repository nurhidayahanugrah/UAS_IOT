#include <WiFi.h>
#include <MQTT.h>
#include <DHT.h>

const int DHT_PIN = 2;
DHT dht(DHT_PIN, DHT22);

const char ssid[] = "Wokwi-GUEST";
const char pass[] = "";

WiFiClient net;
MQTTClient client;

float temp = 0;
float hum = 0;

unsigned long lastMillis = 0;

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("Ucup Compiler","uas-iot","8q2gDDs8UHgon0AC")) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  //client.subscribe("anton/prafanto/suhu");
  // client.unsubscribe("/hello");
}

void messageReceived(String &topic, String &payload) {
  Serial.println("incoming: " + topic + " - " + payload);

  // Note: Do not use the client in the callback to publish, subscribe or
  // unsubscribe as it may cause deadlocks when other things arrive while
  // sending and receiving acknowledgments. Instead, change a global variable,
  // or push to a queue and handle it in the loop after calling `client.loop()`.
}

void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  client.begin("uas-iot.cloud.shiftr.io", net);

  connect();
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity(); 

  String suhu = String(temp); //membuat variabel temp untuk di publish ke broker mqtt
  String kelembapan = String(hum); //membuat variabel hum untuk di publish ke broker mqtt

  client.loop();
  delay(10);  // <- fixes some issues with WiFi stability

  if (!client.connected()) {
    connect();
  }

  // publish a message roughly every second.
  if (millis() - lastMillis > 1000) {
    lastMillis = millis();

    client.publish("ucupp/iot/bed", suhu, true, 1);
    client.publish("ucupp/iot/living", suhu, true, 1);
    client.publish("ucupp/iot/kitchen", suhu, true, 1);
    client.publish("ucupp/iot/bath", suhu, true, 1);
    client.publish("ucupp/iot/gaming", suhu, true, 1);
    client.publish("ucupp/iot/gym", suhu, true, 1);
  }
}
