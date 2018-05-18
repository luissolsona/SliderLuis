#include "screenluis.h"

screen::screen(){
  numero_ = "1000";
  posicion_ = 0;
  entrada_ = false;
  subentrada_ = false;
}

/*
* Boot the screen and write the RincónIngenieril brand
*/
void screen::set(){

  TFT screen = TFT(cs, dc, rst);
  screen_ = &screen;
  screen.begin();
  screen.setRotation(90);

  screen.background(0, 0, 0);
  screen.stroke(255, 112, 67);
  screen.setTextSize(1);

  screen.text("SliderCAM Arduino", 15, 3);
  screen.line(0, 15, 128, 15);
}

/*
*   Show the menu options
*/
void screen::menu(){
  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(1);
  screen_->text("Posicion", 10, 30);
  screen_->text("Tempo", 10, 40);
  screen_->text("Ciclo", 10, 50);
  screen_->text("Motor a 0", 10, 60);
  screen_->text("Posicion Cabeza", 3, 139);
  screen_->text("Posicion Slider", 3, 149);

  this->actualizarFlecha();
}

/*
*   This screen is shown while the motor is moving
*/
void screen::trabajando(){
  subposicion_ = 0;

  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(2);
  screen_->text("trabajando", 15, 30);

  screen_->setTextSize(1);
  screen_->text("Press to stop", 15, 60);
}

/*
*   This screen guide the user in order to
*   set the next posicion of the slider
*/
void screen::porPosicion(int posicion){
  //Clear menu
  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  //Write the title
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(2);
  screen_->text("posicion", 15, 30);

  //screen animation, it depends on subposicion_ value
  switch (subposicion_) {
    case 0:   //The posicion number is selected
      this->atrasBoton(false);
      this->inicoBoton(false);
      screen_->fill(255,255,255);

      if (!subentrada_) screen_->stroke(0, 0, 0);
      else screen_->stroke(255, 0, 0);

      break;
    case 1:   //The back button is selected
      this->atrasBoton(true);
      this->inicoBoton(false);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
    case 2:   //The start button is selected
      this->atrasBoton(false);
      this->inicoBoton(true);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
  }
  screen_->setTextSize(3);
  screen_->rect(15, 70, 92, 30);
  //Get and print the posicion value
  String numero_string = String(posicion);
  numero_string.toCharArray(numero_, numero_string.length()+1);
  screen_->text(numero_, 30, 75);
}

/*
*   This screen guide the user in order
*   to set the time with will be used
*   for the complete movement
*/
void screen::porTiempo(long int timing){
  //Clear menu
  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  //Write the title
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(2);
  screen_->text("Time", 15, 30);

  //screen animation, it depends on subposicion_ value
  switch (subposicion_) {
    case 0:   //The time value is selected
      this->atrasBoton(false);
      this->inicoBoton(false);
      screen_->fill(255,255,255);

      if (!subentrada_) screen_->stroke(0, 0, 0);
      else screen_->stroke(255, 0, 0);

      break;
    case 1:   //The back button is selected
      this->atrasBoton(true);
      this->inicoBoton(false);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
    case 2:   //The start button is selected
      this->atrasBoton(false);
      this->inicoBoton(true);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
  }
  screen_->setTextSize(3);
  screen_->rect(15, 70, 92, 30);
  //Get and print the time value
  String numero_string = String(timing);
  numero_string.toCharArray(numero_, numero_string.length()+1);
  screen_->text(numero_, 30, 75);

}

void screen::porCiclo(bool state){
  //Clear menu
  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  //Wrtie the title
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(2);
  screen_->text("Loop", 15, 30);

  //Get and print the posicion value
  switch (subposicion_) {
    case 0:   //The laps value is selected
      this->atrasBoton(false);
      this->inicoBoton(false);
      screen_->fill(255,255,255);

      if (!subentrada_) screen_->stroke(0, 0, 0);
      else screen_->stroke(255, 0, 0);

      break;
    case 1:   //The back button is selected
      this->atrasBoton(true);
      this->inicoBoton(false);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
    case 2:   //The start button is selected
      this->atrasBoton(false);
      this->inicoBoton(true);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
  }
  screen_->setTextSize(1);
  screen_->rect(15, 70, 92, 30);
  if(state)
    screen_->text("Enable", 40, 80);
  else
    screen_->text("Disable", 40, 80);

}




