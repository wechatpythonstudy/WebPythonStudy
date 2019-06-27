

# Git work step



### step1.  clone a reposity and checkout to work branch

- clone reposity to local
- check out a branch `git checkout -b feature_x`

### step2. edit your code and get your features

- commit the change when you get your features
- after getover your work , you need to rebase the commit to one commit for push `git rebase -i  HEAD^` 
  - fix the commit message `git commit --amend`
  - reset the commit `git reset HEAD^ -soft` soft reset just reset the commit ,don't  reset file or document.

### step3. merage the code to the main branch

- `git merage --squash`









