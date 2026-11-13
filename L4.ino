void setup(){
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  Serial.begin(9600);
}
void loop(){
  int temp=digitalRead(8);
  Serial.print("Intensity: ");
  Serial.println(temp);
  delay(300);
  if(temp==HIGH){
    digitalWrite(9,HIGH);
  }
  else digitalWrite(9,LOW);
}
