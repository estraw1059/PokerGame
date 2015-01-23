#include "toBinary.h"

string toBinary::reverse (string s)
 {

    string result="";

    for (int i=0; i<s.length( ) ; i++) 
    {
        result = s[ i ] + result ; //take the newest character and add it before what we have already
    }

    return result;
}

string convertToBinary(int x)
{
    string s;
    while (x != 0)
    {
        if (x%2 == 0)
        {
            s = s + "0";
        }
        else
        {
            s= s + "1";
        }
        x = x/2;
    }
    s = reverse(s);
    return s;
}   
