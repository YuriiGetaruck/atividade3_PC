#include <stdio.h>
#include <stdlib.h>
#include <bool.h>


#define MAX=3;

typedef struct{
  int id;
  int RRN;
}chave;

typedef struct{
  int count;
  chave chave[MAX];
  int filhos[MAX+1];
}treeB;

Page inicia(int ordem){

  FILE *arq;
  
  if(arq!=NULL){
    arq=fopen("arvoreB.txt","r+");
  }else{
    arq=fopen("arvoreB.txt","w+");


  }
  
  
  treeB *raiz;
  raiz = malloc(sizeof(treeB));
  raiz.count=0;
  

  
}


int pesquisa(Page raiz, int chave){

  if()
  
  
  
  
} 




int int main(int argc, char const *argv[]) {








  
  return 0;
}
