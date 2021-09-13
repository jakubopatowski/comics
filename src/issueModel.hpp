#pragma once

#include<QAbstractTableModel>

class IssueModel: public QAbstractTableModel
{
    public:
        int rowCount(const QModelIndex &) const;
        int columnCount(const QModelIndex &) const;
        QVariant data(const QModelIndex &, int) const;
};