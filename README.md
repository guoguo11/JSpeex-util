## JSpeex-util 使用
功能介绍：PC端将.speex文件解码为*.wav文件

### 环境：
1. MAC OS 10.12.5/Linux
2. Xcode 
3. Gcc
4. JDK 1.8
5. speex 1.2.0

### 步骤：
1. 安装libspeex
> 从https://www.speex.org/downloads/下载speex-1.2.0.tar.gz

> 解压speex-1.2.0.tar.gz

>cd pathto/speex-1.2.0
>./configure 
```
    ...
    config.status: creating win32/VS2003/libspeex/Makefile
    config.status: creating win32/VS2003/speexdec/Makefile
    config.status: creating win32/VS2003/speexenc/Makefile
    config.status: creating win32/VS2005/Makefile
    config.status: creating win32/VS2005/libspeex/Makefile
    config.status: creating win32/VS2005/speexdec/Makefile
    config.status: creating win32/VS2005/speexenc/Makefile
    config.status: creating win32/VS2005/tests/Makefile
    config.status: creating win32/VS2008/Makefile
    config.status: creating win32/VS2008/speexdec/Makefile
    config.status: creating win32/VS2008/tests/Makefile
    config.status: creating win32/VS2008/libspeex/Makefile
    config.status: creating win32/VS2008/speexenc/Makefile
    config.status: creating include/speex/speex_config_types.h
    config.status: creating ti/Makefile
    config.status: creating ti/speex_C54_test/Makefile
    config.status: creating ti/speex_C55_test/Makefile
    config.status: creating ti/speex_C64_test/Makefile
    config.status: creating config.h
    config.status: executing depfiles commands
    config.status: executing libtool commands
    Type "make; make install" to compile and install Speex
```
>sudo make install 
```
    Making install in libspeex
     .././install-sh -c -d '/usr/local/lib'
     /bin/sh ../libtool   --mode=install /usr/bin/install -c   libspeex.la '/usr/local/lib'
    libtool: install: /usr/bin/install -c .libs/libspeex.1.dylib /usr/local/lib/libspeex.1.dylib
    libtool: install: (cd /usr/local/lib && { ln -s -f libspeex.1.dylib libspeex.dylib || { rm -f libspeex.dylib && ln -s libspeex.1.dylib libspeex.dylib; }; })
    libtool: install: /usr/bin/install -c .libs/libspeex.lai /usr/local/lib/libspeex.la
    libtool: install: /usr/bin/install -c .libs/libspeex.a /usr/local/lib/libspeex.a
    libtool: install: chmod 644 /usr/local/lib/libspeex.a
    libtool: install: ranlib /usr/local/lib/libspeex.a
    make[2]: Nothing to be done for `install-data-am'.
    Making install in include
    Making install in speex
    ...
    ...

```


2.打包
> cd pathto/release
 
linux系统:  
> make -f makefile-linux  
> make -f makefile-linux install  

mac系统:
  
> make -f makefile-mac    
> make -f makefile-mac install  

3.测试
    SpeexUtils.decode("pathto/a.speex", "pathto/a-test.wav");
    
4.测试文件
./resources/a.speex
./resources/b.speex

## 说明
>本项目的目的为学习测试用，若有侵权行为，请联系作者guoshuyun@zixunfan.com

## 参考


## 常见问题
> 1.linux 生成动态库时提示relocation R_X86_64_32 against `.rodata' can not be used when making a shared object;

由于系统是AMD64位的，所以需要在编译的时候添加 -fPIC 选项

解决方法:

例如:

gcc -c -fPIC head.c

or

g++ -c -fPIC head.cpp 生成head.o

g++ -fpic -shared -o libfun.so head.o 

> 缺少动态连接库.so--cannot open shared object file: No such file or directory
总结下来主要有3种方法：
1. 用ln将需要的so文件链接到/usr/lib或者/lib这两个默认的目录下边

```
ln -s /where/you/install/lib/*.so /usr/lib
sudo ldconfig
```

2.修改LD_LIBRARY_PATH

```
export LD_LIBRARY_PATH=/where/you/install/lib:$LD_LIBRARY_PATH
sudo ldconfig
```


3.修改/etc/ld.so.conf，然后刷新
```
vim /etc/ld.so.conf
增加一行 include /where/you/install/lib

sudo ldconfig
```

