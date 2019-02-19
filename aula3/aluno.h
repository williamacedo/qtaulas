#ifndef ALUNO_H
#define ALUNO_H
#include<QString>

class Aluno
{
private:
        QString nome, endereco,idade;
public:
        void set_nome(QString x) {
            nome=x;
        }

        void set_endereco(QString y) {
            endereco=y;
        }

        void set_idade(QString z) {
            idade=z;
        }

        QString ret_nome() {
            return nome;
        }

        QString ret_endereco() {
            return endereco;
        }

        QString ret_idade() {
            return idade;
        }

};

#endif // ALUNO_H
