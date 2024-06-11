#ifndef GIT_INIT_H
#define GIT_INIT_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Init : public QObject
{
    Q_OBJECT
public:
    explicit Git_Init(QObject *parent = nullptr);
    void runCommand();
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitInitWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_INIT_H
