#include "issueModel.hpp"

int IssueModel::rowCount(const QModelIndex& /*index*/) const {
    return 1;
}

int IssueModel::columnCount(const QModelIndex& /*index*/) const {
    return 5;
}

QVariant IssueModel::data(const QModelIndex& index, int x) const {
    return QVariant();
}