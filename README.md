

# Spinner

A lightweight C++ library for displaying terminal spinners and progress animations (like `⠏ Project compiled successfully.`).
Cross-platform and dependency-light, perfect for CLI tools and build systems.

---

## ✨ Features

* Minimal and easy-to-use API
* Multiple spinner styles (Unicode braille, ASCII, etc.)
* Works on Linux, macOS, and Windows
* Cross-platform with **fmt** for output formatting
* Available on **Conan 2** package manager
* Build from source with **cppsage**

---

## 📦 Installation

### 1. Conan 2 (Recommended)

```sh
Coming Soon...
```

---

### 2. Build from Source with cppsage

Clone and build using **cppsage**:

```sh
git clone https://github.com/vishal-ahirwar/spinner.git
cd spinner
sage build
```

This will:

* Build the library
* Install dependencies (like `fmt`)
* Produce `spinner.lib` / `libspinner.a` (depending on your OS)

Then link it in your project:

```cmake
add_executable(example src/main.cpp)
target_link_libraries(example spinner)
```

---

## 🚀 Example

```cpp
#include <spinner/include/spinner.h>

#include <chrono>
#include <thread>

int main() {
  Spinner spinner("Ding dong ding...",Spinner::Color::yellow);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  spinner.setDisplayMessage("Now i'm doing some heavy work",
                            Spinner::Color::gray);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  spinner.setDisplayMessage("Almost Done", Spinner::Color::sky_blue);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  return 0;
}
```

Output:

<img width="574" height="75" alt="image" src="https://github.com/user-attachments/assets/7e07349b-95a2-496f-9f32-e03cac02c252" />


---

## 🛠 Development

To run the provided example:

```sh
sage build example
```

---

## 📄 License

MIT License © 2025 [Vishal Ahirwar](https://github.com/vishal-ahirwar)

---

