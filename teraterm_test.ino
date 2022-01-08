int potXPin = A0;               //x-axis pin connected to A0
int potYPin = A1;               //y-axis pin connected to A1
int potXValue = 0;              //digital value of joystick (0-1023)
int potYValue = 0;
int currXValue = 0;
int currYValue = 0;

void setup() 
{           
  Serial.begin(9600);
  pinMode(potXPin, INPUT);     //setting the joystick pins as inputs
  pinMode(potXPin, INPUT);
}

// when joystick is resting in middle, both values are roughly
// 1023 divided by 2

void loop() 
{  

    potXValue = analogRead(potXPin);    //reading analog value, ADC to digital value
    potYValue = analogRead(potYPin);
    if(currXValue != potXValue || currYValue != potYValue) {    //only want to write to serial communication port if joystick value is changing
      Serial.print("X Val: ");                
      Serial.print(potXValue);            //writing x-value
      Serial.print(", ");
      Serial.print("Y-Val: ");
      Serial.print(potYValue);            //writing y-value
      Serial.println();
    }
    currXValue = potXValue;     //updating currValue to ultimately check if joystick value is changing
    currYValue = potYValue; 
    delay(50);
  }


  
