#pragma once

#include <QObject>

class IssueInfo : public QObject
{
    Q_OBJECT
  public:
    IssueInfo( const QObject* parent = nullptr );

  private:
    QString _title;
    unsigned short _no;
    unsigned short _pages;
    unsigned float _price;
    QString notes;
}