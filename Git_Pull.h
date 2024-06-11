#ifndef GIT_PULL_H
#define GIT_PULL_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Pull : public QObject
{
    Q_OBJECT
public:
    explicit Git_Pull(QObject *parent = nullptr);
    void runCommand(QString URl);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitPullWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_PULL_H
