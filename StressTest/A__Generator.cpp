#include <bits/stdc++.h>
using namespace std;
const string NAME = "A";
const int NTEST = 100;

mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
#define rand rd


long long Rand(long long l, long long h) {
    assert(l <= h);
    return l + rd() * 1LL * rd() % (h - l + 1);
}

int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp((NAME + ".inp").c_str());
        int n=Rand(1, 10);
        inp << n;
       	cout<<n<<endl;
        for (int i=1; i<=n; i++)
        {
        	int t=Rand(1, 100);
        	inp << t <<" ";
        	cout<< t << " ";
		}
		cout<<endl;
        inp.close();

        system((NAME + ".exe").c_str());
        system((NAME + "_ans.exe").c_str());
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}
