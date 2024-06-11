#include "Git_Push.h"

Git_Push::Git_Push(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Push::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Push::onReadyReadStandardError);
}


void Git_Push::runCommand(QString URl , QString Branch)
{
    QStringList arg;
    arg << "push" << URl << Branch;

    qDebug() << "Running command: git push"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git push"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git push"<<Qt::endl;
    }
}

void Git_Push::onReadyReadStandardOutput()
{
    emit gitPushWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Push::onReadyReadStandardError()
{
    emit gitPushWriteToTerminal(Process->readAllStandardError());
}
