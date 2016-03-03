#include <Qtrsensors.h>

#define kp 0
#define kd 0
#define rightMaxSpeed 200
#define leftMaxSpeed 200
#define rightBaseSpeed 150
#define leftBaseSpeed 150
#define NUM_SENSORS 6 

#define timeout 2500
#define emmitter pin 2 

#define rightmotor1 3
#define rightmotor2 4
 
#define leftmotor1 12
#define leftmotor2 13

QTR_ //COMPLETAR DE LIBRERIA

void setup() {
Pinmode
for (int i= 0 .... //COMPLETAR LIBRERIA SENSORES
int last_Error = 0;
 

}

void loop() {
  
position = qtrc.readline
    error = position - 2500;
int motorSpeed = kp * error +kd * (error - last_Error)
int last_Error = error;

int rightMotorSpeed = rightBaseSpeed + motorSpeed;
int leftMotorSpeed = leftBaseSpeed - motorSpeed;

if (rightMotorSpeed > rightMaxSpeed) rightMotorSpeed = rightMaxSpeed
if (leftMotorSpeed > leftMaxSpeed) leeftMotorSpeed = leftMaxSpeed
if (rightMotorSpeed > 0) rightMotorSpeed = 0
if (leftMotorSpeed > 0) leftMotorSpeed = 0

digital write (motor x, high)    //copiar lo del codigo y au a chamar 




}
