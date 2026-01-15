#include <iostream>
#include <cstring>
#include <string>
#include <sys/sysctl.h>

#ifdef __linux__
#include <fstream>
#include <ostream>
#endif

#ifdef __APPLE__
#include <mach-o/arch.h>
#endif

// function implementations are in the named source files
void run_stack_tests(); 
void run_passing_tests();
void run_benchmarks();

void print_system_info() {
#ifdef __linux__
    std::ifstream cpuModel("/proc/cpuinfo");
    std::ifstream ramCapacity("/proc/meminfo");

    std::string cpuLine;
    std::string ramLine;

    while (getline(cpuModel, cpuLine)) {
        if (cpuLine.find("model name") != std::string::npos) {
            size_t pos = cpuLine.find(":");
            std::string value = cpuLine.substr(pos + 1);
            std::cout << "CPU MODEL: " << value << std::endl;
            break;
        }
    }

    while (getline(ramCapacity, ramLine)) {
        if (ramLine.find("MemTotal") != std::string::npos) {
            size_t pos = ramLine.find(":");
            std::string value = ramLine.substr(pos + 1);
            int ramValue = std::stoi(value);
            std::cout << "TOTAL RAM: " << ramValue / 1024 << " MB" << std::endl;
            break;
        }
    }
#elif __APPLE__
    size_t size{};
    if (sysctlbyname("machdep.cpu.brand_string", nullptr, &size, nullptr, 0) != 0 || size == 0) {
        throw std::runtime_error("Unable to retrieve CPU type (size query failed)");
    }

    std::string buffer(size, '\0');
    if (sysctlbyname("machdep.cpu.brand_string", buffer.data(), &size, nullptr, 0) != 0) {
        throw std::runtime_error("Unable to retrieve CPU type (value query failed)");
    }

    if (!buffer.empty() && buffer.back() == '\0') {
        buffer.pop_back();
    }

    int mib [] = { CTL_HW, HW_MEMSIZE };
    int64_t value = 0;
    size_t length = sizeof(value);

    if(sysctl(mib, 2, &value, &length, NULL, 0) == -1) {
        throw std::runtime_error("Unable to retreive total ram amount (sysctl failed)");
    }

    std::cout << "CPU MODEL: " << buffer << std::endl;
    std::cout << "TOTAL RAM: " << value / 1024 / 1024 << " MB" << std::endl;
#endif

//wont work on windows
    struct rlimit limit;
    getrlimit(RLIMIT_STACK, &limit);
    std::cout << "STACK LIMIT: " << limit.rlim_cur / 1024 << " KB" << std::endl;
}

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
            run_benchmarks();
        }
    }

    std::cout << "\nHere will be a summary:\n\n";
    print_system_info();
    return 0;
}
