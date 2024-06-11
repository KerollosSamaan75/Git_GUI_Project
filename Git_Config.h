#ifndef GIT_CONFIG_H
#define GIT_CONFIG_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Config : public QObject
{
    Q_OBJECT
public:
    explicit Git_Config(QObject *parent = nullptr);
    void runCommand(QString username,QString email);
private:
    QProcess* Process;
};

#endif // GIT_CONFIG_H
