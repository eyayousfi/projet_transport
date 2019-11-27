#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "guichet.h"
#include "ticket.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->afficherGuichet->setModel(tmpguichet.afficher());
    ui->afficherTicket->setModel(tmpticket.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::on_ajouterGuichet_clicked()
{
    int prix = ui->PrixAjout->text().toInt();
    int numero_guichet = ui->NumeroAjout->text().toInt();
    QString emplacement= ui->EmplaAjout->text();
  guichet g(numero_guichet,emplacement,prix);
  bool test=g.ajouter();
  if(test)
{ui->afficherGuichet->setModel(tmpguichet.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un guichet"),
                  QObject::tr("Guichet ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un guichet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimerGuichet_clicked()
{
    int numero_guichet = ui->NumeroSupp->text().toInt();
    bool test=tmpguichet.supprimer(numero_guichet);
    if(test)
    {
        ui->afficherGuichet->setModel(tmpguichet.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Guichet"),
                    QObject::tr("Guichet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un guichet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_ajouterTicket_clicked()
{
    int etat = ui->EtatAjout->text().toInt();
    int numero_ticket = ui->NumeroTickAjout->text().toInt();
    int numero_bus= ui->NumBusAjout->text().toInt();
  ticket t(numero_ticket,numero_bus,etat);
  bool test=t.ajouter();
  if(test)
{ui->afficherTicket->setModel(tmpticket.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un ticket"),
                  QObject::tr("Ticket ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_supprimerTicket_clicked()
{

    int numero_ticket = ui->NumeroTickSupp->text().toInt();
    bool test=tmpticket.supprimer(numero_ticket);
    if(test)
    {
        ui->afficherTicket->setModel(tmpticket.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Guichet"),
                    QObject::tr("Guichet supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un guichet"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_modifierTicket_clicked()
{
    int etat = ui->EtatModif->text().toInt();
    int numero_ticket = ui->NumTickModif->text().toInt();
    int numero_bus= ui->NumBusModif->text().toInt();
  ticket t(numero_ticket,numero_bus,etat);
  bool test=t.modifier(numero_ticket);
  if(test)
{ui->afficherTicket->setModel(tmpticket.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un ticket"),
                  QObject::tr("Ticket modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un ticket"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_modifierGuichet_clicked()
{
    int prix = ui->PrixModif->text().toInt();
    int numero_guichet = ui->NumeroModif->text().toInt();
    QString emplacement= ui->EmplaModif->text();
  guichet g(numero_guichet,emplacement,prix);
  bool test=g.modifier(numero_guichet);
  if(test)
{ui->afficherGuichet->setModel(tmpguichet.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Modifier un guichet"),
                  QObject::tr("Guichet modifié.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Modifier un guichet"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
