# MI6 SIMS By Cpp
#### 暂时终版, 期末预习了, 还有一些TODO, 老师见谅;
- MFC学生管理系统, Cpp大作业;

- 为什么用MFC, 主要是Qt有点恶心, 期末有点预习不完了, 遂作罢;

- 提交了.idea目录, 因为还是CLion字体好, vs把我看吐了, 用惯了idea不习惯;

- 没有提交.vs目录也不需要, 里面数据库和ipch太大了, 一会测试下那个有无影响;

- vs我真的佛了, 那个过滤器长得跟目录一样,  
    我还以为是真目录, 没想到是虚拟目录, 全部都写在一起了, 就写成了在一坨, 看着是真滴难受;
    佛了, MVC都架构了, 这下架构个寂寞;
    不敢改, Cpp把我改吐了, 还是Java好;
    
- 现在的问题是这个**过滤器也没法tree, 我佛了,  
    不过我上传了.filters文件, 他可以帮你规划出vs里的虚拟目录, 麻烦老师凑活着用吧, 呜呜;  
    我会尝试简单描述下目录的架构;    
    
---

#### 关于打包

- 打包给我打吐了, 关键是好像mfc142.dll等一系列dll我还要自己找..;  

- MS自家的setup project是真的抽象;  
 以前做Java项目和.NET Core项目用 Inno Setup和winrar做自解压都很简单, 主要是依赖简单,
 编译环境也不像远古Cpp的编译链那么抽象;  

 所以确实安装包没打出来, 呜呜, 老师海涵, 其他科预习不完了, 期末考完后我再继续折腾完善项目;
 
- Cpp的bug那是更加抽象, 语法是真的又乱又复杂,  
    如果不遵守类似Google的规范, 我自己写出来的真的我客观评价也是一坨shit一样  
    怪不得连Cpp的创始人都睡不敢说自己掌握了Cpp,
    能与之媲美的简直只能有JavaScript(特别ES6之前的)  
    我也是基本初次用vs, 以前写C都是Clion, 调试真的用不来, 打印个东西都很恼火  
    说实话还是Java的Swing和Csharp的WPF和winform用着舒服, 打包也舒服;
    
    
---

#### TODO

- ~~// TODO 打开文件后必选择, 不能取消或者×掉, 否则会丢指针, 直接爆掉, 很麻烦;~~  
    已经解决;

- // TODO 加载文件路径在当前./sample/最好, 但是Cpp好像不太好做到, 属实是比较裂开的;

- // TODO 点保存直接保存当前文件, 现在是必须另存为才行个另存为;

- // TODO 记录未保存的工作, 询问是否保存;

- // TODO 权限菜单;

- // TODO 左边栏目录树显示学院班级树状;