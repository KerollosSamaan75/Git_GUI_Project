#ifndef GIT_STATUS_H
#define GIT_STATUS_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Status : public QObject
{
    Q_OBJECT
public:
    explicit Git_Status(QObject *parent = nullptr);
    void runCommand();
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitStatusWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_STATUS_H
