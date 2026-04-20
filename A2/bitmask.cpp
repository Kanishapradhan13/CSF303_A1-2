#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int& x : nums) cin >> x;

    int K;
    cin >> K;

    int count = 0;
    int total_subsets = 1 << N; 

    for (int mask = 0; mask < total_subsets; mask++) {
        int subset_sum = 0;
        for (int i = 0; i < N; i++)
            if (mask & (1 << i))  
                subset_sum += nums[i];

        if (subset_sum % K == 0)
            count++;
    }

    cout << "Count: " << count << "\n";
    return 0;
}