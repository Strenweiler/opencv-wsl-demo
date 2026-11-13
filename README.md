# opencv-wsl-demo

在 **WSL2 (Ubuntu)** 里用 **C++ + CMake + OpenCV** 跑通「读图 → 打印尺寸 → 写出图片」的最小 demo，用来确认 OpenCV 环境装好了、能正常读取和写出图片。

## 环境

- Windows 10/11 + WSL2（Ubuntu 22.04 / 24.04 均可）
- `build-essential`、`cmake`、`libopencv-dev`

## 安装依赖

```bash
sudo apt update
sudo apt install -y build-essential cmake libopencv-dev
```

验证 OpenCV 已安装：

```bash
pkg-config --modversion opencv4
```

## 构建

```bash
cmake -S . -B build
cmake --build build -j
```

## 运行

```bash
cd build
./show_img
```

程序会：

1. 读取上一级目录里的 `test.jpg`（`../test.jpg`，所以必须在 `build/` 目录里运行）；
2. 打印图片宽高，证明 OpenCV 读图正常；
3. 把图片另存为 `output.png`，证明写图正常。

成功时输出类似：

```text
图片读取成功！尺寸: 1280 x 720
```

`build/` 和 `output.png` 已在 `.gitignore` 里忽略，不会污染仓库。

## 项目结构

| 文件 | 说明 |
| --- | --- |
| `main.cpp` | 读取 `../test.jpg`、打印尺寸、写出 `output.png` |
| `CMakeLists.txt` | `find_package(OpenCV REQUIRED)` 并链接 `show_img` 可执行文件 |
| `test.jpg` | 测试图片 |
| `.gitignore` | 忽略 `build/` 与 `output.png` |

## 适用场景

把它当作 OpenCV 环境自检模板：换台机器、重装 WSL、升级 Ubuntu 之后跑一遍，能读能写就说明开发环境没问题。要扩展成正式项目时，把 `main.cpp` 换成自己的处理流程即可。
