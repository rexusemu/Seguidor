#include <QTRSensors.h>

#define NUM_SENSORS   8     // Numero de sensores 
#define TIMEOUT       2500  //Esperar 2500 segundos para lectura de sensores
#define EMITTER_PIN   2     // LED on 

//Pines LED
#define led1          13 
#define led2          4 

#define boton_1       2  //pin para boton

//Pines motores
#define MOT1_IN1 7  //MOTOR DERECHO
#define MOT1_IN2 9  //MOTOR DERECHO

#define MOT2_IN1 8  //MOTOR IZQUIERDO
#define MOT2_IN2 10 //MOTOR IZQUIERDO

//Pines para sensores
#define SENSOR1 19
#define SENSOR2 18 
#define SENSOR3 17
#define SENSOR4 16
#define SENSOR5 15
#define SENSOR6 14
#define SENSOR7 11
#define SENSOR8 12

//Variables Sensores
int left_sensor_data = 0;
int right_sensor_data = 0;
int center_sensor_data = 0;
//Velocidades
int spd = 0;
int spdstr = 255;

QTRSensorsRC qtrrc((unsigned char[]) {19, 18, 17, 16,15,14,11,12},
  NUM_SENSORS, TIMEOUT, EMITTER_PIN); 
unsigned int sensorValues[NUM_SENSORS];


void setup()
{
  pinMode(MOT1_IN1,OUTPUT);
  pinMode(MOT1_IN2,OUTPUT);
  pinMode(MOT2_IN1,OUTPUT);
  pinMode(MOT2_IN2,OUTPUT);
  
  pinMode(SENSOR1,INPUT);
  pinMode(SENSOR2,INPUT);
  pinMode(SENSOR3,INPUT);
  pinMode(SENSOR4,INPUT);
  pinMode(SENSOR5,INPUT);
  pinMode(SENSOR6,INPUT);
  pinMode(SENSOR7,INPUT);
  pinMode(SENSOR8,INPUT);
  
  digitalWrite(MOT1_IN1,LOW);
  digitalWrite(MOT1_IN2,HIGH);
  digitalWrite(MOT2_IN1,LOW);
  digitalWrite(MOT2_IN2,HIGH);
  Serial.begin(9600);
  
  delay(800);
 pinMode(led1, OUTPUT); //led1
 pinMode(led2, OUTPUT); //led2
        pinMode(boton_1, INPUT); //boton 1 para empezar
        
        for (int i = 0; i < 40; i++)  //calibracion durante 2.5 segundos,
 {                                 //para calibrar es necesario colocar los sensores sobre la superficie negra y luego la blanca
  digitalWrite(led1, HIGH); 
                delay(20);
  qtrrc.calibrate();    //funcion para calibrar sensores   
  digitalWrite(led1, LOW);  
                delay(20);
 }
        digitalWrite(led1, LOW); //apagar sensores para indicar fin 
                                  //de calibracion 
        delay(400); 
        digitalWrite(led2,HIGH); //encender led 2 para indicar la
                                 // espera  de pulsacion de boton
       
        while(true)
        {
          int x=digitalRead(boton_1); //leemos y guardamos el valor del boton
                                      
                                      delay(100);
          if(x==0) //si se presiona boton 
          {
             digitalWrite(led2,LOW); //indicamos que se presiono boton
             digitalWrite(led1,HIGH); //encendiendo led 1
             delay(100);
             break; //saltamos hacia el bucle principal
          }
        }
}       
void loop() {
  
  left_sensor_data = get_sensor_left_data();
  right_sensor_data = get_sensor_right_data();
  center_sensor_data = get_sensor_center_data();
  
  if(left_sensor_data > 375 && right_sensor_data < 375){
    spd = map(left_sensor_data,0,3000,0,255);
    move_left(spd);
  }
  else{
    if(right_sensor_data > 375 && left_sensor_data < 375){
      spd = map(right_sensor_data,0,3000,0,255);
      move_right(spd);
    }
    else{
      if(right_sensor_data > 375 && left_sensor_data > 375){
        move_stop();
      }
      else
        move_straight(spdstr);
    }
  }
  delay(50);
  //Serial.println(sensor_data);
  //delay(1000);
  /*move_straight(255);
  delay(2000);
  move_straight(0);
  delay(1000);
  move_left(255); 
  delay(1000);
  move_straight(255);
  delay(2000);*/
}
int get_sensor_right_data(){
  int data = 0;
  data += analogRead(SENSOR4);
  data += (analogRead(SENSOR5)*2);
  return data;
  
}

int get_sensor_left_data(){
  int data = 0;
  data += analogRead(SENSOR1);
  data += (analogRead(SENSOR2)*2);
  return data;
}

int get_sensor_center_data(){
  int data = 0;
  data += analogRead(SENSOR3);
  return data;

}

void move_straight(int spd){  //Movimiento recto
  analogWrite(MOT1_IN1,spd);
  analogWrite(MOT2_IN1,spd);
}

void move_left(int spd){      //Movimiento Izquierdo
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT2_IN1,spd);
}

void move_right(int spd){     //Movimiento Derecho
  analogWrite(MOT1_IN1,spd);
  analogWrite(MOT2_IN1,0);
}

void move_stop(){             //Parada
  analogWrite(MOT1_IN1,0);
  analogWrite(MOT1_IN2,0);
  analogWrite(MOT2_IN1,0);
  analogWrite(MOT2_IN2,0);
}

