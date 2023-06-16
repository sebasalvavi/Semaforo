#include <Arduino.h>
#include "pulsantes.h"
#include "semaforo.h"

unsigned long t_antpuls= 0;

VTecla tecla1 = {'1', 40, BOTON_UP};
VTecla tecla2 = {'2', 40, BOTON_UP};

//Funcion que realiza el antirebote del boton
void teclas_act(VTecla& tecla, int boton) {
  switch (tecla.estadob) {
    case BOTON_UP:
      if (digitalRead(boton) == LOW) {
        tecla.estadob = BOTON_FALLING;
        t_antpuls= millis();}
      break;

    case BOTON_FALLING:
      if (millis() - t_antpuls>= tecla.delay) {
        if (digitalRead(boton) == LOW) {
          tecla.estadob = BOTON_DOWN;
        } else {
          tecla.estadob = BOTON_UP;
        }}
      break;

    case BOTON_DOWN:
      if (digitalRead(boton) == HIGH) {
        tecla.estadob = BOTON_RISING;
        t_antpuls= millis();}
      break;

    case BOTON_RISING:
      if (millis() - t_antpuls>= tecla.delay) {
        if (digitalRead(boton) == HIGH) {
          tecla.estadob = BOTON_UP;
        } else {
          tecla.estadob = BOTON_DOWN;
        }}
      break;
  }
}
//Funcion que reemplaza el delay, toma como parametro el tiempo en milisegundos
bool retraso(unsigned long tiempo) {
  static unsigned long tiempoInicial = 0; // Variable para almacenar el tiempo inicial

  if (millis() - tiempoInicial >= tiempo) {
    tiempoInicial = millis(); // Reiniciar el tiempo inicial
    return true; // Ha pasado el tiempo especificado
  }

  return false; // No ha pasado el tiempo especificado
}