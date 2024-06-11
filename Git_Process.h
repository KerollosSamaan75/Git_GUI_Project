#ifndef GIT_PROCESS_H
#define GIT_PROCESS_H

#include<QObject>
#include<QDebug>
#include<QProcess>
#include<QMessageBox>

class Git_Process : public QProcess
{
    Q_OBJECT
public:
    explicit Git_Process(QObject *parent = nullptr);
    void runGitCommand(const QString &command,const QStringList &arg);
signals:
};

#endif // GIT_PROCESS_H
