#include <iostream>

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            if (x > 0 && result > (2147483647 - x % 10)/10)
                return 0;
            if (x < 0 && result < (-2147483648 - x %10)/10)
                return 0;
            result = result * 10 + x % 10;
            x /= 10;
        }
        return result;
    }
};

// int main() {
//     auto s = Solution();
//     std::cout << s.reverse(1534236469);
// }