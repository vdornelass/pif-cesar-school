#include <stdio.h>

/*
 * Questao 23: Calculo de Horario de Termino de Experimento Biologico
 * Le horario de inicio (h, m, s) e duracao total em segundos.
 * Calcula o horario exato de termino no formato hh:mm:ss usando / e %.
 */

int main(void) {
    int h_ini, m_ini, s_ini;
    int duracao_seg;

    printf("Digite o horario inicial (hh mm ss): ");
    if (scanf("%d %d %d", &h_ini, &m_ini, &s_ini) != 3) return 1;

    printf("Digite a duracao do experimento em segundos: ");
    if (scanf("%d", &duracao_seg) != 1) return 1;

    // Converte horario inicial para total em segundos
    int total_segundos = (h_ini * 3600) + (m_ini * 60) + s_ini + duracao_seg;

    // Normaliza para o periodo de 24 horas (86400 segundos)
    int seg_no_dia = total_segundos % 86400;

    int h_fim = seg_no_dia / 3600;
    int m_fim = (seg_no_dia % 3600) / 60;
    int s_fim = seg_no_dia % 60;

    printf("Horario exato de termino: %02d:%02d:%02d\n", h_fim, m_fim, s_fim);
    return 0;
}
