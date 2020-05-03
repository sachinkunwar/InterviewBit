/*
Valid IP address
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address must be in the form of A.B.C.D, where A,B,C and D are numbers from 0-255. The numbers cannot be 0 prefixed unless they are 0.

Example:

Given “25525511135”,

return [“255.255.11.135”, “255.255.111.35”]. (Make sure the returned strings are sorted in order)
*/
int valid(string ip)
{
    vector<string> v;
    int n;
    string parsed;
    stringstream input_stringstream(ip);
    while(getline(input_stringstream,parsed,'.'))
    {
         v.push_back(parsed);
    }
    for(int i=0;i<v.size();i++)
    {
        int n=stoi(v[i]);
        if(n<0 || n>255 || (v[i].length()>1 && v[i][0]=='0') || v[i].length()==0)
        {
            return 0;
        }
    }
    return 1;
    
}
vector<string> Solution::restoreIpAddresses(string A) {
    int len=A.length();
    int n=len;
    vector<string> v;
    string ip="";
    if(len>=4 && len<=12)
    {
        for(int i=1;i<n && i<4;i++)
        {
            for(int j=i+1;j<n && j<i+4;j++)
            {
                for(int k=j+1;k<n && k<j+4;k++)
                {
                   ip+=A.substr(0,i)+"."
                        +A.substr(i,j-i)+"."
                        +A.substr(j,k-j)+"."
                        +A.substr(k,len-k);
                    if(valid(ip)){
                        v.push_back(ip);
                    }
                    ip="";
                }
            }
        }
        return v;
    }
    else return v;
}
