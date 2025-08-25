#include "funciones.h"
bool flag = false;
void configuracion() {
  Serial.begin(BAUDRATE);
  pinMode(LED1,OUTPUT); 
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  pinMode(BTN,INPUT);
  digitalWrite(LED1, false);
  digitalWrite(LED2, false);
  digitalWrite(LED3, false);
  digitalWrite(LED4, false);

}
void espera() {
  if(BTN==true){
    flag = true;
  }

}
void secuencia(){
  if(flag){
    flag = false;
    digitalWrite(LED1,true);
    delay(DELAY);
    digitalWrite(LED2,true);
    delay(DELAY);
    digitalWrite(LED3,true);
    delay(DELAY);
    digitalWrite(LED4,true);
    delay(DELAY);
    digitalWrite(LED1,false);
    digitalWrite(LED2,false);
    digitalWrite(LED3,false);
    digitalWrite(LED4,false);

  }
}