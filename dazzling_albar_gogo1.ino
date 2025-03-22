
#include<LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Define pins for ultrasonic sensors
#define sensor1 10
#define sensor2 9
#define sensor3 8

int distancethreshold = 100;

void setup()
{
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  Serial.begin(9600);
}

// Function to read distance from ultrasonic sensor using 1 pin
long readdistance(int sensorPin)
{
  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, LOW);
  delayMicroseconds(2);
  digitalWrite(sensorPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPin, LOW);

  pinMode(sensorPin, INPUT);
  long duration = pulseIn(sensorPin, HIGH);
  return (duration * 0.0343) / 2;  // Convert to distance in cm
}

void loop()
{
  float d1 = readdistance(sensor1);
  float d2 = readdistance(sensor2);
  float d3 = readdistance(sensor3);

  Serial.println("d1 = " + String(d1) + " cm");
  Serial.println("d2 = " + String(d2) + " cm");
  Serial.println("d3 = " + String(d3) + " cm");

  lcd.clear();

  if (d1 > distancethreshold && d2 > distancethreshold && d3 > distancethreshold)
  {
    lcd.setCursor(0, 0);
    lcd.print("3 slots are free");
    lcd.setCursor(0, 1);
    lcd.print("Slots 1 2 3 are free");
  }
  else if ((d1 > distancethreshold && d2 > distancethreshold) ||
           (d2 > distancethreshold && d3 > distancethreshold) ||
           (d3 > distancethreshold && d1 > distancethreshold))
  {
    lcd.setCursor(0, 0);
    lcd.print("2 slots are free");
  }
  else if (d1 > distancethreshold || d2 > distancethreshold || d3 > distancethreshold)
  {
    lcd.setCursor(0, 0);
    lcd.print("1 slot is free");
  }
  else
  {
    lcd.setCursor(0, 0);
    lcd.print("No slots free");
  }

  delay(1000);
}

          
                               
           
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  
  

  