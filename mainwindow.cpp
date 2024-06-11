#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lE_username->setText("KerollosSamaan75");
    ui->lE_email->setText("kiro.samaan.kodoos@gmail.com");
    gitInit = new Git_Init;
    gitCommit = new Git_Commit;
    gitPush = new Git_Push;
    gitPull = new Git_Pull;
    gitClone = new Git_Clone;
    gitLog = new Git_Log;
    gitStatus = new Git_Status;
    gitReset = new Git_Reset;
    gitCherryPick = new Git_Cherry_Pick;
    gitConfig = new Git_Config;
    gitBranch = new Git_Branch;
    gitCheckOut = new Git_CheckOut;
    gitMerge = new Git_Merge;

    connect(gitInit,&Git_Init::gitInitWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitCommit,&Git_Commit::gitCommitWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitPush,&Git_Push::gitPushWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitPull,&Git_Pull::gitPullWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitLog,&Git_Log::gitLogWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitStatus,&Git_Status::gitStatusWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitReset,&Git_Reset::gitResetWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitCherryPick,&Git_Cherry_Pick::gitCherryPickWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitBranch,&Git_Branch::gitBranchWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitCheckOut,&Git_CheckOut::gitCheckOutWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitMerge,&Git_Merge::gitMergeWriteToTerminal,this,&MainWindow::writeOnTerminal);

    connect(gitClone,&Git_Clone::gitCloneWriteToTerminal,this,&MainWindow::writeOnTerminal);
    connect(gitClone,&Git_Clone::CloneFinished,this,&MainWindow::onCloneFinished);
    connect(gitClone,&Git_Clone::StateChanged,this,&MainWindow::onStateChanged);


    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::writeOnTerminal(QByteArray Data)
{
    QString str = QString(Data);
    ui->Terminal->append(str);
}

void MainWindow::on_pb_go_function_clicked()
{
    QString username = ui->lE_username->text();
    QString useremail = ui->lE_email->text();
    if (username.isEmpty() || username.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please enter a username and email");
        return ;
    }
    else
    {
        gitConfig->runCommand(username,useremail);
        ui->tabWidget->setTabEnabled(1,true);
        ui->tabWidget->setTabEnabled(0,false);
    }
}
void MainWindow::on_pb_Back_clicked()
{
    ui->tabWidget->setTabEnabled(0,true);
    ui->tabWidget->setTabEnabled(1,false);
    ui->Terminal->clear();
}

void MainWindow::on_pb_Clear_clicked()
{
    ui->Terminal->clear();
}

void MainWindow::on_pb_Browse_clicked()
{
    QString dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),"", QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty())
    {
        ui->LE_Directory->setText(dir);
    }
}

void MainWindow::on_pb_git_init_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;

    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (dir.exists(".git"))
    {

        QMessageBox::information(this, "Info", "This directory already contains a Git local repository.\nyou don't need to create another one");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            gitInit->runCommand();
        }
    }
}

void MainWindow::on_pb_git_commit_clicked()
{
    commitFlag = false;
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;

    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    else
    {
        if(QDir::setCurrent(directoryPath) && dir.exists(".git"))
        {
            bool ok;
            QString commitMessage = QInputDialog::getText(this, tr("Commit Message"),
                                                          tr("Enter your commit message:"), QLineEdit::Normal,
                                                          "", &ok);
            if (!ok || commitMessage.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Commit message is required");
                return;
            }
            gitCommit->runCommand(commitMessage);
            commitFlag = true;
        }
        else
        {
            QMessageBox::warning(this, "Error", "You should create local repository before click commit \nclick git init to create local repo.");
            return ;
        }
    }
}


