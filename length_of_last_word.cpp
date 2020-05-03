/*
Length of the last word
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

Example:

Given s = "Hello World",

return 5 as length("World") = 5.
*/
int Solution::lengthOfLastWord(const string A) {
    int len=0,flag=0;
    int i=A.length()-1;
    while(A[i]==' ')i--;
    while(i>=0 && A[i]!=' ')
    {
        if(flag==1 && A[i]==' ')break;
        if(A[i]!=' ')
        {
            len++;
            flag=1;
        }
        // cout<<A[i];
        i--;
    }
    // cout<<endl;
    return len;
}
