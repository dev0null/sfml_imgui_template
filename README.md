# SFML + ImGui Template
This is a template project that combines SFML (Simple and Fast Multimedia Layer) + ImGui (Immediate Mode Gui) to get started with C++ graphics/game development.

- **SFML Version**: 2.6
- **ImGui Version**: 1.89

# Installation
- Download project:
  ```shell
  git clone https://github.com/dev0null/sfml_imgui_template
  ```
  
# How to do it from scratch
## 1. Install SFML
**Debian**: 
```
sudo apt install libsfml-dev
```
**Arch**:
```
sudo pacman -S sfml
```

Or check the SFML [documentation](https://www.sfml-dev.org/tutorials/2.6/#getting-started) for complete instructions.

## 2. Get ImGui source code
- Download:
```git-clone https://github.com/ocornut/imgui.git```
- Take all the source files from the root directory and copy over to the new project ```./src/imgui``` folder.

## 3. Get SFML backend
- Download:
```git-clone https://github.com/SFML/imgui-sfml.git```
- Append the content of **imconfig-SFML.h** to src/imgui/**imconfig.h**
- Copy the remaining source files into the same folder ```./src/imgui```

## 4. Setup Makefile
The Makefile is made for Linux. If you are on a different platform make sure to adjust it for your OS.

## 5. Compile & Run
From the root folder of the project:

Compile the project.
```
make -j $(nproc)
```
Or compile and run.
```
make run -j $(nproc)
```

# ImGui UI Elements
Interactive "documentation" [here](https://pthom.github.io/imgui_manual_online/manual/imgui_manual.html)
