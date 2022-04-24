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
        // pinMode(pino_da_luz, OUTPUT);
        // definirBilho(valor_minimo_brilho);

        pinMode(pino_da_luz, OUTPUT);
        ledcAttachPin(pino_da_luz, canal_para_o_pino);
        ledcSetup(canal_para_o_pino, frequencia_hz, resolucao_em_bits);
        ledcWrite(canal_para_o_pino, valor_minimo_brilho);
    }

    /* void desligado()
     {
         definirBilho(valor_minimo_brilho);
         return;
     }

     void ligado()
     {
         valor_atual_brilho = valor_brilho_quando_ligar;
         definirBilho(valor_atual_brilho);
         return;
     }

     void reduzirBrilho()
     {
         valor_atual_brilho -= nivel_incremento;
         if (valor_atual_brilho < valor_minimo_brilho)
         {
             valor_atual_brilho = valor_minimo_brilho;
         }
         definirBilho(valor_atual_brilho);
         return;
     }

     void aumentarBrilho()
     {
         valor_atual_brilho += nivel_incremento;
         if (valor_atual_brilho > valor_maximo_brilho)
         {
             valor_atual_brilho = valor_maximo_brilho;
         }
         definirBilho(valor_atual_brilho);
         return;
     }

     void definirIncrementoBrilho(int nivel){
         nivel_incremento  = nivel;
     }*/

    int ultimo_valor = -1;

    void definirBilho(int porcentagem_brilho)
    {
        // int min_bri = valor_minimo_brilho;
        // int max_bri = valor_maximo_brilho;
        // int min_bits = valor_minimo_bits_pwm;
        // int max_bits = valor_maximo_bits_pwm;

        // int bytes_de_saida = map(porcentagem_brilho, min_bri, max_bri, min_bits, max_bits);

        int bytes_de_saida = valor_maximo_bits_pwm * porcentagem_brilho / valor_maximo_brilho;

        if (ultimo_valor != bytes_de_saida)
        {
            // analogWrite(pino_da_luz, bytes_de_saida);
            ledcWrite(canal_para_o_pino, bytes_de_saida);
            Serial.print("pino luz: ");
            Serial.print(pino_da_luz);
            Serial.print('\t');
            Serial.print("valor em bites: ");
            Serial.print(bytes_de_saida);
            Serial.println();
            ultimo_valor = bytes_de_saida;
        }
        return;
    }
};