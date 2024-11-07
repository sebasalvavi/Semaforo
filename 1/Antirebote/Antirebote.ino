// Creado por: Sebastian Alvarez
// Para un semaforo con arduino.
// Primera tarea: Tecla antirebote
// ... github
#include "teclas.h"


void setup() {
  Serial.begin(9600);
  teclas_ini();
}

void loop() {
  teclas_act();
}


