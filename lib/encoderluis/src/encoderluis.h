#include "screenluis.h"
#include "motorluis.h"

class Encoder{
  public:
    Encoder(screen* screen, Motor* motor);
    void giroDerecha();
    void giroIzquierda();
    void presBoton();
    void dibujaSubmenu();
  private:
    screen* screen_;
    Motor* motor_;
    unsigned long int time_;
    int changeTime_;

};
