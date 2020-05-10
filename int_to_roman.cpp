/*
Integer To Roman
Another question which belongs to the category of questions which are intentionally stated vaguely.
Expectation is that you will ask for correct clarification or you will state your assumptions before you start coding.

Given an integer A, convert it to a roman numeral, and return a string corresponding to its roman numeral version

 Note : This question has a lot of scope of clarification from the interviewer. Please take a moment to think of all the needed clarifications and see the expected response using “See Expected Output” For the purpose of this question, https://projecteuler.net/about=roman_numerals has very detailed explanations. 


Input Format

The only argument given is integer A.
Output Format

Return a string denoting roman numeral version of A.
Constraints

1 <= A <= 3999
For Example

Input 1:
    A = 5
Output 1:
    "V"

Input 2:
    A = 14
Output 2:
    "XIV"
*/

string intToRoman(int n)
{
    switch(n){
        case 1:
            return "I";
        case 5:
            return "V";
        case 10:
            return "X";
        case 50:
            return "L";
        case 100:
            return "C";
        case 500:
            return "D";
        case 1000:
            return "M";
        default:
            return "";
            
    }
}
string itor(int n)
{
    int t,i=1;
    string s="";
    while(n>0)
    {
        t=n%10;
        n/=10;
        if(t>0){
            if(i*t<(i*5-i))
            {
                while(t--)
                {
                    s=intToRoman(i)+s;
                }
            }
            else if(i*t==(i*5-i))
            {
                s=intToRoman(i*5)+s;
                s=intToRoman(i)+s;
            }
            else if(i*t==(i*5))
            {
                s=intToRoman(i*5)+s;
            }
            else if(i*t<(i*9))
            {
                while(t-->5)
                {
                    s=intToRoman(i)+s;
                }
                s=intToRoman(i*5)+s;
            }
            else if(i*t==(i*9))
            {
                s=intToRoman(i*10)+s;
                s=intToRoman(i)+s;
            }
        }
        i*=10;
    }
    return s;
}
string Solution::intToRoman(int A) {
    return itor(A);
}
