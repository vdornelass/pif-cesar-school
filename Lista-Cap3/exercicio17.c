#include <stdio.h>

/*
 * Questao 17: Estatisticas de Turma (Menor, Maior, Media e Contagem)
 * Le uma sequencia de notas de alunos (de 0.0 a 10.0) ate o sentinela -1.0.
 * Exibe o total de alunos avaliados, a maior nota, a menor nota e a media geral da turma.
 */

int main(void) {
    double nota;
    double soma = 0.0;
    double maior = 0.0;
    double menor = 10.0;
    int total_alunos = 0;

    printf("Digite as notas dos alunos (0.0 a 10.0). Para encerrar, digite -1.0:\n");

    while (1) {
        printf("Nota do aluno %d: ", total_alunos + 1);
        if (scanf("%lf", &nota) != 1) {
            while (getchar() != '\n');
            printf("Entrada invalida! Digite uma nota valida.\n");
            continue;
        }

        // Condicao de parada sentinela
        if (nota == -1.0) {
            break;
        }

        // Validacao do intervalo permitido
        if (nota < 0.0 || nota > 10.0) {
            printf("Nota invalida! As notas devem estar entre 0.0 e 10.0 (ou -1.0 para sair).\n");
            continue;
        }

        if (total_alunos == 0) {
            maior = nota;
            menor = nota;
        } else {
            if (nota > maior) maior = nota;
            if (nota < menor) menor = nota;
        }

        soma += nota;
        total_alunos++;
    }

    printf("\n=== Estatisticas da Turma ===\n");
    if (total_alunos > 0) {
        printf("a) Total de alunos avaliados: %d\n", total_alunos);
        printf("b) Maior nota da turma:       %.2f\n", maior);
        printf("c) Menor nota da turma:       %.2f\n", menor);
        printf("d) Media geral da turma:      %.2f\n", soma / total_alunos);
    } else {
        printf("Nenhum aluno foi avaliado.\n");
    }

    return 0;
}
