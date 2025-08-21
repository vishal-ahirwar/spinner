#ifndef SPINNER_H
#define SPINNER_H

#include <atomic>
#include <string>
#include <thread>

#if defined(_WIN32)
#include <windows.h>
#endif


class Spinner {
 public:
  Spinner(std::string message = "")
      : mMessage(std::move(message)), mRunning(false) {}

  void start();

  void stop();

  void setDisplayMessage(std::string);

  ~Spinner() { stop(); }

 private:
  void run();

  static void setupConsole();

  std::string mMessage;
  std::atomic<bool> mRunning;
  std::thread mThread;
};

#endif  // SPINNER_H