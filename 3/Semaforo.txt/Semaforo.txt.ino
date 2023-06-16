#include "pulsantes.h"

const int intervalo = 400;

int estado = 0;
float velocidades[] = {0.5, 1, 2};
int v_act = 1;
int b_estado = 0;
float velocidad;

struct led_inter {
  int led;
  int delay;
};

led_inter modo2 = {led_Y, 500};
led_inter modo3 = {led_R, 1000};

enum Estado_Semaforo {
  NORMAL,
  DESCONECTADO,
  ALARMA
};

Estado_Semaforo estado_act = NORMAL;

void setup() {
  pinMode(led_G, OUTPUT);
  pinMode(led_Y, OUTPUT);
  pinMode(led_R, OUTPUT);
  pinMode(boton1, INPUT_PULLUP);
  pinMode(boton2, INPUT_PULLUP);
  teclas_ini();
  Serial.begin(9600);
}

void loop() {
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
        break;
      case 1:
        estado_act = DESCONECTADO;
        break;
      case 2:
        estado_act = ALARMA;
        break;
    }
  }


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


void desconectado(led_inter& modo){
  static boolean intermitente = LOW;
  if (retraso(modo.delay*velocidad)) {
    intermitente = !intermitente;
    digitalWrite(led_G, LOW);
    digitalWrite(led_Y, LOW);
    digitalWrite(led_R, LOW);
    digitalWrite(modo.led, intermitente);
  }
}
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