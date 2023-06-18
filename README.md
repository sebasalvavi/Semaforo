# Control Digital : Práctica 2 

## Máquina de estados del antirebote
Para el desarrollo de la programación del anteirebote se define primero la máquina de estados que se muestra en la siguiente figura:

[![estados-anti.png](https://i.postimg.cc/CKBRGvnB/estados-anti.png)](https://postimg.cc/DWhfFPgn)

Los cambios de estados ocurren cuando:
- El estado inicial es Button Up, cuando se presiona el botón pasa al estado Button Falling.
- En el estado Falling espera un tiempo (variable t_rebote) y vuelve a leer el pulsador, si el botón sigue presionado pasa al estado Down y llama a la función buttonPressed(), la cual indica que el botón sí ha sido presionado, caso contrario vulve al estado UP.
- Si está en el estado Down y se libera el botón, pasa al estado Rising.
- En el estado Rising espera un tiempo (variable t_rebote) y vuelve a leer el pulsador, si este está liberado pasa al estado Up y llama a la función buttonReleased(), indicando que el botón ha sido liberado, caso contrario vuelve al estado Down.

## Máquina de estados del semáforo
Para el desarrollo de la programación del semáforo se define primero la máquina de estados que se muestra en la siguiente figura:

Los 3 primeros codigos del trabajo 2 de programacion en mircos de control digital
