#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "guichet.h"
#include "ticket.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouterGuichet_clicked();

    void on_supprimerGuichet_clicked();

    void on_ajouterTicket_clicked();

    void on_supprimerTicket_clicked();

    void on_modifierTicket_clicked();

    void on_modifierGuichet_clicked();

private:
    Ui::MainWindow *ui;
    guichet tmpguichet;
    ticket tmpticket;
};
#endif // MAINWINDOW_H
