// programa principal do projeto "The Boys - 2024/2"
// Autor: Murilo de Paula Bob, GRR 20242184

#include <stdio.h>
#include <stdlib.h>
#include "fprio.h"
#include "conjunto.h"
#include "lista.h"

#define NHEROIS   10
#define NBASES    10
#define NMISSOES  10
#define T_FIM_DO_MUNDO 525600
#define 
#define
/*
#define CHEGA     0
#define ESPERA    1
#define DESISTE   2
#define AVISA     3
#define ENTRA     4
#define SAI       5
#define VIAJA     6
#define MORRE     7
#define MISSAO    8
#define FIM       9
*/
// minimize o uso de variáveis globais

//struct de cada elemento do mundo
struct heroi
{ 
  unsigned int ID;
  unsigned int pac;
  unsigned int vel;
  unsigned int exp;
  unsigned int baseID; 
  struct cjto_t* hab;
};

struct base 
{
  unsigned int ID;
  unsigned int lota;
  struct cjto_t* heroiPres;
  struct fprio_t* filaEsp;
  unsigned int y;
  int x;
};

struct missao
{
  unsigned int ID;
  struct cjto_t* habs;
  unsigned int perigo;
  unsigned int x;
  int y;
};

struct mundo 
{
  struct heroi herois[NHEROIS];
  struct base bases[NBASES];
  struct missao missoes[NMISSOES];

  unsigned int NHab;
  int TamMundo;

  unsigned int relogio; //Minutos
};

//struct dos tipos de evento 
// TODO: pensar em nome melhor 

struct evento1 
{
  struct heroi heroi;
  struct base base;
  struct mundo mundo;
};

struct evento2
{
  struct base base;
  struct mundo mundo;
};

struct evento3
{
  struct missao missao;
  struct mundo mundo;
};

struct evento4
{
  struct mundo mundo;
};


void chega(int tempo, struct heroi heroi, struct base base, struct fprio_t lef, struct mundo mundo)
{
  int espera;
  struct evento1 eventoEsp; 
  //Mudando a base do heroi
  heroi.baseID = base.ID;

  //Se tiver espaco na base e a fila de espera for 0
  if(base.heroiPres.num < base.lota && base.filaEsp.num == 0)
  {
    espera = 1;    
  }
  else 
  {
    espera = heroi.pac > 10 * base.filaEsp.num;
  }
  
  //inicializando os componentes do evento  
  eventoEsp.heroi = heroi;
  eventoEsp.mundo = mundo;
  eventoEsp.base = base;

  if(espera)
  {
    //Inserindo na lista de eventos futuros
    lef.num = fprio_insere(lef, eventoEsp, 1, 0);
  }
  else
  {
    lef.num = fprio_insere(lef, eventoEsp, 2, 0);
  }

}
int main ()
{
  /*
   * tipo:
   * 0 = chega THB 
   * 1 = espera THB
   * 2 = desiste THB
   * 3 = avisa TB
   * 4 = entra THB
   * 5 = sai THB
   * 6 = viaja THB
   * 7 = morre THB
   * 8 = missao TM
   * 9 = fim T
   */
  struct fprio_t lef; 
  // iniciar o mundo

  // executar o laço de simulação

  // destruir o mundo

  return (0) ;
}


