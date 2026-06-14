int trigPin = 9;
int echoPin = 10;
int buzzerPin = 2;
int buttonPin = 7;
bool systemOn  = false;
long duration;
int distance;
int lastButtonState = LOW;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(buttonPin,INPUT_PULLUP);

}
void loop(){
  bool currentButtonState = digitalRead(buttonPin);
  if(lastButtonState == HIGH && currentButtonState == LOW) {
    systemOn = !systemOn;
    if (systemOn) {
      tone(buzzerPin , 1500,100);
      }
      else{
        tone(buzzerPin ,800,100);
      
      }
      
  }
     lastButtonState = currentButtonState;
     if (systemOn){
      digitalWrite(trigPin,LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin,HIGH);
      delayMicroseconds(10);
      
      duration = pulseIn(echoPin,HIGH);
    
      distance = duration * 0.034 / 2;
      if (distance < 20){
        tone(buzzerPin,1000);
      }
      else if (distance < 50){
        tone(buzzerPin , 500);
      }
      else {
        noTone(buzzerPin);
      }
     }
  Serial.println(distance);
}
