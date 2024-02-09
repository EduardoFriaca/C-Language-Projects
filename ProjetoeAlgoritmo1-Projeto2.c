// Grupo (Integrantes):
// Nome: Eduardo Honorio Friaca     Tia: 42205794
// Nome: Gabriel Mason Guerino      Tia: 42240328
// Nome: Pedro Akira Cardoso Toma   Tia: 42207002

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Criação do tipo Aluno
typedef struct {
  int ano;
  char nome[50];
  char disciplina[20];
  float nota;
} Aluno;

void EntradaAleatoria(char *arquivo, int quantidadeAlunos) {
  srand(time(NULL));              // gerador de números aleatórios
  FILE *fp = fopen(arquivo, "w"); // abre o arquivo
  char *disciplinas[] = {"matemática", "português", "geografia"};  // lista de disciplinas
  char *nomes[] = {"Eduardo", "Pedro",  "Gabriel", "Caroline", "Rebecca", // lista de nomes
                   "Helena",  "Rafael", "Sara",    "Beatriz",  "Vitória",
                   "Natália", "Felipe", "Yuki",    "Iago",     "Ana",
                   "João",    "Diogo",  "Zack",    "Leonardo", "Marina"};
  int i;

  for (i = 0; i < quantidadeAlunos; i++) {
    Aluno aluno;
    aluno.ano = 2010 + rand() % 14; // gera um ano aleatorio entre 2010 e 2023
    sprintf(aluno.nome, "%s%d", nomes[rand() % 20], rand() % 1000); // gera um nome para o aluno
    strcpy(aluno.disciplina, disciplinas[rand() % 3]); // disciplina aleatoria
    aluno.nota =
        (float)rand() / RAND_MAX * 10; // nota aleatoria entre 0.0 e 10.0

    // informacoes do aluno no arquivo
    fprintf(fp, "%d,%s,%s,%.2f\n", aluno.ano, aluno.nome, aluno.disciplina,
            aluno.nota);
  }

  fclose(fp); // fecha o arquivo
}

void bubbleSort(Aluno *alunos, int quantidadeAlunos,
                long *passos) { // bubbleSort com long, pois com valores maiores
                                // estourou o limite de int
  int i, j;
  for (i = 0; i < quantidadeAlunos - 1; i++) {
    for (j = 0; j < quantidadeAlunos - i - 1; j++) {
      if (alunos[j].nota > alunos[j + 1].nota) {
        Aluno temp = alunos[j];
        alunos[j] = alunos[j + 1];
        alunos[j + 1] = temp;
      }
      (*passos)++;
    }
  }
}

