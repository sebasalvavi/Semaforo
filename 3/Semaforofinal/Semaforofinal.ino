#include "pulsantes.h"
#include "semaforo.h"
void setup() {
  semaforo_ini();//Funcion de inicializacion de semaforos
  Serial.begin(9600);
  }
void loop() {
   Estado_Semaforo estadoActual = semaforo_act(); //Aqui se obtiene el estado desde la funcion de actualizacion de estados del semaforo
   Serial.println(estadoActual);
   }