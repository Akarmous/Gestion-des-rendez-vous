#ifndef RDV_H
#define RDV_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class RDV
{
public:
    RDV();
    RDV(int,QString,QString);
    QString get_nom();
    QString get_prenom();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool rech(int);
    bool modifier(int,QString,QString);
    QSqlQueryModel * recherche(QString);
    QSqlQueryModel * trie(int);
    bool rech(QString x);
    QSqlQueryModel *Rechercher(long code);





private:
    QString nom,prenom;
    int id;
};

#endif // RDV_H


