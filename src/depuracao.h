#pragma once
#include "configuracoes.h"

void mostrarInformacoes()
{

    Serial.print("ringlight: ");    
    if (ring_light_ligado == true)
    {
        Serial.print("Ligado");
    }
    else
    {
        Serial.print("Desligado");
    }

    Serial.print('\t');
    Serial.print("intensidade da luz (%): ");
    Serial.print(intensidade_da_luz_atual);
    Serial.print('\t');
    Serial.print("luz: ");

    switch (luz_selecionada)
    {
    case LUZ_BRANCA:
        Serial.print("Branca");
        break;
    case LUZ_AMARELA:
        Serial.print("Amarela");
        break;
    case LUZ_BRANCA_E_AMARELA:
        Serial.print("Amarela e Branca");
        break;
    }
    Serial.println();
}