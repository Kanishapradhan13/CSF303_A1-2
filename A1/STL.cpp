#include <iostream>
#include <vector>
#include <deque>
#include <array>
#include <numeric>    // for std::accumulate
#include <algorithm>  // for std::reverse


void demonstrate_vector_reverse(int element_count) {
    std::vector<int> integer_sequence(element_count);

    std::cout << "Enter " << element_count << " integers: ";
    for (int& value : integer_sequence) {
        std::cin >> value;
    }


    std::cout << "Reversed: ";
    for (auto it = integer_sequence.rbegin(); it != integer_sequence.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

void demonstrate_deque_operations() {
    std::deque<int> task_queue;


    task_queue.push_back(10);
    task_queue.push_back(20);
    task_queue.push_front(5);   // jumps ahead of 10 and 20
    task_queue.push_back(30);
    task_queue.pop_front();     // removes the 5 that jumped in

    std::cout << "Deque contents after operations: ";
    for (int job : task_queue) {
        std::cout << job << " ";
    }
    std::cout << "\n";

}


void demonstrate_array_sum() {
    std::array<int, 6> fixed_data = {12, 45, 7, 33, 89, 4};


    long long total = std::accumulate(fixed_data.begin(), fixed_data.end(), 0LL);

    std::cout << "Array elements: ";
    for (int element : fixed_data) {
        std::cout << element << " ";
    }
    std::cout << "\nSum: " << total << "\n";
}


int main() {
    int N;
    std::cout << "Enter N (1 <= N <= 100000): ";
    std::cin >> N;


    if (N < 1 || N > 100000) {
        std::cout << "N out of valid range.\n";
        return 1;
    }

    std::cout << "\n--- Part A: vector reverse ---\n";
    demonstrate_vector_reverse(N);

    std::cout << "\n--- Part B: deque operations ---\n";
    demonstrate_deque_operations();

    std::cout << "\n--- Part C: std::array sum ---\n";
    demonstrate_array_sum();

    return 0;
}