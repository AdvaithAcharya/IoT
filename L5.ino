#define PIEZO_PIN 9
const int trigger=6;
const int echo=7;
const int soundPin=A0;
float dist_inches;
const float DIST_THRESHOLD=5.0;
const int SOUND_THRESHOLD=520;
void setup(){
  Serial.begin(9600);
  pinMode(trigger,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(PIEZO_PIN,OUTPUT);
}
void loop(){
  digitalWrite(trigger,LOW);
  delayMicroseconds(5);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  float duration=pulseIn(echo,HIGH);
  dist_inches=duration*0.00675;
  int soundValue=analogRead(soundPin);
  if(dist_inches<DIST_THRESHOLD && soundValue>SOUND_THRESHOLD){
    tone(PIEZO_PIN,1500);
    delay(200);
    noTone(PIEZO_PIN);
    Serial.print("Intrusion detected! Object with sound at distance: ");
    Serial.print(dist_inches);
    Serial.println(" inches");
  }
  else if(soundValue>SOUND_THRESHOLD){
    Serial.println("Sound detected!");
  }
  else{
    Serial.println("No intrusion detected");
  }
  delay(200);
}
