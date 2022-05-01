#pragma once
#include "Arduino.h"
class BotaoPressao
{

private:
    bool trava = false;
    // bool estado_botao_pressionado = false;
    int pino_do_botao = 0;
    // unsigned long tempo_atual = 0;
    unsigned long tempo_anterior = 0;
    unsigned long tempo_de_trava = 0;

public:
    void criar()
    {
        pinMode(pino_do_botao, INPUT_PULLUP);
        return;
    }

    bool pressionadoAgora()
    {

        if (pinoBotaoPressionadoAgora())
        {            
            resetCroneometro();
            if (respostaDesbloqueadaAgora())
            {
                bloqueiaResposta();
                return true;
            }
        }
        else
        {
            if (fimDoCronometroAgora())
            {
                desbloqueiaResposta();
            }
        }
        return false;
    }

    BotaoPressao(int pino_btn, unsigned long tempo_trv = 250)
    {
        pino_do_botao = pino_btn;
        tempo_de_trava = tempo_trv;
    }

    ~BotaoPressao()
    {
    }

private:
    void bloqueiaResposta()
    {
        trava = true;
    }

    void desbloqueiaResposta()
    {
        trava = false;
    }

    bool respostaDesbloqueadaAgora()
    {
        if (!trava)
        {
            return true;
        }
        return false;
    }

    bool fimDoCronometroAgora()
    {
        if (pegarTempoAtual() - tempo_anterior >= tempo_de_trava)
        {
            return true;
            resetCroneometro();
        }
        return false;
    }

    void resetCroneometro()
    {
        tempo_anterior = pegarTempoAtual();
    }

    unsigned long pegarTempoAtual()
    {
        return millis();
    }

    bool pinoBotaoPressionadoAgora()
    {
        int estado_atual = digitalRead(pino_do_botao);
        bool botao_pressionado = estado_atual == LOW;
        return botao_pressionado;
    }
};