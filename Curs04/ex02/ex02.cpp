#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> v1 = { 1, 2, 3, 5, 6, 7, 11, 22 , 33};

    int s = 0;
    std::for_each(v1.begin() + 2, v1.end() - 1, [&s](int x) {s += x; });
    std::cout << s << std::endl;
}