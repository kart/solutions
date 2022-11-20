#include <iostream>

const int kMaxElements = 10;

// The idea is simple: keep three variables: max1, max2 and max3.
//
// Initially assign all the variables to the first element in
// the array.
//
// After that, as we visit every element in the array, if we see
// an element greater than max1, what does it mean? It means, we
// found the largest so far. So, we should update max1. But, before
// we do that, we should update max2 to max1 and max3 to max2. This
// way we keep the ordering correct.
//
// However, if the current element is less than max1 but greater than
// max2, we should update max2. But, before that we should update max3.
//
// Finally, if the current element is greater than ONLY max3, we should
// just update max3.
//
// That's all. Now convert the above english to code :)
int solve(int arr[], int N) {
    int max1 = arr[0], max2 = arr[0], max3 = arr[0];
    for (int i = 1; i < N; i++) {
        if (arr[i] >= max1) {
            max3 = max2;
            max2 = max1;
            max1 = arr[i];
        } else if (arr[i] >= max2) {
            max3 = max2;
            max2 = arr[i];
        } else if (arr[i] >= max3) {
            max3 = arr[i];
        }
    }
    return max3;
}

void solve() {
    int N, arr[kMaxElements];
    std::cin >> N;

    // Read all the input elements.
    for (int i = 0; i < N; i++) {
        std::cin >> arr[i];
    }
    int ans = solve(arr, N);
    std::cout << ans << std::endl;
}

int main() {
    solve();
}