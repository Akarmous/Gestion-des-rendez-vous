#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "rdv.h"
#include "salle.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit_id->setValidator( new QRegExpValidator( QRegExp("[0-9]{5,5}"), this ) );
    ui->lineEdit_nom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,32}"), this ));
    ui->lineEdit_prenom->setValidator(new QRegExpValidator( QRegExp("[A-Za-z]{0,32}"), this ));
    ui->tab_RDV->setModel(tmprdv.afficher());


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
  RDV v(id,nom,prenom);
  bool test=v.ajouter();
  if(test)
{ui->tab_RDV->setModel(tmprdv.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un Rendezvous"),
                  QObject::tr("Rendezvous ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter un Rendezvous"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}



void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->lineEdit_id_2->text().toInt();
    bool test=tmprdv.supprimer(id);
    if(test)
    {ui->tab_RDV->setModel(tmprdv.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un Rendezvous"),
                    QObject::tr("Rendezvous supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un Rendezvous"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pb_modifier_clicked()
{
    int id = ui->lineEdit_id_3->text().toInt();
    QString nom = ui->lineEdit_nom_2->text();
    QString prenom = ui->lineEdit_prenom_2->text();

    RDV v;
    if(v.rech(id)){

        bool test = v.modifier(id,nom,prenom);
        if(test){
            ui->tab_RDV->setModel(tmprdv.afficher());
            QMessageBox::information(nullptr,QObject::tr("Rendezvous modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}



void MainWindow::on_pushButton_trie_clicked()
{
    int id = ui->lineEdit_rech->text().toInt();

    ui->tab_RDV->setModel(tmprdv.trie(id));//refresh
}



void MainWindow::on_Ajouter_2_clicked()
{
    int num = ui->lineEdit_num->text().toInt();
    QString bloc= ui->lineEdit_bloc->text();

  salle s(num,bloc);
  bool test=s.ajouter();
  if(test)
{ui->tab_salle->setModel(tmpsalle.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une salle"),
                  QObject::tr("salle ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("Ajouter une salle"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_supp_clicked()
{
    int num = ui->lineEdit_num_2->text().toInt();
    bool test=tmpsalle.supprimer(num);
    if(test)
    {ui->tab_salle->setModel(tmpsalle.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("salle supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une salle"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pushButton_clicked()
{
    int num = ui->lineEdit_num_3->text().toInt();
    QString bloc = ui->lineEdit_bloc_2->text();
    salle s;
    if(s.rech(num)){

        bool test = s.modifier(num,bloc);
        if(test){
            ui->tab_salle->setModel(tmpsalle.afficher());
            QMessageBox::information(nullptr,QObject::tr("salle modifier"),QObject::tr("click cancel to exit!"),QMessageBox::Cancel);
        }
    }
}



void MainWindow::on_pushButton_trie_2_clicked()
{
    int  num = ui->lineEdit_rech->text().toInt();

    ui->tab_salle->setModel(tmpsalle.trie(num));//refresh
}


void MainWindow::on_lineEdit_rech_textChanged(const QString &arg1)
{

        long id=ui->lineEdit_rech->text().toLong();
        ui->tab_RDV->setModel(tmprdv.Rechercher(id));

}

void MainWindow::on_lineEdit_rech_2_textChanged(const QString &arg1)
{
    long num=ui->lineEdit_rech_2->text().toLong();
    ui->tab_salle->setModel(tmpsalle.Rechercher(num));
}
