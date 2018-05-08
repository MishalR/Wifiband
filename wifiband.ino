
#include <ESP8266WiFi.h>
#include <ESP8266Ping.h>
#include <UniversalTelegramBot.h>
#define BOTtoken "393109425:AAGaiGZu_hJCj37jyTTnd2tQUllFWmItIV4"
#define CHAD_ID "304352658"
const char* ssid     = "Iserver";
const char* password = "jkdw34";
int   a=1;
int   b=1;
#define ledPin   D7

WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);


const IPAddress remote_ip(192, 168, 225, 71);

void setup() {
  Serial.begin(9600);
  delay(10);

  // We start by connecting to a WiFi network
    // the number of the LED pin
  Serial.println();
  Serial.println("Connecting to WiFi");

  WiFi.begin(ssid, password);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println();
  Serial.print("WiFi connected with ip ");
  Serial.println(WiFi.localIP());
  //bot.begin();
  //bot.sendMessage(m.chat_id, "Telegram test");

  Serial.print("Pinging ip ");
  Serial.println(remote_ip);
  pinMode(ledPin, OUTPUT);


}

void loop() {
 
   
  if (Ping.ping(remote_ip)&& a=1) {
    bot.sendMessage(CHAD_ID, "connected");
    Serial.println("Success!!");
    digitalWrite(ledPin, LOW);
    a=0;
    b=1;
  }
  if (!Ping.ping(remote_ip)&& b=1)  {
    bot.sendMessage(CHAD_ID, "disconnected");
    Serial.println("Error :(");
    digitalWrite(ledPin, HIGH);
    b=0;
    a=1;
  }
  delay(100);
}
