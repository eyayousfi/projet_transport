#ifndef GUICHET_H
#define GUICHET_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>


class guichet
{
private:
    QString emplacement;
    int prix,numero_guichet;

public:
    guichet();
    guichet(int,QString,int);
    guichet(int,QString);
    QString get_emplacement();
    int get_numero_guichet();
    int get_prix();
    bool ajouter();
    bool modifier(int);
    QSqlQueryModel * afficher();
    bool supprimer(int);
};

#endif // GUICHET_H
