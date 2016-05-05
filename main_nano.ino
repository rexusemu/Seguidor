#include <QTRSensors.h>
#define NUM_SENSORS   8    // number of sensors used
#define TIMEOUT       2500  // waits for 2500 microseconds for sensor outputs to go low
#define EMITTER_PIN   6     // emitter is controlled by digital pin 2


// sensors 0 through 7 are connected to digital pins 3 through 10, respectively
QTRSensorsRC qtrrc((unsigned char[]) {19, 18, 17, 16,15,14,11,12},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


//Pines digitales para los motores

//Motor 1
#define EN1 7


//Motor 2
#define EN2 8

//Especificación de velocidades constantes
        
int spdstr = 200;       //Velocidad recto
int spdstr_b = 150;     //Velocidad Atras
int spd_stop = 0;       //Paro
int spd2 = 55;          //curva -
int spd1 = 120;         //Velocidad de curva+

//Límite cambio de Blanco o negro
int limite = 600;

//Pines analógicos para el sensor  /Pines para sensores

#define SENSOR0 19
#define SENSOR1 18 
#define SENSOR2 17
#define SENSOR3 16
#define SENSOR4 15
#define SENSOR5 14
#define SENSOR6 11
#define SENSOR7 12



//Nombre de las funciones de movimiento
void movimiento_recto(int spdstr);
void movimiento_recto_b(int spdstr_b);
void movimiento_izquierda(int spd1,int spd2);
void movimiento_derecha(int spd1,int spd2);
void movimiento_stop(int spd_stop);

//FUNCIONES DE MOVIMIENTO

void movimiento_recto(int spdstr){
  digitalWrite(EN1,spdstr);                       //MOVIMIENTO EN DIRECCIÓN RECTA                         digitalWrite(IN1,spd);
  digitalWrite(EN2,spdstr);                                                                              //digitalWrite(IN2,spd);
}                                                                                                    

void movimiento_recto_b(int spdstr_b){
  digitalWrite(EN1,LOW);                         //MOVIMIENTO MARCHA ATRÁS
  digitalWrite(EN2,spdstr_b);
}

void movimiento_izquierda(int spd1,int spd2){
  digitalWrite(EN1,spd2);                       //MOVIMIENTO CURVA HACIA IZQUIERDA              
  digitalWrite(EN2,LOW);  
}

void movimiento_derecha(int spd1,int spd2){
  digitalWrite(EN1,LOW);                         //MOVIMIENTO CURVA HACIA DERECHA
  digitalWrite(EN2,spd1);
}

void movimiento_stop(int spd_stop){
  digitalWrite(EN1,LOW);                         //SIN MOVIMIENTO
  digitalWrite(EN2,LOW);                                                                                                                                            //JORGITO 2.016            
}

void setup(){
 //Entradas y salidas de los componentes
 
  pinMode(EN1,OUTPUT);       //MOTOR 1a
  pinMode(EN2,OUTPUT);       //MOTOR 1b

  pinMode(SENSOR0,INPUT);
  pinMode(SENSOR1,INPUT);
  pinMode(SENSOR2,INPUT);
  pinMode(SENSOR3,INPUT);
  pinMode(SENSOR4,INPUT);
  pinMode(SENSOR5,INPUT);
  pinMode(SENSOR6,INPUT);
  pinMode(SENSOR7,INPUT);
  Serial.begin(9600);
}

void loop(){
  
//Calibración arreu
  qtrrc.read(sensorValues);


//VARIABLES LECTURA SENSORES
//movimiento derecha

if (sensorValues[0] > limite)
  {
    movimiento_derecha(spd1,spd2);
  }

else if (sensorValues[1] > limite)
  {  
    movimiento_derecha(spd1,spd2);
  }

else if (sensorValues[2] > limite)
  {
    movimiento_derecha(spd1,spd2);
  }

else if (sensorValues[3] > limite && sensorValues[4] > limite)
  { 
    movimiento_recto(spdstr);
  }

else if (sensorValues[5] > limite)
  {
    movimiento_izquierda(spd1,spd2);
  }

else if (sensorValues[6] > limite)
  {
    movimiento_izquierda(spd1,spd2);
  }

else if (sensorValues[7] > limite)
  {
    movimiento_izquierda(spd1,spd2); 
  }

else if (sensorValues[0] < limite && sensorValues[1] < limite && sensorValues[2] < limite && sensorValues[3] < limite 
        && sensorValues[4] < limite && sensorValues[5] < limite && sensorValues[6] < limite && sensorValues[7] < limite)
  {
    movimiento_stop(spd_stop);
  }
  else {
    movimiento_derecha(spd1,spd2);
  }
}
