#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

double comb(int n, int k) {
    if (k < 0 || k > n) return 0.0;
    if (k == 0 || k == n) return 1.0;

    k = min(k, n - k);
    double result = 1.0;

    for (int i = 1; i <= k; ++i) {
        result *= (n - k + i);
        result /= i;
    }
    return result;
}

int main() {
    const int total_units = 1500;
    const int sample_size = 150;
    vector<int> hypotheses = {1, 2, 3, 4, 5};

    double denominator = comb(total_units, sample_size);

    cout << fixed;
    cout.precision(4);

    for (int defective : hypotheses) {
        int good_units = total_units - defective;
        double numerator = defective * comb(good_units, sample_size - 1);
        double probability = numerator / denominator;

        cout << "P(A|H_" << defective << ") = " << probability << endl;
    }

    return 0;
}
