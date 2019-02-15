#ifndef CARRO_H
#define CARRO_H
#include<QString>


class carro
{
private:
    QString fab, ano, valor;
public:
    void set_fab(QString x);
    void set_ano(QString z);
    void set_valor(QString z);
    QString ret_fab();
    QString ret_ano();
    QString ret_valor();
};

#endif // CARRO_H
