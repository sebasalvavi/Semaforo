#include <Arduino.h>
#include "teclas1.h"

int boton1 = 11;
int boton2 = 10;
int led1 = 7;
int led2 = 5;
unsigned long t_anterior = 0;

VTecla tecla1 = {'1', 40, BOTON_UP};
VTecla tecla2 = {'2', 40, BOTON_UP};

void teclas_ini() {
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void teclas_act(VTecla& tecla, int boton) {
  switch (tecla.estadob) {
    case BOTON_UP:
      if (digitalRead(boton) == LOW) {
        tecla.estadob = BOTON_FALLING;
        t_anterior = millis();}
      break;

    case BOTON_FALLING:
      if (millis() - t_anterior >= tecla.delay) {
        if (digitalRead(boton) == LOW) {
          tecla.estadob = BOTON_DOWN;
          // Realizar acción asociada al botón presionado
          // Ejemplo: digitalWrite(led1, HIGH);
        } else {
          tecla.estadob = BOTON_UP;
        }}
      break;

    case BOTON_DOWN:
      if (digitalRead(boton) == HIGH) {
        tecla.estadob = BOTON_RISING;
        t_anterior = millis();}
      break;

    case BOTON_RISING:
      if (millis() - t_anterior >= tecla.delay) {
        if (digitalRead(boton) == HIGH) {
          tecla.estadob = BOTON_UP;
          // Realizar acción asociada al botón liberado
          // Ejemplo: digitalWrite(led1, LOW);
        } else {
          tecla.estadob = BOTON_DOWN;
        }}
      break;
  }
}