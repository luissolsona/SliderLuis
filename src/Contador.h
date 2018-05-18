class Contador{
  private:
    int N;

  public:
    void SetContador( int n){
      N = n;
    }

    void Incrementar(){
      N++;
    }

    int GetCont(){
      return (N);
    }
};
