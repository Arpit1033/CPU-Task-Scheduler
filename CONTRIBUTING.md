# Contributing to CPU Task Scheduler

Thank you for your interest in contributing! This document provides guidelines and instructions for contributing to this project.

## 🚀 Getting Started

1. **Fork the repository** on GitHub
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/cpu-task-scheduler.git
   cd cpu-task-scheduler
   ```
3. **Create a branch** for your changes:
   ```bash
   git checkout -b feature/your-feature-name
   ```

## 💻 Development Setup

### Prerequisites
- C++ compiler (g++, clang++, or MSVC)
- CMake 3.10+

### Building
```bash
mkdir build && cd build
cmake ..
cmake --build . --config Release
```

## 📝 How to Contribute

### Reporting Bugs
- Check if the bug has already been reported in Issues
- If not, create a new issue with:
  - Clear title and description
  - Steps to reproduce
  - Expected vs actual behavior
  - Your environment (OS, compiler version)

### Suggesting Features
- Open an issue with the `enhancement` label
- Describe the feature and its use case
- Explain how it benefits the project

### Adding a New Scheduling Algorithm

1. Create a new file `your_algorithm.cpp`:
   ```cpp
   #include <iostream>
   #include "scheduler.h"

   using namespace std;

   void your_algorithm(vector<Task> &tasks) {
       // Your implementation here
   }

   int main() {
       vector<Task> tasks = {
           Task("Task1", 5),
           Task("Task2", 3),
           Task("Task3", 8)
       };

       cout << "Your Algorithm Scheduling:\n";
       your_algorithm(tasks);
       return 0;
   }
   ```

2. Add the function declaration to `scheduler.h`

3. Add the build target to `CMakeLists.txt`

4. Update `.github/workflows/build.yml` to include your algorithm

5. Update `README.md` with algorithm details

## ✅ Code Guidelines

- Use C++17 features
- Follow existing code style
- Use meaningful variable names
- Add comments for complex logic
- Keep functions focused and small

## 📤 Submitting Changes

1. **Commit your changes** with a clear message:
   ```bash
   git commit -m "feat: add XYZ scheduling algorithm"
   ```
   
   Commit message prefixes:
   - `feat:` - New feature
   - `fix:` - Bug fix
   - `docs:` - Documentation changes
   - `refactor:` - Code refactoring
   - `chore:` - Maintenance tasks

2. **Push to your fork**:
   ```bash
   git push origin feature/your-feature-name
   ```

3. **Open a Pull Request** on GitHub

## 🧪 Testing

Before submitting, ensure your code compiles without errors, all existing algorithms still work, your new algorithm produces correct output, and the CI pipeline passes.

## 📄 License

By contributing, you agree that your contributions will be licensed under the MIT License.
