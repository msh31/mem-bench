# mem-bench
A simple tool built to improve gaps in my understanding of memory management
---

## What is this?
A project that helped me understand the difference in performance when it comes to accessing data in a large struct (>1KB).
When to choose to pass by value, by pointer and by reference. 

## Tests
- Stack
    - this simply tests to see how many local variables can be stored on your system since they are stored on the stack, also has heap tests included
- Passing
    - this shows how bad passing by value can be for big structs (> ~16KB)

## Results 
Both tests were run with 100,000 iterations.

- 1KB of data
```cpp
Running passing tests
Time scores for each accessing of data method x100,000
By value: 62.168ms
By pointer: 57.0405ms
By reference: 56.7913ms

Here will be a summary:

CPU MODEL:  AMD Ryzen 7 7800X3D 8-Core Processor
TOTAL RAM: 31801 MB
STACK LIMIT: 16384 KB
```
---

- 100KB of data
```cpp
Running passing tests
Time scores for each accessing of data method x100,000
By value: 6279.61ms
By pointer: 57.1102ms
By reference: 56.9188ms

Here will be a summary:

CPU MODEL:  AMD Ryzen 7 7800X3D 8-Core Processor
TOTAL RAM: 31801 MB
STACK LIMIT: 16384 KB
```

## Notes
For small structs (~1KB / 256 floats (is what i used here)) its generally fine to pass by value as the difference is not *that* big as seen in the results section, 
for bigger structs (~100KB) the difference is massive, a whopping 6.2 seconds vs 56-57ms for pointer/reference.

A float is generally 4 bytes, so stuff like that, integers, are generally fine to copy, but I try to pass by reference/pointer for structs larger than ~16 bytes.
