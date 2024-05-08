#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn = 1e5 + 7;
int f(int n){ 
  int ans = 0; 
  if(n < 10){ 
    return n; 
  } 
  else{ 
    int d = 1, nt = n, b = 1; 
    while(nt > 9){ 
      ans += (9 * b * d); 
      b *= 10; 
      nt /= 10; 
      ++d; 
    } 
    ans += d * (n + 1 - b); 
  } 
  return ans; 
} 
int tim(int n)
{
  int b = 9, d = 1;
        while (n - b * d > 0)
        {
            n -= b * d;
            b *= 10;
            d += 1;
        }
        int num = pow(10, d - 1) + (n - 1) / d;
        return to_string(num)[(n - 1) % d] - '0';
}
int ba(int n)
{
  int d=1, b=9;
	while (n-d*b>=0)
	{
		n-=d*b;
		d++;
		b*=10;
	}
  if (n%d!=0) return -1;
  else
	return pow(10,d-1)+n/d-1;
}
 
signed main(){ 
  int n; 
  cin >> n; 
  cout << f(n); 
  cout<<endl;
  cout<<tim(n);
  cout<<endl;
  cout<< ba(n);
} 

