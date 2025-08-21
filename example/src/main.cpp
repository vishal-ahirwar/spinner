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