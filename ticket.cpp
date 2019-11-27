#include "ticket.h"
ticket::ticket()
{
numero_ticket=0;
numero_bus=0;
etat=0;
}
ticket::ticket(int numero_ticket,int numero_bus,int etat)
{
  this->numero_ticket=numero_ticket;
  this->numero_bus=numero_bus;
  this->etat=etat;
}
int ticket::get_numero_ticket(){return  numero_ticket;}
int ticket::get_numero_bus(){return numero_bus;}
int ticket::get_etat(){return  etat;}

bool ticket::ajouter()
{
QSqlQuery query;
QString res= QString::number(numero_ticket);
query.prepare("INSERT INTO ticket (NUMERO_TICKET, NUMERO_BUS, ETAT) "
                    "VALUES (:numero_ticket, :numero_bus, :etat)");
query.bindValue(":numero_ticket", res);
query.bindValue(":numero_bus", numero_bus);
query.bindValue(":etat", etat);

return    query.exec();
}

QSqlQueryModel * ticket::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from ticket order by NUMERO_TICKET");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero_ticket"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numero_bus "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Etat"));
    return model;
}

bool ticket::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from ticket where NUMERO_TICKET = :numero_ticket ");
query.bindValue(":numero_ticket", res);
return    query.exec();
}

bool ticket::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE ticket SET NUMERO_BUS=:numero_bus, ETAT=:etat WHERE numero_ticket=:numero_ticket");
query.bindValue(":numero_ticket", res);
query.bindValue(":numero_bus", numero_bus);
query.bindValue(":etat", etat);

return    query.exec();
}
