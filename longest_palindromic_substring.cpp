/*
Longest palindromic substring
Given a string S, find the longest palindromic substring in S.

Substring of string S:

S[i...j] where 0 <= i <= j < len(S)

Palindrome string:

A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S.

Incase of conflict, return the substring which occurs first ( with the least starting index ).

Example :

Input : "aaaabaaa"
Output : "aaabaaa"
*/
string longest_palindromic_substring(char *t, int n, string str)
{
    // cout<<"HI"<<endl;
    int c=0,r=0,mirr;
    int p[n];
    for(int i=0;i<n;i++)p[i]=0;
    for(int i=1;i<n-1;i++)
    {
        mirr=2*c-i;
        if(i<r)
        {
            p[i]=min(r-i,p[mirr]);
        }
        while(t[i+(1+p[i])]==t[i-(1+p[i])])
        {
            p[i]++;
        }
        if(i+p[i]>r)
        {
            c=i;
            r=i+p[i];
        }
    }
    int index=0;
    int mx=0;
    for(int i=1;i<n-1;i++)
    {
        if(mx<p[i])
        {
            mx=p[i];
            index=(i/2)-1;
        }
    }
    // for(int i=0;i<n;i++)
    //     cout<<p[i]<<" ";
    // cout<<mx<<endl;
    // cout<<index<<endl;
    int l=mx%2==0?mx/2-1:mx/2;
    return str.substr(index-l,mx);
 
}
string Solution::longestPalindrome(string A) {
    int n=A.length();
    n=2*n+3;
    char t[n];
    int j=0;
    for(int i=1;i<n-1;i++)
    {
        if(i%2==0)
            t[i]=A[j++];
        else t[i]='#';
    }
    t[0]='@';
    t[n-1]='$';
    return longest_palindromic_substring(t,n,A);
}
