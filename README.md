# Git GUI Application

This is a Qt-based GUI application for managing Git repositories. The application allows users to perform common Git operations such as creating repositories, cloning repositories, adding and committing changes, pushing and pulling from remotes, and more, all from a user-friendly graphical interface.


## Features

- **Create Repository**: Initialize a new Git repository.
- **Clone Repository**: Clone an existing Git repository from a remote URL.
- **Add Changes**: Stage all changes in the repository.
- **Commit Changes**: Commit staged changes with a user-provided commit message.
- **Push Changes**: Push commits to a remote repository.
- **Pull Changes**: Pull changes from a remote repository.
- **Branch Management**: Create, switch, and list branches.
- **Merge Branches**: Merge a specified branch into the current branch.
- **View Logs**: View the commit logs of the repository.
- **Browse for Directory**: Select a directory for Git operations using a file dialog.
- **Reset Changes**: Reset the repository to the previous commit.
- **Cherry-Pick Commit**: Cherry-pick a specific commit by its hash.

## Requirements

- Qt 5.12 or later
- C++17 or later
- Git

## Installation

1. **Clone the Repository**:
   git clone <repository-url>

2. **Open the Project**:
   - Open the project in Qt Creator.

3. **Build the Project**:
   - Configure the project using the appropriate kit.
   - Build the project.

4. **Run the Application**:
   - Run the built application.

## Usage

1. **Configure Git**:
   - Enter your Git username and email in the provided fields and click "Go".

2. **Initialize a Repository**:
   - Enter the path where you want to create the repository.
   - Click the "Git Init" button.

3. **Clone a Repository**:
   - Enter the local path and the remote repository URL.
   - Click the "Git Clone" button.

4. **Add Changes**:
   - Click the "Git Commit" button.
   - Enter a commit message in the prompt that appears.

5. **Push Changes**:
   - Enter the remote repository URL and branch name.
   - Click the "Git Push" button.

6. **Pull Changes**:
   - Enter the remote repository URL.
   - Click the "Git Pull" button.

7. **Create a Branch**:
   - Click the "Create Branch" button.
   - Enter the branch name in the prompt that appears.

8. **Switch Branch**:
   - Click the "Go to Branch" button.
   - Enter the branch name to switch to in the prompt that appears.

9. **Merge Branch**:
   - Click the "Git Merge" button.
   - Enter the branch name to merge in the prompt that appears.

10. **View Logs**:
    - Click the "Git Log" button to view the commit logs.

11. **View Status**:
    - Click the "Git Status" button to view the current status of the repository.

12. **Reset Changes**:
    - Click the "Git Reset" button to reset the repository to the previous commit.

13. **Cherry-Pick Commit**:
    - Click the "Cherry-Pick" button.
    - Enter the commit hash to cherry-pick in the prompt that appears.


## Acknowledgements

- [Qt](https://www.qt.io/) - Cross-platform software development framework.
- [Git](https://git-scm.com/) - Version control system.
   
