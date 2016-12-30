#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "publisher.h"
#include "subscriber.h"

extern string username;
extern unsigned long password;
extern int disp;
extern unsigned long countid[4];
extern unsigned long msgid[4];
extern unsigned long recvcounter[4];

namespace Ui {
class MainWindow;
}

class CB_Publisher;
class CB_Subscriber;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_type_returnPressed();

    void on_password_returnPressed();

    void on_logout_clicked();

private:
    Ui::MainWindow  *ui;
    QMessageBox     info;
    CB_Publisher    *pb;
    CB_Subscriber   *sb;
};

#endif // MAINWINDOW_H
