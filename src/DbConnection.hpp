#pragma once

#include <QSqlDatabase>

class DbConnection
{
public:
    DbConnection() : db(nullptr), m_driver(QString("QSQLITE") /*hardcode!!*/), m_name(QString("database.sqlite")){};

private:
    QSqlDatabase *db;
    const QString m_driver;
    const QString m_name;
};