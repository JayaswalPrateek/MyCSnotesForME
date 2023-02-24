## `git init`
- running it in an empty folder creates .git directory in the folder

## `git status`
- shows branch you are working on, commits, untracked/modified but tracked files

## `git add <location of untracked file>` or `git add .`
- to track a file, we cannot commit it directly, we first need to add it to the staging area
- `git add .` will track all untracked files in current working directory
	- otherwise you can specify which untracked files you want to track by `git add <location of untracked file>`
- git add will create history but not create a restore point with a message(called a commit)

## `git commit -m "<commit message>"`
- stage is now empty as we made a commit, `git status` says nothing to commit, working tree clean

## `git restore --staged`
- if you committed by mistake you can undo the commit using this command, modified files will be back on the stage as if you had added them
	- you can only rollback one commit behind

## `git log`
- prints the commit history with each commit having its commit id

## `git reset <commit id>`
- if you want to roll back to older commit 
- git log removes the commits above `<commit id>` including the `<commit id>`
	- these commits were unstaged so you need to add them to the stage before committing again so you have untracked changes

## `git stash`
- when you want to reset, but could modify the files and still might want to undo the reset later
- before stashing, files should be staged
- status after stashing is nothing to commit, working tree clean
- allows you to try somethi