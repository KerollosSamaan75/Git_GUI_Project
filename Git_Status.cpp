#include "Git_Status.h"

Git_Status::Git_Status(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Status::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Status::onReadyReadStandardError);
}

void Git_Status::runCommand()
{
    QStringList arg;
    arg<<"status";

    qDebug() << "Running command: git status"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git status"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git status"<<Qt::endl;
    }
}

void Git_Status::onReadyReadStandardOutput()
{
    emit gitStatusWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Status::onReadyReadStandardError()
{
    emit gitStatusWriteToTerminal(Process->readAllStandardError());
}
