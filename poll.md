# Linux系统调用之Poll

IO复用技术：把我们关注的描述符组成一个描述符表，调用I/O复用函数（select/poll/epoll)

当描述符表中有可进行非阻塞I/O操作的描述符时，复用函数返回；否则阻塞复用函数，直到描述符表中有可进行非阻塞I/O操作的描述符出现时，才唤醒进程继续执行复用函数；

I/O复用的描述符通常包括：终端/伪终端，pipes, socket等



### I/O复用函数主要过程：

1. 遍历描述符表，判断该描述符表中是否有描述符可进行非阻塞I/O操作
2. 

* 进程控制

* 文件系统控制

* 系统控制

* 内存管理

* 网络管理

* socket控制

* 用户管理

* 进程间通信

  