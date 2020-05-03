/*
Reverse the String
Given a string A.

Return the string A after reversing the string word by word.

NOTE:

A sequence of non-space characters constitutes a word.

Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.

If there are multiple spaces between words, reduce them to a single space in the reversed string.



Input Format

The only argument given is string A.
Output Format

Return the string A after reversing the string word by word.
For Example

Input 1:
    A = "the sky is blue"
Output 1:
    "blue is sky the"

Input 2:
    A = "this is ib"
Output 2:
    "ib is this"
*/
string Solution::solve(string A) {
    string s="";
    int n=A.length();
    int i=0,j=0;
    // int flag=0;
    for(;j<n;){
        while(j<n && A[j]==' ')j++;
        i=j;
        while(j<n && A[j]!=' ')j++;
        if(j!=n)s=A.substr(i,j-i)+" "+s;
        // j--;
        
        // if(j==n)flag=1;
    }
    if(A[j]!=' '){
        s=A.substr(i,j-i+1)+" "+s;
    }
    n=s.length();
    if(s[0]==' ')
        s=s.substr(1,n-1);
    n=s.length();
    if(s[n-1]==' ')
        s=s.substr(0,n-1);
    return s;
}

