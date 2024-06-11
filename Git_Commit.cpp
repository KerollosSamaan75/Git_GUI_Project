#include "Git_Commit.h"

Git_Commit::Git_Commit(QObject *parent)
    : QObject{parent}
{
    Process = new QProcess;
    connect(Process,&QProcess::readyReadStandardOutput,this,&Git_Commit::onReadyReadStandardOutput);
    connect(Process,&QProcess::readyReadStandardError,this,&Git_Commit::onReadyReadStandardError);

}

void Git_Commit::runCommand(QString CommitMessage)
{
    QStringList addarg;
    QStringList commitarg;

    addarg<<"add"<<".";
    qDebug() << "Running command: git add"<<Qt::endl;
    Process->start("git",addarg);

    if (!Process->waitForStarted())
    {
        qDebug() << "Failed to start command: git add"<<Qt::endl;
        qDebug() <<Process->errorString()<<Qt::endl;
    }
    else
    {
        Process->waitForFinished();
        qDebug() << "Command finished: git add"<<Qt::endl;

        commitarg<<"commit"<<"-m"<<" \"" + CommitMessage + "\"";
        qDebug() << "Running command: git commit"<<Qt::endl;
        Process->start("git",commitarg);
        if (!Process->waitForStarted())
        {
            qDebug() << "Failed to start command: git add"<<Qt::endl;
            qDebug() <<Process->errorString()<<Qt::endl;
        }
        else
        {
            Process->waitForFinished();
            qDebug() << "Command finished: git commit"<<Qt::endl;
        }
    }
}

void Git_Commit::onReadyReadStandardOutput()
{
    emit gitCommitWriteToTerminal(Process->readAllStandardOutput());
}

void Git_Commit::onReadyReadStandardError()
{
    emit gitCommitWriteToTerminal(Process->readAllStandardError());
}
