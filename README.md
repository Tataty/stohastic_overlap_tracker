# My C++ Project

This is a basic C++ project structured using CMake. It includes a simple example demonstrating how to set up a C++ application with a header file and a main source file.

## Project Structure

```
my-cpp-project
├── src
│   └── main.cpp        # Entry point of the application
├── include
│   └── main.hpp        # Header file with declarations
├── .vscode
│   ├── tasks.json      # VS Code tasks for building the project
│   └── launch.json      # VS Code debugger configuration
├── CMakeLists.txt      # CMake configuration file
└── README.md           # Project documentation
```

## Requirements

- CMake (version 3.10 or higher)
- A C++ compiler (e.g., g++, clang++)

## Building the Project

1. Open a terminal and navigate to the project directory.
2. Create a build directory:
   ```
   mkdir build
   cd build
   ```
3. Run CMake to configure the project:
   ```
   cmake ..
   ```
4. Build the project:
   ```
   cmake --build .
   ```

## Running the Application

After building the project, you can run the application from the build directory:
```
./my-cpp-project
```

## VS Code Configuration

To build and run the project in Visual Studio Code, you can use the provided `.vscode/tasks.json` and `.vscode/launch.json` files. Make sure to open the project folder in VS Code and use the integrated terminal to execute the build and run tasks.