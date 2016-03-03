
#include <QTRSensors.h>                                                                                                                                                //JORGITO 2.016
#define NUM_SENSORS 6
#define NUM_SAMPLES_PER_SENSOR 4
#define EMITTER_PIN 2

//PWM Defenicion de pines digitales(POWER)			//provisional
//#define EN1 6
//#define EN2 11

//Pines digitales para los motores

//Motor 1
#define IN1 3
#define IN2 5

//Motor 2
#define IN3 10
#define IN4 9

//Pines analógicos para el sensor  
#define SENSOR2 A0
#define SENSOR3 A1
#define SENSOR4 A2        //Los pines 1,8 se dejan sin conectar
#define SENSOR5 A3
#define SENSOR6 A4
#define SENSOR7 A5

//sensores 2,3
int sensor_izquierdo_data = 0;	//IZQUIERDA
int sensor_izquierdo_data2 = 0;

//sensores 4,5
int sensor_central_data = 0;
int sensor_central_data2 = 0;    //LOS DE 4,5 SON DEL CENTRO

//sensores 6,7
int sensor_derecho_data = 0;
int sensor_derecho_data2 = 0;    	//DERECHA

//Recepción sensores 2,3
int lectura_sensor_izquierdo_data();
int lectura_sensor_izquierdo_data2();

//Recepción sensores 4,5
int lectura_sensor_central_data();
int lectura_sensor_central_data2();

//Recepción sensores 6,7
int lectura_sensor_derecho_data();
int lectura_sensor_derecho_data2();


//Nombre de las funciones de movimiento
void movimiento_recto(int spdstr);
void movimiento_recto_b(int spdstr_b);
void movimiento_izquierda(int spd1);
void movimiento_derecha(int spd1);
void movimiento_stop(int spd_stop);

//FUNCIONES DE MOVIMIENTO

void movimiento_recto(int spdstr){
  analogWrite(IN1,spdstr);                       //MOVIMIENTO EN DIRECCIÓN RECTA                         analogWrite(IN1,spd);
  analogWrite(IN2,0);                                                                              //analogWrite(IN2,spd);
  analogWrite(IN3,spdstr);
  analogWrite(IN4,0);
}                                                                                                    

void movimiento_recto_b(int spdstr_b){
  analogWrite(IN1,0);                         //MOVIMIENTO MARCHA ATRÁS
  analogWrite(IN2,spdstr_b);
  analogWrite(IN3,0);
  analogWrite(IN4,spdstr_b);
}

void movimiento_izquierda(int spd1){
  analogWrite(IN1,spd1);                       //MOVIMIENTO CURVA HACIA IZQUIERDA              
  analogWrite(IN2,0);                                                                                 
  analogWrite(IN3,spd1);
  analogWrite(IN4,0);
}

void movimiento_derecha(int spd1){
  analogWrite(IN1,0);                         //MOVIMIENTO CURVA HACIA DERECHA
  analogWrite(IN2,spd1);
  analogWrite(IN3,0);
  analogWrite(IN4,spd1);
}

void movimiento_stop(int spd_stop){
  analogWrite(IN1,0);                         //SIN MOVIMIENTO
  analogWrite(IN2,0); 
  analogWrite(IN3,0);
  analogWrite(IN4,0);                                                                                                                                             //JORGITO 2.016            
}


//LECTURA DE SENSORES CON BUCLE

int lectura_sensor_derecho_data(){
  int data = 0;
  data += analogRead(SENSOR6);             //LECTURA SENSOR-6
  return data;
  }

  int lectura_sensor_derecho_data2(){
  int data = 0;
  data += analogRead(SENSOR7);             //LECTURA SENSOR-7
  return data;
  }


int lectura_sensor_izquierdo_data(){
  int data = 0;
  data += analogRead(SENSOR2);                //LECTURA SENSOR-2
  return data;
  }

  int lectura_sensor_izquierdo_data2(){
  int data = 0;
  data += analogRead(SENSOR3);                //LECTURA SENSOR-3
  return data;
  }



int lectura_sensor_central_data(){
  int data = 0;
  data += analogRead(SENSOR4);             //LECTURA SENSOR-4 x2
  return data;
  }



int lectura_sensor_central_data2(){
  int data = 0;
  data += analogRead(SENSOR5);             //LECTURA SENSOR-5 x2
  return(data);
  }



//Especificación de velocidades constantes
int spd_low = 0;        //LOW EN IN DEL DRIVER         
int spd1 = 125;         //Velocidad de curva
int spdstr = 255;       //Velocidad recto
int spdstr_b = 150;     //Velocidad Atras
int spd_stop = 0;       //Paro

