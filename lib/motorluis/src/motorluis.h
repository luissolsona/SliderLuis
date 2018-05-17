#include <Arduino.h>

class Motor{
  public:
    Motor(int stepPin, int dirPin, int enablePin);
    void move();
    int tomarPosicion();
    void fijarPosicion(int position);
    int getTarget();
    void setTarget(int target);
    int getStepTime();
    void setStepTime(int stepTime);
    void settrabajando(bool trabajando);
    bool gettrabajando();
    long int getStepsDistance();
    unsigned long int getTime();
    void setTime(unsigned long int timing, int target);
    bool getFinished();
    void setFinished(bool finished);
    bool getLoop();
    void setLoop(bool loop);
    int getlength();
  private:
    int stepPin_;
    int dirPin_;
    int enablePin_;
    int posicion_;
    int target_;
    int stepTime_;
    int stepBymm_;
    int length_;
    long int steps_;
    unsigned long int time_;
    unsigned long int stepsDistance_;
    bool direction_;
    bool trabajando_;
    bool finished_;
    bool loop_;
};
