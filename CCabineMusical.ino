#include <Adafruit_MLX90614.h>
int pinLed = 10;
long delayTime = 500;
int frequency = 82;
const int CONST_DELAY_REFINEMENT = 100;
short temporaryConverter = 4;
Adafruit_MLX90614 mlx = Adafruit_MLX90614();
float readedTemp = 0;

long setNewFrequency(long delayTime){
  return delayTime * CONST_DELAY_REFINEMENT/ frequency;
}

int loadFrequency(){
  readedTemp = mlx.readObjectTempC();
  //if(howManyTimesWasReaded == 5)
  //{
  //  howManyTimesWasReaded = 0;
    //frequency = 110;
    frequency = temporaryConverter * (int)readedTemp;
  //}
  //howManyTimesWasReaded++;
}

void setup()
{
  pinMode(pinLed, OUTPUT);
  mlx.begin();
  Serial.begin(9600);
}
  
void loop()
{
  loadFrequency();
  digitalWrite(pinLed, HIGH);
  delay(delayTime);
  digitalWrite(pinLed, LOW);
  delay(setNewFrequency(delayTime));
  if (Serial.availableForWrite())
  {
    Serial.write(frequency);
  }
}