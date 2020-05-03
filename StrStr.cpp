/*
Implement StrStr
Implement strStr().

 strstr - locate a substring ( needle ) in a string ( haystack ). 
Try not to use standard library string functions for this question.

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 NOTE: Good clarification questions:
What should be the return value if the needle is empty?
What if both haystack and needle are empty?
For the purpose of this problem, assume that the return value should be -1 in both cases. 
*/
int Solution::strStr(const string t, const string p) {
    
    int p_n=p.length();
    int t_n=t.length();
    if(p_n==0 || t_n==0 || p_n>t_n)return -1;
    int p_a[p_n];
    int i=0,j=1,pos;
    p_a[0]=0;
    while(j<p_n)
    {
        if(p[i]==p[j])
        {
            p_a[j]=i+1;
            i++;
            j++;
        }
        else if(i>0)
        {
            i=p_a[i-1];
        }
        else{            
            p_a[j]=0;
            j++;
        }
    }
    // for(i=0;i<p_n;i++)cout<<p_a[i]<<" ";
    // cout<<endl;
    i=0;j=0;
    pos=-1;
    int tp=-1;
    int cnt=0;
    while(i<t_n)
    {
        if(t[i]==p[j])
        {
            if(tp==-1)tp=i;
            i++;
            j++;
            if(j==p_n)
            {
                pos=tp;
                break;
            }
        }
        else if(j>0)
        {
            j=p_a[j-1];
            tp=i-j;;
        }
        else{
            i++;
            tp=-1;
        }
    }
    return pos;
}
