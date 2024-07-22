# Bismuth 终端应用开发工具 API 文档

---
## 目录
### 1. `WorkSpace` 类 API 文档
### 2. `TuiTools` 类 API 文档
### 3. `Module` 类 API 文档

---
# WorkSpace 类 API 文档

## 概述

`WorkSpace` 类用于创建和管理工作空间对象。工作空间具有宽度、高度、标题和背景颜色等属性。该类提供了一些方法来获取和设置这些属性，以及绘制工作空间。

## 类定义

### `WorkSpace`

**包含文件：**

```cpp
#include "WorkSpace.h"
```

### 公共成员函数

#### `WorkSpace(int width, int height, const string& title)`

- **描述：** 使用指定的宽度、高度和标题创建一个新的 `WorkSpace` 对象。
- **参数：**
    - `int width`：工作空间的宽度。
    - `int height`：工作空间的高度。
    - `const string& title`：工作空间的标题。

#### `WorkSpace(int width, int height)`

- **描述：** 使用指定的宽度和高度创建一个新的 `WorkSpace` 对象，标题使用默认值 `"WORK SPACE"`。
- **参数：**
    - `int width`：工作空间的宽度。
    - `int height`：工作空间的高度。

#### `WorkSpace()`

- **描述：** 使用默认宽度（80）、高度（25）和标题（"WORK SPACE"）创建一个新的 `WorkSpace` 对象。

#### `vector<int> size() const`

- **描述：** 获取工作空间的尺寸（宽度和高度）。
- **返回值：** 一个包含两个整数的向量，第一个元素为宽度，第二个元素为高度。

#### `string title() const`

- **描述：** 获取工作空间的标题。
- **返回值：** 工作空间的标题。

#### `void title(const string& newTitle)`

- **描述：** 设置工作空间的标题。
- **参数：**
    - `const string& newTitle`：新的标题。

#### `string backgroundChar() const`

- **描述：** 获取工作空间的背景颜色。
- **返回值：** 工作空间的背景颜色。

#### `void backgroundChar(const string& newBackgroundColor)`

- **描述：** 设置工作空间的背景颜色。
- **参数：**
    - `const string& newBackgroundColor`：新的背景颜色。

#### `void draw()`

- **描述：** 绘制工作空间。

## 常量

- `#define SPACE '#'`：表示填充字符。
- `#define DEFAULT_TITLE "WORK SPACE"`：默认标题。
- `#define DEFAULT_WIDTH 80`：默认宽度。
- `#define DEFAULT_HEIGHT 25`：默认高度。

---

# TuiTools 类 API 文档

## 概述

`TuiTools` 类提供了一组用于终端用户界面（TUI）操作的工具函数，包括清屏、隐藏/显示光标、移动光标位置、打印系统版本和延时等功能。

## 类定义

### `TuiTools`

**包含文件：**

```cpp
#include "TuiTools.h"
```

### 公共成员函数

#### `static void hideCursor()`

- **描述：** 在 Windows 系统上隐藏光标。
- **平台：** 仅限 Windows。

#### `static void showCursor()`

- **描述：** 在 Windows 系统上显示光标。
- **平台：** 仅限 Windows。

#### `static void movCursorTo(int x, int y)`

- **描述：** 将光标移动到指定位置。
- **参数：**
  - `int x`：光标的目标横坐标。
  - `int y`：光标的目标纵坐标。
- **平台：** 仅限 Windows。

#### `static void clearScreen()`

- **描述：** 清除终端屏幕内容。

#### `static void printVersion(const string& VERSION)`

- **描述：** 打印指定版本信息。
- **参数：**
  - `const string& VERSION`：版本信息字符串。

#### `static string systemVersion()`

- **描述：** 获取操作系统版本信息。
- **返回值：** 表示操作系统版本的字符串。

#### `static void timeSleep(int time)`

- **描述：** 延时指定毫秒数。
- **参数：**
  - `int time`：延时时间（毫秒）。

### 私有成员函数

#### `static unique_ptr<string> pCaseWindowsVersion(OSVERSIONINFOEX& osvi)`

- **描述：** 获取 Windows 操作系统版本信息的辅助函数。
- **参数：**
  - `OSVERSIONINFOEX& osvi`：Windows 版本信息结构体。
- **返回值：** 一个指向表示 Windows 版本信息字符串的智能指针。
- **平台：** 仅限 Windows。

## 常量

- `#define ANSI_CLEAR "\033[2J\033[1;1H"`：ANSI 终端清屏指令。

---

# Module 类 API 文档

## 概述

`Module` 类用于创建和管理模块对象。模块具有宽度、高度、形状和位置等属性。该类提供了一些方法来获取和设置这些属性，以及绘制模块。

## 类定义

### `Module`

**包含文件：**

```cpp
#include "Module.h"
```

### 公共成员函数

#### `Module(const vector<string>& appearance, int xPosition, int yPosition)`

- **描述：** 使用指定的形状和位置创建一个新的 `Module` 对象。
- **参数：**
  - `const vector<string>& appearance`：模块的形状。
  - `int xPosition`：模块的初始横坐标位置。
  - `int yPosition`：模块的初始纵坐标位置。
- **可能抛出的异常：**
  - `std::runtime_error("A empty appearance vector")`：空的向量。
  - `std::runtime_error("Strings are not equal in length");`：向量中字符串长度不统一。

#### `explicit Module(const vector<string>& appearance)`

- **描述：** 使用指定的形状创建一个新的 `Module` 对象，初始位置为 (0, 0)。
- **参数：**
  - `const vector<string>& appearance`：模块的形状。
- **可能抛出的异常：**
  - `std::runtime_error("A empty appearance vector")`：空的向量。
  - `std::runtime_error("Strings are not equal in length");`：向量中字符串长度不统一。

#### `Module()`

- **描述：** 创建一个默认的 `Module` 对象。

#### `vector<int> size() const`

- **描述：** 获取模块的尺寸（宽度和高度）。
- **返回值：** 一个包含两个整数的向量，第一个元素为宽度，第二个元素为高度。

#### `vector<string> appearance() const`

- **描述：** 获取模块的形状。
- **返回值：** 模块的形状，一个字符串向量。

#### `void appearance(const vector<string>& appearance)`

- **描述：** 设置模块的形状。
- **参数：**
  - `const vector<string>& appearance`：新的形状。

#### `vector<int> position() const`

- **描述：** 获取模块的当前位置（横坐标和纵坐标）。
- **返回值：** 一个包含两个整数的向量，第一个元素为横坐标，第二个元素为纵坐标。

#### `void position(int newXPosition, int newYPosition)`

- **描述：** 设置模块的新位置。
- **参数：**
  - `int newXPosition`：新的横坐标位置。
  - `int newYPosition`：新的纵坐标位置。

#### `void draw() const`

- **描述：** 绘制模块。

## 常量

- `#define EMPTY '#'`：表示默认空字符。

---
