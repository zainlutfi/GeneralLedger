#ifndef ACCOUNT_TABLE_H
#define ACCOUNT_TABLE_H

#include <qtable.h>

class QKeyEvent;

class Database;
class Settings;

class AccountTable : public QTable
{
    Q_OBJECT
    public:
        AccountTable(QWidget *parent = 0, const char *name = 0);
        ~AccountTable();
        void populate();
        
    signals:
        void goToMain();
        void goToJournal();
        void goToReports();
        void goToHelp();
    
    private slots:
        void updateDb(int, int);
        void edittingChanged(int, int);
        
    private:
        void keyPressEvent(QKeyEvent *event);
        void insert();
        void remove(int row);

        Database *db;
        Settings *settings;

        QString iconPath;
        
        bool editting;
        int edittingRow;
        int edittingCol;

        bool inserting;
        
};

#endif
