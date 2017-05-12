
const int LED_PIN = 2;
const int LED_CONTROL_PIN = 4;
const int SENSOR = 3;
const int SENSOR_CONTROL = 4;
const int WATERPUMP_HUMIDITY_TRESHOLD = 600;

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
      digitalWrite(SENSOR_CONTROL, HIGH);
      delay(2000);
      val = getAverageHumidityAndEnablePump(false);
      delay(1000);
      digitalWrite(SENSOR_CONTROL, LOW);
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

int getAverageHumidityAndEnablePump(boolean enablePump){
  int const NUMBER_OF_MEASUREMENTS=10;
  int data[NUMBER_OF_MEASUREMENTS];
  int sumOfMeasurements=0;
  for(int i=0; i<NUMBER_OF_MEASUREMENTS; i++){
    data[i]=analogRead(SENSOR);
    sumOfMeasurements+=data[i];
    delay(2000);
  }
  int average = sumOfMeasurements/NUMBER_OF_MEASUREMENTS;
  if(enablePump){
    if(average>WATERPUMP_HUMIDITY_TRESHOLD) enableWaterPump();
  }
  return average;
}

void enableWaterPump(){
  digitalWrite(LED_PIN, HIGH);
  delay(7000);
  digitalWrite(LED_PIN, LOW);
}

