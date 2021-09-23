#include "sqlite3.h"
#include <iostream>
#include <vector>
#include <memory>
#include "issueModel.hpp"

// main.cpp
#include <QApplication>
#include <QTableView>
#include "mymodel.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel myModel;
    tableView.setModel(&myModel);
    tableView.show();
    return a.exec();
}