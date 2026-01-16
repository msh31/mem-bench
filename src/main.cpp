#include <iostream>
#include <cstring>

// function implementations are in the named source files
void run_stack_tests(); 
void run_passing_tests();

struct SensorData {};
void process_by_value(SensorData data);
void process_by_pointer(SensorData* data);
void process_by_reference(SensorData& data);

void print_system_info();

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout << "Usage: mem-bench --test [stack|passing] | --benchmark\n";
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--test") == 0) {
            if (i + 1 < argc) {
                if(strcmp(argv[i+1], "stack") == 0) {
                    run_stack_tests();
                }

                if(strcmp(argv[i+1], "passing") == 0) {
                    run_passing_tests();
                }
                i++;
            }
        }
        else if (strcmp(argv[i], "--benchmark") == 0) {
            std::cout << "running all benchmarks..\n";
            run_stack_tests();
            run_passing_tests();
        }
    }

    std::cout << "\nHere will be a summary:\n\n";
    print_system_info();
    return 0;
}
