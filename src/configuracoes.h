#pragma once
#include "Arduino.h"

const int ENTRADA_BOTAO_LIGAR = 27;
const int ENTRADA_BOTAO_TROCA_CORES = 26;
const int ENTRADA_BOTAO_DIMINUIR_LUZ = 14;
const int ENTRADA_BOTAO_AUMENTAR_LUZ = 32;

const int SAIDA_LUZ_BRANCA = 25;
const int SAIDA_LUZ_AMARELA = 33;

const int INTENSIDADE_INICIAL = 50;
const int INTENSIDADE_ZERO = 0;
const int INTENSIDADE_MINIMA = 10;
const int INTENSIDADE_MAXIMA = 100;
const int VALOR_INCREMENTO_INTENSIDADE = 10;

const int LUZ_BRANCA = 0;
const int LUZ_AMARELA = 1;
const int LUZ_BRANCA_E_AMARELA = 2;