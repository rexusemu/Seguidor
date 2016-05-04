#include <QTRSensors.h>
#define NUM_SENSORS   8     // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   2     // emitter is controlled by digital pin 2

// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {19, 18, 17, 16,15,14,11,12},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];
int limite=500;
int vel=150;
int correccion=100;
int correccion1=100;
int retardo=100;

void setup() {

Serial.begin(9600); 
pinMode(8,OUTPUT);
pinMode(7,OUTPUT); 
pinMode(5,OUTPUT);  

pinMode(9,OUTPUT); 
pinMode(4,OUTPUT);  
pinMode(6,OUTPUT); 

}

void loop() {

   // read raw sensor values
  qtrrc.read(sensorValues);

  
 if (sensorValues[0] > limite){
    
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);

    digitalWrite(9,LOW);
    digitalWrite(4,HIGH);
    //delay(retardo);

    analogWrite(5,correccion);
    analogWrite(6,correccion1);

    //Serial.print("GIRA A LA IZQ3");Serial.print('\t');Serial.println();delay(250);
  }

  
   if (sensorValues[1] > limite){
    
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);

    digitalWrite(9,LOW);
    digitalWrite(4,HIGH);
    //delay(retardo);

    analogWrite(5,correccion);
    analogWrite(6,correccion1);

    //Serial.print("GIRA A LA IZQ2");Serial.print('\t');Serial.println();delay(250);
  }

  if (sensorValues[2] > limite){
    
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);

    digitalWrite(9,LOW);
    digitalWrite(4,HIGH);
    //delay(retardo);

    analogWrite(5,correccion);
    analogWrite(6,correccion1);

    //Serial.print("GIRA A LA IZQ1");Serial.print('\t');Serial.println();delay(250);
  }

  if (sensorValues[3] > limite){
    
    
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);

    digitalWrite(9,HIGH);
    digitalWrite(4,LOW);
    //delay(retardo);

    analogWrite(5,vel);
    analogWrite(6,vel);
     }
    //Serial.print("DELANTE");Serial.print('\t');Serial.println();delay(250);
   
   if (sensorValues[3] > limite){
     if (sensorValues[2] > limite){
    
    digitalWrite(8,HIGH);
    digitalWrite(7,LOW);

    digitalWrite(9,HIGH);
    digitalWrite(4,LOW);
    //delay(retardo);

    analogWrite(5,vel);
    analogWrite(6,vel);
     }
    //Serial.print("DELANTE");Serial.print('\t');Serial.println();delay(250);

  }

  if (sensorValues[4] > limite){
    
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);

    digitalWrite(9,HIGH);
    digitalWrite(4,LOW);
    //delay(retardo);

    analogWrite(5,correccion1);
    analogWrite(6,correccion);

    //Serial.print("GIRA A LA DER1");Serial.print('\t');Serial.println();delay(250);
    
  }

  if (sensorValues[5] > limite){
    
    digitalWrite(8,LOW);
    digitalWrite(7,HIGH);

    digitalWrite(9,HIGH);
    digitalWrite(4,LOW);
    //delay(retardo);

    analogWrite(5,correccion1);
    analogWrite(6,correccion);

    //Serial.print("GIRA A LA DER2");Serial.print('\t');Serial.println();delay(250);
    
  }   
  
}
