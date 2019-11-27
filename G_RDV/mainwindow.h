#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "rdv.h"
#include "salle.h"
#include <QMainWindow>

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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pushButton_trie_clicked();

    void on_pushButton_recherche_clicked();

    void on_Ajouter_2_clicked();

    void on_pushButton_supp_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_rech_clicked();

    void on_pushButton_trie_2_clicked();

    void on_lineEdit_rech_textChanged(const QString &arg1);

    void on_lineEdit_rech_2_textChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    RDV tmprdv;
    salle tmpsalle;
};
#endif // MAINWINDOW_H
