#ifndef TICKET_H
#define TICKET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class ticket
{
private:
    int numero_ticket,etat,numero_bus;
public:
    ticket();
    ticket(int,int,int);
    int get_numero_ticket();
    int get_numero_bus();
    int get_etat();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // TICKET_H
