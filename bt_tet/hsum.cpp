#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef string bignum_str;
void equal_length(bignum_str &a, bignum_str &b)
{
    while (a.size() < b.size())
        a = '0' + a;
    while (b.size() < a.size())
        b = '0' + b;
}
bignum_str add(bignum_str a, bignum_str b)
{
    equal_length(a, b);
    
    int carry = 0;
    bignum_str res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        int d = (a[i] - '0') + (b[i] - '0') + carry;
        carry = d / 10; 
        res = (char)(d % 10 + '0') + res; 
    }
    if (carry)
        res = '1' + res;
        
    return res;
}
bignum_str diff(bignum_str a, bignum_str b)
{
    equal_length(a, b);
    
    int d = 0, carry  = 0;
    bignum_str res;
    for (int i = a.size() - 1; i >= 0; --i)
    {
        d = (a[i] - '0') - (a[i] - '0') - carry;
        if (d < 0)
        {
            d += 10;
            carry = 1;
        }
        else 
            carry = 0;
        res = (char) (d + '0') + res;
    }
    while (res.size() > 1 && res.front() == '0')
        res.erase(res.begin());
        
    return res;
}
int main() {
    string x;
    vector <string> v;
    string sum="";
    while (cin >> x)
    {
        v.push_back(x);
    }
    for (int i=0; i<v.size()-2; i+=2)
    {
        sum+=add(v[i], v[i+1]);
    }
    cout<<sum;
    
}

