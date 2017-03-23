String readString;
#include <Servo.h> 
Servo myservo;

void setup() 
{
  Serial.begin(9600);
  myservo.attach(27);  //the pin for the servo control 
  Serial.println("servo-test"); // so I can keep track of what is loaded
}

void loop()
{
  while (Serial.available())
  {
    delay(11);  
    if (Serial.available() >0)
    {
      char c = Serial.read();  //gets one byte from serial buffer
      readString += c; //makes the string readString
    } 
  }

  if (readString.length() >0)
  {
    Serial.println(readString);  //so you can see the captured string 
    int n;
    char carray[6]; //converting string to number
    readString.toCharArray(carray, sizeof(carray));
    n = atoi(carray); 
    myservo.writeMicroseconds(n); // for microseconds
    myservo.write(n); //for degees 0-180
    readString="";
  } 
}

