#include <Arduino.h>
//Variables para los estados del antirebote del boton
enum Estado_Boton {
  BOTON_UP,
  BOTON_FALLING,
  BOTON_RISING,
  BOTON_DOWN
};

//Estructura de las variables de las teclas para controlar 2 (o mas) simultaneamente
struct VTecla {
  char tecla;
  int8_t delay;
  Estado_Boton estadob;
};

//Variables externas para poder usarlas fuera de la funcion
extern VTecla tecla1;
extern VTecla tecla2;

void teclas_act(VTecla& tecla, int boton);
bool retraso(unsigned long tiempo);
