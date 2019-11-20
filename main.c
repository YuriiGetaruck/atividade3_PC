#include <stdio.h>
#include <stdlib.h>
#include <bool.h>


#define MAX=3;

typedef struct key{
  int id;
  int RRN;
}key;

typedef struct NOtreeB{
  int count;
  key chave[MAX];
  int filhos[MAX+1];
}NOtreeB;

NOtreeB driver(int ordem){

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


bool pesquisa(int RRN, key chave,int *FOUND_RRN,int *FOUND_POS){

  FILE *arq;
  char buffer[10];
  int a;

  if(RRN=-1){
    pritnf("chave nao encontrada")
  }else{
    arq=fopen("arvoreB.txt","r");
    fread(buffer,1,1,"arvoreB.txt");
    a=atoi(buffer);
    fseek()
    
    
  }
  
  
  
  
} 




int int main(int argc, char const *argv[]) {








  
  return 0;
}
