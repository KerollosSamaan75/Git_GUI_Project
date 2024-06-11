#include "Git_Process.h"

Git_Process::Git_Process(QObject *parent)
    : QProcess{parent}
{}

void Git_Process::runGitCommand(const QString &command, const QStringList &arg)
{
    qDebug() << "Running command:" << command <<arg;
    this->start(command,arg);
    if (!this->waitForStarted())
    {
        qDebug() << "Failed to start command:" << command <<arg;
        qDebug() <<this->errorString()<<Qt::endl;

        //QMessageBox::critical(this, "Error", "Failed to start git command");
    }
    else
    {
        this->waitForFinished();
        qDebug() << "Command finished:" << command <<arg;
    }
}
