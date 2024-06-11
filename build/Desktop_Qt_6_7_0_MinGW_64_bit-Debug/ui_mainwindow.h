/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *lE_username;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *lE_email;
    QPushButton *pb_go_function;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QLineEdit *LE_Directory;
    QPushButton *pb_Browse;
    QPushButton *pb_git_init;
    QTextEdit *Terminal;
    QPushButton *pb_git_commit;
    QPushButton *pb_git_push;
    QPushButton *pb_git_pull;
    QPushButton *pb_git_clone;
    QPushButton *pb_git_reset;
    QPushButton *pb_git_status;
    QPushButton *pb_git_log;
    QPushButton *pb_git_branch;
    QPushButton *pb_create_branch;
    QPushButton *pb_gotobranch;
    QPushButton *pb_gitmerge;
    QPushButton *pb_Back;
    QPushButton *pb_Clear;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(595, 632);
        QIcon icon;
        icon.addFile(QString::fromUtf8("C:/Users/Kirollos/Downloads/icons8-git-48.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tab = new QWidget();
        tab->setObjectName("tab");
        gridLayout = new QGridLayout(tab);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(tab);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_5 = new QLabel(tab);
        label_5->setObjectName("label_5");
        label_5->setPixmap(QPixmap(QString::fromUtf8("C:/Users/Kirollos/Downloads/git-seeklogo.jpg")));
        label_5->setScaledContents(true);

        gridLayout->addWidget(label_5, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        lE_username = new QLineEdit(tab);
        lE_username->setObjectName("lE_username");

        horizontalLayout_2->addWidget(lE_username);


        gridLayout->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");

        horizontalLayout_3->addWidget(label_3);

        lE_email = new QLineEdit(tab);
        lE_email->setObjectName("lE_email");

        horizontalLayout_3->addWidget(lE_email);


        gridLayout->addLayout(horizontalLayout_3, 3, 0, 1, 1);

        pb_go_function = new QPushButton(tab);
        pb_go_function->setObjectName("pb_go_function");
        pb_go_function->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);\n"
"font: 16pt \"Segoe UI\";"));

        gridLayout->addWidget(pb_go_function, 4, 0, 1, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName("gridLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        label_4 = new QLabel(tab_2);
        label_4->setObjectName("label_4");

        verticalLayout->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        LE_Directory = new QLineEdit(tab_2);
        LE_Directory->setObjectName("LE_Directory");

        horizontalLayout->addWidget(LE_Directory);

        pb_Browse = new QPushButton(tab_2);
        pb_Browse->setObjectName("pb_Browse");

        horizontalLayout->addWidget(pb_Browse);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout_2->addLayout(verticalLayout, 0, 0, 1, 2);

        pb_git_init = new QPushButton(tab_2);
        pb_git_init->setObjectName("pb_git_init");
        pb_git_init->setMinimumSize(QSize(85, 0));
        pb_git_init->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_init, 1, 0, 1, 1);

        Terminal = new QTextEdit(tab_2);
        Terminal->setObjectName("Terminal");

        gridLayout_2->addWidget(Terminal, 1, 1, 12, 1);

        pb_git_commit = new QPushButton(tab_2);
        pb_git_commit->setObjectName("pb_git_commit");
        pb_git_commit->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_commit, 2, 0, 1, 1);

        pb_git_push = new QPushButton(tab_2);
        pb_git_push->setObjectName("pb_git_push");
        pb_git_push->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_push, 3, 0, 1, 1);

        pb_git_pull = new QPushButton(tab_2);
        pb_git_pull->setObjectName("pb_git_pull");
        pb_git_pull->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_pull, 4, 0, 1, 1);

        pb_git_clone = new QPushButton(tab_2);
        pb_git_clone->setObjectName("pb_git_clone");
        pb_git_clone->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_clone, 5, 0, 1, 1);

        pb_git_reset = new QPushButton(tab_2);
        pb_git_reset->setObjectName("pb_git_reset");
        pb_git_reset->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_reset, 6, 0, 1, 1);

        pb_git_status = new QPushButton(tab_2);
        pb_git_status->setObjectName("pb_git_status");
        pb_git_status->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_status, 7, 0, 1, 1);

        pb_git_log = new QPushButton(tab_2);
        pb_git_log->setObjectName("pb_git_log");
        pb_git_log->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_log, 8, 0, 1, 1);

        pb_git_branch = new QPushButton(tab_2);
        pb_git_branch->setObjectName("pb_git_branch");
        pb_git_branch->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_git_branch, 9, 0, 1, 1);

        pb_create_branch = new QPushButton(tab_2);
        pb_create_branch->setObjectName("pb_create_branch");
        pb_create_branch->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_create_branch, 10, 0, 1, 1);

        pb_gotobranch = new QPushButton(tab_2);
        pb_gotobranch->setObjectName("pb_gotobranch");
        pb_gotobranch->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_gotobranch, 11, 0, 1, 1);

        pb_gitmerge = new QPushButton(tab_2);
        pb_gitmerge->setObjectName("pb_gitmerge");
        pb_gitmerge->setStyleSheet(QString::fromUtf8("font: 700 12pt \"Segoe UI\";\n"
"font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);"));

        gridLayout_2->addWidget(pb_gitmerge, 12, 0, 1, 1);

        pb_Back = new QPushButton(tab_2);
        pb_Back->setObjectName("pb_Back");
        pb_Back->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);\n"
