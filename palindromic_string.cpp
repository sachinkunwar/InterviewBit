/*
Palindromic String
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example:

"A man, a plan, a canal: Panama" is a palindrome.

"race a car" is not a palindrome.

Return 0 / 1 ( 0 for false, 1 for true ) for this problem
*/
inline int alfanum(char c)
{
    if((c>='0' && c<='9') || (c>='A' && c<='Z') || (c>='a' && c<='z'))
        return 1;
    return 0;
}
inline char lowerc(char c)
{
    if(c>='A' && c<='Z')
        return c+32;
    if(c>='a' && c<='z')
        return c;
    if(c>='0' && c<='9')
        return c;
}
int Solution::isPalindrome(string A) {
    int i,j;
    i=0;
    j=A.length()-1;
    while(i<j)
    {
        if(alfanum(A[i]))
        {
            if(alfanum(A[j]))
            {
                // cout<<lowerc(A[i])<<" "<<lowerc(A[j])<<endl;
                if(lowerc(A[i])!=lowerc(A[j]))return 0;
                i++;
                j--;
            }
            else j--;
        }
        else i++;
    }
   
    return 1;
}
