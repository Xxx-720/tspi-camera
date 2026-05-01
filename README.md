# 📷 泰山派RK3566 相机Qt项目
基于泰山派RK3566平台开发的嵌入式相机Qt应用，800*480横屏显示，一键配置环境与开机自启。

---

## 📁 项目结构
```text
.
├── all/                    # 开发板一键配置文件（可直接传到板上使用）
│   ├── truetype/           # 中文字体文件
│   ├── auto.sh             # rcS调用的运行脚本
│   ├── auto_config.sh      # 一键配置脚本
│   ├── my_project          # Qt程序可执行文件
│   ├── rcS                 # 开机自启脚本
│   └── weston.ini          # Weston compositor配置文件
└── my_project/             # Qt相机应用源码
    └── my_project.pro      # Qt工程文件
```

---

## ✨ 项目功能
- ✅ 适配泰山派RK3566的3.1寸屏幕480x800横屏显示
- ✅ Qt 5嵌入式GUI界面，支持中文显示
- ✅ 支持开机自启，一键配置开发板运行环境
- ✅ 无依赖OpenCV，纯Qt实现，轻量高效

---

## 🛠️ 开发环境
- 开发板：泰山派RK3566
- 系统：立创开发板提供的Buildroot Linux（带Weston Wayland compositor）
- Qt版本：Qt 5.12.10 

---

## 🚀 快速上手（开发板端）
### 1. 准备工作
将`all`文件夹完整传输到开发板（路径xxx随意，但是脚本要跟着修改）：
- 这里使用`adb`直接传输文件至板端`/wxq/all`路径下
```bash
adb push all /wxq/all
```

### 2. 一键配置环境
```bash
cd /wxq/all
chmod +x auto_config.sh
./auto_config.sh
```
脚本将自动完成：
- 配置Weston显示服务
- 设置中文字体
- 配置开机自启脚本
- 赋予可执行文件权限

### 3. 开机自启配置
脚本已自动配置，重启开发板即可自动运行程序：
```bash
reboot
```

---

## 💻 源码编译（PC端）
### 1. 环境准备
- 已配置RK3566 Qt交叉编译环境（禁用OpenGL/Vulkan/SSE2/OpenSSL）
- 确保交叉编译工具链路径已添加到环境变量

### 2. 编译步骤
```bash
cd my_project
# 使用交叉编译的qmake生成Makefile
/path/to/qt/bin/qmake my_project.pro
make -j$(nproc)
```
编译完成后，可执行文件将生成在`my_project`目录下，替换`all`文件夹中的`my_project`文件即可。

---

## 📝 关键配置说明
### 1. 横屏显示配置


### 2. 中文显示配置
`all/truetype/`中包含中文字体文件，脚本会自动将字体复制到系统字体目录，Qt程序无需额外配置即可正常显示中文。

---

## ❌ 常见问题排查
1. **程序无法启动/黑屏**


2. **画面无法旋转**


3. **中文显示乱码**
   - 检查字体文件是否已复制到`/usr/share/fonts/`目录
   - 确认Qt编译时已启用字体支持

---

## 📌 注意事项
- 开发板端运行需依赖Weston compositor，Buildroot系统需确保Wayland支持已启用
- 编译时禁用了Vulkan/OpenGL，以适配RK3566嵌入式环境，避免兼容性问题

---

## 📄 许可证
MIT License

---
