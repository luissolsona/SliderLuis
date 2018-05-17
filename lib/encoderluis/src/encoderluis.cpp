#include "encoderluis.h"

Encoder::Encoder(screen* screen, Motor* motor){
  screen_ = screen;
  motor_ = motor;
  changeTime_ = 20;
}

/*
*   When the rotatory enconder go clock-wise
*/
void Encoder::giroDerecha(){
  //Timeout to prevent debounce on the rotatory encoder
//  if((millis() - time_) > changeTime_)
//  {
//    time_ = millis();
    // If we are in the menu (tomarEntrada == false),
    // update the position of the arrow
    if(digitalRead(3) == HIGH && screen_->tomarEntrada() == false){
      screen_->sumaPosicion();
      screen_->actualizarFlecha();
    }
    //If we are inside a submenu (tomarEntrada == true)
    else if(digitalRead(3) == HIGH && screen_->tomarEntrada() == true){
      //If we are NOT trying to change the number value (tomarSubEntrada == false)
      if(screen_->tomarSubEntrada() == false)
        screen_->sumaSubPosicion();

      //Draw the submenu
      switch (screen_->tomarPosicion()) {
        case 0:
          //If we are changing the number value
          if(screen_->tomarSubEntrada() == true){
            if(motor_->getTarget() < motor_->getlength())
              motor_->setTarget(motor_->getTarget() + 10);
            else
              motor_->setTarget(0);
          }
          //Draw porPosicion submenu and update the position number
          screen_->porPosicion(motor_->getTarget());
          break;
        case 1:
          //If we are changing the number value
          if(screen_->tomarSubEntrada() == true)
            motor_->setTime(motor_->getTime() + 10, 240);
          //Draw porTiempo submenu
          screen_->porTiempo(motor_->getTime());
          break;
        case 2:
          //If we are changing the value
          if(screen_->tomarSubEntrada() == true)
            motor_->setLoop(!motor_->getLoop());
          //Draw porCiclo menu
          screen_->porCiclo(motor_->getLoop());
          break;
      }
    }
//  }
}

/*
*   When the rotatory encoder go counter-clock-wise
*/
void Encoder::giroIzquierda()
{
  //Time out to prevent debounce on the rotatory encoder
//  if((millis() - time_) > changeTime_)
//  {
//    time_ = millis();
    // If we are in the menu (tomarEntrada == false)
    // update the position of the arrow
    if(digitalRead(2) == HIGH && screen_->tomarEntrada() == false)
    {
      screen_->restaPosicion();
      screen_->actualizarFlecha();
    }
    // If we are inside a submenu (tomarEntrada == true)
    else if(digitalRead(2) == HIGH && screen_->tomarEntrada() == true){
      //If we are NOT trying to change the number value (tomarSubEntrada == false)
      if(screen_->tomarSubEntrada() == false)
        screen_->restaSubPosicion();

      //Draw the submenu
      switch (screen_->tomarPosicion()) {
        case 0:
          //If we are changing the value number
          if(screen_->tomarSubEntrada() == true){
            if(motor_->getTarget() > 0)
              motor_->setTarget(motor_->getTarget() - 10);
            else
              motor_->setTarget(motor_->getlength());
          }
          //Draw byPositon submenu
          screen_->porPosicion(motor_->getTarget());
          break;
        case 1:
          //If we are changing the value number
          if(screen_->tomarSubEntrada() == true)
            motor_->setTime(motor_->getTime() - 10, 240);
          //Draw porTiempo submenu
          screen_->porTiempo(motor_->getTime());
          break;
        case 2:
          //If we are changing the value
          if(screen_->tomarSubEntrada() == true)
            motor_->setLoop(!motor_->getLoop());
          //Draw porCiclo menu
          screen_->porCiclo(motor_->getLoop());
          break;
      }
    }
//  }
}

/*
*   When the button is pressed
*/
void Encoder::presBoton(){
  //Emergency stop when the motor is moving
  if(motor_->gettrabajando()){
    motor_->settrabajando(false);
  }

  //If we are in the menu
  if(!screen_->tomarEntrada()){
    //Draw the submenu
    screen_->fijarEntrada(true);
    this->dibujaSubmenu();
  }
  //If we are in the submenu
  else {
    //If back button is selected
    if(screen_->tomarSubPosicion() == 1){
      //Go to menu
      screen_->fijarEntrada(false);
      screen_->menu();
    }
    //If start button is selected
    else if (screen_->tomarSubPosicion() == 2) {
      //Start moving and update screen
      motor_->settrabajando(true);
      screen_->trabajando();
    }
    //If number is selected
    else {
      //Change status
      if(screen_->tomarSubPosicion() == 0 && !screen_->tomarSubEntrada())
        screen_->fijarSubEntrada(true);
      else
        screen_->fijarSubEntrada(false);

      this->dibujaSubmenu();

    }
  }


}

void Encoder::dibujaSubmenu(){
  switch (screen_->tomarPosicion()) {
    case 0:
      screen_->porPosicion(motor_->getTarget());
      break;
    case 1:
      screen_->porTiempo(motor_->getTime());
      break;
    case 2:
      screen_->porCiclo(motor_->getLoop());
      break;
  }
}
