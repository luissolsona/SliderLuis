#include <TFT.h>
#include <SPI.h>

#define cs   10
#define dc   9
#define rst  8

class screen{
  public:
    screen();
    void set();
//    void welcome();
    int tomarPosicion();
    void fijarPosicion(int posicion);
    int tomarSubPosicion();
    void fijarSubPosicion(int posicion);
    void menu();
    void trabajando();
    void actualizarFlecha();
    void atrasBoton(bool fill);
    void inicoBoton(bool fill);
    int sumaPosicion();
    int restaPosicion();
    int sumaSubPosicion();
    int restaSubPosicion();
    void fijarEntrada(bool entered);
    bool tomarEntrada();
    void fijarSubEntrada(bool entered);
    bool tomarSubEntrada();
    void porPosicion(int posicion);
    void porTiempo(long int timing);
    void porCiclo(bool state);
  private:
    int posicion_;
    bool entrada_;
    int subposicion_;
    bool subentrada_;
    TFT* screen_;
    char* numero_;
};
