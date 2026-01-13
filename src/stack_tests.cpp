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

void test_extra_small_heap() {
    int* arr = new int[10000000];  //40MB
    
    if(arr == nullptr) {
        std::cerr << "\nThe allocation of 40MB on the heap failed (seriously? buy more ram)";
        return;
    }

    std::cout << "10,000,000 ints on heap: OK\n";
    delete[] arr;  // thy shall not leak!
}

void test_small_heap() {
    int* arr = new int[1000000000];  //4GB
    
    if(arr == nullptr) {
        std::cerr << "\nThe allocation of 4GB on the heap failed!";
        return;
    }

    std::cout << "1,000,000,000 ints on heap: OK\n";
    delete[] arr;  // thy shall not leak!
}


void test_medium_heap() {
    int* arr = new int[2000000000];  //8GB
    
    if(arr == nullptr) {
        std::cerr << "\nThe allocation of 8GB on the heap failed!";
        return;
    }

    std::cout << "2,000,000,000 ints on heap: OK\n";
    delete[] arr;  // thy shall not leak!
}

void test_large_heap() {
    int* arr = new int[4000000000];  //16GB
    
    if(arr == nullptr) {
        std::cerr << "\nThe allocation of 16GB on the heap failed!";
        return;
    }

    std::cout << "4,000,000,000 ints on heap: OK\n";
    delete[] arr;  // thy shall not leak!
}

void run_stack_tests() {
    std::cout << "Running stack tests\n";

    std::cout << "\n- Running Small Stack Test\n";
    test_small_stack();

    std::cout << "\n- Running Large Stack Test\n";
    test_large_stack();

    // std::cout << "\n- Running Extra Large Stack Test\n";
    // test_extra_large_stack();

    // std::cout << "\n- Running Very Large Stack Test\n";
    // test_very_large_stack();
    
    std::cout << "\n- Running Extra Small Heap Test\n";
    test_extra_small_heap();

    std::cout << "\n- Running Small Heap Test\n";
    test_small_heap();

    std::cout << "\n- Running Medium Heap Test\n";
    test_medium_heap();

    std::cout << "\n- Running Large Heap Test\n";
    test_large_heap();
}
