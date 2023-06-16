#include <Arduino.h>

extern const int8_t boton1;
extern const int8_t boton2;
extern const int8_t led_G;
extern const int8_t led_Y;
extern const int8_t led_R;


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
bool retraso(unsigned long tiempo);
