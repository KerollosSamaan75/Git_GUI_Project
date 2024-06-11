#include "Git_Cherry_Pick.h"

Git_Cherry_Pick::Git_Cherry_Pick(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Cherry_Pick::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Cherry_Pick::onReadyReadStandardError);
}

void Git_Cherry_Pick::runCommand(QString commitHash)
{
    QStringList arg;
    arg << "cherry-pick" << commitHash;

    qDebug() << "Running command: git cherry-pick"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git cherry-pick"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git cherry-pick"<<Qt::endl;
    }
}

void Git_Cherry_Pick::onReadyReadStandardOutput()
{
    emit gitCherryPickWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Cherry_Pick::onReadyReadStandardError()
{
    emit gitCherryPickWriteToTerminal(Process->readAllStandardError());
}
