
const int LED_PIN = 2;
const int SENSOR = 3;
const int SENSOR_CONTROL = 4;

void setup(){
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
  pinMode(SENSOR_CONTROL, OUTPUT);
}

void loop(){
  //digitalWrite(LED_PIN, HIGH);
  if(Serial.available()){
    //digitalWrite(LED_PIN, HIGH);
    //setPin('h');
   //setPin(Serial.read());
   int input = Serial.read();
   Serial.println(input);
   setPin(input);
  }  
}

void setPin(int c){
  int val = 0;
  switch(c){
    case 104:
      digitalWrite(LED_PIN, HIGH);
      break;
    case 108:
      digitalWrite(LED_PIN, LOW);
      break;
    case 114:
      val = analogRead(SENSOR);
      digitalWrite(LED_PIN, HIGH);
      delay(2000)
      digitalWrite(LED_PIN, LOW);
      Serial.println(val);
      break;
    case 101:
      digitalWrite(SENSOR_CONTROL, HIGH);
      break;
    case 100:
      digitalWrite(SENSOR_CONTROL, LOW);
      break;
    default:
      break;
  }
}

