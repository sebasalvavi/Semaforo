// Creado por: Sebastian Alvarez
// Para un semaforo con arduino.
// Segunda Tarea: Teclas actuando asincronica e independientemente
#include <Arduino.h>

extern int boton1;
extern int boton2;
extern int led1;
extern int led2;


enum Estado_Boton {
  BOTON_UP,
  BOTON_FALLING,
  BOTON_RISING,
  BOTON_DOWN
};

struct VTecla {
  char tecla;
  int8_t delay;
  Estado_Boton estadob;
};

void teclas_ini();

extern VTecla tecla1;
extern VTecla tecla2;

void teclas_act(VTecla& tecla, int boton);
