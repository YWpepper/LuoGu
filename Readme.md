
- 0514 - 0524 计划
    - 洛谷 2024 官方题单（10~12 月）
    - https://www.luogu.com.cn/training/692077#problems

### 分支管理

#### 1 创建分支并且提交自己的更改

```shell
## 0 检查当前remote仓库
git remote -v

## 1. check the branch at now 
git branch 

## 2.new a branch
git branch tiger

## 3. change the branch into pepper
git checkout tiger

## 4. tradition add
git add .
git commit -m "test"

## 5. here you need to specify branch is pepper
git push -u origin tiger 

```

####  2 使用merge命令实现自己分支与主分支的合并

```shell
## 1. 确保你的本地仓库是最新的，先执行以下命令拉取最新的代码：
git checkout tiger 
git pull origin tiger

## 2. 切换到主分支，如果你不知道自己的branch使用git branch查看
##    确保主分支也是最新版本
git checkout master
git pull origin master 

## 3. 使用主分支的角色，合并tiger分支到主分支
git merge tiger

## 3.0 处理合并冲突（如果有的话）。如果 `git` 自动合并无法解决所有冲突，你需要手动解决冲突。打开包含冲突的文件，查找并编辑冲突部分，然后保存文件。
git stas

## 4. 提交合并结果
git commit -m "merge tiger into master"

## 5. 将合并后的更改推送到远程仓库
git push origin mster

```



### 部分参考信息链接
- [书籍书单](https://github.com/SZU-ITer/CS-Books-PDF)


