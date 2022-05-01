#pragma once
#include "Arduino.h"

class Luz
{
private:
    int valor_minimo_bits_pwm = 0;
    int valor_maximo_bits_pwm = 0;
    int valor_minimo_brilho = 0;
    int valor_maximo_brilho = 0;
    int valor_brilho_quando_ligar = 0;
    int pino_da_luz = 0;
    int valor_atual_brilho;
    int nivel_incremento = 1;
    int canal_para_o_pino = 0;
    int frequencia_hz = 1000;
    int resolucao_em_bits = 10;
    int ultimo_valor_bites_de_saida = -1;

public:
    Luz(int pino_luz, int canal, int brilho_quando_ligar = 50, int brilho_minimo = 0, int brilho_maximo = 100, int total_bits_pwm = 1024)
    {
        pino_da_luz = pino_luz;
        valor_brilho_quando_ligar = brilho_quando_ligar;
        valor_minimo_brilho = brilho_minimo;
        valor_maximo_brilho = brilho_maximo;
        valor_maximo_bits_pwm = total_bits_pwm - 1;
        canal_para_o_pino = canal;
    }

    ~Luz()
    {
    }

    void criar()
    {
        pinMode(pino_da_luz, OUTPUT);
        ledcAttachPin(pino_da_luz, canal_para_o_pino);
        ledcSetup(canal_para_o_pino, frequencia_hz, resolucao_em_bits);
        ledcWrite(canal_para_o_pino, valor_minimo_brilho);
    }

    void definirBilho(int porcentagem_brilho)
    {
        int bites_de_saida = valor_maximo_bits_pwm * porcentagem_brilho / valor_maximo_brilho;

        if (ultimo_valor_bites_de_saida != bites_de_saida)
        {
            ledcWrite(canal_para_o_pino, bites_de_saida);
            ultimo_valor_bites_de_saida = bites_de_saida;
        }
        return;
    }
};