void setup(){
 //Entradas y salidas de los componentes
 
 //pinMode(EN1,OUTPUT);	     //ENABLE1  MOTOR 1    	(provisional)
 //pinMode(EN2,OUTPUT);	     //ENABLE2  MOTOR 2
 //pinMode(OUT1,OUTPUT);     //SALIDA1  MOTOR 1 
 //pinMode(OUT2,OUTPUT)      //SALIDA2  MOTOR 1
 //pinMode(OUT3,OUTPUT);     //SALIDA1  MOTOR 2               
 //pinMode(OUT4,OUTPUT);     //SALIDA2  MOTOR 2
  pinMode(IN1,OUTPUT);       //MOTOR 1a
  pinMode(IN2,OUTPUT);       //MOTOR 1b
  pinMode(IN3,OUTPUT);       //MOTOR 2a
  pinMode(IN4,OUTPUT);       //MOTOR 2b
  pinMode(SENSOR2,INPUT);
  pinMode(SENSOR3,INPUT);
  pinMode(SENSOR4,INPUT);
  pinMode(SENSOR5,INPUT);
  pinMode(SENSOR6,INPUT);
  pinMode(SENSOR7,INPUT);
  Serial.begin(9600);
  /*digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN3,LOW);       Sólo en digital
  digitalWrite(IN4,HIGH);
  /*/
}

void loop(){
               //ASOCIACIÓN DE SENSORES Y SU RECEPCIÓN
  
 sensor_izquierdo_data = lectura_sensor_izquierdo_data();          //SENSOR2
 sensor_izquierdo_data2 = lectura_sensor_izquierdo_data2();        //SENSOR3
 sensor_central_data = lectura_sensor_central_data();              //SENSOR4
 sensor_central_data2 = lectura_sensor_central_data2();            //SENSOR5
 sensor_derecho_data = lectura_sensor_derecho_data();              //SENSOR6
 sensor_derecho_data2 = lectura_sensor_derecho_data2();            //SENSOR7

  

  //REVISAR VALORES DE UMBRALES
  //CONDICIONALES BASE DE LECTURA DE LOS SENSORES

  //GIROS IZQUIERDA
  
  if(sensor_izquierdo_data > 375 && sensor_izquierdo_data2 > 375 && sensor_central_data < 375 
  && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)
  {                                                                                          //Sensores 2,3 en negro, 4,5,6,7 en blanco. Gira a la izquierda.
    movimiento_izquierda(spd1);                                                                         //Asignada velocidad de curva "spd1" en 120
  }
  else if(sensor_izquierdo_data > 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375 
  && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)
    {                                                                                        //Sensor 2 en negro, 3,4,5,6,7 en blanco. Gira a la izquierda.
            
      movimiento_izquierda(spd1);                                                                      //Asignada velocidad de curva "spd1" en 120
    }
  else if(sensor_izquierdo_data > 375 && sensor_izquierdo_data2 > 375 && sensor_central_data > 375 
  && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)       //Sensores 2,3,4 en negro, 5,6,7 blanco. Gira Izquierda
  {
    movimiento_izquierda(spd1);
  }
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 > 375 && sensor_central_data > 375 
  && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)      //Sensores 3,4 en negro, 2,5,6,7 blanco. Gira Izquierda
  {
    movimiento_izquierda(spd1);
  }

  //GIROS DERECHA
  
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375
      && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 > 375)  //Sensor 7 negro, 2,3,4,5,6 blanco. Gira a la derecha
     {
      movimiento_derecha(spd1);
     }
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375
      && sensor_central_data2 < 375 && sensor_derecho_data > 375 && sensor_derecho_data2 > 375)   //Sensores 7,6 en negro, 2,3,4,5 blanco. Gira a la derecha
      {
        movimiento_derecha(spd1);
      }
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375
      && sensor_central_data2 > 375 && sensor_derecho_data > 375 && sensor_derecho_data2 > 375)   //Sensores 5,6,7 en negro, 2,3,4 blanco. Gira a la derecha
      {
        movimiento_derecha(spd1);
      }
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375
      && sensor_central_data2 > 375 && sensor_derecho_data > 375 && sensor_derecho_data2 < 375)   //Sensores 5,6 en negro, 2,3,4,7 blanco. Gira a la derecha
      {
        movimiento_derecha(spd1);
      }


   //LÍNEA RECTA
   
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data > 375
      && sensor_central_data2 > 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)    //Sensores centrales 4,5 en negro, 2,3,6,7 blanco. Va hacia delante.
  {
    movimiento_recto(spdstr);
  }

  //MARCHA ATRÁS
  
  else if(sensor_izquierdo_data < 375 && sensor_izquierdo_data2 < 375 && sensor_central_data < 375
      && sensor_central_data2 < 375 && sensor_derecho_data < 375 && sensor_derecho_data2 < 375)   //Todos los sensores en blanco. Para y da marcha atrás.
      {                                 
        movimiento_stop(spd_stop);                                                                         //Función de parar
      }
  else
  {
        movimiento_recto_b(spdstr_b);                                                           //Asignada velocidad de línea recta MARCHA ATRÁS "spdstr_b" en 150
    
  }
}






