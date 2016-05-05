#include <QTRSensors.h>
#define NUM_SENSORS   8    // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   6     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {19, 18, 17, 16,15,14,11,12},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


void setup()

void loop() {

   // read raw sensor values
  qtrrc.read(sensorValues);

  
 if (sensorValues[0] > limite){
    
    digitalWrite(7,255);
    digitalWrite(9,LOW);

    digitalWrite(8,LOW);
    digitalWrite(10,255);
    //delay(retardo);
    //Serial.print("GIRA A LA IZQ3");Serial.print('\t');Serial.println();delay(250);
  }

  
   if (sensorValues[1] > limite){
    
    digitalWrite(7,vel);
    digitalWrite(9,LOW);

    digitalWrite(8,LOW);
    digitalWrite(10,vel);
    //delay(retardo);

    //Serial.print("GIRA A LA IZQ2");Serial.print('\t');Serial.println();delay(250);
  }

  if (sensorValues[2] > limite){
    
  digitalWrite(7,vel);
    digitalWrite(9,LOW);
    
    digitalWrite(8,LOW);
    digitalWrite(10,vel);
    //delay(retardo);
    //Serial.print("GIRA A LA IZQ1");Serial.print('\t');Serial.println();delay(250);
  }

  if (sensorValues[3] > limite){
    
    
    digitalWrite(7,vel);
    digitalWrite(9,LOW);

    digitalWrite(8,vel);
    digitalWrite(10,LOW);
    //delay(retardo);

     }
    //Serial.print("DELANTE");Serial.print('\t');Serial.println();delay(250);
   
   if (sensorValues[3] > limite){
     if (sensorValues[2] > limite){
    
    digitalWrite(7,vel);
    digitalWrite(9,LOW);

    digitalWrite(8,vel);
    digitalWrite(10,LOW);
    //delay(retardo);

        }
    //Serial.print("DELANTE");Serial.print('\t');Serial.println();delay(250);

  }

  if (sensorValues[4] > limite){
    
    digitalWrite(7,LOW);
    digitalWrite(9,vel);

    digitalWrite(8,vel);
    digitalWrite(10,LOW);
    //delay(retardo);

    //Serial.print("GIRA A LA DER1");Serial.print('\t');Serial.println();delay(250);
    
  }

  if (sensorValues[5] > limite){
    
    digitalWrite(7,LOW);
    digitalWrite(9,vel);

    digitalWrite(8,vel);
    digitalWrite(10,LOW);
    //delay(retardo);

   
    //Serial.print("GIRA A LA DER2");Serial.print('\t');Serial.println();delay(250);
    
  }   
  
}
