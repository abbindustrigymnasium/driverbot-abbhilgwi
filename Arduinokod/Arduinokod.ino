#include "EspMQTTClient.h" //vad som behöver includas
#include <Servo.h>

#define motorPinDir  0//D2  //definear de som används
#define motorPinSpeed 5//D1

Servo servo;

void onConnectionEstablished(); //kör metoden

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


void setup() {  //setup körs en gång när koden startas, här deffinieras vad som in/output bl.a.
  servo.attach(14); //D5
  pinMode(motorPinDir, OUTPUT);
  pinMode(motorPinSpeed, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  Serial.begin(115200);
  servo.write(0);

  delay(2000);  //så att koden ska hinna köras innan programmet går vidare
}

bool off = false; //sätter boolen 'off' till false

void turn(bool left, int degrees) { //en metod som hanterar bilens svängning. Den kollar om bolen 'left' är true och sedan hur många degrees den ska svänga åt vänster, är 'left' false blir det istället höger

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

void drive(bool dir, int speed) { //en metod som hanterar bilens hastighet, 'dir' avgör om den ska frammåt eller bakått genom att vara true eller false medan 'speed' avgör hastigheten
  
  servo.write(90);
  Serial.println("Åk!");
  Serial.println(speed);
  digitalWrite(motorPinDir, dir);
  analogWrite(motorPinSpeed, speed);
  digitalWrite(LED_BUILTIN, dir);

}

void onConnectionEstablished()  //När den har lyckats connecta ska den subscribea. Den plockar ur första tecknet som förvaras i 'info' och längden som förvaras i 'length'
{                               //I 'value' förvaras allt utom första tecknet som görs om till int och förvaras i 'speed'. Den kollar om första tecknet är 'f' eller 'b' och kollar isåfall vilken av dem, 'f' -> kör framåt & 'b' kör bakåt
                                //Hastigheten, 'speed', används sedan i metoden 'drive' som förklaras ovan. På liknande sätt gör den ifall det första teknet skulle visa sig vara 'r' eller 'l', den avgör vilken av dem och svänger lika många grader som finns lagrade i 'speed' med hjälp av metoden 'turn'
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
