#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while(left < right) {
            while (!isalnum(s[left]) && left < right) {
                left += 1;
            }

            while(!isalnum(s[right]) && left < right) {
                right -= 1;
            }

            // if (left >= right) {
            //     break;
            // }

            if (tolower(s[left]) != tolower(s[right])){
                cout << s[left] << " " << s[right] << endl;
                return false;
            }
            left += 1;
            right -= 1;
        }

        return true;

    }
};
