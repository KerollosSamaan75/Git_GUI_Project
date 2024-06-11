#ifndef GIT_COMMIT_H
#define GIT_COMMIT_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Commit : public QObject
{
    Q_OBJECT
public:
    explicit Git_Commit(QObject *parent = nullptr);
    void runCommand(QString CommitMessage);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitCommitWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_COMMIT_H
