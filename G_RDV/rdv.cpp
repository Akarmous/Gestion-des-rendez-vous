#include "rdv.h"
#include <QDebug>
#include <QString>

RDV::RDV()
{
    id=0;
    nom="";
    prenom="";
}

RDV::RDV(int id,QString nom,QString prenom)
{
    this->id=id;
    this->nom=nom;
    this->prenom=prenom;
}
  QString RDV::get_nom(){return  nom;}
  QString RDV::get_prenom(){return prenom;}
  int RDV::get_id(){return  id;}

bool RDV::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO Rendezvous (ID, NOM, PRENOM) "
                    "VALUES (:id, :nom, :prenom)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);

return    query.exec();
}

QSqlQueryModel * RDV::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Rendezvous");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
    return model;
}

bool RDV::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from Rendezvous where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}

bool RDV::rech(int x){
    QSqlQuery query;
    QString res= QString::number(x);

    query.prepare("select * from Rendezvous where id = :id");
    query.bindValue(":id", res);
    return query.exec();
}

bool RDV::modifier(int a,QString b,QString c){
    QSqlQuery query;
    query.prepare("update Rendezvous set nom=:nom ,prenom=:prenom   where id = :id");
    query.bindValue(":id", a);
    query.bindValue(":nom", b);
    query.bindValue(":prenom", c);

    return query.exec();
}

QSqlQueryModel * RDV::Rechercher(long id)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QString res=QString::number(id);
    model->setQuery("select * from Rendezvous where (id LIKE '"+res+"%' ) ");
            model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));


            return  model;
}

QSqlQueryModel * RDV::trie(int)
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from Rendezvous order by id");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    return model;
}


