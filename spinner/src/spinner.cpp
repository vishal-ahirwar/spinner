#include "../include/spinner.h"

#include <fmt/color.h>
#include <fmt/core.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>

void Spinner::start() {
  if (mRunning.exchange(true)) return;
  setupConsole();
  mThread = std::thread([this] { run(); });
};

void Spinner::stop() {
  if (!mRunning.exchange(false)) return;
  if (mThread.joinable()) mThread.join();
  fmt::print("\r{:<30}\n", mMessage);
  std::cout.flush();
}

void Spinner::run() {
  static const char* frames[] = {"⠋", "⠙", "⠹", "⠸", "⠼",
                                 "⠴", "⠦", "⠧", "⠇", "⠏"};
  size_t i = 0;
  while (mRunning.load()) {
    fmt::print("\r{} {:<30}", frames[i], mMessage);
    std::cout.flush();
    i = (i + 1) % (sizeof(frames) / sizeof(frames[0]));
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }
}
void Spinner::setupConsole() {
#if defined(_WIN32)
  SetConsoleOutputCP(CP_UTF8);
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  if (hOut != INVALID_HANDLE_VALUE) {
    DWORD mode = 0;
    if (GetConsoleMode(hOut, &mode)) {
      mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
      SetConsoleMode(hOut, mode);
    }
  }
#endif
}

void Spinner::setDisplayMessage(std::string message) {
  this->mMessage = std::move(message);
}