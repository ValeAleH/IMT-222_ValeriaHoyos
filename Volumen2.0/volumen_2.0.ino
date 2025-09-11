#include "funciones.h"

void setup() {
  conf();           
  iniciarEEPROM();  
}

void loop() {
  leerBotones();     
  mostrarEstado();   
  manejarEEPROM();  
  delay(50);
}
