# Git - A Beginner's Guide

A personal reference guide covering everything I learned about Git — from setup to branching and collaboration.
 
---

## Table of Contents

- [What is Git?](#what-is-git)
- [Installation & Setup](#installation--setup)
- [Core Concepts](#core-concepts)
- [Basic Workflow](#basic-workflow)
- [Branching](#branching)
- [Remote Repositories](#remote-repositories)
- [Undoing Things](#undoing-things)
- [Common Commands Cheat Sheet](#common-commands-cheat-sheet)
---

## What is Git?

Git is a distributed version control system that tracks changes in your files over time. It lets you save snapshots of your project, revert to earlier versions, and collaborate with others without overwriting each other's work.
 
---

## Installation & Setup

Download Git from [git-scm.com](https://git-scm.com) and install it for your operating system.

After installing, configure your identity — Git attaches your name and email to every commit you make.

- Set your username with `git config --global user.name`
- Set your email with `git config --global user.email`
- Check your configuration with `git config --list`
---

## Core Concepts

**Repository (Repo)** — A folder tracked by Git. It contains your project files and the entire history of changes.

**Commit** — A saved snapshot of your project at a specific point in time. Each commit has a unique ID and a message describing what changed.

**Staging Area** — A middle step between editing files and committing them. You choose which changes to include in the next commit by staging them first.

**Branch** — An independent line of development. The default branch is usually called `main` or `master`.

**HEAD** — A pointer to the current commit you are working from.

**Remote** — A version of your repository hosted online (e.g. GitHub, GitLab).
 
---

## Basic Workflow

The typical day-to-day Git workflow follows these steps:

1. **Initialize** a new repository in your project folder using `git init`
2. **Check status** at any time with `git status` to see which files are changed or staged
3. **Stage changes** using `git add` to mark files for the next commit
4. **Commit** the staged changes with `git commit -m "your message"` — write a clear, descriptive message
5. **View history** using `git log` to see all past commits
### The Three States of a File

| State | Meaning |
|-------|---------|
| Modified | Changed but not yet staged |
| Staged | Marked to be included in the next commit |
| Committed | Safely saved in the repository history |
 
---

## Branching

Branches let you work on new features or fixes without affecting the main codebase.

- Create a new branch with `git branch branch-name`
- Switch to a branch with `git checkout branch-name` or `git switch branch-name`
- Create and switch in one step with `git checkout -b branch-name`
- List all branches with `git branch`
- Merge a branch into your current branch with `git merge branch-name`
- Delete a branch after merging with `git branch -d branch-name`
### Merge Conflicts

A conflict happens when two branches edit the same part of a file differently. Git will mark the conflicting sections inside the file. You manually edit the file to keep the correct version, then stage and commit the resolved file.
 
---

## Remote Repositories

A remote repository (like one on GitHub) lets you back up your work and collaborate with others.

- Link a remote to your local repo with `git remote add origin <url>`
- Push your commits to the remote with `git push origin branch-name`
- Pull the latest changes from the remote with `git pull origin branch-name`
- Clone an existing remote repo to your machine with `git clone <url>`
- View connected remotes with `git remote -v`
### Push vs Pull

| Command | What it does |
|---------|--------------|
| `git push` | Sends your local commits to the remote |
| `git pull` | Fetches and merges remote commits into your local branch |
| `git fetch` | Downloads remote changes without merging them |
 
---

## Undoing Things

Git gives you several ways to undo changes depending on how far along you are.

| Situation | Command |
|-----------|---------|
| Discard changes in a file (not staged) | `git checkout -- filename` |
| Unstage a file | `git reset HEAD filename` |
| Undo the last commit (keep changes) | `git reset --soft HEAD~1` |
| Undo the last commit (discard changes) | `git reset --hard HEAD~1` |
| Create a new commit that reverses a past one | `git revert commit-id` |

> **Tip:** Prefer `git revert` over `git reset` when working with shared/remote branches, as it does not rewrite history.
 
---

## Common Commands Cheat Sheet

| Command | Description |
|---------|-------------|
| `git init` | Initialize a new repository |
| `git clone <url>` | Clone a remote repository |
| `git status` | Show the current state of the working directory |
| `git add <file>` | Stage a specific file |
| `git add .` | Stage all changed files |
| `git commit -m "message"` | Commit staged changes |
| `git log` | View commit history |
| `git log --oneline` | Compact view of commit history |
| `git branch` | List all branches |
| `git checkout -b <name>` | Create and switch to a new branch |
| `git merge <branch>` | Merge a branch into the current one |
| `git push origin <branch>` | Push to remote |
| `git pull origin <branch>` | Pull from remote |
| `git diff` | Show unstaged changes |
| `git stash` | Temporarily save uncommitted changes |
| `git stash pop` | Restore stashed changes |
 
---

## Tips & Best Practices

- **Commit often** — small, focused commits are easier to understand and revert
- **Write meaningful commit messages** — describe *what* changed and *why*, not just *how*
- **Never commit directly to main** — use feature branches and merge when ready
- **Pull before you push** — always sync with the remote before pushing to avoid conflicts
- **Use `.gitignore`** — create a `.gitignore` file to exclude files you don't want tracked (e.g. build files, secrets, node_modules)
---

## Resources

- Official Docs: [git-scm.com/doc](https://git-scm.com/doc)
- Interactive Practice: [learngitbranching.js.org](https://learngitbranching.js.org)
- GitHub Guides: [docs.github.com](https://docs.github.com)
 
