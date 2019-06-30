#pragma once

#include <random>
#include <string>
#include <vector>

/**
 * @brief The PerformanceAnalysis class
 */
class HardWorker {
 public:
  /**
   * @brief PerformanceAnalysis Default constructor
   */
  HardWorker();

  /**
   * @brief veryComplicatedStuff
   * @return
   */
  double veryComplicatedStuff();

  /**
   * @brief verySimpleStuff
   * @return
   */
  double verySimpleStuff();

  double rand();

 private:
  std::uniform_real_distribution<double> distribution_;
  std::random_device rd_;
  std::mt19937 mt_;
};
