

const int button_Pin = 2;     // the number of the pushbutton pin
const int led_Pin =  13;      // the number of the LED pin
const int analogInput_Pin=0; //Data out of the Analog sensor is connected in Arduino's analog Pin A0

void setup() {
  // initialize the LED pin as an output:
  pinMode(led_Pin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(button_Pin, INPUT);
  // opens serial port, sets data rate to 9600 bps
  Serial.begin(9600);
}


void Check_Button(int ledPin,int buttonPin){
  
  int Button_State = 0; // variable for reading the pushbutton status
  
  // read the state of the pushbutton value:
  Button_State = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (Button_State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
    Serial.print("pressed");
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
    Serial.print("Not pressed");
  }
}

void CalcTemperature(int analogInputPin){
  
  float sensor_Temp = 0.0;  // For storing raw data from the Analog sensor
  float Temperature = 0.0; // For storing the converted temperature
  sensor_Temp = analogRead(analogInputPin); // Reads sensor data from pin A0
  Temperature = sensor_Temp * 0.48875855; //(+Vcc * 1000 / 1023) / 10

  Serial.print("Temperature = ");
  Serial.print(Temperature);
  Serial.print(" C\n"); 
}
void loop() {
  
Check_Button(led_Pin,button_Pin);
delay(1500); // Temperature is printed in the Serial Monitor every 3 seconds
CalcTemperature(analogInput_Pin);
delay(1500); // Temperature is printed in the Serial Monitor every 3 seconds

}


