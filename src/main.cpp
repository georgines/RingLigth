#include "configuracoes.h"
#include "depuracao.h"
#include "funcoes_ringligth.h"
#include "botao.h"
#include "luz.h"
#include "bluetooth.h"

BotaoPressao BotaoLigar(ENTRADA_BOTAO_LIGAR);
BotaoPressao BotaoDiminuir(ENTRADA_BOTAO_DIMINUIR_LUZ);
BotaoPressao BotaoAumentar(ENTRADA_BOTAO_AUMENTAR_LUZ);
BotaoPressao BotaoTrocaCores(ENTRADA_BOTAO_TROCA_CORES);

Luz LuzBranca(SAIDA_LUZ_BRANCA, CANAL_LUZ_BRANCA);
Luz LuzAmarela(SAIDA_LUZ_AMARELA, CANAL_LUZ_AMARELA);

void mudarLuz(int luz, int intensidade)
{
    switch (luz)
    {
    case LUZ_BRANCA:
        LuzBranca.definirBilho(intensidade);
        LuzAmarela.definirBilho(INTENSIDADE_ZERO);
        break;
    case LUZ_AMARELA:
        LuzBranca.definirBilho(INTENSIDADE_ZERO);
        LuzAmarela.definirBilho(intensidade);
        break;
    case LUZ_BRANCA_E_AMARELA:
        LuzBranca.definirBilho(intensidade);
        LuzAmarela.definirBilho(intensidade);
        break;
    }
}



void setup()
{
    Serial.begin(115200);
    Serial.println("Serial Iniciada");

    BotaoLigar.criar();
    BotaoAumentar.criar();
    BotaoDiminuir.criar();
    BotaoTrocaCores.criar();

    LuzBranca.criar();
    LuzAmarela.criar();

    iniciarBluetooth();
}

void loop()
{
    char comando_recebido = lerbluetooth();

    if (BotaoLigar.pressionadoAgora() || comando_recebido == 'P')
    {
        ring_light_ligado = !ring_light_ligado;

        if (ring_light_ligado)
        {
            ligarLuz();
        }
        else
        {
            desligarLuz();
        }
        mostrarInformacoes();
    }

    if (ring_light_ligado)
    {
        if (BotaoTrocaCores.pressionadoAgora() || comando_recebido == 'T')
        {
            trocarCor();
            mostrarInformacoes();
        }

        if (BotaoDiminuir.pressionadoAgora() || comando_recebido == '<')
        {
            reduzirBrilho();
            mostrarInformacoes();
        }

        if (BotaoAumentar.pressionadoAgora() || comando_recebido == '>')
        {
            aumentarBrilho();
            mostrarInformacoes();
        }
    }

    mudarLuz(luz_selecionada, intensidade_da_luz_atual);
}