void screen::porPosicion2(int posicion2){
  //Clear menu
  screen_->fill(0, 0, 0);
  screen_->stroke(0, 0, 0);
  screen_->rect(0, 18, 128, 142);
  //Write the title
  screen_->stroke(255, 255, 255);
  screen_->setTextSize(2);
  screen_->text("posicion", 15, 30);

  //screen animation, it depends on subposicion_ value
  switch (subposicion_) {
    case 0:   //The posicion number is selected
      this->atrasBoton(false);
      this->inicoBoton(false);
      screen_->fill(255,255,255);

      if (!subentrada_) screen_->stroke(0, 0, 0);
      else screen_->stroke(255, 0, 0);

      break;
    case 1:   //The back button is selected
      this->atrasBoton(true);
      this->inicoBoton(false);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
    case 2:   //The start button is selected
      this->atrasBoton(false);
      this->inicoBoton(true);
      screen_->noFill();
      screen_->stroke(255, 255, 255);
      break;
  }
  screen_->setTextSize(3);
  screen_->rect(15, 70, 92, 30);
  //Get and print the posicion value
  String numero_string = String(posicion2);
  numero_string.toCharArray(numero_, numero_string.length()+1);
  screen_->text(numero_, 30, 75);
}








int screen::sumaPosicion(){
    posicion_++;
    if(posicion_ > 3)  posicion_ = 0;

}

int screen::restaPosicion(){
    posicion_--;
    if(posicion_ < 0)  posicion_ = 3;

}

int screen::sumaSubPosicion(){
    subposicion_++;
    if(subposicion_ > 2)  subposicion_ = 0;

}

int screen::restaSubPosicion(){
    subposicion_--;
    if(subposicion_ < 0)  subposicion_ = 2;

  }

/*
*   This method update the arrow
*   posicion in the menu screen
*/
void screen::actualizarFlecha(){
  switch(posicion_){
    case 0:
      screen_->stroke(0, 0, 0);
      screen_->text(">", 3, 40);
      screen_->text(">", 3, 50);
      screen_->text(">", 3, 60);
      screen_->stroke(255, 255, 255);
      screen_->text(">", 3, 30);
      break;
    case 1:
      screen_->stroke(0, 0, 0);
      screen_->text(">", 3, 30);
      screen_->text(">", 3, 50);
      screen_->text(">", 3, 60);
      screen_->stroke(255, 255, 255);
      screen_->text(">", 3, 40);
      break;
    case 2:
      screen_->stroke(0, 0, 0);
      screen_->text(">", 3, 30);
      screen_->text(">", 3, 40);
      screen_->text(">", 3, 60);
      screen_->stroke(255, 255, 255);
      screen_->text(">", 3, 50);
      break;
    case 3:
      screen_->stroke(0, 0, 0);
      screen_->text(">", 3, 30);
      screen_->text(">", 3, 40);
      screen_->text(">", 3, 50);
      screen_->stroke(255, 255, 255);
      screen_->text(">", 3, 60);
      break;
  }
}

/*
*   This method draw the back button
*/
void screen::atrasBoton(bool fill){
  if(fill){
    screen_->fill(255,255,255);
    screen_->stroke(0, 0, 0);
  } else {
    screen_->noFill();
    screen_->stroke(255, 255, 255);
  }

  screen_->rect(0, 120, 56, 30);  //rectangulo atras
  screen_->setTextSize(1);
  screen_->text("Back", 15, 130);
}

/*
*   This method draw the start button
*/
void screen::inicoBoton(bool fill){

  if(fill){
    screen_->fill(255,255,255);
    screen_->stroke(0, 0, 0);
  } else {
    screen_->noFill();
    screen_->stroke(255, 255, 255);
  }

  screen_->rect(66, 120, 62, 30);  //rectangulo start
  screen_->setTextSize(1);
  screen_->text("Start", 80, 130);

}

void screen::fijarEntrada(bool entered){
    entrada_ = entered;
}

bool screen::tomarEntrada(){
  return entrada_;
}

void screen::fijarSubEntrada(bool entered){
    subentrada_ = entered;
}

bool screen::tomarSubEntrada(){
  return subentrada_;
}

int screen::tomarPosicion(){
  return posicion_;
}

int screen::tomarSubPosicion(){
  return subposicion_;
}

void screen::fijarSubPosicion(int posicion){
  subposicion_ = posicion;
}
