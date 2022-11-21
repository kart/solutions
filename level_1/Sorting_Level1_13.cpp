#include <iostream>
#include <cmath>

const int kMaxElements = 100;

// This is a simple problem once you get a hang of it. It also
// introduces another pattern -- frequency array.
//
// What is being asked?
//
// Consider this array:
// 4 6 5 3 3 1
//
// First, let's understand what is a subarray. A subarray is
// any subset if the given array. In this case, 4, 3, 1 is
// a subarray of size 3. 6, 5, 1 is another subarray. Basically,
// if you have an array of size N, there are 2^N subarrays.
//
// So one brute force approach you can follow is this:
// Try every subarray and see if the given property holds.
// But, this is going to take a long time. Anytime you see an
// expoential complexity, you should look for a better solution.
//
// Let's look first to see why '3' is the answer to the above array.
//
// What they are asking is find a subarray that is longest AND any
// two pairs in the array is <= 1. Now, when can this happen?
// If all the elements of the array are the same, like 3, 3, 3 then
// it is definitely an answer. How can we find such subarrays? Well,
// you keep track of frequency of each element in a separate array.
//
// Now, how do we find those pairs which are at a difference of 1?
// We can compare adjacent frequencies. Let's see with an example.
//
// For the above array, the frequency arry will be:
//
// 0 -> 0
// 1 -> 1
// 2 -> 0
// 3 -> 2 (basically, we have two '3' in the array)
// 4 -> 1
// 5 -> 1
// 6 -> 1
//
// Makes sense?
//
// We can then go through each of the frequencies. Let's see
// what hapens when we see freq[1]. This is 1. That means, there
// is at least one subarray of length 1 which matches the criteria.
//
// We can then see freq[2]. This is 0. So, not much we can do other
// than continue.
//
// Now, let's see what happens when we hit freq[3]. This is 2. So,
// now we have a subarray of size 2 which has a difference of 0.
// Great! Now, we have better than what we had before. So, we update.
//
// Also, freq[4] (the next element) is 1. So, we can now make a size
// of 3 subarray (4, 3, 3) which satisfies the criteria. So, now the
// answer is 3. We continue. But, nothing else beats this answer. So,
// this is the final answer.

int solve(int arr[], int n) {
    // Initialize the frequency array to be 0. Why are we initializing
    // the array with `kMaxElements`?
    int freq[kMaxElements] = {0};
    // Set up the frequency array.
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    // Now, run the loop.
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (freq[i] + freq[i + 1] > ans) {
            ans = freq[i] + freq[i + 1];
        }
    }

    return ans;
}

void solve() {
    int N, arr[kMaxElements];
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int ans = solve(arr, N);
    std::cout << ans << std::endl;
}

int main() {
    solve();
}