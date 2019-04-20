#include<stdio.h>
#include <string.h>
#define MAX 50
/*
Desenvolvedor - David Machado da silva
Curso-Redes de computadores
Instituição - Ifpb
*/
typedef int telem;// telem é telem

typedef struct no {
     telem matricula,idade;
     char nome[MAX];
     char curso[MAX];
     struct no *prox;
} tno;
typedef tno *tlista;
/////////////////////////////////////////////////////////////////
void criar (tlista *L) {//cria a cabeça da lisca inicializando com NULL
     *L = NULL;
}
//////////////////////////////////////////////////////////////
int vazia (tlista L) {
     return (L == NULL);
}
/////////////////////////////////////////////////////////////
int tamanho (tlista L) { //Retorna um valor inteiro correspondente o tamanho de "nós" da lista
     tlista p = L;
     int n = 0;
     while (p != NULL) {
        p = p->prox;
        n++;
     }
     return (n);
}
////////////////////////////////////////////////////////////////////////
int inserirDados (tlista *L, int pos ) {//insere o nó de acordo com a posição desejada pelo usuario
     tlista p, novo;
     int n;
     if (*L == NULL)//testa se a lista está vazia
       if (pos != 1)//se ela for vazia obrigatoriamente tem que ser a primeira posição
         return (0);
     novo = (tlista) malloc(sizeof(tno)); // aloca memoria pra um nó do tipo tlista
     if (novo == NULL)//verifica se foi realmente alocado
        return (0);

     printf("Digite o nome :");
     scanf("%s",novo->nome);
     printf("Digite o Curso :");
     scanf("%s",novo->curso);
     printf("Digite idade :");
     scanf("%d",&novo->idade);
     printf("Digite Matricula :");
     scanf("%d",&novo->matricula);
////////////////////////////////////////////////
     if((pos == 1)&&(*L == NULL)){  // Se for o primeiro elemento da lista
       novo->prox = NULL; //inicializa o prox do primeiro nó
       *L = novo; // insere o indereço do primeiro nó na cabeça da lista
       return (1);
     }
////////////////////////////////////////////////////////
     if((pos == 1)&&(*L != NULL)){//inserir no primeiro nó ,se já existir nós na lista
        novo->prox = *L; // prox é apontada para o primeiro elemento
        *L = novo; // a cabeça da lista recebe o nó criado
        return (1);
     }
 ///////////////////////////////////////////////////////////
     // se tiver no meio da lista
      p = *L;
      n = 1;
      while ((n < pos-1) && (p != NULL)) {
        p = p->prox;
        n++;
      }
      if (p == NULL)
        return (0);

      novo->prox = p->prox;
      p->prox = novo;
      return (1);
  }
/////////////////////////////////////////////////////////////////////////
  int verificaCurso (tlista L, char curso[MAX]) {//Verifica a string informada pelo usuario com a que tem no campo curso da estrutura
      tlista tmp;
      int a = 0;
      tmp = L;
      for (tmp = L; tmp!= NULL; tmp = tmp->prox){
        if (strcmp(tmp->curso,curso) == 0){
          printf("|Aluno = %s||Curso = %s|\n", tmp->nome,tmp->curso);
          a = 1;
        }
      }
      return a;
  }
/////////////////////////////////////////////////////////////////////////////////////
  int maiorDeIdade(tlista L){//verifica todos os elementos que contem o campo idade maior ou igual a 18 anos
      tlista tmp;
      int a = 0;
      for (tmp = L; tmp!= NULL; tmp = tmp->prox){
        if (tmp->idade >= 18){
           printf("|Aluno = %s||Idade = %d|\n",tmp->nome,tmp->idade);
           a = 1;
        }
      }
      system("pause");
      return a;
  }
//////////////////////////////////////////////////////////////////////////////////////
