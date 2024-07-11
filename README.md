# CCaculator v1.1 使用指南

<div style="display: flex; justify-content: space-between; padding: 0 30%;">
  <a href="./README.md">中文指南</a>
  <a href="./ReadMe_EN.md">English Instruction</a>
</div>

## 目录

- [0. 效果预览](#chapter-0)
- [1. 数据库准备](#chapter-1)
- [2. 按键&快捷键说明](#chapter-2)
- [3. 颜色切换功能(初版)](#chapter-3)
- [4. 未来开发展望](#chapter-4)
- [5. 打赏渠道 & 联系邮箱](#Support)

## <a id="chapter-0">0. 效果预览</a>

- 普通计算模式效果如下：

<div style="text-align: center;"> 
	<img src="https://pic.imgdb.cn/item/66875f1bd9c307b7e92ac000.png" alt="普通计算模式效果演示图片">
</div>

- 科学计算模式效果如下：

<div style="text-align: center;"> 
	<img src="https://pic.imgdb.cn/item/66875f3fd9c307b7e92af696.png" alt="科学计算模式效果演示图片">
</div>

- 更具体的功能演示视频见如下链接：

<div style="text-align: center;">
  <a href="https://www.bilibili.com/video/BV12UhZe5EwT/?vd_source=057305f6f7570cd5ef98cb1a31358015" target="\_blank">👉点我跳转演示视频👈</a>
</div>

## <a id="chapter-1">1. 数据库准备</a>

本项目采用的后端数据库为 **`SQLite`** ，因为他是 `C++ Qt 6.x` 内置支持的一种数据库，同时其可视化软件 `SQLite Expert` 的下载和使用都很简单。

在 `Qt Creator` 中为了能够顺利链接 `SQLite` 数据库，需要在项目配置文件中进行一些补充，具体如下：

- `CMake` 构建的项目

需要在 `CMakeList.txt` 中添加如下内容：

```CMake
# 加入 sql 链接必要的动态库
target_link_libraries(CCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                      Qt${QT_VERSION_MAJOR}::Sql)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)
```

**注意：这里的 `CCalculator` 请替换成您自己的项目名称**

- `QMake` 构建的项目

需要在 `.pro` 项目配置文件中添加如下内容：

```QMake
# 加入 sql 链接必要的动态库
QT += sql
# 在Windows上需要的库（一般情况下Qt会自动处理）
win32:CONFIG(release, debug|release): LIBS += -L$$[QT_INSTALL_LIBS] -lQt6Sql
win32:CONFIG(debug, debug|release): LIBS += -L$$[QT_INSTALL_LIBS] -lQt6Sqld
```

本计算器的按键均绑定了键盘上的按键作为快捷键以方便使用。下面给出所有按键和对于快捷键的说明：

| 按键                      | 快捷键     | 功能                |
|:-----------------------:|:-------:|:-----------------:|
| 0~9                     | 0~9     | 输入0~9             |
| .                       | .       | 输入小数点             |
| Ans                     | Ctrl+A  | 在当前算式末尾输入上一次的运算结果 |
| E                       | Ctrl+E  | 检验输入算式是否存在错误      |
| (                       | (       | 输入左括号             |
| )                       | )       | 输入右括号             |
| ←                       | 键盘上的退格键 | 删除上一个输入的数据/操作符    |
| C                       | Ctrl+C  | 清空所有输入            |
| $+$                     | $+$     | 输入加号              |
| $-$                     | $-$     | 输入减号/负号           |
| ×                       | $*$     | 输入乘号              |
| ÷                       | /       | 输入除号              |
| %                       | %       | 输入百分号             |
| MOD                     | M       | 输入取余符号            |
| ^                       | ^       | 输入乘方/幂符号          |
| !                       | !       | 输入阶乘运算符           |
| !!                      | @       | 输入奇/偶阶乘运算符        |
| $\pi$                   | P       | 输入圆周率$\pi$        |
| e                       | E       | 输入自然数e            |
| =                       | 回车Enter | 计算当前输入算式的结果       |
| Mode→Scientific/Normal  | Alt+S   | 切换普通/科学计算模式       |
| sin                     | S       | 输入正弦函数运算符         |
| arcsin                  | Shift+S | 输入反正弦函数运算符        |
| cos                     | C       | 输入余弦函数运算符         |
| arccos                  | Shift+C | 输入反余弦函数运算符        |
| tan                     | T       | 输入正切函数运算符         |
| arctan                  | Shift+T | 输入反正切函数运算符        |
| ln                      | Shift+L | 输入自然对数运算符         |
| log                     | L       | 输入普通对数运算符         |
| History→Current History | H       | 查看本次运行的计算记录       |
| History→All History     | Alt+H   | 查看本软件安装以来的所有计算记录  |

## <a id="chapter-3">3. 颜色切换功能(初版)</a>

本计算器在 Style 菜单中提供了两种预设的颜色方案，`Light` 表示白色背景，`Dark` 表示黑色背景。

后续将在代码中为所有按键进行归纳分类，并提供对所有按键、窗口背景的颜色方案修改接口。

## <a id="chapter-4">4. 未来开发展望</a>

在后续开发中将按顺序加入如下功能：

v2.0 版本展望：

- 更完整更自由的颜色切换接口
- 通过鼠标和键盘左右按键对输入算式进行插入输入/删除
- 构造一个 About 页面方便大家在使用时查看软件相关信息
- 完成 Contact 快速跳转邮件发送页面的功能
- 完成复数运算模式的开发
- 完成 Practice 随机生成计算题的功能开发

上述功能完成后会 Release 和发布 CCalculator v2.0

## <a id="Support">5. 打赏渠道 & 联系邮箱</a>

如果我的软件和代码对您有帮助或启发，请在经济条件允许的情况下支持我一下吧！

<div style="text-align: center;"> 
	<img src="./SupportOnMe.jpg" alt="打赏二维码">
</div>

另外，如果您对本项目有任何建议、想法或疑惑请联系我的邮箱：

📫chrischanyedu@gmail.com
