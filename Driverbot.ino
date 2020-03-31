#include "EspMQTTClient.h"
#include <Servo.h>

#define motorPinDir  0//D2
#define motorPinSpeed 5//D1

Servo servo;

void onConnectionEstablished();

EspMQTTClient client(
  "ASUS",           // Wifi ssid
  "Svantevante21",           // Wifi password
  "maqiatto.com",  // MQTT broker ip
  1883,             // MQTT broker port
  "hilda.gwiten@abbindustrigymnasium.se",            // MQTT username
  "12341234",       // MQTT password
  "MinRobotbil",          // Client name
  onConnectionEstablished, // Connection established callback
  true,             // Enable web updater
  true              // Enable debug messages
);


void setup() {
  servo.attach(14); //D5
  pinMode(motorPinDir, OUTPUT);
  pinMode(motorPinSpeed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  servo.write(0);

  delay(2000);
}

bool off = false;

void turn(bool left, int degrees) {

  if (left == true)
  {
    degrees -= 90;
    if (degrees < 0)
    {
      degrees = 0;
      digitalWrite(motorPinDir, 1);
      analogWrite(motorPinSpeed, 1000);
    }
    servo.write(degrees);
    Serial.println("Vänster!");
  }
  else
  {
    degrees += 90;
    if (degrees > 180)
    {
      degrees = 180;
      digitalWrite(motorPinDir, 1);
      analogWrite(motorPinSpeed, 1000);
    }
    servo.write(degrees);
    Serial.println("Höger!");
  }
  Serial.println(degrees);
}

void drive(bool dir, int speed) {
  
  servo.write(90);
  Serial.println("Åk!");
  Serial.println(speed);
  digitalWrite(motorPinDir, dir);
  analogWrite(motorPinSpeed, speed);
  digitalWrite(LED_BUILTIN, dir);

}

void onConnectionEstablished()
{

  client.subscribe("hilda.gwiten@abbindustrigymnasium.se/drive", [] (const String & payload)
  {
    char info = payload.charAt(0);
    int length = payload.length();
    String value = payload.substring(1, length);
    int speed = value.toInt();
    if (info == 'f' || info == 'b'  )
    {
      bool dir = false;
      if (info == 'f')
        dir = true;
      drive(dir, speed);
    }
    else if (info == 'r' || info == 'l'  )
    {
      bool dir = false;
      if (info == 'l')
        dir = true;
      turn(dir, speed);
    }
    Serial.println(payload);

  });

  client.publish("hilda.gwiten@abbindustrigymnasium.se/drive", "Meddelande 1");

  client.executeDelayed(5 * 1000, []() {
    client.publish("hilda.gwiten@abbindustrigymnasium.se/drive", "Meddelande 2");
  });
}


void loop() {
  
  client.loop();
}
