# tusa

**A lightweight music player with a classic 2000s look.**

`tusa` is a native desktop music player built with C++ and Qt. It aims to stay
simple, fast, and easy to use, especially on computers with limited resources.
At the time of the initial release, it used around 6 MB of RAM; actual usage
may vary by system and while playing music.

> **Status:** This project is still in development. Support for additional
> audio formats is a work in progress.

## Screenshot

![tusa music player](https://github.com/user-attachments/assets/28f6a6fe-07c6-4781-8a75-d72ad80e08fb)

## Download and run

1. Open the [Releases](https://github.com/habacuq11/tusa/releases) page.
2. Download the latest release.
3. Extract the archive.
4. Run `tusa.exe`.

## Build from source

### Requirements

- C++17-compatible compiler
- CMake 3.16 or later
- Qt 6 with the Widgets and Multimedia modules

### Build

From the project directory, configure and build with CMake:

```powershell
cmake -S . -B build
cmake --build build --config Release
```

The executable will be generated in the build directory (the exact path depends
on your generator and configuration).

## Technology

- C++17
- Qt 6 Widgets
- Qt 6 Multimedia
