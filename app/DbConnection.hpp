#pragma once

#include <QSqlDatabase>

class DbConnection
{
  public:
    DbConnection( const QString& driver = QString( "QSQLITE" ), const QString& name = QString( "database.sqlite" ) )
        : db( nullptr ), m_driver( driver ), m_name( name ){};

  private:
    QSqlDatabase* db;
    const QString m_driver;
    const QString m_name;
};