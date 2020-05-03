/*
Count and Say
Amazon
The count-and-say sequence is the sequence of integers beginning as follows:

1, 11, 21, 1211, 111221, ...
1 is read off as one 1 or 11.
11 is read off as two 1s or 21.

21 is read off as one 2, then one 1 or 1211.

Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

Example:

if n = 2,
the sequence is 11.
*/
string Solution::countAndSay(int A) {
    string s="",r="1";
    char num;
    int cnt=0;
    int n=A;
    while(--n)
    {
        int i=0,j;
        int len=r.length();
        while(i<len)
        {
            num=r[i];
            cnt=1;
            j=i;
            i++;
            while(i<len && r[i]==num)
            {
                cnt++;
                i++;
            }
            s=s+to_string(cnt)+r.substr(j,1);
        }
        r=s;
        s="";
    }
    return r;
    
}
