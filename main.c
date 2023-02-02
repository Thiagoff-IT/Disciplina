#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISCIPLINAS 100

typedef struct DISCIPLINA {
  int cursoCod;
  char cursoNome[10];
  short periodo;
  char codDisc[7];
  char nomeDisc[59];
  int numVagas;
  int cargaHor;
} Disciplina;

Disciplina disciplinas[MAX_DISCIPLINAS];
int numDisciplinas = 0;

void inserirDisciplina() {
  if (numDisciplinas == MAX_DISCIPLINAS) {
    printf("Não é possível inserir mais disciplinas, o limite foi atingido.\n");
    return;
  }

  Disciplina disciplina;
  printf("Insira as informações da disciplina:\n");
  printf("Código do curso: ");
  scanf("%d", &disciplina.cursoCod);
  printf("Nome do curso: ");
  scanf("%s", disciplina.cursoNome);
  printf("Período: ");
  scanf("%hd", &disciplina.periodo);
  printf("Código da disciplina: ");
  scanf("%s", disciplina.codDisc);
  printf("Nome da disciplina: ");
  scanf("%s", disciplina.nomeDisc);
  printf("Número de vagas: ");
  scanf("%d", &disciplina.numVagas);
  printf("Carga horária: ");
  scanf("%d", &disciplina.cargaHor);

  disciplinas[numDisciplinas++] = disciplina;
  printf("Disciplina inserida com sucesso.\n");
}

void listarDisciplina(int indice) {
  if (indice < 0 || indice >= numDisciplinas) {
    printf("Disciplina não encontrada.\n");
    return;
  }

  Disciplina disciplina = disciplinas[indice];
  printf("Código do curso: %d\n", disciplina.cursoCod);
  printf("Nome do curso: %s\n", disciplina.cursoNome);
  printf("Período: %hd\n", disciplina.periodo);
  printf("Código da disciplina: %s\n", disciplina.codDisc);
  printf("Nome da disciplina: %s\n", disciplina.nomeDisc);
  printf("Número de vagas: %d\n", disciplina.numVagas);
  printf("Carga horária: %d\n", disciplina.cargaHor);
}

void listarTodasDisciplinas() {
  printf("Relatório de Disciplinas:\n");
  for (int i = 0; i < numDisciplinas; i++) {
    printf("Disciplina %d:\n", i + 1);
    listarDisciplina(i);
    printf("\n");
  }
}

void removerDisciplina(int indice) {
  if (indice < 0 || indice >= numDisciplinas) {
    printf("Disciplina não encontrada.\n");
    return;
  }

  for (int i = indice; i < numDisciplinas - 1; i++) {
    disciplinas[i] = disciplinas[i + 1];
  }
  numDisciplinas--;
  printf("Disciplina removida com sucesso.\n");
}

void salvarDisciplinas() {
  FILE *arquivo = fopen("disciplinas.txt", "w");
  if (arquivo == NULL) {
    printf("Não foi possível salvar as disciplinas.\n");
    return;
  }

  for (int i = 0; i < numDisciplinas; i++) {
    fprintf(arquivo, "%d\n", disciplinas[i].cursoCod);
    fprintf(arquivo, "%s\n", disciplinas[i].cursoNome);
    fprintf(arquivo, "%hd\n", disciplinas[i].periodo);
    fprintf(arquivo, "%s\n", disciplinas[i].codDisc);
    fprintf(arquivo, "%s\n", disciplinas[i].nomeDisc);
    fprintf(arquivo, "%d\n", disciplinas[i].numVagas);
    fprintf(arquivo, "%d\n", disciplinas[i].cargaHor);
  }

  fclose(arquivo);
  printf("Disciplinas salvas com sucesso.\n");
}

void carregarDisciplinas() {
  FILE *arquivo = fopen("disciplinas.txt", "r");
  if (arquivo == NULL) {
    printf("Não foi possível carregar as disciplinas.\n");
    return;
  }

  while (fscanf(arquivo, "%d\n", &disciplinas[numDisciplinas].cursoCod) == 1) {
    fscanf(arquivo, "%s\n", disciplinas[numDisciplinas].cursoNome);
    fscanf(arquivo, "%hd\n", &disciplinas[numDisciplinas].periodo);
    fscanf(arquivo, "%s\n", disciplinas[numDisciplinas].codDisc);
    fscanf(arquivo, "%s\n", disciplinas[numDisciplinas].nomeDisc);
    fscanf(arquivo, "%d\n", &disciplinas[numDisciplinas].numVagas);
    fscanf(arquivo, "%d\n", &disciplinas[numDisciplinas].cargaHor);
    numDisciplinas++;
  }

  fclose(arquivo);
  printf("Disciplinas carregadas com sucesso.\n");
}

int main() {
carregarDisciplinas();

int opcao;
do {
printf("Escolha uma opção:\n");
printf("1. Inserir disciplina\n");
printf("2. Listar disciplina\n");
printf("3. Listar todas as disciplinas\n");
printf("4. Remover disciplina\n");
printf("5. Sair\n");
scanf("%d", &opcao);

switch (opcao) {
  case 1:
    inserirDisciplina();
    break;
  case 2:
    listarDisciplina(0);
    break;
  case 3:
    listarTodasDisciplinas();
    break;
  case 4:
    removerDisciplina(0);
    break;
  case 5:
    break;
  default:
    printf("Opção inválida.\n");
}

printf("\n");
} while (opcao != 5);

salvarDisciplinas();

return 0;
}
