#include "performance_analysis_example/hard_worker.h"

HardWorker::HardWorker() : distribution_(1.0, 10.0) {}

double HardWorker::veryComplicatedStuff() {
  std::vector<double> dummy_vector;
  for (int i = 0; i < 100000; ++i) dummy_vector.push_back(rand());
  return dummy_vector.back();
}

double HardWorker::verySimpleStuff() { return rand(); }

double HardWorker::rand() { return distribution_(mt_); }
