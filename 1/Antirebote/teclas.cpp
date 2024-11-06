// Creado por: Sebastian Alvarez
// Para un semaforo con arduino.
// Primera tarea: Tecla antirebote
#include <Arduino.h>
#include "teclas.h"
//Teclas y leds
const int boton1 = 11;
const int boton2 = 10;
const int led1 = 7;
const int led2 = 5;



//Estados del boton
enum Estado_Boton{
  BOTON_UP,
  BOTON_FALLING,
  BOTON_RISING,
  BOTON_DOWN
};
Estado_Boton estado_b1 = BOTON_UP;
Estado_Boton estado_b2 = BOTON_UP;

// Variable y constante necesarias para retardo no bloqueante
const int t_rebote = 30;
unsigned long t_anterior1 = 0;
unsigned long t_anterior2 = 0;

//Funcion de boton presionado
void buttonPressed(uint8_t tecla) {
    if (tecla == 1) {
      Serial.println("Pulsador 1 presionado");
      digitalWrite(led1, HIGH);
    } 
    else if (tecla == 2) {
      Serial.println("Pulsador 2 presionado");
      digitalWrite(led2, HIGH);
    }
}
//Funcion de boton liberado
void buttonReleased(uint8_t tecla) {
  if (tecla == 1) {
     Serial.println("Pulsador 1 liberado");
     digitalWrite(led1, LOW);
  } 
  else if (tecla == 2) {
     Serial.println("Pulsador 2 liberado");
     digitalWrite(led2, LOW);
  }
}

// Funcion de inicializacion
void teclas_ini(){
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}
// Funcion de actualizacion de estados
void teclas_act(){
/* ############ B O T O N  1 ############ */ 
  switch (estado_b1) {
  case BOTON_UP:
  t_anterior1 = millis();
    if(digitalRead(boton1) == LOW) {
      estado_b1 = BOTON_FALLING;
    }
  break;

  case BOTON_FALLING:
    if(millis() - t_anterior1 >= t_rebote) {
      if(digitalRead(boton1) == LOW){
        estado_b1 = BOTON_DOWN;
        buttonPressed(1);
      }
      else{
        estado_b1 = BOTON_UP;
      }
    }
  break;

  case BOTON_DOWN:
  t_anterior1 = millis();
    if(digitalRead(boton1) == HIGH){
      estado_b1 = BOTON_RISING;
    }
  break;

  case BOTON_RISING:
    if(millis() - t_anterior1 >= t_rebote){
      if(digitalRead(boton1) == HIGH){
        estado_b1 = BOTON_UP;
        buttonReleased(1);
      }
      else{
        estado_b1 = BOTON_DOWN;
      }
    }
  break;
  }

/* ############ B O T O N  2 ############ */ 
    switch (estado_b2) {
  case BOTON_UP:
  t_anterior2 = millis();
    if(digitalRead(boton2) == LOW) {
      estado_b2 = BOTON_FALLING;
    }
  break;

  case BOTON_FALLING:
    if(millis() - t_anterior2 >= t_rebote) {
      if(digitalRead(boton2) == LOW){
        estado_b2 = BOTON_DOWN;
        buttonPressed(2);
      }
      else{
        estado_b2 = BOTON_UP;
      }
    }
  break;

  case BOTON_DOWN:
  t_anterior2 = millis();
    if(digitalRead(boton2) == HIGH){
      estado_b2 = BOTON_RISING;
    }
  break;

  case BOTON_RISING:
    if(millis() - t_anterior2 >= t_rebote){
      if(digitalRead(boton2) == HIGH){
        estado_b2 = BOTON_UP;
        buttonReleased(2);
      }
      else{
        estado_b2 = BOTON_DOWN;
      }
    }
  break;
  }


}