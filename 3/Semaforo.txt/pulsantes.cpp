#include <Arduino.h>
#include "pulsantes.h"

const int8_t boton1 = 11;
const int8_t boton2 = 10;
const int8_t led_G = 7;
const int8_t led_Y = 5;
const int8_t led_R = 3;

unsigned long t_antpuls= 0;

VTecla tecla1 = {'1', 40, BOTON_UP};
VTecla tecla2 = {'2', 40, BOTON_UP};

void teclas_ini() {
  pinMode(led_G, OUTPUT);
  pinMode(led_Y, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
}

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

bool retraso(unsigned long tiempo) {
  static unsigned long tiempoInicial = 0; // Variable para almacenar el tiempo inicial

  if (millis() - tiempoInicial >= tiempo) {
    tiempoInicial = millis(); // Reiniciar el tiempo inicial
    return true; // Ha pasado el tiempo especificado
  }

  return false; // No ha pasado el tiempo especificado
}