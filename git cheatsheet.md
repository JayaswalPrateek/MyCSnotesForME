# `git init`
- running it in an empty folder creates .git directory in the folder

# `git status`
- shows branch you are working on, commits, untracked/modified but tracked files

# `git add <location of untracked file>` or `git add .`
- to track a file, we cannot commit it directly, we first need to add it to the staging area
- `git add .` will track all untracked files in current working directory
	- otherwise you can specify which untracked files you want to track by `git add <location of untracked file>`
- git add will create history but not create a restore point with a message(called a commit)

# `git commit -m "<commit message>"`
- stage is now empty as we made a commit, `git status` says nothing to commit, working tree clean

# `git restore --staged`
- if you committed by mistake you can undo the commit using this command, modified files will be back on the stage as if you had added them
	- you can only rollback one commit behind

# `git log`
- prints the commit history with each commit having its commit id

# `git reset <commit id>`
- if you want to roll back to older commit 
- git log removes the commits above `<commit id>` including the `<commit id>`
	- these commits were unstaged so you need to add them to the stage before committing again so you have untracked changes

# `git stash`
- when you want to reset, but could modify the files and still might want to undo the reset later
- before stashing, files should be staged using add
- status after stashing is nothing to commit, working tree clean
- allows you to try reimplementing something without having to commit incomplete work that you were implementing before
- rolls back to most recent commit

# `git stash pop`
- if something was stashed it is moved to staging
- this may override the changes you have made between stashing and popping the stash

# `git stash clear`
-  suppose you successfully reimplemented something so you don't need the stashed incomplete work anymore 

# `git remote add origin https://github.com/<username>/<reponame>.git`
- binds a git repo on github to a local git folder

# `git push origin master`
- uploads the local git folder/new commits to github.com 

# Branches
- the master branch reflects production ready code that is not work in progress
- to start working on a feature addition you should create a separate branch and merge it with master when the work is done
	- meanwhile it is possible that the same files you worked on were modified by someone else as they got their