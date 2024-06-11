#include "Git_CheckOut.h"

Git_CheckOut::Git_CheckOut(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_CheckOut::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_CheckOut::onReadyReadStandardError);
}


void Git_CheckOut::runCommand(QString branchName)
{
    QStringList arg;
    arg<<"checkout"<<branchName;

    qDebug() << "Running command: git checkout "<<branchName<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git checkout "<<branchName<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git checkout "<<branchName<<Qt::endl;
    }
}

void Git_CheckOut::onReadyReadStandardOutput()
{
    emit gitCheckOutWriteToTerminal(Process->readAllStandardOutput());
}

void Git_CheckOut::onReadyReadStandardError()
{
    emit gitCheckOutWriteToTerminal(Process->readAllStandardError());
}
