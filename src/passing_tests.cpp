#include <iostream>
#include <chrono>
#include <ostream>

#define test_count 100000 //100k
#define struct_size 25600 //4x256 = 1024 bytes = 1KB 

//wish these could be even longer...
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::chrono::milliseconds;

struct SensorData {
    float readings[struct_size];  // 1KB
};

void process_by_value(SensorData data) {
    float sum = 0;
    for(int i = 0; i < struct_size; i++) {
        sum = sum + data.readings[i];
    }
}

void process_by_pointer(SensorData* data) {
    float sum = 0;
    for(int i = 0; i < 256; i++) {
        sum = sum + data->readings[i];
    }
}

void process_by_reference(SensorData& data) {
    float sum = 0;
    for(int i = 0; i < 256; i++) {
        sum = sum + data.readings[i];
    }
}

void run_passing_tests() {
    std::cout << "Running passing tests\n";
    SensorData data;

    auto st_value = high_resolution_clock::now();
    for (int i = 0; i < test_count; i++) {
        process_by_value(data);
    }
    auto et_value = high_resolution_clock::now();

    auto st_pointer = high_resolution_clock::now();
    for (int i = 0; i < test_count; i++) {
        process_by_pointer(&data);
    }
    auto et_pointer = high_resolution_clock::now();

    auto st_reference = high_resolution_clock::now();
    for (int i = 0; i < test_count; i++) {
        process_by_reference(data);
    }
    auto et_reference = high_resolution_clock::now();

    duration<double, std::milli> tt_value = et_value - st_value;
    duration<double, std::milli> tt_pointer = et_pointer - st_pointer;
    duration<double, std::milli> tt_reference = et_reference - st_reference;

    std::cout << "Time scores for each accessing of data method x100,000\n";
    std::cout << "By value: " << tt_value.count() << "ms" << std::endl;
    std::cout << "By pointer: " << tt_pointer.count() << "ms" << std::endl;
    std::cout << "By reference: " << tt_reference.count() << "ms" << std::endl;
}
