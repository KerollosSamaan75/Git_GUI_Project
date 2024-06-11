#ifndef GIT_BRANCH_H
#define GIT_BRANCH_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Branch : public QObject
{
    Q_OBJECT
public:
    explicit Git_Branch(QObject *parent = nullptr);
    void runCommand(QString branchName = "");
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitBranchWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_BRANCH_H
