#include "Git_Branch.h"


Git_Branch::Git_Branch(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Branch::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Branch::onReadyReadStandardError);
}

void Git_Branch::runCommand(QString branchName)
{
    QStringList arg;
    if(branchName.isEmpty())
    {
        arg<<"branch";
    }
    else
    {
        arg<<"branch"<<branchName;
    }

    qDebug() << "Running command: git branch"<<branchName<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git branch"<<branchName<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git branch"<<branchName<<Qt::endl;
    }
}

void Git_Branch::onReadyReadStandardOutput()
{
    emit gitBranchWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Branch::onReadyReadStandardError()
{
    emit gitBranchWriteToTerminal(Process->readAllStandardError());
}
