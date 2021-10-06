#pragma once

#include <QObject>

class IssueInfo : public QObject
{
    Q_OBJECT
    Q_PROPERTY( unsigned int id READ id WRITE setId NOTIFY valueChanged );
    Q_PROPERTY( QString title READ title WRITE setTitle NOTIFY valueChanged );
    Q_PROPERTY( unsigned short no READ no WRITE setNo NOTIFY valueChanged );
    Q_PROPERTY( unsigned short pages READ pages WRITE setPages NOTIFY valueChanged );
    Q_PROPERTY( float price READ price WRITE setPrice NOTIFY valueChanged );
    Q_PROPERTY( QString note READ note WRITE setNote NOTIFY valueChanged );

  public:
    IssueInfo( QObject* parent = nullptr );
    ~IssueInfo();

    auto id() const { return m_id; }
    auto title


  private:
    unsigned int m_id;
    QString m_title;
    unsigned short m_no;
    unsigned short m_pages;
    float m_price;
};