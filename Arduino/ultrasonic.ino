const int pingPin = 6;
int inPin = 5;
void setup() {
Serial.begin(9600);
 pinMode(7, OUTPUT);
}
void loop()
{
long duration, cm;
pinMode(pingPin, OUTPUT);
digitalWrite(pingPin, LOW);
delayMicroseconds(2);
digitalWrite(pingPin, HIGH);
delayMicroseconds(5);
digitalWrite(pingPin, LOW);
pinMode(inPin, INPUT);
duration = pulseIn(inPin, HIGH);
cm = microsecondsToCentimeters(duration);
  if(cm < 150 && cm >70)
  {
    tone(7, 1000);
    digitalWrite(7,HIGH);
    delay(100);
    noTone(7);
    delay(100);
  }
  else if(cm <= 70)
  {
    tone(7, 1000);
    digitalWrite(7,HIGH);
  }
  else
  {
    noTone(7);
    digitalWrite(7,LOW);
  }
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(100);
}
long microsecondsToCentimeters(long microseconds)
{
// The speed of sound is 340 m/s or 29 microseconds per centimeter.
// The ping travels out and back, so to find the distance of the
// object we take half of the distance travelled.
return microseconds / 29 / 2;
}
