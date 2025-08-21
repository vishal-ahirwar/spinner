#include <spinner/include/spinner.h>

#include <chrono>
#include <thread>

int main() {
  Spinner spinner("Ding dong ding...");
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  spinner.setDisplayMessage("Now i'm doing some heavy work");
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  spinner.setDisplayMessage("Almost Done");
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();
  
  return 0;
}