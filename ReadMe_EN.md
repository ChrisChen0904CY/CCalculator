# CCaculator v1.5 Instruction

<div style="display: flex; justify-content: space-between; padding: 0 30%;">
  <a href="./README.md">中文指南</a>
  <a href="./ReadMe_EN.md">English Instruction</a>
</div>

## Contents

- [0. Preview](#chapter-0)
- [1. Database Preparation](#chapter-1)
- [2. Button & Shortcut Key Instructions](#chapter-2)
- [3. Color Switching Function (Initial Version)](#chapter-3)
- [4. Future Development Prospects](#chapter-4)
- [5. Support & Contact](#Support)

## <a id="chapter-0">0. Preview</a>

- The normal calculation mode looks like this:

<div style="text-align: center;"> 
	<img src="https://pic.imgdb.cn/item/66875f1bd9c307b7e92ac000.png" alt="Normal Calculation Mode Preview">
</div>

- The scientific calculation mode looks like this:

<div style="text-align: center;"> 
	<img src="https://pic.imgdb.cn/item/66875f3fd9c307b7e92af696.png" alt="Scientific Calculation Mode Preview">
</div>

- For more specific feature demonstration videos, see the following link:

<div style="text-align: center;">
  <a href="https://www.bilibili.com/video/BV12UhZe5EwT/?vd_source=057305f6f7570cd5ef98cb1a31358015" target="\_blank">👉Click here to watch the demo video👈</a>
</div>

## <a id="chapter-1">1. Database Preparation</a>

This project uses **`SQLite`** as the backend database because it is natively supported by `C++ Qt 6.x` and its visualization software, `SQLite Expert`, is simple to download and use.

To successfully link the `SQLite` database in `Qt Creator`, some additions are needed in the project configuration file, as follows:

- For projects built with `CMake`:

Add the following to `CMakeLists.txt`:

```CMake
# Add the necessary dynamic library for SQL linkage
target_link_libraries(CCalculator PRIVATE Qt${QT_VERSION_MAJOR}::Widgets
                      Qt${QT_VERSION_MAJOR}::Sql)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)
```

**Note: Replace `CCalculator` with your own project name**

- For projects built with `QMake`:

Add the following to the `.pro` project configuration file:

```QMake
# Add the necessary dynamic library for SQL linkage
QT += sql
# Libraries needed on Windows (usually handled automatically by Qt)
win32:CONFIG(release, debug|release): LIBS += -L$$[QT_INSTALL_LIBS] -lQt6Sql
win32:CONFIG(debug, debug|release): LIBS += -L$$[QT_INSTALL_LIBS] -lQt6Sqld
```

## <a id="chapter-2">2. Button & Shortcut Key Instructions</a>

The buttons of this calculator are all bound to keyboard keys as shortcuts for ease of use. Below are all buttons and their corresponding shortcuts:

| Button                  | Shortcut  | Function                                                                        |
|:-----------------------:|:---------:|:-------------------------------------------------------------------------------:|
| 0~9                     | 0~9       | Input numbers 0~9                                                               |
| .                       | .         | Input decimal point                                                             |
| Ans                     | Ctrl+A    | Input the result of the previous operation at the end of the current expression |
| E                       | Ctrl+E    | Check if the input expression contains errors                                   |
| (                       | (         | Input left parenthesis                                                          |
| )                       | )         | Input right parenthesis                                                         |
| ←                       | Backspace | Delete the last input character/operator                                        |
| C                       | Ctrl+C    | Clear all inputs                                                                |
| $+$                     | $+$       | Input plus sign                                                                 |
| $-$                     | $-$       | Input minus sign/negative sign                                                  |
| ×                       | $*$       | Input multiplication sign                                                       |
| ÷                       | /         | Input division sign                                                             |
| %                       | %         | Input percentage sign                                                           |
| MOD                     | M         | Input modulo symbol                                                             |
| ^                       | ^         | Input power/exponentiation symbol                                               |
| !                       | !         | Input factorial operator                                                        |
| !!                      | @         | Input double factorial operator                                                 |
| $\pi$                   | P         | Input the value of $\pi$                                                        |
| e                       | E         | Input the value of e                                                            |
| =                       | Enter     | Calculate the result of the current expression                                  |
| Mode→Scientific/Normal  | Alt+S     | Switch between normal/scientific calculation modes                              |
| sin                     | S         | Input sine function                                                             |
| arcsin                  | Shift+S   | Input inverse sine function                                                     |
| cos                     | C         | Input cosine function                                                           |
| arccos                  | Shift+C   | Input inverse cosine function                                                   |
| tan                     | T         | Input tangent function                                                          |
| arctan                  | Shift+T   | Input inverse tangent function                                                  |
| ln                      | Shift+L   | Input natural logarithm function                                                |
| log                     | L         | Input logarithm function                                                        |
| History→Current History | H         | View the calculation history of the current session                             |
| History→All History     | Alt+H     | View all calculation history since the software installation                    |
| The Close Button        | Ctrl+W    | Close this software                                                             |

## <a id="chapter-3">3. Color Switching Function (Initial Version)</a>

This calculator offers three preset color schemes in the Style menu: `Light` for a light theme, `Dark` for a dark theme, and `Blue` for a blue and pink color combination.

You can enter the name of your preset appearance directly under the Style menu in the `mainwindow.ui` file. Then, following the comments in `styles.h`, you can write the QSS styles you need. The program will automatically handle the appearance scheme you create.

In the future, the feature to directly set the color palette will be completed under Style DIY in Settings.

## <a id="chapter-4">4. Future Development Prospects</a>

In future development, the following features will be added in order:

Version 2.0 Outlook:

- A more comprehensive and flexible color switching interface (implemented)
- Insert and delete input formulas using the mouse and keyboard arrow keys (keyboard arrow keys for cursor movement implemented)
- Create an About page for users to view relevant software information (implemented)
- Implement the Contact page for quick email sending (implemented)
- Develop complex number operation mode
- Develop the Practice feature to randomly generate math problems

After the above features are completed, CCalculator v2.0 will be released.

## <a id="Support">5. Support & Contact</a>

If my software & source code help you a lot, please support me!

<div style="text-align: center;"> 
	<img src="./SupportOnMe_Paypal.png" alt="Support">
</div>

And if you have any questions or advice about this project, please reach me at this email address:

📫chrischanyedu@gmail.com
