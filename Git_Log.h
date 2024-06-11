#ifndef GIT_LOG_H
#define GIT_LOG_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Log : public QObject
{
    Q_OBJECT
public:
    explicit Git_Log(QObject *parent = nullptr);
    void runCommand();
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitLogWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_LOG_H
