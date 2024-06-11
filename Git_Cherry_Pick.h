#ifndef GIT_CHERRY_PICK_H
#define GIT_CHERRY_PICK_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Cherry_Pick : public QObject
{
    Q_OBJECT
public:
    explicit Git_Cherry_Pick(QObject *parent = nullptr);
    void runCommand(QString commitHash);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitCherryPickWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};

#endif // GIT_CHERRY_PICK_H
