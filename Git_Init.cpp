#include "Git_Init.h"

Git_Init::Git_Init(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Init::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Init::onReadyReadStandardError);
}

void Git_Init::runCommand()
{
    QStringList arg;
    arg<<"init";

    qDebug() << "Running command: git init"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git init"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git init"<<Qt::endl;
    }
}

void Git_Init::onReadyReadStandardOutput()
{
    emit gitInitWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Init::onReadyReadStandardError()
{
    emit gitInitWriteToTerminal(Process->readAllStandardError());
}


