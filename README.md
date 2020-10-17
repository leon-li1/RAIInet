# Data Rush


## Installation

First, get your public ssh key from here:
```
cat ~/.ssh/id_rsa.pub
```
Take the output of that command, and copy paste it into the textbox under `Gitlab User Settings > SSH Keys > Add an SSH Key`. Hit the submit button.


Then, go into `~/cs246` and run the command:
```
git clone ist-git@git.uwaterloo.ca:a5-mll/raiinet.git
```
This will create a folder at `~/cs246/raiinet` with all of the project shtuff.

# Running

```
make
./raiinet
```


## Making changes

Run `git pull` before making your changes (to update your local branch with the new code from the remote branch). 
If there are any conflicts, fix them, and then run `git add .` + `git commit`.


After making your changes, run:
```
git status     (just to chekc for errors)
git add .
git commit -m "commit message"
git push
```
