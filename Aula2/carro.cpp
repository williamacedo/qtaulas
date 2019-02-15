#include "carro.h"

void carro::set_fab(QString x)
{
    fab=x;
}

void carro::set_ano(QString y)
{
    ano=y;
}

void carro::set_valor(QString z)
{
    valor=z;
}

QString carro::ret_ano(){
    return ano;
}

QString carro::ret_fab(){
    return fab;
}

QString carro::ret_valor(){
    return valor;
}
