[.NET Docker remote debug的原理](https://docs.microsoft.com/en-us/aspnet/core/host-and-deploy/docker/visual-studio-tools-for-docker?view=aspnetcore-2.2#debug)

基于相同的思路进行C++的remote debug,使用VS Code进行debug，测试代码运行在docker container中，利用VS Code的attach功能附加到远程运行中的进程，实现remote debug.

## Prerequisites:
[VS Code Docker extension](https://marketplace.visualstudio.com/items?itemName=PeterJausovec.vscode-docker)


## Steps:

1. clone代码到本地.

2. 右键点击`docker-compose.yml`文件，选择Compose Up.

![compose](https://github.com/w12379564/dev_demo_attach/blob/master/images/compose.png)

3. 进入debug界面，点击`Remote Debug (C++)`开始调试.

![debug](https://github.com/w12379564/dev_demo_attach/blob/master/images/debug.png)
