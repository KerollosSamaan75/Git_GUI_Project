#ifndef GIT_RESET_H
#define GIT_RESET_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Reset : public QObject
{
    Q_OBJECT
public:
    explicit Git_Reset(QObject *parent = nullptr);
    void runCommand();
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitResetWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_RESET_H
