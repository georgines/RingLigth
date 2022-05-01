#pragma once
#include "configuracoes.h"

void reduzirBrilho()
{
    intensidade_da_luz_atual -= VALOR_INCREMENTO_INTENSIDADE;
    if (intensidade_da_luz_atual < INTENSIDADE_MINIMA)
    {
        intensidade_da_luz_atual = INTENSIDADE_MINIMA;
    }
}

void aumentarBrilho()
{
    intensidade_da_luz_atual += VALOR_INCREMENTO_INTENSIDADE;
    if (intensidade_da_luz_atual > INTENSIDADE_MAXIMA)
    {
        intensidade_da_luz_atual = INTENSIDADE_MAXIMA;
    }
}

void ligarLuz()
{
    luz_selecionada = LUZ_BRANCA;
    intensidade_da_luz_atual = INTENSIDADE_INICIAL;
}

void desligarLuz()
{
    intensidade_da_luz_atual = INTENSIDADE_ZERO;
}

void trocarCor()
{
    luz_selecionada++;
    if (luz_selecionada > LUZ_BRANCA_E_AMARELA)
    {
        luz_selecionada = LUZ_BRANCA;
    }
}