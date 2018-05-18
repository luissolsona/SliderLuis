#include <Arduino.h>
#include "Contador.h"

Contador C1,C2;

void setup()
   {
      C1.SetContador(10);
      C2.SetContador(100);
   }
void loop()
   {
      C1.Incrementar() ;
      Serial.print("C1 = ") ; Serial.println(C1.GetCont());

      C2.Incrementar() ; C2.Incrementar() ; C2.Incrementar();
      Serial.print("C2 = ") ; Serial.println(C2.GetCont());
   }
