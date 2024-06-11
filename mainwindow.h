#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include<QDir>
#include<QFileDialog>
#include<QMetaEnum>
#include<QPushButton>
#include<QInputDialog>

#include<Git_Init.h>
#include<Git_Commit.h>
#include<Git_Push.h>
#include<Git_Pull.h>
#include<Git_Clone.h>
#include<Git_Log.h>
#include<Git_Status.h>
#include<Git_Reset.h>
#include<Git_Cherry_Pick.h>
#include<Git_Config.h>
#include<Git_Branch.h>
#include<Git_CheckOut.h>
#include<Git_Merge.h>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void writeOnTerminal(QByteArray Data);
    void onCloneFinished(int exitCode, QProcess::ExitStatus exitStatus);
    void onStateChanged(QProcess::ProcessState newState);
private slots:

    void on_pb_git_init_clicked();
    void on_pb_Browse_clicked();
    void on_pb_git_commit_clicked();
    void on_pb_Back_clicked();
    void on_pb_git_push_clicked();
    void on_pb_Clear_clicked();
    void on_pb_git_log_clicked();
    void on_pb_git_status_clicked();
    void on_pb_git_pull_clicked();
    void on_pb_git_reset_clicked();
    void on_pb_git_clone_clicked();
    void on_pb_go_function_clicked();
    void on_pb_git_cherry_pick_clicked();
    void on_pb_git_branch_clicked();
    void on_pb_create_branch_clicked();
    void on_pb_gotobranch_clicked();
    void on_pb_gitmerge_clicked();

private:
    Ui::MainWindow *ui;

    bool commitFlag;

    Git_Init *gitInit;
    Git_Commit *gitCommit;
    Git_Push *gitPush;
    Git_Pull *gitPull;
    Git_Clone *gitClone;
    Git_Log *gitLog;
    Git_Status *gitStatus;
    Git_Reset *gitReset;
    Git_Cherry_Pick *gitCherryPick;
    Git_Config *gitConfig;
    Git_Branch *gitBranch;
    Git_CheckOut *gitCheckOut;
    Git_Merge *gitMerge;
};
#endif // MAINWINDOW_H
