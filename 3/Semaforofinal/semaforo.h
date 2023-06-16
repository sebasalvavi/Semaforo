#include <Arduino.h>

extern const int8_t boton1;
extern const int8_t boton2;
extern const int8_t led_G;
extern const int8_t led_Y;
extern const int8_t led_R;

//Variables para los estados del semaforo
enum Estado_Semaforo {
  NORMAL,
  DESCONECTADO,
  ALARMA
};
//Estructura para usar la misma funcion en el modo DESCONECTADO y ALARMA del semaforo 
struct led_inter {
  int led;
  int delay;
};
//Variables externas para poder usarlas fuera de la funcion
extern led_inter modo2;
extern led_inter modo3;


void semaforo_ini();
Estado_Semaforo semaforo_act();
void desconectado(led_inter& modo);
void normal();