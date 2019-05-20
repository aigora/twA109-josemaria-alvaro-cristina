const int Trigger = 5;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor
#include <SoftwareSerial.h>
SoftwareSerial BT1(4,2);

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  BT1.begin(9600);
  pinMode(12,OUTPUT);
}

void loop()
{
  char modo;
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);
  
  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t/59;             //escalamos el tiempo a una distancia en cm
  
 
 if (BT1.available())
 modo=BT1.read();

 if (BT1.available())
     Serial.write(modo);
 switch (modo){
 case 'a':
{ if (d<20){
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
    BT1.println("PELIGRO");
    delay(589);  
  }else
  digitalWrite(11,LOW);
  break;
}
case 'b':
{ if (d<20){
  digitalWrite(11,LOW);
  digitalWrite(12,HIGH);
    BT1.println("PELIGRO");
    delay(589);  
  }else
  digitalWrite(12,LOW);
  break;
}
case 'c':
{ if (d<20){
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
    BT1.println("PELIGRO");
    delay(589);  
  }else
 { digitalWrite(11,LOW);
  digitalWrite(12,LOW);}
  break;}
default:
{if (d<20){
    BT1.println("PELIGRO");
    delay(589);  
  }else
  {BT1.println("DESPEJADO");
  delay(600);
  break;}
}
}
 }
