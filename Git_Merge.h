#ifndef GIT_MERGE_H
#define GIT_MERGE_H

#include <QObject>
#include <QProcess>
#include<QDebug>

class Git_Merge : public QObject
{
    Q_OBJECT
public:
    explicit Git_Merge(QObject *parent = nullptr);
    void runCommand(QString branchName);
public slots:
    void onReadyReadStandardOutput();
    void onReadyReadStandardError();
signals:
    void gitMergeWriteToTerminal(QByteArray Data);
private:
    QProcess* Process;
};


#endif // GIT_MERGE_H
