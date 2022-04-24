#include "configuracoes.h"
#include "botao.h"
#include "luz.h"

BotaoPressao BotaoLigar(ENTRADA_BOTAO_LIGAR);
BotaoPressao BotaoDiminuir(ENTRADA_BOTAO_DIMINUIR_LUZ);
BotaoPressao BotaoAumentar(ENTRADA_BOTAO_AUMENTAR_LUZ);
BotaoPressao BotaoTrocaCores(ENTRADA_BOTAO_TROCA_CORES);

Luz LuzBranca(SAIDA_LUZ_BRANCA);
Luz LuzAmarela(SAIDA_LUZ_AMARELA);

bool ring_light_ligado = false;
int luz_selecionada = LUZ_BRANCA;
int intensidade_da_luz_atual = INTENSIDADE_ZERO;

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

void estadoLuzAtual()
{
    switch (luz_selecionada)
    {
    case LUZ_BRANCA:
        LuzBranca.definirBilho(intensidade_da_luz_atual);
        LuzAmarela.definirBilho(INTENSIDADE_ZERO);
        break;
    case LUZ_AMARELA:
        LuzBranca.definirBilho(INTENSIDADE_ZERO);
        LuzAmarela.definirBilho(intensidade_da_luz_atual);
        break;
    case LUZ_BRANCA_E_AMARELA:
        LuzBranca.definirBilho(intensidade_da_luz_atual);
        LuzAmarela.definirBilho(intensidade_da_luz_atual);
        break;
    }
}

void deupurar()
{
    Serial.print("intensidade: ");
    Serial.print(intensidade_da_luz_atual);
    Serial.print('\t');
    Serial.print("luz: ");
    Serial.print(luz_selecionada);
    Serial.println();
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

    // pinMode(3, OUTPUT);
    // pinMode(11, OUTPUT);
    // TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
    // TCCR2B = _BV(CS22);
    // OCR2A = 180;
    // OCR2B = 50;
}

void loop()
{
    if (BotaoLigar.pressionadoAgora())
    {
        ring_light_ligado = !ring_light_ligado;

        if (ring_light_ligado)
        {
            Serial.println("ligado");
            ligarLuz();
        }
        else
        {
            Serial.println("desligado");
            desligarLuz();
        }
        deupurar();
    }

    if (ring_light_ligado)
    {
        if (BotaoTrocaCores.pressionadoAgora())
        {
            Serial.println("troca de cores");
            trocarCor();
            deupurar();
        }

        if (BotaoDiminuir.pressionadoAgora())
        {
            Serial.println("reduzir luzes");
            reduzirBrilho();
            deupurar();
        }

        if (BotaoAumentar.pressionadoAgora())
        {
            Serial.println("aumentar luzes");
            aumentarBrilho();
            deupurar();
        }
    }

    estadoLuzAtual();
}