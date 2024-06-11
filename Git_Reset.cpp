#include "Git_Reset.h"

Git_Reset::Git_Reset(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Reset::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Reset::onReadyReadStandardError);
}

void Git_Reset::runCommand()
{
    QStringList arg;
     arg << "reset" << "--hard" << "HEAD~1";

    qDebug() << "Running command: git reset --hard HEAD~1"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git reset --hard HEAD~1"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git reset --hard HEAD~1"<<Qt::endl;
    }
}

void Git_Reset::onReadyReadStandardOutput()
{
    emit gitResetWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Reset::onReadyReadStandardError()
{
    emit gitResetWriteToTerminal(Process->readAllStandardError());
}
