int Rectificacion=5;
int Vel=55 ;         //Velocidad porcentual de funcionamiento

int MIA = 9;      // Motor Izquierda terminal + (avanza)
int MIR = 10;     // Motor Izquierda terminal - (retrocede)
int MDA = 5;      // Motor Derecha terminal + (avanza)
int MDR = 6;      // Motor Derecha terminal - (retrocede)

int SD1 = 12;     // Sensor Derecha 1
int SD2 = 7;      // Sensor Derecha 2
int SD3 = 8;      // Sensor Derecha 3
int SD4 = 13;     // Sensor Derecha 4
int SI1 = 11;     // Sensor Izquierda 1 
int SI2 = 4;      // Sensor Izquierda 2 
int SI3 = 3;      // Sensor Izquierda 3
int SI4 = 2;      // Sensor Izquierda 4

int TD = A3;      // Sensor trasero Derecha
int TI = A2;      // Sensor trasero Izquierda

int LSD1 = 0;     // Lectura Sensor Derecha 1
int LSD2 = 0;     // Lectura Sensor Derecha 2
int LSD3 = 0;     // Lectura Sensor Derecha 3
int LSD4 = 0;     // Lectura Sensor Derecha 4
int LSI1 = 0;     // Lectura Sensor Izquierda 1
int LSI2 = 0;     // Lectura Sensor Izquierda 2
int LSI3 = 0;     // Lectura Sensor Izquierda 3
int LSI4 = 0;     // Lectura Sensor Izquierda 4
int LSD = 0;      // Resumen de sensores Derechos
int LSI = 0;      // Resumen de sensores Izquierdos


int LTD1 = 0;     // Lectura Sensor trasero Derecha (Analogico)
int LTI1 = 0;     // Lectura Sensor trasero Izquierda (Analogico)
int LTD  = 0;     // Lectura Sensor trasero Derecha (Digital)
int LTI  = 0;     // Lectura Sensor trasero Izquierda (Digital)


float VA  ;       //Velocidad de la rueda para avanzar
float VG  ;       //Velocidad de la rueda para girar
float VR  ;       //Velocidad de la rueda para retroceder
int Velocidad;
int Velocidad1;
int Velocidad2;
int Velocidad1X;
int Velocidad2X;
int SensorCentral;
int SensorIzquierdo1;
int SensorIzquierdo2;
int SensorIzquierdo3;
int SensorDerecho1;
int SensorDerecho2;
int SensorDerecho3;
int SensorPrueba;
int VelocidadRectificadora;

unsigned long ms;
unsigned long msr;
int Segundos;

int Posicion;
int Push = A7;    //Pulsador
int LPush = 0;    //Lectura del Pulsador
bool contador = false; //Variable para iniciar el programa
int flanco1=0;

int Lecturas_Sensores(bool imprimir)
{
  LSD1=digitalRead(SD1);    // Lectura del sensor derecho 1 es la lectura digital del Sensor derecho 1                      
  LSD2=digitalRead(SD2);    // Lectura del sensor derecho 1 es la lectura digital del Sensor derecho 2                      
  LSD3=digitalRead(SD3);    // Lectura del sensor derecho 1 es la lectura digital del Sensor derecho 3                      
  LSD4=digitalRead(SD4);    // Lectura del sensor derecho 1 es la lectura digital del Sensor derecho 4                      
  LSI1=digitalRead(SI1);    // Lectura del sensor izquierdo 1 es la lectura digital del Sensor izquierdo 1                  
  LSI2=digitalRead(SI2);    // Lectura del sensor izquierdo 1 es la lectura digital del Sensor izquierdo 2                  
  LSI3=digitalRead(SI3);    // Lectura del sensor izquierdo 1 es la lectura digital del Sensor izquierdo 3                  
  LSI4=digitalRead(SI4);    // Lectura del sensor izquierdo 1 es la lectura digital del Sensor izquierdo 4                  
  LTD1=analogRead(A3);      // Lectura del sensor trasero derecho es la lectura analogica del Sensor trasero derecho        
  LTI1=analogRead(A2);      // Lectura del sensor trasero izquierdo es la lectura analogica del Sensor trasero izquierdo    
                                                                                                                            
  LSI=LSI1&&LSI2&&LSI3&&LSI4;                                                                                                
  LSD=LSD1&&LSD2&&LSD3&&LSD4;                                                                                              
                                                                                                                            
  if (LTD1<600) LTD=0;      // Si la lectura LTDI es menor de 600 (detecta Blanco) igualo la LTD a 0
  else          LTD=1;      // Si la lectura LTDI es mayor de 600 (detecta Blanco) igualo la LTD a 1                                                                                                          
                        
   if (LTI1<600)LTI=0;      // Si la lectura LTDI es menor de 600 (detecta Blanco) igualo la LTD a 0                                                                                                                                                                                                                  
   else         LTI=1;      // Si la lectura LTDI es mayor de 600 (detecta Blanco) igualo la LTD a 1                 
  SensorCentral=LSI1||LSD1;
  SensorIzquierdo1=LSI1||LSI2;
  SensorIzquierdo2=LSI2||LSI3;
  SensorIzquierdo3=LSI3||LSI4;
  SensorDerecho1=LSD1||LSD2;
  SensorDerecho2=LSD2||LSD3;
  SensorDerecho3=LSD3||LSD4;
  SensorPrueba=LSI4||LSD4;
  
  if (SensorIzquierdo3==0) Posicion=-10;  
  if (SensorIzquierdo2==0) Posicion=-5;
  if (SensorIzquierdo1==0) Posicion=-2;
  if (SensorCentral==0)    Posicion=0;
  if (SensorDerecho1==0)   Posicion=2;
  if (SensorDerecho2==0)   Posicion=5;
  if (SensorDerecho3==0)   Posicion=10;

  
  if (imprimir==true)
  {
    Serial.print("");                                                                                                 
    Serial.print(LSI4);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSI3);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSI2);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSI1);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSD1);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSD2);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSD3);                                                                                                     
    Serial.print("-");                                                                                                   
    Serial.print(LSD4);                                                                                                     
    Serial.print("   ");                                                                                                    
    Serial.print(LTI);                                                                                                      
    Serial.print("-");                                                                                                    
    Serial.print(LTD);                                                                                                      
    Serial.print("   "); 
    Serial.print(SensorIzquierdo3);
    Serial.print("  ");
    Serial.print(SensorIzquierdo2);
    Serial.print("  ");  
    Serial.print(SensorIzquierdo1);
    Serial.print("  ");
    Serial.print(SensorCentral);
    Serial.print("  ");
    Serial.print(SensorDerecho1);
    Serial.print("  ");
    Serial.print(SensorDerecho2);
    Serial.print("  ");
    Serial.print(SensorDerecho3);
    Serial.print("       ");
    Serial.println(SensorPrueba);
                                                                                               
    //delay(2000);  
  }
}

 int Avanzar(int V1, int V2)              //Funcion que hace avanzar
{
  analogWrite(MIA,V2);
  analogWrite(MIR,0);
  analogWrite(MDA,V1);
  analogWrite(MDR,0);
}

    
int Retroceder(int VR)           //Funcion que hace retroceder
{  
  analogWrite(MIA,0);
  analogWrite(MIR,VR);
  analogWrite(MDA,0);
  analogWrite(MDR,VR);   
}

