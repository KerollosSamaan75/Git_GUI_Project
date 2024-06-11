#ifndef GIT_CHECKOUT_H
#define GIT_CHECKOUT_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_CheckOut : public QObject
{    Q_OBJECT
public:
    explicit Git_CheckOut(QObject *parent = nullptr);
    void runCommand(QString branchName);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitCheckOutWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};


#endif // GIT_CHECKOUT_H
