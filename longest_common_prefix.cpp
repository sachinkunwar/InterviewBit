/*
Longest Common Prefix
Given the array of strings A,
you need to find the longest string S which is the prefix of ALL the strings in the array.

Longest common prefix for a pair of strings S1 and S2 is the longest string S which is the prefix of both S1
and S2.

For Example, longest common prefix of "abcdefgh" and "abcefgh" is "abc".



Input Format

The only argument given is an array of strings A.
Output Format

Return longest common prefix of all strings in A.
For Example

Input 1:
    A = ["abcdefgh", "aefghijk", "abcefgh"]
Output 1:
    "a"
    Explanation 1:
        Longest common prefix of all the strings is "a".

Input 2:
    A = ["abab", "ab", "abcd"];
Output 2:
    "ab"
    Explanation 2:
        Longest common prefix of all the strings is "ab".
*/
string Solution::longestCommonPrefix(vector<string> &A) {
    if(A.size()==0)return "";
    if(A.size()==1)return A[0];
    int k=0,n=A[0].length();
    string s="";
    for(int i=1;i<A.size();i++)
    {
        if(n<A[i].length());
        {
            n=A[i].length();
            k=i;
        }
    }
    for(int j=0;j<n;j++)
    {
        int flag=1;
        for(int i=0;i<A.size();i++)
        {
            if(A[k][j]!=A[i][j])
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            s+=A[k].substr(j,1);
        }
        else break;
    }
    return s;
}
