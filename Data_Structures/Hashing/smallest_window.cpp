#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

string find_window(string s, string pat)
{
    int SL = s.length();
    int PL = pat.length();

    // Corner case
    if (PL > SL)
    {
        return "NONE";
    }
    // 2. Freq Maps
    int FS[256] = {0};
    int FP[256] = {0};

    for (int i = 0; i < PL; i++)
    {
        char ch = pat[i];
        FP[ch]++;
    }

    // 3. Sliding window(expansion and contraction +Update the min Length Window )
    int cnt = 0;
    int start = 0;         // left pointer for shrinking the window
    int min_len = INT_MAX; // int max is the maximum value of the variable type int
    int start_idx = -1;
    for (int i = 0; i < SL; i++)
    {
        char ch = s[i];
        FS[ch]++;

        if (FP[ch] != 0 and FS[ch] <= FP[ch])
        {
            cnt++;
        }
        // if all the characters match
        if (cnt == PL)
        {
            char temp = s[start];
            // start shrinking the window
            while (FP[temp] == 0 or FS[temp] > FP[temp])
            {
                FS[temp]--;
                start++;
                temp = s[start];
            }
            // window size
            int window_len = i - start + 1; // 'i' will traverse to the string length and start will be at the window starting till where we could shrink
            if (window_len < min_len)
            {
                min_len = window_len;
                start_idx = start;
            }
        }
    }
    if (start_idx == -1)
    {
        return "NONE";
    }
    string ans = s.substr(start_idx, min_len); // function which takes two parameters - 1. start point form where we need to print the string .... 2. length till that point we have to print
    return ans;
}

int main()
{
    string s = "heello";
    string p = "elo";

    cout << find_window(s, p);
    return 0;
}