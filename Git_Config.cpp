#include "Git_Config.h"

Git_Config::Git_Config(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
}

void Git_Config::runCommand(QString username,QString email)
{
    QStringList userarg;
    QStringList emailarg;

    userarg << "config" << "--global" << "user.name" << username;
    qDebug() << "Running command: git config --global user.name"<<username<<Qt::endl;

    Process->start("git",userarg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git config --global user.name"<<username<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git config --global user.name"<<username<<Qt::endl;
    }

    emailarg << "config" << "--global" << "user.email" << email;
    qDebug() << "Running command: git config --global user.email"<<email<<Qt::endl;

    Process->start("git",emailarg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git config --global user.email"<<email<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git config --global user.email"<<email<<Qt::endl;
    }
}
