#ifndef GIT_CLONE_H
#define GIT_CLONE_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Clone : public QObject
{ 
    Q_OBJECT
public:
    explicit Git_Clone(QObject *parent = nullptr);
    void runCommand(QString remoteRepoUrl);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
    void onCloneFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onStateChanged(QProcess::ProcessState newState);
signals:
    void gitCloneWriteToTerminal(QByteArray Data);
    void CloneFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void StateChanged(QProcess::ProcessState newState);
private:
    QProcess* Process;
};

#endif // GIT_CLONE_H
