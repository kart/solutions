#include <iostream>
#include <cmath>

// This is a bit tricky question. We need to attack in different fronts:
//
// First: n(n+1)/2 should trigger the sum of first N numbers.
// Basically, 1 + 2 + 3 + ... a = a(a+1)/2
//
// Second: the maximum input N can be 10^9 which is 1 billion.
//
// What are they asking?
// Find two numbers a and b such that a(a+1)/2 + b(b+1)/2 == N
//
// Now, let's find what is the largest 'a' possible? This is easy:
// a(a+1)/2 <= 10^9
//
// If you solve the above quadratic equation, you will get 'a' to
// be roughly 45000.
//
// Now, we can do this:
// For every number, 'a', between 1 to 45000, we can subtract a(a+1)/2
// from N. This will give us a new number and all we have to do now is
// see if that number is of the form b(b+1)/2. This can be done by
// solving a simple quadratic equation and see if the roots are integers.

const int MAX = int(1e9);

std::string solve(int N) {
    for (int i = 1; i <= std::min(45000, N); i++) {
        int num1 = (i * (i + 1)) / 2;
        long long diff = N - num1;
        // Now, all we need to do is find if `diff` is of the form b(b+1)/2
        // We can do this by finding the roots of the quadratic equation:
        // b^2 + b - 2N = 0 and see if it has integer roots.
        //
        // (-1 ± sqrt(1 + 8N)) / 2
        long long determinant = 1 + 8 * diff;
        double sqrtDeterminant = sqrt(double(determinant));
        // Now, we fist have to make sure the sqrt is an integer. There is
        // a common way to do this: floor(N) == N -- this tells us if
        // N is an integer.
        if (floor(sqrtDeterminant) != sqrtDeterminant) {
            // Not a perfect square.
            continue;
        }
        // Okay, so, sqrt is a perfect square. Now, let's see if the
        // numerator of the positive root is even.
        if ((int(sqrtDeterminant) - 1) % 2 == 0) {
            return "YES";
        }
    }
    return "NO";
}

void solve() {
    int N;
    std::cin >> N;
    std::cout << solve(N) << std::endl;    
}

int main() {
    solve();
}