const int led[]={2,3,4,5,6};
const int n=5;
void setup(){
  for(int i=0;i<n;i++){
    pinMode(led[i],OUTPUT);
  }
}
void loop(){
  for(int i=0;i<n;i++){
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
  }
  for(int i=n-1;i>=0;i--){
    digitalWrite(led[i],HIGH);
    delay(200);
    digitalWrite(led[i],LOW);
  }
}
