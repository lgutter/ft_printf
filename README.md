# ft_printf
[![Build Status](https://travis-ci.com/lgutter/ft_printf.svg?token=1XqUmANNphr1YCadgPKp&branch=master)](https://travis-ci.com/lgutter/ft_printf)
[![codecov](https://codecov.io/gh/lgutter/ft_printf/branch/master/graph/badge.svg?token=mIYsxaVIbL)](https://codecov.io/gh/lgutter/ft_printf)

[The project board for ft_printf](https://github.com/lgutter/ft_printf/projects/3)

## Make commands
### make (all)
compiles any .c files that have changed to .o files, and compiles the **ft_printf.a** library.

### make test
Calls *norm* and *clean* and then it compiles the criterion tests into the **test** executable.

### make gcov
Generates *gcov* reports for all .c files of ft_printf and .c files in libft that are in the CovSources file.

### make clean
Removes junk files and coverage files.


### ONLY USE THE FOLLOWING MAKE RULES WHEN ABSOLUTELY NEEDED
### make oclean & make fclean
*Oclean* calls *clean* and then removes object files, and *fclean* additionally removes the compiled library and test executable.

### make re
Calls *fclean* and then *all*

## Git workflow

### Setup
enable [git rerere](https://git-scm.com/book/en/v2/Git-Tools-Rerere) to make certain merge issues easier. run this to enable it:
```
git config --global rerere.enabled true
```
Optionally, enable gpg signing by follow [this guide](https://github.com/OscarMulder/codam-gpg-signing).

### 0. git fetch & merge or git pull
ALWAYS make sure you are up to date with the github repository before you do anything.
This will prevent a lot of nasty merge conflicts when you've changed things.

### 1. Switch to the correct branch
for some things a suitable branch will already exist (e.g. docs/readmeChanges), so use these commands to get to the right branch:
```
# check which branches already exist
git branch

# checkout the branch you need
git checkout docs/readmeChanges
```
If you're starting work on something new, follow these instructions:
```
# create a new branch and switch to it, using a correct branch name as seen below
 git checkout -b <category/branchname>

# some example branchnames:
feature/floatModule
hotfix/normFixes
docs/readmeChanges
devops/travisConfigChanges
etc
```

### 2. Commit changes seperated by type and provide a clear description
For example, if you've created ft_strexpand function, commit it like this:
1. add all .c files you've created and commit them with a clear title and description like:
```
added c file for ft_strexpand

function works by checking of source is empty, and calling ft_strdup if it IS empty,
or calling ft_strjoin and freeing the old source string if it is NOT empty.
```
2. add all support files (headers, Makefile, sources files) and commit them with a clear title and description like:
```
changed ft_printf.h and Sources to include ft_strexpand

added prototype of ft_strexpand to ft_printf.h and filename to Sources.
```
3. add all test files and commit them with a clear title and description like:
```
added tests for ft_strexpand

added tests that test the 2 basic components of ft_strexpand.
Also added test files to tests/testsources
```
### 3. If there are changes in master, merge master into your branch
This prevents a lot of merge conflicts during a pull request, so do it often.
Make sure you've committed your current changes in your branch though, to avoid losing work when pulling master.
```
git checkout master
git pull
git checkout <your/branch>
git merge master
```

### 4. Push your branch when everything is ready
Before pushing, make sure you've pulled the most recent version of the online repository, and you've merged master into your branch.
For new branches, use this command to push, so git creates the brand on the remote repository:
```
git push -u origin <your/branch>
```

### 5. Create a pull request on github
Provide a clear description of all the changes in the pull request,
and if it should close an issue (for example because you've completed a feature), tag it by including `closes #42` in the description, where 42 is the issue number.
also make sure to assign a reviewer, labels, project and milestone if applicable.
