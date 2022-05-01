#pragma once
#include "Arduino.h"
#include "BluetoothSerial.h"

BluetoothSerial nosso_bt;
// String dados_recebidos;
// const int TAMANHO_MAXIMO_COMANDOS = 100;

void iniciarBluetooth()
{
    // dados_recebidos.reserve(TAMANHO_MAXIMO_COMANDOS);
    nosso_bt.begin("RingLinght");
}

char lerbluetooth()
{

    if (nosso_bt.available())
    {
        return nosso_bt.read();
        
    }
    return -1;
}
