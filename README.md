# Control Digital : Práctica 2 

## 1) Anti rebote
Para el desarrollo de la programación del anteirebote se define primero la máquina de estados que se muestra en la siguiente figura:

[![estados-anti.png](https://i.postimg.cc/CKBRGvnB/estados-anti.png)](https://postimg.cc/DWhfFPgn)

Los cambios entre estados ocurren cuando:
- El estado inicial es Button Up, cuando se presiona el botón pasa al estado Button Falling.
- En el estado Falling espera un tiempo (variable t_rebote) y vuelve a leer el pulsador, si el botón sigue presionado pasa al estado Down y llama a la función buttonPressed(), la cual indica que el botón sí ha sido presionado, caso contrario vulve al estado UP.
- Si está en el estado Down y se libera el botón, pasa al estado Rising.
- En el estado Rising espera un tiempo (variable t_rebote) y vuelve a leer el pulsador, si este está liberado pasa al estado Up y llama a la función buttonReleased(), indicando que el botón ha sido liberado, caso contrario vuelve al estado Down.

[Desarrollo actividad 1](https://github.com/sebasalvavi/Semaforo/tree/main/1/Antirebote)

## 2) Control de 2 teclas
Para este programa se define la misma máquina de estados que la realizada en el ítem anterior. Para escalar a dos o más botones se crea una estructura **VTecla** que contiene:
- Tecla: Variable **tecla** de tipo char, identificador de la tecla.
- Tiempo para cambio de estado: Variable **delay** de tiempo para realizar los cambios de estado.
- Estado: Variable **estadob** de tipo **enum** usada para los cambios de estados.

[Desarrollo actividad 2](https://github.com/sebasalvavi/Semaforo/tree/main/2/Teclasindepen)

## 3) Semáforo

Para el desarrollo de la programación del semáforo se define tres modos de operación, mismos que se muestran en la siguiente figura:

[![modos.png](https://i.postimg.cc/Y2YpwvWW/modos.png)](https://postimg.cc/G930FhzL)

El cambio entre los modos de operación ocurre al presionar uno de los dos botones disponibles, para esto ya se implementa el anti rebote en cada uno de los botones.

Las acciones en cada modo son:
- Normal: Los leds siguen la secuencia: verde 3s, verde y amarillo 500ms, rojo 2s iterativamente. Los tiempos de la secuencia son modificados al presionar uno de los dos botones, el cual variará la velocidad entre 0.5x, 1x y 2x.
- Desconectado: Led amarillo intermitente cada 500ms.
- Alarma: Led rojo intermitente cada 1s


## 4) Comunicación UART

