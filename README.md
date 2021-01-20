# LearnROS

ROS基础教程代码仓库

## 前言

回忆起我之前学习ros的时候，杂乱无章，东一吹西一棒，没有系统，不得要领。那么我针对稍微知道点ros皮毛，但是无法熟练运用的一大批门外汉们，详细撰写了一份ROS基础系列教程。这既是一份系统学习ROS的课件，又是查询ROS相关工具使用的检索包。

## 教程介绍

所谓ROS系统，究其本质就是一个超级工具包。为了避免重复造轮子，ROS系统提供给我们面向机器人的各个环节、各式各样有用的工具包。从前，我们建立机器人简直难于上青天。现在有了ROS，我们自己手动搭建一个机器人，也不过是个把月的时间。

### 1. 通讯方式
一个自成体系的系统，最根本的部分是通讯机制。教程中首先面向ROS分布式通讯特点，常用的通讯手段进行详细讲解。并给出开发中常用的实例：


[1. ROS之topic通讯机制](https://blog.csdn.net/allenhsu6/article/details/112334048)

[2. ROS之service通讯机制](https://blog.csdn.net/allenhsu6/article/details/112384549)


### 2. 核心功能包
第三章节提及到的三块内容：参数服务器、命名空间与launch文件大全解互相之间有千丝万缕的联系，我们把它放在一章，方便知识相互印证。
第四章节的TF坐标变换是所有想要搭建机器人的朋友必然绕不开的知识点。
第五章节比较短小，主要面向ROS中的时间机制。这部分同样与TF息息相关，因为TF查询的时候势必要与时间相关联。

[3. 参数服务器、命名空间与launch文件大全解](https://blog.csdn.net/allenhsu6/article/details/112604296)

[4.一文说尽TF坐标变换 ](https://blog.csdn.net/allenhsu6/article/details/112552971)

[5. ROS中的时间与TF中的时间](https://blog.csdn.net/allenhsu6/article/details/112694790)

### 3. 搭建机器人
这部分内容，首先引入实体机器人的软硬件组成与分析。

然后搭建仿真机器人的各个环节中，我们会与实体机器人中硬件概念一一印证。从而彻底理解机器人各个部件的本质，以及他们负责的功能。

在自己手动搭建仿真环境下的机器人的过程，我们会学习到各个重要的相关ros功能包，会对TF有更深的理解。同样，我们会对整个机器人系统有更加宏观的认识。



[6. 实体机器人平台软硬件组成与分析](https://blog.csdn.net/allenhsu6/article/details/112402274)


[7. 机器人建模语言：URDF与xacro](https://blog.csdn.net/allenhsu6/article/details/112729832#comments_14654514)

[8. 打通控制系统与底层：机器人控制器ROS_Controller](https://blog.csdn.net/allenhsu6/article/details/112730929)

[9. 机器人在gazebo仿真中的运动](https://blog.csdn.net/allenhsu6/article/details/112731225)
