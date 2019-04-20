#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include"Exercicio.h"
/*
Desenvolvedor - David Machado da silva
Curso-Redes de computadores
Instituição - Ifpb
*/
int main(){
  setlocale(LC_ALL, "Portuguese");
  int quantidade,pos;
  tlista lista,tmp;
  telem valor;
  criar(&lista);
  char opc,curso[MAX];
  do{
    system("cls");
    puts("|--------------------------------|");
    puts("|       Inscrição de alunos      |");
    puts("|                                |");
    puts("|      1-Exibir lista            |");
    puts("|      2-Inserir Aluno           |");
    puts("|      3-Procurar Curso          |");
    puts("|      4-Maior de 18             |");
    puts("|    ESC-Sair                    |");
    puts("| Digite sua Opção:              |");
    puts("|--------------------------------|");
    opc = getch();
    switch(opc){
 /////////////////////////////////////////////////////////////////////////////
      case'1':{
        system("cls");
        printf("tamanho %d\n",tamanho(lista));
        if (vazia(lista)){
          puts("lista vazia !");
          system("pause");
          break;
        }
        tmp = lista;
        for (tmp = lista; tmp!= NULL; tmp = tmp->prox){
           puts("---------------------------------------");
           printf("|matricula = %d|\n", tmp->matricula);
           printf("|Curso = %s|",tmp->curso);
           printf("|Nome = %s|\n",tmp->nome);
           printf("|Idade = %d|\n",tmp->idade);
           puts("---------------------------------------");
        }
        system("pause");
      break;
      }
///////////////////////////////////////////////////////////////////////////////////////////////////////
      case'2':{
         system("cls");
         printf("Digite a posição :");
         scanf("%d",&pos);
        if(inserirDados (&lista,pos)){
           puts("inserido com sucesso !");
         }else{
           puts("verifique a posição informada e tente novamente !");
         }
         system("pause");
      break;
      }
/////////////////////////////////////////////////////////////////////////////////////////
      case'3':{
          system("cls");
          printf("Digite o Curso :");
          scanf("%s",curso);
          if(!(verificaCurso (lista,curso))){
            puts("não existe esse curso na lista");
          }
          system("pause");
      break;
      }
      case '4':{
        system("cls");
        if(!(maiorDeIdade(lista))){
          puts("Não existe maior de idade");
          system("pause");
        }
      break;
      }
     }
  }while(opc != 27);
}
