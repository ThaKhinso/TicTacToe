#include <future>
#include <vector>
#include <iostream>
std::async()
int solution(int number) 
{
  if(number < 0) return 0;
  std::vector<uint>multipliesofthree = { 0 };
  std::vector<uint>multipliesoffive = { 0 };
  int i = 0;
  bool running = true;
  while(running) {
    if(3 * i < number) running = false;break;
    multipliesofthree[i] = 3 * i;
    i++;
  }
  for (auto& e : multipliesofthree) {
    std::cout << e << "\n";
  }
  int j = 0;
  while(running) {
    if(5 * j < number) running = false;break;
    multipliesoffive[j] = 5 * j;
    j++;
  }
  int sumofthree = 0;
  for (auto& e : multipliesofthree) {
    sumofthree += e;
  }

  int sumoffive = 0;
  for (auto& e : multipliesoffive) {
    sumoffive += e;
  }
  return sumofthree + sumoffive;
};

int solution2(int number) {
    int multithree[20] = {0};
    int multifive[20] = {0};
    int i = 0;
    while (3 * i < number) {
        multithree[i] = 3 * i;
        i++;
    }
    int threesum = 0;
    for (int i = 0; i < 20; i++) {
        threesum += multithree[i];
    }
    int j = 0;
    while(5 * j < number) {
        multifive[j] = j * 5;
        j++;
    }
    int fivesum = 0;
    for (int i = 0; i < 20; i++) {
        fivesum += multifive[i];
    }

    return threesum + fivesum;
}

int main(void) {
    std::cout << solution2(10) << "\n";
    std::cout << solution(10) << "\n";
    return 0;
}