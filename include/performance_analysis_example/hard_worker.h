#pragma once

#include <random>
#include <string>
#include <vector>

/**
 * @brief The HardWorker class is a dummy class used to exemplify a class that
 * can do a very simple and complicated operations. This is used as a testbench
 * for running perf so we can see that the complicated operation actually takes
 * more computer resoureces that the simple one.
 */
class HardWorker {
 public:
  /**
   * @brief HardWorker Default constructor
   */
  HardWorker();

  /**
   * @brief veryComplicatedStuff expresses a very complicated operation
   * @return a random double
   */
  double veryComplicatedStuff();

  /**
   * @brief verySimpleStuff expresses a very simple operation
   * @return a random double
   */
  double verySimpleStuff();

  /**
   * @brief rand generates a random number
   * @return a random double
   */
  double rand();

 private:
  std::uniform_real_distribution<double> distribution_;
  std::random_device rd_;
  std::mt19937 mt_;
};
