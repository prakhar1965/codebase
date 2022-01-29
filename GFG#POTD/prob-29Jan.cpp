// https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        string reverseString;
        int len = S.size(), lenWord = 0;
        for(int i=0; i<len;i++) {
            if(S[i] == '.') {
                
               
                reverseString.insert(0,S,i-lenWord,lenWord);
                reverseString.insert(0,".");
                lenWord = 0;
            }
            else
             lenWord++;
            if(i == len-1) {
                reverseString.insert(0,S,len - lenWord,lenWord);
            }
        }
        return reverseString;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends