#include <gtest/gtest.h>
#include <chrono>

#include <performance_analysis_example/hard_worker.h>

TEST(HardWorkerTest, Creation) { HardWorker hard_worker; }

TEST(HardWorkerTest, SimpleStuff) {
  HardWorker hard_worker;
  ASSERT_NE(hard_worker.verySimpleStuff(), 0.0);
}

TEST(HardWorkerTest, ComplicatedStuff) {
  HardWorker hard_worker;
  ASSERT_NE(hard_worker.veryComplicatedStuff(), 0.0);
}

TEST(HardWorkerTest, AllStuff) {
  HardWorker hard_worker;
  std::chrono::seconds test_duration_seconds(3);

  auto start = std::chrono::system_clock::now();
  auto end = start + test_duration_seconds;

  while (std::chrono::system_clock::now() < end) {
    ASSERT_NE(hard_worker.verySimpleStuff(), 0.0);
    ASSERT_NE(hard_worker.veryComplicatedStuff(), 0.0);
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
