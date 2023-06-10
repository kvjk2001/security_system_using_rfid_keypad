// X_ray alert code
#include <SoftwareSerial.h>
#define BT_TX 2
#define BT_RX 3
SoftwareSerial BTSerial(BT_TX, BT_RX);

int irsensor_1 = 9;
int irsensor_2 = 5;
int buzzer_1 = 7;
int detect_led_1 = 12; 
int detect_led_2 = 13;
bool obj_detect_1 = false;
bool obj_detect_2 = false;
float duration_1;
float duration_2;
unsigned long detect_start_1;
unsigned long detect_start_2;

void setup() 
{
  pinMode (irsensor_1, INPUT); 
  pinMode (detect_led_1, OUTPUT); 
  pinMode (irsensor_2, INPUT); 
  pinMode (detect_led_2, OUTPUT);
  Serial.begin (9600);
  BTSerial.begin(9600); 
}

void loop()
{  
  int sensordata_1 = digitalRead (irsensor_1); 
  int sensordata_2 = digitalRead (irsensor_2); 

  if (sensordata_1 == 0) 
  {
    digitalWrite(detect_led_1, HIGH);
    digitalWrite(buzzer_1, HIGH);
      //if (sensordata_1 == 0 && !obj_detect_1)
      if (!obj_detect_1)
      {
      BTSerial.println(".........................................................................Inhalation Started_1 - Second ball reached maximum ");
      obj_detect_1 = true;
      detect_start_1 = millis();
      }
  
      //if(sensordata_1 == 0 && obj_detect_1)
      else
      {
      duration_1 = millis() - detect_start_1;
      }
  }

  else
  {
    digitalWrite(detect_led_1, LOW);
    digitalWrite(buzzer_1, LOW);
      if(obj_detect_1)
      {
      BTSerial.println("..........................................................................Inhalation Stopped_1 - Second ball dropped from maximum ");
      BTSerial.print(" Time for which Second ball threshold was met =  ");
      BTSerial.print(duration_1);
      BTSerial.print(" ms ");
      BTSerial.println();
      obj_detect_1 = false;
      }
  }



 if (sensordata_2 == 0) 
  {
    digitalWrite(detect_led_2, HIGH);
      //if (sensordata_2 == 0 && !obj_detect_2)
      if (!obj_detect_2)
      {
      BTSerial.println(" Third ball reached maximum ");
      obj_detect_2 = true;
      detect_start_2 = millis();
      }
  
      //if(sensordata_1 == 0 && obj_detect_1)
      else
      {
      duration_2 = millis() - detect_start_2;
      }
  }

  else
  {
    digitalWrite(detect_led_2, LOW);
      if(obj_detect_2)
      {
      BTSerial.println("Third ball dropped from maximum ");
      BTSerial.print(" Time for which Third ball threshold was met =  ");
      BTSerial.print(duration_2);
      BTSerial.print(" ms ");
      BTSerial.println();
      obj_detect_2 = false;
      }
  }
  
delay(5);
}
