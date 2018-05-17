#include "encoderluis.h"

screen screen;
Motor motor(5, 6, 7);
Encoder encoder(&screen, &motor);
static boolean rotating=false;

void rotEncoder()
{
  rotating=true; // If motion is detected in the rotary encoder,
                 // set the flag to true
}

void giDer()
{
  encoder.giroDerecha();
}
void giIzq()
{
  encoder.giroIzquierda();
}



void setup()
{
  Serial.begin(115200);
  pinMode(4, INPUT);
  attachInterrupt(0, rotEncoder, CHANGE);
//  attachInterrupt(1, giIzq, FALLING);
  screen.set();
  screen.menu();
}

void loop() {
  if(digitalRead(4) == LOW)
  {
    encoder.presBoton();
    delay(10);
  }

  while(rotating)
  {
   delay(2);  // debounce by waiting 2 milliseconds
              // (Just one line of code for debouncing)
   if (digitalRead(3) == digitalRead(2))  // CCW
     giDer();
   else                          // If not CCW, then it is CW
    giIzq();

   rotating=false; // Reset the flag
  }

  motor.move();
  if(motor.getFinished())
  {
    encoder.dibujaSubmenu();
    motor.setFinished(false);
  }


}
