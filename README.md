# MenuDemo
![MenuDemo](https://i.imgur.com/epgcVno.png)

## What's MenuDemo?
MenuDemo is a simple CLI-based menu demo created as part of a school assignment.  
It showcases basic menu navigation and game selection in C++ using a modular structure.

---

## Requirements

- CMake (v3.10 or higher)
- A C++ compiler:
  - **Windows**: MinGW (recommended)
  - **Linux/macOS**: `g++` or `clang++`

---

## Build

To build the project yourself, follow these steps:

### Windows (with MinGW)

1. Clone the repository
   ```bash
   git clone https://github.com/Cascian08/MenuDemo.git
   ```

2. Enter the project folder
   ```bash
   cd MenuDemo
   ```

3. Create a build directory and compile
   ```bash
   mkdir build
   cd build
   cmake -G "MinGW Makefiles" ..
   mingw32-make
   ```

4. Run the program
   ```bash
   ./MenuDemo.exe
   ```

---

### Linux / macOS

1. Clone the repository
   ```bash
   git clone https://github.com/Cascian08/MenuDemo.git
   ```

2. Enter the project folder
   ```bash
   cd MenuDemo
   ```

3. Create a build directory and compile
   ```bash
   mkdir build
   cd build
   cmake ..
   make
   ```

4. Run the program
   ```bash
   ./MenuDemo
   ```

---

## License

This project is released under the [MIT License](LICENSE).