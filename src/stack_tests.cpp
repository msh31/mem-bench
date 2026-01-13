#include <iostream>

void test_small_stack() {
    int arr[1000] = {0};  // 4KB
    std::cout << "1000 ints: OK\n";
}

void test_large_stack() {
    int arr[1000000] = {0};  // 4MB 
    std::cout << "1,000,000 ints: OK\n";
}

void test_extra_large_stack() { //40MB
    int arr[10000000] = {0};
    std::cout << "10,000,000 ints: OK\n";
}

void test_very_large_stack() {
    int arr[100000000] = {0};
    std::cout << "100,000,000 ints: OK\n";
}

void run_stack_tests() {
    std::cout << "Running stack tests\n";

    std::cout << "\n- Running Small Stack Test\n";
    test_small_stack();

    std::cout << "\n- Running Large Stack Test\n";
    test_large_stack();

    std::cout << "\n- Running Extra Large Stack Test\n";
    test_extra_large_stack();

    std::cout << "\n- Running **Very** Large Stack Test\n";
    test_very_large_stack();
}
