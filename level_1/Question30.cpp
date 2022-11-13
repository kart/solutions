#include <iostream>

void solve(int N) {
    // Outer loop runs for every row in the theater.
    for (int row = 1; row <= N; row++) {
        // Inner loop runs for every seat in THAT row.
        // Inner loop must only run for as much as the row number.
        // So, 1st row contains only one seat.
        // 2nd row contains 2 seats.
        // 3rd row contains 3 seats.
        // So on.
        int start = (row % 2 == 1 ? 1 : 2);
        for (int seat = 1; seat <= row; seat++, start += 2) {
            std::cout << " " << start;
        }
        std::cout << std::endl;
    }
}

void solve() {
    int N;
    std::cin >> N;
    solve(N);
}

int main() {
    solve();
}