"font: 12pt \"Segoe UI\";"));

        gridLayout_2->addWidget(pb_Back, 13, 0, 1, 1);

        pb_Clear = new QPushButton(tab_2);
        pb_Clear->setObjectName("pb_Clear");
        pb_Clear->setStyleSheet(QString::fromUtf8("font: 12pt \"Segoe UI\";\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgb(62, 44, 0);\n"
""));

        gridLayout_2->addWidget(pb_Clear, 13, 1, 1, 1);

        tabWidget->addTab(tab_2, QString());

        gridLayout_3->addWidget(tabWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 595, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Git GUI", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:36pt; font-weight:700;\">Welcome to my Git App</span></p></body></html>", nullptr));
        label_5->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Enter your Git username:</span></p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Enter your Git email:</span></p></body></html>", nullptr));
        pb_go_function->setText(QCoreApplication::translate("MainWindow", "Go to Git Functions", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Welcome", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:18pt; font-weight:700;\">Please enter the project directory :</span></p></body></html>", nullptr));
        pb_Browse->setText(QCoreApplication::translate("MainWindow", "Browse", nullptr));
        pb_git_init->setText(QCoreApplication::translate("MainWindow", "git init", nullptr));
        pb_git_commit->setText(QCoreApplication::translate("MainWindow", "git commit", nullptr));
        pb_git_push->setText(QCoreApplication::translate("MainWindow", "git push", nullptr));
        pb_git_pull->setText(QCoreApplication::translate("MainWindow", "git pull", nullptr));
        pb_git_clone->setText(QCoreApplication::translate("MainWindow", "git clone", nullptr));
        pb_git_reset->setText(QCoreApplication::translate("MainWindow", "git reset", nullptr));
        pb_git_status->setText(QCoreApplication::translate("MainWindow", "git status", nullptr));
        pb_git_log->setText(QCoreApplication::translate("MainWindow", "git log", nullptr));
        pb_git_branch->setText(QCoreApplication::translate("MainWindow", "git branch", nullptr));
        pb_create_branch->setText(QCoreApplication::translate("MainWindow", "create branch", nullptr));
        pb_gotobranch->setText(QCoreApplication::translate("MainWindow", "go to branch", nullptr));
        pb_gitmerge->setText(QCoreApplication::translate("MainWindow", "git merge", nullptr));
        pb_Back->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        pb_Clear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "Git Functions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
