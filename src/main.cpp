#include <Arduino.h>
#include "encoderluis.h"

Encoder encoder();
static boolean rotando=false;



void rotEncoder()
{
  rotando=true; // Si es detectado movimiento en el encoder,
                 // cambia "rotando" a TRUE
}



void setup()
{
  Serial.begin(9600);
  pinMode(4, INPUT);
  attachInterrupt(0, rotEncoder, CHANGE);
}



void loop()
{
  while(rotando)
    {
     delay(25);  // debounce esperando 2 milis
                // (Solo una linea de codigo)
     if (digitalRead(3) == digitalRead(2))  // CCW
      encoder::giroDerecha();
     else                          // Si no es CCW, entonces es CW
      encoder::giroIzquierda();

     rotando=false; // Reset the flag
    }
  }
