### 网络工程二班    李博仁  2220161459  

# 实验二：  Shell实践

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

##### 成功实现基本任务1，基本任务2，基本任务3，以及部分选做功能，详细如下：

1.


    
