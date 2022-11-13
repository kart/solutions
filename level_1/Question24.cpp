#include <iostream>
#include <cmath>

// APPROACH 1
// Let's see if we can solve for [0, end].
// Note that we cannot just iterate from 0 to end one by one.
// That's because the input is quite large -- 1 billion (see the problem).
// So, we have to do something smart.
// We know 1 is a perfect square. So, let's start from there.
// What's the next perfect square? 4. The next? 9. Next? 16.
// So, if we adjust the for loop slightly, we can skip a lot of numbers
// that are not squares.
// That's what we do here: increment by 1, but set the condition to (i * i <= end).
int solve(int end) {
    int ans = 0;
    for (int i = 1; i * i <= end; i++) {
        ans++;
    }
    return ans;
}

int solveApproach1(int start, int end) {
    // Many mathematical solutions use this idea:
    // instead of doing start to end, we do [0, end] - [0, start] which
    // essentially gives the same answer.
    return solve(end) - solve(start);
}

// APPROACH 2
// Take an example:
// Let's say, we have a number like 24.
// How many perfect squares are there between 1 and 24 (inclusive)?
// We have 1, 4, 9, and 16 -- so, there are 4 perfect squares. Right?
// How else we can get 4 as the answer? Simple: sqrt(24) == 4.xxxx
// Now if you take a floor(4.xxxx), that will be 4.0 and if you make it
// an integer, you will get 4.
//
// Now, we can use this idea once for start and once for end.
// So, the answer is sqrt(end) - sqrt(start) and those many perfect
// squares exist between start and end (inclusive).
//
// What's the time complexity? 
// The time complexity is O(log(N)) where N is the input start or end.
// Why? Because sqrt takes log(N) time complexity.
int solveApproach2(int start, int end) {
    return (int)(floor(sqrt((double)end))) - (int)(floor(sqrt((double)start)));
}

void solve() {
    // Read input
    int N, start, end;
    std::cin >> N;
    for (int i = 0; i < N; i++) {
        int start, end;
        std::cin >> start >> end;
        int ans = solveApproach1(start, end);
        std::cout << ans << std::endl;
    }
}

int main() {
    solve();    
}