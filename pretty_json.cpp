/*
Given a string A representating json object. Return an array of string denoting json object with proper indentaion.

Rules for proper indentaion:

Every inner brace should increase one indentation to the following lines.
Every close brace should decrease one indentation to the same line and the following lines.
The indents can be increased with an additional ‘\t’
Note:

[] and {} are only acceptable braces in this case.

Assume for this problem that space characters can be done away with.



Input Format

The only argument given is the integer array A.
Output Format

Return a list of strings, where each entry corresponds to a single line. The strings should not have "\n" character in them.
For Example

Input 1:
    A = "{A:"B",C:{D:"E",F:{G:"H",I:"J"}}}"
Output 1:
    { 
        A:"B",
        C: 
        { 
            D:"E",
            F: 
            { 
                G:"H",
                I:"J"
            } 
        } 
    }

Input 2:
    A = ["foo", {"bar":["baz",null,1.0,2]}]
Output 2:
   [
        "foo", 
        {
            "bar":
            [
                "baz", 
                null, 
                1.0, 
                2
            ]
        }
    ]
    */

vector<string> Solution::prettyJSON(string A) {
    int n=A.length();
    int i=0,j=0;
    string s="";
    string tb="";
    vector<string> v;
    while(i<n)
    {
        if(A[i]=='{'||A[i]=='['||A[i]==']'||A[i]=='}')
        {
            if(j<i)
            {
                s=tb+A.substr(j,i-j);
                v.push_back(s);
                s="";
            }
            if(A[i]=='{'||A[i]=='[')
            {
                s=tb+A.substr(i,1);
                v.push_back(s);
                s="";
                j=i+1;
                tb+="\t";
            }
            else if(A[i]==']'||A[i]=='}')
            {
                tb=tb.substr(0,tb.length()-1);
                s=tb+A.substr(i,1);
                if(i<n-1 && A[i+1]==',')
                {
                    s+=A.substr(i+1,1);
                    i+=1;
                }
                v.push_back(s);
                s="";
                j=i+1;
            }
        }
        else if(A[i]==',')
        {
            s=tb+A.substr(j,(i-j+1));
            v.push_back(s);
            j=i+1;
        }
        // else if(i<n-1 && A[i]==':' && (A[i+1]=='{' || A[i+1]=='['))
        // {
        //     s=A.substr(j,i-j+1);
        //     v.push_back(s);
        //     j=i+1;
        // }
        // else if(i<n-1 && (A[i+1]=='}' || A[i+1]==']'))
        // {
        //     s=A.substr(j,i-j+1);
        //     v.push_back(s);
        //     j=i+1;
        // }
        i++;
    }
    return v;
}
