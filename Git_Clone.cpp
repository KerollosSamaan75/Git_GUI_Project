#include "Git_Clone.h"

Git_Clone::Git_Clone(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Clone::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Clone::onReadyReadStandardError);
    connect(Process, &QProcess::finished, this, &Git_Clone::onCloneFinished);
    connect(Process,&QProcess::stateChanged,this,&Git_Clone::onStateChanged);
}

void Git_Clone::runCommand(QString remoteRepoUrl)
{
    QStringList arg;
    arg << "clone" << remoteRepoUrl;

    qDebug() << "Running command: git clone"<<Qt::endl;
    Process->start("git",arg);
    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git clone"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git clone"<<Qt::endl;
    }
}

void Git_Clone::onReadyReadStandardOutput()
{
    emit gitCloneWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Clone::onReadyReadStandardError()
{
    emit gitCloneWriteToTerminal(Process->readAllStandardError());
}

void Git_Clone::onCloneFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    emit CloneFinished(exitCode,exitStatus);
}

void Git_Clone::onStateChanged(QProcess::ProcessState newState)
{
    emit StateChanged(newState);
}