void MainWindow::on_pb_git_push_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "directoryPath: " << directoryPath << Qt::endl;

    if (directoryPath.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return;
    }

    QDir dir(directoryPath);
    if (!dir.exists())
    {
        QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return;
    }

    if (!dir.exists(".git"))
    {
        QMessageBox::critical(this, "Error", "This directory doesn't have a local repository.\n"
                                             "You should click init to create a local repository and click commit before push.");
        commitFlag = false;
        return;
    }

    if (QDir::setCurrent(directoryPath))
    {
        if (commitFlag == true)
        {
            bool ok;
            QString remoteRepoUrl = QInputDialog::getText(this, tr("Remote Repository URL"),
                                                          tr("Enter the remote repository URL:"), QLineEdit::Normal,
                                                          "", &ok);
            if (!ok || remoteRepoUrl.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Remote repository URL is required");
                return;
            }

            bool ok_2;
            QString branch = QInputDialog::getText(this, tr("Branch name"),
                                                   tr("Enter the Branch name:"), QLineEdit::Normal,
                                                   "", &ok_2);
            if (!ok_2 || branch.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Branch name is required");
                return;
            }

            // Check if the branch exists
            QString branchRef = "refs/heads/" + branch;
            QStringList arg;
            arg << "show-ref" << "--verify" << "--quiet" << branchRef;
            QProcess process;
            process.start("git", arg);
            process.waitForFinished();
            int exitCode = process.exitCode();

            if (exitCode != 0) // branch does not exist
            {
                QMessageBox::critical(this, "Error", "Branch not found. The specified branch does not exist.");
                return;
            }
            else
            {
                gitPush->runCommand(remoteRepoUrl, branch);
            }
        }
        else
        {
            QMessageBox::warning(this, "Warning", "You should click commit before pushing your project.");
            return;
        }
    }
}




void MainWindow::on_pb_git_log_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;
    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (!dir.exists(".git"))
    {

        QMessageBox::critical(this, "Error", "This directory don't have local repository\n"
                                             "You should click init to create local repository");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            gitLog->runCommand();
        }
    }
}


void MainWindow::on_pb_git_status_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;
    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (!dir.exists(".git"))
    {

        QMessageBox::critical(this, "Error", "This directory don't have local repository\n"
                                             "You should click init to create local repository");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            gitStatus->runCommand();
        }
    }
}


void MainWindow::on_pb_git_pull_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "directoryPath: " << directoryPath <<Qt::endl;


    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if(!dir.exists(".git"))
    {
        QMessageBox::critical(this, "Error", "This directory don't have local repository");
        return ;
    }
    if(QDir::setCurrent(directoryPath))
    {

        bool ok;
        QString remoteRepoUrl = QInputDialog::getText(this, tr("Remote Repository URL"),
                                                      tr("Enter the remote repository URL:"), QLineEdit::Normal,
                                                      "", &ok);
        if (!ok || remoteRepoUrl.isEmpty())
        {
            QMessageBox::critical(this, "Error", "Remote repository URL is required");
            return;
        }
        gitPull->runCommand(remoteRepoUrl);

    }
}


void MainWindow::on_pb_git_reset_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;
    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (!dir.exists(".git"))
    {

        QMessageBox::critical(this, "Error", "This directory don't have local repository\n"
                                             "You should click init to create local repository");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            gitReset->runCommand();
        }
    }
}


void MainWindow::on_pb_git_clone_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "directoryPath: " << directoryPath <<Qt::endl;


    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            bool ok;
            QString remoteRepoUrl = QInputDialog::getText(this, tr("Remote Repository URL"),
                                                          tr("Enter the remote repository URL:"), QLineEdit::Normal,
                                                          "", &ok);
            if (!ok || remoteRepoUrl.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Remote repository URL is required");
                return;
            }
            gitClone->runCommand(remoteRepoUrl);
        }
    }
}
void MainWindow::onCloneFinished(int exitCode, QProcess::ExitStatus exitStatus)
{
    if (exitStatus == QProcess::CrashExit)
    {
        QMessageBox::warning(this, "Error", "The clone process crashed.");
    }
    else if (exitCode != 0)
    {
        QMessageBox::warning(this, "Error", "The clone process failed.");
    }
    else
    {
        QMessageBox::information(this, "Success", "Repository cloned successfully.");
    }
}

void MainWindow::onStateChanged(QProcess::ProcessState newState)
{
    QMetaEnum meta = QMetaEnum::fromType<QProcess::ProcessState>();
    ui->Terminal->append(meta.valueToKey(newState));
}





void MainWindow::on_pb_git_cherry_pick_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "directoryPath: " << directoryPath <<Qt::endl;

    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if(!dir.exists(".git"))
    {
        QMessageBox::critical(this, "Error", "This directory don't have local repository");
        return ;
    }
    if(QDir::setCurrent(directoryPath))
    {
        bool ok;
        QString commitHash = QInputDialog::getText(this, tr("Cherry-Pick Commit"),
                                                   tr("Enter the commit hash to cherry-pick:"), QLineEdit::Normal,
                                                   "", &ok);
        if (!ok || commitHash.isEmpty())
        {
            QMessageBox::critical(this, "Error", "Commit hash is required");
            return;
        }
        gitCherryPick->runCommand(commitHash);
    }
}


