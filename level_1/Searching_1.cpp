#include <iostream>

// This is a very simple question. All you have to do is read
// the input and find the height:width ratio and if it is between
// [1.6, 1.7], we increment the answer. That's it.

// One small catch -- the problem wasn't specific -- but looks like
// we need to check both ratios height:width and width:height.

// Here's a function that checks if a rectangle is a "silver"
// rectangle.
bool isSilverRectangle(double height, double width) {
    // First find height:width.
    double ratio1 = height/ width;

    // Now, find width::height
    double ratio2 = width / height;

    // Now check if either of the ratios is in the interval.
    return (ratio1 >= 1.6 && ratio1 <= 1.7) 
                || (ratio2 >= 1.6 || ratio2 <= 1.7);
}

void solve() {
    int N;
    std::cin >> N;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int height, width;
        std::cin >> height >> width;
        // Here, we are "type casting" integer to double. The way you
        // do it is: double(height) -- if you remember, we discussed this
        // sometime back (copy constructor?).
        if (isSilverRectangle(double(height), double(width))) {
            ans++;
        }
    }
    std::cout << ans << std::endl;
}

int main() {
    solve();
}