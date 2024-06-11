#ifndef GIT_PUSH_H
#define GIT_PUSH_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Push : public QObject
{
    Q_OBJECT
public:
    explicit Git_Push(QObject *parent = nullptr);
    void runCommand(QString URl , QString Branch);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitPushWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_PUSH_H
