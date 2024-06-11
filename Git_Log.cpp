#include "Git_Log.h"

Git_Log::Git_Log(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Log::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Log::onReadyReadStandardError);
}


void Git_Log::runCommand()
{
    QStringList arg;
    arg<<"log";

    qDebug() << "Running command: git log"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git log"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git log"<<Qt::endl;
    }
}

void Git_Log::onReadyReadStandardOutput()
{
    emit gitLogWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Log::onReadyReadStandardError()
{
    emit gitLogWriteToTerminal(Process->readAllStandardError());
}