void MainWindow::on_pb_git_branch_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;
    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (!dir.exists(".git"))
    {

        QMessageBox::critical(this, "Error", "This directory don't have local repository\n"
                                             "You should click init to create local repository");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            gitBranch->runCommand();
        }
    }
}


void MainWindow::on_pb_create_branch_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath <<Qt::endl;
    if (directoryPath.isEmpty())
    {   QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return ;
    }
    QDir dir(directoryPath);
    if (!dir.exists())
    {   QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return ;
    }
    if (!dir.exists(".git"))
    {

        QMessageBox::critical(this, "Error", "This directory don't have local repository\n"
                                             "You should click init to create local repository");
        return;
    }
    else
    {
        if(QDir::setCurrent(directoryPath))
        {
            bool ok;
            QString branchName = QInputDialog::getText(this, tr("Branch Name"),
                                                       tr("Enter the branch name you want to create:"), QLineEdit::Normal,
                                                       "", &ok);
            if (!ok || branchName.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Branch name is required");
                return;
            }
            gitBranch->runCommand(branchName);
        }
    }
}


void MainWindow::on_pb_gotobranch_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath << Qt::endl;
    if (directoryPath.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return;
    }

    QDir dir(directoryPath);
    if (!dir.exists())
    {
        QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return;
    }

    if (!dir.exists(".git"))
    {
        QMessageBox::critical(this, "Error", "This directory doesn't have a local repository.\n"
                                             "You should click init to create a local repository.");
        return;
    }
    else
    {
        if (QDir::setCurrent(directoryPath))
        {
            bool ok;
            QString branchName = QInputDialog::getText(this, tr("Branch Name"),
                                                       tr("Enter the branch name you want to create:"), QLineEdit::Normal,
                                                       "", &ok);
            if (!ok || branchName.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Branch name is required");
                return;
            }

            // Check if the branch exists
            QString branchRef = "refs/heads/" + branchName;
            QStringList arg;
            arg << "show-ref" << "--verify" << "--quiet" << branchRef;
            QProcess process;
            process.start("git", arg);
            process.waitForFinished();
            int exitCode = process.exitCode();

            if (exitCode != 0) // branch does not exist
            {
                QMessageBox::critical(this, "Error", "Branch not found. The specified branch does not exist.");
                return;
            }

            // Proceed with checkout if branch exists
            gitCheckOut->runCommand(branchName);
        }
    }
}




void MainWindow::on_pb_gitmerge_clicked()
{
    QString directoryPath = ui->LE_Directory->text();
    qInfo() << "Path: " << directoryPath << Qt::endl;
    if (directoryPath.isEmpty())
    {
        QMessageBox::warning(this, "Warning", "Please enter a valid path");
        return;
    }

    QDir dir(directoryPath);
    if (!dir.exists())
    {
        QMessageBox::warning(this, "Error", "The specified path does not exist.");
        return;
    }

    if (!dir.exists(".git"))
    {
        QMessageBox::critical(this, "Error", "This directory doesn't have a local repository.\n"
                                             "You should click init to create a local repository.");
        return;
    }
    else
    {
        if (QDir::setCurrent(directoryPath))
        {
            bool ok;
            QString branchName = QInputDialog::getText(this, tr("Branch Name"),
                                                       tr("Enter the branch name you want to create:"), QLineEdit::Normal,
                                                       "", &ok);
            if (!ok || branchName.isEmpty())
            {
                QMessageBox::critical(this, "Error", "Branch name is required");
                return;
            }

            // Check if the branch exists
            QString branchRef = "refs/heads/" + branchName;
            QStringList arg;
            arg << "show-ref" << "--verify" << "--quiet" << branchRef;
            QProcess process;
            process.start("git", arg);
            process.waitForFinished();
            int exitCode = process.exitCode();

            if (exitCode != 0) // branch does not exist
            {
                QMessageBox::critical(this, "Error", "Branch not found. The specified branch does not exist.");
                return;
            }

            // Proceed with checkout if branch exists
            gitMerge->runCommand(branchName);
        }
    }
}

