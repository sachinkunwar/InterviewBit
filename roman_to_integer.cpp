/*
Roman to Integr
Given a string A representing a roman numeral.
Convert A into integer.

A is guaranteed to be within the range from 1 to 3999.

NOTE: Read more
details about roman numerals at Roman Numeric System



Input Format

The only argument given is string A.
Output Format

Return an integer which is the integer verison of roman numeral string.
For Example

Input 1:
    A = "XIV"
Output 1:
    14

Input 2:
    A = "XX"
Output 2:
    20
*/
void initmp(map<string,int> &mp)
{
    mp["I"]=1;
    mp["V"]=5;
    mp["X"]=10;
    mp["L"]=50;
    mp["C"]=100;
    mp["D"]=500;
    mp["M"]=1000;
}
int cnv(string s,map<string,int> &mp, int &n)
{
    
    int l=s.length();
    // cout<<s<<" "<<l<<" ";
    if(l>1)
    {
        string s1,s2;
        s1=s.substr(0,1);
        s2=s.substr(1,1);
        if(mp[s1]<mp[s2])
        {
            n+= mp[s2]-mp[s1];
            return 2;
        }
        else{
            n+= mp[s1];
            return 1;
        } 
    }
    else{
        n+= mp[s];
        return 1;
    } 
}
int Solution::romanToInt(string A) {
    map<string,int> mp;
    initmp(mp);

    int n=A.length();
    int i=0;
    int nm=0;
    while(i<n)
    {
        if(i<n-1)
        {
            i+=cnv(A.substr(i,2),mp,nm);
        }
        else i+=cnv(A.substr(i,1),mp,nm);
    }
    return nm;
}
