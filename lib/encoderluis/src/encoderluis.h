//#include "screenluis.h"
//#include "motorluis.h"
//#include <AccelStepper.h>

class Encoder{
  public:
    Encoder();
    void giroDerecha();
    {
      if(digitalRead(3) == HIGH)
      {
        Serial.println("Giro a la izquierda");
      }
    }
    void giroIzquierda();
    {
      if(digitalRead(2) == HIGH)
        {
          Serial.println("Giro a la derecha")
        }
    }
//    void presBoton();
//    void dibujaSubmenu();
  private:
//    screen* screen_;
//    Motor* motor_;
//    unsigned long int time_;
//    int changeTime_;

};
