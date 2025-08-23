#include <spinner/include/spinner.h>

#include <chrono>
#include <thread>

int main() {
  Spinner spinner("Booting up...", Spinner::Color::yellow);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  spinner.stop();

  spinner.setDisplayMessage("Now i'm doing some heavy work",
                            Spinner::Color::gray);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  spinner.setDisplayMessage("Finishing up...");
  std::this_thread::sleep_for(std::chrono::seconds(3));
  spinner.stop();

  spinner.setDisplayMessage("Almost Done", Spinner::Color::sky_blue);
  spinner.start();
  std::this_thread::sleep_for(std::chrono::seconds(2));
  spinner.setDisplayMessage(
      "You won't belive me I know a guy who reads loading messages!");
  std::this_thread::sleep_for(std::chrono::seconds(5));
  spinner.stop();

  return 0;
}