int Sigue_Lineas(int sec)
{                                                                                       
    if ((LSD==1)&&(LSI==1))        // Si todos los sensores frontales de la derecha y de la izquierda detectan blanco, retrocede buscando la linea
    {
      VR=50;
      //Retroceder(VR);
    }
    
    VelocidadRectificadora = Posicion * Rectificacion;
    Velocidad1 = Velocidad + VelocidadRectificadora;
    Velocidad2 = Velocidad + (VelocidadRectificadora*(-1));
    switch(Posicion)
    {
      case 0:
        Velocidad=Vel*2;
        break;
      case 2:
        Velocidad=Vel*1.5;
        break; 
      case -2:
        Velocidad=Vel*1.5;
        break; 
      case 5:
        Velocidad=Vel*1.2;
        break; 
      case -5:
        Velocidad=Vel*1.2;
        break; 
      case 10:
        Velocidad=Vel*1;
        break; 
      case -10:
        Velocidad=Vel*1;
        break; 
    }
}

void setup()
{
  //pinMode(MDA,OUTPUT);  // Declaro Patilla del motor derecho + como Salida
  //pinMode(MDR,OUTPUT);  // Declaro Patilla del motor derecho - como Salida
  //pinMode(MIA,OUTPUT);  // Declaro Patilla del motor izquierdo + como Salida
  //pinMode(MIR,OUTPUT);  // Declaro Patilla del motor izquierdo - como Salida
 
  pinMode (SD1,INPUT);  // Declaro el sensor derecho 1 como Entrada
  pinMode (SD2,INPUT);  // Declaro el sensor derecho 2 como Entrada
  pinMode (SD3,INPUT);  // Declaro el sensor derecho 3 como Entrada
  pinMode (SD4,INPUT);  // Declaro el sensor derecho 4 como Entrada
  pinMode (SI1,INPUT);  // Declaro el sensor izquierdo 1 como Entrada
  pinMode (SI2,INPUT);  // Declaro el sensor izquierdo 2 como Entrada
  pinMode (SI3,INPUT);  // Declaro el sensor izquierdo 3 como Entrada
  pinMode (SI4,INPUT);  // Declaro el sensor izquierdo 4 como Entrada
  pinMode (TD,INPUT);   // Declaro el sensor trasero derecho como Entrada
  pinMode (TI,INPUT);   // Declaro el sensor trasero izquierdo como Entrada
  Serial.begin(9600);     
}

void loop()
{
  LPush=analogRead(Push);
  if ((LPush<700)&&(flanco1==false))                  //Si pulso el pulsador, le doy a contador Valor 1
  { 
    contador = 1;
    flanco1=true;
    Serial.print(contador);
    Serial.print("  ");
    Serial.print(flanco1);
    Serial.print("  ");
    Serial.println(LPush);
  }
  if (contador==1)
  {
    flanco1=false;
    Lecturas_Sensores(false);
    Sigue_Lineas(100);
    Avanzar(Velocidad2,Velocidad1);
  }
    
    Serial.print(Posicion);
    Serial.print("  ");
    Serial.print(Velocidad1);
    Serial.print("  ");
    Serial.println(Velocidad2);
}
//la velocidad de giro perfecta 12 veces la lenta