void merge(Aluno *alunos, int inicio, int meio, int fim,
           long *passos) { // MergeSort
  int i, j, k;
  int n1 = meio - inicio + 1;
  int n2 = fim - meio;

  // arrays ('L' e 'R') dinamicamente alocados para não ocorrer Stack Overflow
  Aluno *L = (Aluno *)malloc(n1 * sizeof(Aluno));
  Aluno *R = (Aluno *)malloc(n2 * sizeof(Aluno));

  for (i = 0; i < n1;
       i++) // copiei os dados para os arrays L e R
    L[i] = alunos[inicio + i];
  for (j = 0; j < n2; j++)
    R[j] = alunos[meio + 1 + j];

  /* juntei os arrays de volta para o array alunos[inicio..fim]*/
  i = 0;      // indice inicial do primeiro subarray
  j = 0;      // indice inicial do segundo subarray
  k = inicio; // indice inicial do subarray misturado
  while (i < n1 && j < n2) {
    (*passos)++; // contagem dos passos para cada vez q houver elemento em L comparado com elemento em R
    if (L[i].nota <= R[j].nota) {
      alunos[k] = L[i];
      i++;
    } else {
      alunos[k] = R[j];
      j++;
    }
    k++;
  }
  /* Copia os elementos restantes de L, se tiver */
  while (i < n1) {
    alunos[k] = L[i];
    i++;
    k++;
  }

  /* Copia os elementos restantes de R, se tiver */
  while (j < n2) {
    alunos[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(Aluno *alunos, int inicio, int fim, long *passos) {
  if (inicio < fim) {
    // (inicio+fim)/2, evitando overflow para grandes valores de inicio e fim
    int meio = inicio + (fim - inicio) / 2;

    // Ordena primeira e segunda metades
    mergeSort(alunos, inicio, meio, passos);
    mergeSort(alunos, meio + 1, fim, passos);
    merge(alunos, inicio, meio, fim, passos);
  }
}

void imprimirAlunos(char *arquivo, Aluno *alunos, int quantidadeAlunos) {
  FILE *fp = fopen(arquivo, "r"); // abre o arquivo para leitura
  int i;

  for (i = 0; i < quantidadeAlunos; i++) {
    fscanf(fp, "%d,%[^,],%[^,],%f\n", &alunos[i].ano, alunos[i].nome,
           alunos[i].disciplina,
           &alunos[i].nota); // le a informacoes do aluno do arquivo
  }

  fclose(fp); // fecha o arquivo
}

void inserirAlunos(char *arquivo, Aluno *alunos, int quantidadeAlunos) {
  FILE *fp = fopen(arquivo, "w"); // abre o arquivo para escrita
  int i;

  for (i = 0; i < quantidadeAlunos; i++) {
    fprintf(fp, "%d,%s,%s,%.2f\n", alunos[i].ano, alunos[i].nome,
            alunos[i].disciplina,
            alunos[i].nota); // imprime as informacoes do aluno no arquivo
  }
  fclose(fp); // fecha o arquivo
}

int main() {
  int opcao, quantidadeAlunos;
  long int passos = 0;
  bool finalizar = false;

  // loop para execução do programa e verificação de entrada
  while (!finalizar) {

    // menu
    printf("1. Gerar entrada aleatoria\n");
    printf("2. Ordenar por nota (Bubble Sort)\n");
    printf("3. Ordenar por nota (Merge Sort)\n");
    printf("Escolha uma opcao:");
    scanf("%d", &opcao);
    switch (opcao) {
    case 1: {
      printf("Digite a quantidade de alunos: ");
      scanf("%d", &quantidadeAlunos);
      EntradaAleatoria("entrada.csv", quantidadeAlunos);
      break;
    }
    case 2: {
      // se não houver arquivo "entrada.csv" retora erro
      if (!(fopen("entrada.csv", "r"))) {
        printf("\nErro! Entrada Aleatória Não Foi Criada!\n");
      } else {
        Aluno *alunos = (Aluno *)malloc(quantidadeAlunos * sizeof(Aluno)); // aloca memórica para vetor alunos
        // aqui eh a leitura dos dados do arquivo
        imprimirAlunos("entrada.csv", alunos, quantidadeAlunos);
        clock_t inicio = clock(); // inicia contagem de tempo
        bubbleSort(alunos, quantidadeAlunos, &passos);
        clock_t fim = clock(); // encerra contagem de tempo
        double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC; // calcula tempo total
        // inserção de dados dos Alunos em arquivo saida.csv (ordenados)
        inserirAlunos("saida.csv", alunos, quantidadeAlunos);
        // aqui imprimi os resultados com o tempo e as comparacoes
        printf("\nAlgoritmo: Bubble Sort\n");
        printf("Tamanho Entrada: %d\n", quantidadeAlunos);
        printf("Tempo execução: %f segundos\n", tempo_total);
        printf("Comparações (passos): %ld\n", passos);
        free(alunos); // libera memória do vetor Alunos
        finalizar = true;
      }
      break;
    }
    case 3: {
      // se não houver arquivo "entrada.csv" retora erro
      if (!(fopen("entrada.csv", "r"))) {
        printf("\nErro! Entrada Aleatória Não Foi Criada!\n");
      } else {
        Aluno *alunos = (Aluno *)malloc(quantidadeAlunos * sizeof(Aluno));
        // aqui eh a leitura dos dados do arquivo
        imprimirAlunos("entrada.csv", alunos, quantidadeAlunos);
        clock_t inicio = clock(); // inicia contagem de tempo
        mergeSort(alunos, 0, quantidadeAlunos - 1, &passos);
        clock_t fim = clock(); // encerra contagem de tempo
        double tempo_total = (double)(fim - inicio) / CLOCKS_PER_SEC; // calcula tempo total
        // inserção de dados dos Alunos em arquivo saida.csv (ordenados)
        inserirAlunos("saida.csv", alunos, quantidadeAlunos);
        // aqui imprimi os resultados com o tempo e as comparacoes
        printf("\nAlgoritmo: Merge Sort\n");
        printf("Tamanho Entrada: %d\n", quantidadeAlunos);
        printf("Tempo execução: %f segundos\n", tempo_total);
        printf("Comparações (passos): %ld\n", passos);
        free(alunos); // libera memória do vetor Alunos
        finalizar = true;
      }
      break;
    }
    default:
      printf("Opcao invalida\n"); // erro na entrada de opção
    }
  }

  return 0;
}
