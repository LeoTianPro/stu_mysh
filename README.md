# Shell实践

#### 一、实验目的
***
1.理解 shell 程序的功能。
2.学会 shell 的使用。
3.构造一个简单的 shell。

#### 二、实验内容
***
#####基本任务 1：用 C/C++编写一个简单的 shell 程序，实现以下基本的命令。
1) 浏览目录和文件的各种属性 ls（可以不支持参数）
2) 回显命令 echo
3) 显示文件内容 cat
4) 创建目录 mkdir
5) 删除文件 rm
6) 切换目录 cd
7) 显示当前目录 pwd
8) 文字统计 wc
    
#####基本任务 2：写一个 makefile 来管理
#####基本任务 3：写清楚编译和运行的过程
    
#####选做任务
任何你想实现的其它命令
提供友好的人机界面：例如提供命令列表、命令查询、命令帮助等。
Advanced shell 功能，例如:
1) 输入输出重定向，例如 ./a.out > output.dat
2) 支持多管道命令，例如 ./a.out –a | ./b.out | ./c.out
3) 支持后台运行命令，例如 ls | wc &
4) 其它：参考 GNU bash 提供的功能。

#### 三、实验步骤
***

1.寻找在编写实现所要求功能的程序中所需要的所有头文件，以及所需的全局变量和函数声明置于`stu1459_mysh.h`中。
2.编写完成各种功能的子函数，并分别置于各自命名的c文件中。
3.编写主函数及一些如显示提示符、获取输入等功能函数，置于`stu1459_mysh.c`中。
4.编写`makefile`对项目进行自动化编译管理。
5.反复调试，增强代码鲁棒性，并在可复用性、精简性等方面进一步优化。

#### 四、实验结果
***

##### 完成基本任务1（部分超额完成任务），基本任务2，基本任务3，以及部分选做功能，详细如下：

####基本任务1

1.UI

![](/lab2_image/ui.png)

2.`ls [FILE]...`（支持绝对/相对路径的目录，且用不同颜色高亮不同的文件类型）

![](/lab2_image/ls.png)

3.`echo`（支持打印环境变量）

![](/lab2_image/echo.png)

4.`cat`（支持查看多个文件）

![](/lab2_image/cat.png)

5.`mkdir`(支持同时建立多个目录，初始权限为755)

![](/lab2_image/mkdir1.png)
![](/lab2_image/mkdir3.png)
![](/lab2_image/mkdir2.png)

6.`rm`（支持使用`-r`/`-R`选项递归删除多个目录及文件）

![](/lab2_image/rm1.png)
![](/lab2_image/rm2.png)![](/lab2_image/rm3.png)

7.`cd`

![](/lab2_image/cd_pwd.png)

8.`pwd`

![](/lab2_image/pwd.png)

9.`wc`（支持统计多个文件并最后求和）

![](/lab2_image/wc.png)

***
####选做任务

1.`man [command]`（查看总体或单独的命令手册）

![](/lab2_image/man1.png)
![](/lab2_image/man2.png)

2.`exit/quit`（退出stu1459_mysh并给予一定提示）

![](/lab2_image/exit.png)

3.`time`（查看当前时间）

![](/lab2_image/time.png)

6.`clear`（清屏）

![](/lab2_image/clear1.png)
![](/lab2_image/clear2.png)

5.`echo [STRING] >/>> FILE`（支持`echo`的输入输出重定向到某个文件，包括覆盖和追加）

![](/lab2_image/echo1.png)
![](/lab2_image/echo2.png)
![](/lab2_image/echo3.png)
![](/lab2_image/echo4.png)

***
#### 五、编译、运行

1.`make clean`（清除所有`.o`文件及可执行文件`stu1459_mysh`）

![](/lab2_image/make_clean.png)

2.`make`（编译所有.c文件并最终生成可执行文件`stu1459_mysh`）

![](/lab2_image/make.png)

3.`./stu1459_mysh`（运行当前目录的可执行文件`stu1459_mysh`）

![](/lab2_image/run.png)

***
#### 六、实验分析

&emsp;&emsp;通过本次实验，我熟悉了一些Linux下进行C编程所用到的一些API，体会到了与Windows下进行C编程的API上的一些异同点，了解了Shell一些命令的工作原理，并通过编程去实现，在此过程中，我了解了Linux的文件及目录的结构。除此之外，我还活用了操作系统中进程方面的知识，实现了`echo`的输入输出重定向。同时，通过编写`makefile`，我实现了对多个项目进行管理，了解了自动化编译技术。最后，为了让项目更加完整，让读者更加了解项目内容，我编写了此`README.md`文件。

***
#### 七、命令手册


#####1.显示目录内容：`ls [FILE]...`

#####2.打印字符串/环境变量：`echo[STRING/$ENVIRON]...`

#####3.显示文件内容：`cat [FILE]...`

#####4.创建目录：`mkdir DIRECTORY...`

#####5.删除目录/文件：`rm [-r/-R] [FILE]...`

#####6.切换目录：`cd DIRECTORY`

#####7.打印当前目录：`pwd`

#####8.统计文件的行数、字数及字符数：`wc`

#####9.退出Shell：`exit/quit`

#####10.打印当前时间：`time`

#####11.echo命令的输入输出重定向：`echo [STRING] >/>> FILE`

#####12.打印关于信息：`sh`

#####13.查看命令手册：`man [command]`

***
#### 八、参考资料
随便写写的

1.《UNIX环境高级编程：第3版》（美） 史蒂文斯 (Stevens,W.R.)，（美）拉戈（Rago，S.A.）著； 戚正伟， 张亚英， 尤晋元译 
2.《C Primer Plus： 第6版》 （美） 普拉达 （Prata S.） 著； 姜佑译
3.《现代操作系统：第3版》 （荷） Andrew S. Tanenbaum 著 陈向群 马洪兵 等译
