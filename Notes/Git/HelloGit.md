



```cpp
git init  // 在终端当前指向的位置初始化一个 Git 仓库
git add [filename]  // 由工作区向版本库 stage 提交修改
git commit -m ""  // 由版本库 stage 向分支 master 提交修改
git status  // 查看

    
    
```



```cpp
git diff
git diff HEAD -- [filename]  
```

可以查看工作区与暂存区之间的差异。这个命令会显示自上次 `git add` 以来的修改内容。

可以查看工作区与最新提交。这个命令会显示自上次 `git commit` 以来的所有修改内容。



```cpp
git checkout -- readme.txt
```

把`readme.txt`文件在工作区的修改全部撤销，这里有两种情况：

- `readme.txt`自修改后还没有被放到暂存区，现在，撤销修改就回到和版本库一模一样的状态；

- `readme.txt`已经添加到暂存区后，**又作了修改**，现在，撤销修改就**回到添加到暂存区后的状态**。

总之，即为**清空工作区相对于版本库的所有修改**。如有已添加但未提交的修改，就回到最近一次 `git add`，否则回到最近一次`git commit`。