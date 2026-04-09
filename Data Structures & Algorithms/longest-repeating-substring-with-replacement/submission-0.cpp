class Solution {
public:
    int characterReplacement(std::string s, int k) {
        unordered_map<char, int> count;
        int res = 0;
        int slen = s.length();
        int l = 0, maxf = 0;
        for (int r = 0; r < slen; r++) {
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            if ((r - l + 1) - maxf > k) {
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }

        return res;
    }
};
/*For those who are struggling to understand the optimisation with maxf, here is how i understood it: 

For a substring to be valid, we need window_length - maxf <= k. Here, maxf is the frequency of the most common character in the current window. The difference window_length - maxf tells us how many characters we'd need to change to make the whole window the same character.

The biggest valid substring we can get is of size maxf + k. So, the larger maxf is, the better. If maxf doesn't change or goes down, our potential best answer doesn't change. We don't need to update maxf in this case.

On the other hand, if maxf goes up, it means we've found a character in the current window that appears more often than in previous windows. This means we might be able to get a longer valid substring, so we update maxf.

Hope this helps! And thank you neetcode for the wonderful video as always.*/
