#include <Arduino.h>
#include "pulsantes.h"
#include "semaforo.h"
//Constantes de leds y pulsantes
const int8_t boton1 = 11;
const int8_t boton2 = 10;
const int8_t led_G = 7;
const int8_t led_Y = 5;
const int8_t led_R = 3;

const int intervalo = 300;//Constante para que los cambios de velocidad y estado no se salten valore
int estado = 0;//Constante que maneja el switch case del semaforo en modo normal
float velocidades[] = {0.5, 1, 2};//Velocidades de los modos
int v_act = 1;
float velocidad;
//Bandera para ciclar estados del semaforo
int b_estado = 0;

//Variables para lla funcion de intermitencia
led_inter modo2 = {led_Y, 500};
led_inter modo3 = {led_R, 1000};
Estado_Semaforo estado_act = NORMAL;

// Funcion que se usa para los estados de DESCONECTADO y ALARMA
void desconectado(led_inter& modo){
  static boolean intermitente = LOW;
  if (retraso(modo.delay*velocidad)) {
    intermitente = !intermitente;
    digitalWrite(led_G, LOW);
    digitalWrite(led_Y, LOW);
    digitalWrite(led_R, LOW);
    digitalWrite(modo.led, intermitente);
  }
};
// Funcion para el estado NORMAL
void normal() {
  switch (estado) {
    case 0:
      if (!retraso(3000*velocidad)) {
        digitalWrite(led_G, HIGH);
        digitalWrite(led_Y, LOW);
        digitalWrite(led_R, LOW);
      } else {
        estado = 1;}
      break;

    case 1:
      if (!retraso(500*velocidad)) {
        digitalWrite(led_G, HIGH);
        digitalWrite(led_Y, HIGH);
        digitalWrite(led_R, LOW);
      } else {
        estado = 2;}
      break;

    case 2:
      if (!retraso(2000*velocidad)) {
        digitalWrite(led_G, LOW);
        digitalWrite(led_Y, LOW);
        digitalWrite(led_R, HIGH);
      } else {
        estado = 0;}
      break;
  }
};

//Funcion de inicializacion del semaforo
void semaforo_ini() {
  pinMode(led_G, OUTPUT);
  pinMode(led_Y, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
};
//Funcion que cambia los estados del semaforo, devuelve informacion sobre su estado y ejecuta las funciones de luz.
Estado_Semaforo semaforo_act(){
  teclas_act(tecla1, boton1);
  teclas_act(tecla2, boton2); 
  if (tecla1.estadob == BOTON_DOWN && retraso(intervalo)) {
    v_act = (v_act + 1) % 3;
  } 
  velocidad = velocidades[v_act];
  //Serial.println(velocidad);

  if (tecla2.estadob == BOTON_RISING && digitalRead(boton2) == HIGH) {
    b_estado = (b_estado + 1) % 3;
    switch (b_estado) {
      case 0:
        estado_act = NORMAL;
        return NORMAL;
        break;
      case 1:
        estado_act = DESCONECTADO;
        return DESCONECTADO;
        break;
      case 2:
        estado_act = ALARMA;
        return ALARMA;
        break;
    }
  }

//Esta seccion de codigo se podria colocar en el archivo .ino con el objetivo de realizar mas acciones segun el estado del semaforo.
  Serial.println(b_estado);

  switch (estado_act) {
  case NORMAL:
    normal();
  break;

  case DESCONECTADO:
    desconectado(modo2);
  break;

  case ALARMA:
    desconectado(modo3);
  break;
  }
}

