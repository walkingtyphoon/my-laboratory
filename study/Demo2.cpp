//
// Created by walking typhoon on 2025/11/18.
//

#include <iostream>
#include <vector>

using namespace std;

vector<vector<bool> > generateBoolCombinations(int n) {
    vector<vector<bool> > res;
    int total = 1 << n;
    for (int i = 0; i < total; ++i) {
        vector<bool> combo;
        for (int j = 0; j < n; ++j) {
            combo.push_back((i & 1 << j) != 0);
        }
        res.push_back(combo);
    }
    return res;
}

template<typename Func1, typename Func2>
bool verifyEquivalence(Func1 f1, Func2 f2, int varCount) {
    auto combos = generateBoolCombinations(varCount);
    for (auto &vals: combos) {
        bool res1 = f1(vals[0], vals[1]);
        bool res2 = f2(vals[0], vals[1]);
        if (res1 != res2) {
            cout << "不等价，输入：";
            for (bool v: vals) cout << v << " ";
            cout << "\nf1=" << res1 << ", f2=" << res2 << "\n";
            return false;
        }
    }
    return true;
}

int main() {
    cout << 35 % 4;

    return 0;
}
