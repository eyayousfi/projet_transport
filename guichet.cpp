#include "guichet.h"

guichet::guichet()
{
    numero_guichet=0;
    emplacement="";
    prix=0;
}

guichet::guichet(int numero_guichet,QString emplacement,int prix)
{
  this->numero_guichet=numero_guichet;
  this->emplacement=emplacement;
  this->prix=prix;
}

guichet::guichet(int prix,QString emplacement)
{
  this->emplacement=emplacement;
  this->prix=prix;
}

int guichet::get_numero_guichet(){return  numero_guichet;}
QString guichet::get_emplacement(){return emplacement;}
int guichet::get_prix(){return  prix;}

bool guichet::ajouter()
{
QSqlQuery query;
QString res= QString::number(numero_guichet);
query.prepare("INSERT INTO guichet (NUMERO_GUICHET, EMPLACEMENT, PRIX) "
                    "VALUES (:numero_guichet, :emplacement, :prix)");
query.bindValue(":numero_guichet", res);
query.bindValue(":emplacement", emplacement);
query.bindValue(":prix", prix);

return    query.exec();
}

bool guichet::modifier(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("UPDATE guichet SET EMPLACEMENT=:emplacement, PRIX=:prix WHERE numero_guichet=:numero_guichet");
query.bindValue(":numero_guichet", res);
query.bindValue(":emplacement", emplacement);
query.bindValue(":prix", prix);

return    query.exec();
}

QSqlQueryModel * guichet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from guichet order by NUMERO_GUICHET");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("Numero_guichet"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Emplacement "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prix"));
    return model;
}

bool guichet::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Guichet where NUMERO_GUICHET = :numero_guichet ");
query.bindValue(":numero_guichet", res);
return    query.exec();
}
