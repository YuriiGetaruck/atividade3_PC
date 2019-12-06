/*
* @file treeB.h
* @author Gustavo Lázaro and Yuri Getaruck
* @date 20 Nov 2019
* @brief Implementacao da árvore B
* Implementa a árvore B vista na disciplina
* pesquisa e classificacao de dados.
*/

#ifndef UNTITLED_TREEB_H
#define UNTITLED_TREEB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX 3
#define TAM_REGISTRO 56

typedef struct key{
    int ID;
    int RRN;
}key;

typedef struct NOtreeB{

    int count; //Quantos elementos a árvore tem
    key chave[MAX];
    int filhos[MAX+1];

}NOtreeB;

int particiona(key *V, int inicio, int fim);
/**
 * \brief Função recursiva usada pela quick sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * Funcao coloca o valor do pivo no seu lugar, garantindo que esse numero esteja ordenado
 */

void quicksort(key *V, int inicio, int fim);
/**
 * \brief Método de organização quick sort
 *
 * \param V vetor a ser organizado
 * \param inicio posicao do vetor inicial para comecar a organizar
 * \param fim tamanho do vetor
 *
 * Funcao recursiva que ordena o vetor por meio da quick sort
 */

void criaIndice(FILE *arq, int tamanho, key *vetor);

/**
 * \brief Funcao que cria um indice primario com ID e RRN, ordenado pelo ID
 *
 * \param arq arquivo de texto a ser escrito
 * \param tamanho tamanho do vetor de registro
 * \param vetor vetor de registros a serem utilizados
 *
 * Cria um indice primario
 */

NOtreeB driver(int ordem);
/**
 * \brief Cria uma árvore B de n ordem
 *
 * \param ordem ordem da árvore B a ser criada
 *
 * Cria uma árvore B com ordem definida pelo usuário;
 */

int destroyTree(NOtreeB **tree);
/**
 * \brief Destrói uma árvore B
 *
 * \param tree árvore B a ser destruida
 *
 * Destrói uma árvore B;
 */

bool pesquisa(int RRN, int key, int *FOUND_RRN, int *FOUND_POS);
/**
 * \brief Pesquisa um elemento em uma árvore B
 *
 * \param RRN Página atual onde será pesquisado a chave
 * \param key Chave que será pesquisada
 * \param FOUND_RRN RRN do arquivo onde foi achado a chave
 * \param FOUND_POS posição na árvore onde foi achado
 *
 * Procura uma chave na árvore B;
 */

int insert(int CURRENT_RRN, key chave, int PROMO_R_CHILD, key PROMO_KEY);
/**
 * \brief Insere um elemento em uma árvore B
 *
 * \param CURRENT_RRN Página atual onde será pesquisado a chave
 * \param Chave que será inserida
 * \param PROMO_R_CHILD RRN filho da direita
 * \param PROMO_KEY chave promovida
 *
 * Insere uma chave na árvore B;
 */


 
 void em_ordem(Apontador raiz)//printa arvore
{
    int i;
    if (raiz != NULL){
         for (i = 0; i < raiz->n; i++){
            em_ordem(raiz->p[i]);
            printf("%d ", raiz->r[i].chave);
            printf("\n");
          }
         em_ordem(raiz->p[i]);
    }
}

void buscainFile(Registro Reg, Apontador pagina){//--- ta sendo usada na func BUSCA
	Registro reg[2*ORDEM];
	int i;
	FILE *arq = fopen(namefile,"rb");
	if (arq == NULL)
	exit(1);
	fseek(arq, pagina->pageNum*(2*ORDEM*sizeof(Registro)), SEEK_SET);
	fread(reg, (2*ORDEM*sizeof(Registro)),1,arq);
	fclose(arq);
	for(i = 0; i < 2*ORDEM; i++){
		if (Reg.chave == reg[i].chave)
		printf("%s%d\n",reg[i].nome,reg[i].idade);
    }
}

void Busca(NOtreeB Reg, Apontador Ap){//BUSCA ----não faço ideia do que é esse apontador (tem no codigo do cara mas nao entendi)
  int i;

      if (Ap == NULL){
        printf("chave nao encontrada: %d\n", Reg.chave);
        return;
      }
  i = 1;
  while (i < Ap->n && Reg.chave > Ap->r[i - 1].chave)
  i++;
      if (Reg.chave == Ap->r[i - 1].chave){
        printf("chave: %d \n", Reg.chave);
        buscainFile(Ap->r[i-1],Ap);
        return;
      }
  if (Reg.chave < Ap->r[i - 1].chave)
    Busca(Reg, Ap->p[i-1]);
  else
    Busca(Reg, Ap->p[i]);
}

void InsereNaPagina(Apontador Ap, NOtreeB Reg, Apontador ApDir){//------ NAO SEI O QUE É APOTADOR, PARECE QUE É UMA STRUCT A PARTE 
	
  int k;
  int NaoAchouPosicao;

  k = Ap->n;
  NaoAchouPosicao = k > 0;
      while (NaoAchouPosicao){
        if (Reg.chave >= Ap->r[k - 1].chave){
          NaoAchouPosicao = 0;
          break;
        }
        
        Ap->r[k] = Ap->r[k - 1];
        
        Ap->p[k + 1] = Ap->p[k];
        
        k--;
        if (k < 1)
          NaoAchouPosicao = 0;
      }
  Ap->r[k] = Reg;
  Ap->p[k + 1] = ApDir;
  Ap->n++;
}  




#endif //UNTITLED_TREEB_H
