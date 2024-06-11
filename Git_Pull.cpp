#include "Git_Pull.h"


Git_Pull::Git_Pull(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Pull::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Pull::onReadyReadStandardError);
}


void Git_Pull::runCommand(QString URl)
{
    QStringList arg;
    arg << "pull" << URl << "master";

    qDebug() << "Running command: git pull"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git pull"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git pull"<<Qt::endl;
    }
}

void Git_Pull::onReadyReadStandardOutput()
{
    emit gitPullWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Pull::onReadyReadStandardError()
{
    emit gitPullWriteToTerminal(Process->readAllStandardError());
}
