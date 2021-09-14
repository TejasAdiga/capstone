#include<time.h>

#define SENSORA 2
#define SENSORB 3
#define ACTION 4


byte data;
void setup() {
  // put your setup code here, to run once:
    Serial.begin(38400);
    pinMode(SENSORA, INPUT_PULLUP);
    pinMode(SENSORB, INPUT_PULLUP);
    pinMode(ACTION, OUTPUT);
}

void loop() 
{
    byte motor1=64,motor2=192;
    
    int L1=digitalRead(SENSORA);
    int L2=digitalRead(SENSORB);

    
    if(L1==1 and L2==1 and Serial.available() > 0)
    {
     
     data = Serial.read();
     
     digitalWrite(ACTION,LOW);   
    
     if(data==49)
     {
      
     motor1=75;
     Serial.write(motor1);
     motor2=203;
     Serial.write(motor2);
     
    }
    else if(data==50)
    {
     
     motor1=75;
     motor2=192;
     Serial.write(motor1);
     Serial.write(motor2);
     
     
    }
    else if(data==51)
    {
      
     motor1=64;
     motor2=203;
     Serial.write(motor1);
     Serial.write(motor2);
     
     
    }
    else 
    {
      
     motor1=64;
     motor2=192;
     Serial.write(motor1);
     Serial.write(motor2);
    
    }
   }

   else
   {
    digitalWrite(ACTION,HIGH);
    
    motor1=64;
    motor2=192;
    Serial.write(motor1);
    Serial.write(motor2);
   }
   
}
    
