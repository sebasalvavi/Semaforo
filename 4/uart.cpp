#include <Arduino.h>
#include "uart.h"

void uart_antirebote(char tecla_pres,Estado_Boton estado_antirebote){
  /* Funcion uart_antirebote()
  Para informar la tecla presionada y el estado actual
  Entrada:
    tecla_pres: Tipo char, correspondiente a la tecla presionada
    estado_antirebote: Tipo enum, corresponde al estado del boton
  */

  Serial.print("Tecla: ");
  Serial.print(tecla_pres);

  switch (estado_antirebote)
  {
    case BOTON_UP
      Serial.println("Estado actual de botón: BOTON_UP");
    break

    case BOTON_FALLING
      Serial.println("Estado actual de botón: BOTON_FALLING");
    break

    case BOTON_RISING
      Serial.println("Estado actual de botón: BOTON_RISING");
    break

    case BOTON_DOWN
      Serial.println("Estado actual de botón: BOTON_DOWN");
    break

    default:
      Serial.println("Estado actual de botón: BOTON_UP");
    break
  }
}

void uart_semaforo(Estado_Semaforo estado_semaforo){
  /* Funcion uart_semaforo()
  Para informar el modo actual del semaforo
  Entrada:
    estado_semaforo: Tipo enum, corresponde al estado actual del semaforo
  */
  
  switch (estado_semaforo)
  {
    case NORMAL
      Serial.println("Estado del semáforo: NORMAL");
    break

    case DESCONECTADO
      Serial.println("Estado actual de botón: DESCONECTADO");
    break

    case ALARMA
      Serial.println("Estado actual de botón: ALARMA");
    break

    default:
      Serial.println("Estado actual de botón: NORMAL");
    break
  }
}


