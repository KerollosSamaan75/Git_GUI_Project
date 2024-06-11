#include "Git_Merge.h"

Git_Merge::Git_Merge(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Merge::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Merge::onReadyReadStandardError);
}


void Git_Merge::runCommand(QString branchName)
{
    QStringList arg;
    arg<<"merge"<<branchName;

    qDebug() << "Running command: git merge "<<branchName<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git merge "<<branchName<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git merge "<<branchName<<Qt::endl;
    }
}

void Git_Merge::onReadyReadStandardOutput()
{
    emit gitMergeWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Merge::onReadyReadStandardError()
{
    emit gitMergeWriteToTerminal(Process->readAllStandardError());
}
