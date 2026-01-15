#include <iostream>

struct SensorData {
    float readings[256];  // 1KB
};

void process_by_value(SensorData data) {
}

void process_by_pointer(SensorData* data) {
}

void process_by_reference(SensorData& data) {
}

void run_passing_tests() {
    std::cout << "Running passing tests\n";
}
