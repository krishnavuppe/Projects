/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *send;
    QTextEdit *disp;
    QLineEdit *type;
    QTextEdit *disp_2;
    QTextEdit *disp_3;
    QTextEdit *disp_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *logout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(598, 307);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        send = new QPushButton(centralWidget);
        send->setObjectName(QStringLiteral("send"));
        send->setGeometry(QRect(490, 190, 81, 41));
        disp = new QTextEdit(centralWidget);
        disp->setObjectName(QStringLiteral("disp"));
        disp->setGeometry(QRect(200, 20, 371, 171));
        type = new QLineEdit(centralWidget);
        type->setObjectName(QStringLiteral("type"));
        type->setGeometry(QRect(200, 190, 291, 41));
        disp_2 = new QTextEdit(centralWidget);
        disp_2->setObjectName(QStringLiteral("disp_2"));
        disp_2->setGeometry(QRect(200, 20, 371, 171));
        disp_3 = new QTextEdit(centralWidget);
        disp_3->setObjectName(QStringLiteral("disp_3"));
        disp_3->setGeometry(QRect(200, 20, 371, 171));
        disp_4 = new QTextEdit(centralWidget);
        disp_4->setObjectName(QStringLiteral("disp_4"));
        disp_4->setGeometry(QRect(200, 20, 371, 171));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(20, 10, 131, 51));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(20, 70, 131, 51));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(20, 130, 131, 51));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(20, 190, 131, 51));
        username = new QLineEdit(centralWidget);
        username->setObjectName(QStringLiteral("username"));
        username->setGeometry(QRect(150, 50, 291, 41));
        password = new QLineEdit(centralWidget);
        password->setObjectName(QStringLiteral("password"));
        password->setGeometry(QRect(150, 110, 291, 41));
        logout = new QPushButton(centralWidget);
        logout->setObjectName(QStringLiteral("logout"));
        logout->setGeometry(QRect(510, 0, 61, 16));
        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 598, 19));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        send->setText(QApplication::translate("MainWindow", "Send", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Akhil", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Chaitu", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Alekya", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "Ravi", Q_NULLPTR));
        logout->setText(QApplication::translate("MainWindow", "Logout", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
