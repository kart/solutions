#include <iostream>
#include <cassert>

const int kMaxStudents = 100000;
const int kMaxRows = 100000;
const int kMaxCols = 500;

int solve() {
    int N, M, K, ans = 0;
    std::cin >> N >> M >> K;

    // Initialize all the rows to say that no seats are occupied.
    int rows[kMaxRows] = {0};

    for (int i = 0; i < N; i++) {
        int preferredRow;
        std::cin >> preferredRow;
        // Change from 1-based index to 0-based index.
        preferredRow--;
        assert(preferredRow < M && preferredRow >= 0);
        // Check if the preferred row is filled?
        if (rows[preferredRow] < K) {
            // Preferred row available. Occupy it.
            rows[preferredRow]++;
            // Nothing more to do, go to next student.
            continue;
        }
        // Preferred row is completely filled. Check if
        // any of the next rows are available. Remember that we
        // have to go back to row 0 if all are booked.
        // Start from the next row.
        //
        // NOTE: the % M trick is one that is used all the time.
        // It's used to iterate in a circular loop.
        // For example, consider 5 rows: 0, 1, 2, 3, 4
        // Let's say, you start at row 4, next row is 0. But,
        // how do you find that? (4 + 1) % 5 == 0 -- see?
        int start = (preferredRow + 1) % M;
        bool found = false;
        while (start != preferredRow) {
            if (rows[start] < K) {
                // row 'start' is available; use it.
                rows[start]++;
                found = true;
                break;
            }
            // Same modulus trick here :)
            start = (start + 1) % M;
        }
        if (!found) {
            ans++;
        }
    }
    return ans;
}

int main() {
    int ans = solve();
    std::cout << ans << std::endl;
}