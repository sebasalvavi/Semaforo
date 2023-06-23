#include <Arduino.h>
#include "pulsantes.h"
#include "semaforo.h"

// Funciones para mostrar informacion

//Funcion para mostrar informacion de los botones
void uart_antirebote(char tecla_pres,  Estado_Boton estado_antirebote);

//FUncion para mostrar informacion del semaforo
void uart_semaforo(Estado_Semaforo estado_semaforo);

