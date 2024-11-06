// Creado por: Sebastian Alvarez
// Para un semaforo con arduino.
// Segunda Tarea: Teclas actuando asincronica e independientemente
#include "teclas1.h"

void setup() {
  Serial.begin(9600);
  teclas_ini();
}

void loop() {
  teclas_act(tecla1, boton1);
  teclas_act(tecla2, boton2);

  if (tecla1.estadob == BOTON_DOWN) {
    Serial.println("Tecla 1 activada");
    digitalWrite(led1, HIGH);
  } else{
    digitalWrite(led1, LOW);
  }
  
  if (tecla2.estadob == BOTON_DOWN) {
    Serial.println("Tecla 2 activada");
    digitalWrite(led2, HIGH);
  } else{
    digitalWrite(led2, LOW);
  }
}

