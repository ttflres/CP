#include <bits/stdc++.h>
using namespace std;

const string NAME = "A";     // problem name
const string TestType = "Themis";  // "CMS", "Themis"

const int NTEST = 14;           // number of tests

mt19937_64 rd;

int Rand(int lo,int hi){
    assert(lo <= hi);
    return rd() % (hi - lo + 1) + lo;
}

void makeTest(ofstream &input, int testId){
    int n, q;
	
    if (testId < 2)
        n = 80,
        q = Rand(1, n);
    else if (testId < 8)
        n = 100,
        q = Rand(1, n);
    else if (testId < 14)
        n = 200,
        q = Rand(1, n);

    input << n << ' '<<q<<"\n";
    cout << n << ' '<<q<<"\n";
    map<int, int> mp;
    for (int i=1; i<n; i++)
    {
    	int i1=Rand(1, n), i2=Rand(1, n), i3=Rand(1, n);
    	if (i1==i2) i2=Rand(1, n);
    	input<<i1<<' '<<i2<<' '<<i3<<"\n";
    	cout<<i1<<' '<<i2<<' '<<i3<<"\n";
	}
	for (int i=1; i<=q; i++)
	{
		int i1=Rand(1, n), i3=Rand(1, n);
		input<<i1<<' '<<i3<<"\n";
		cout<<i1<<' '<<i3<<"\n";
	}
}

int main(){
    unsigned randomSeed = chrono::system_clock::now().time_since_epoch().count();

    rd.seed(randomSeed);
    for(int _ = 0; _ < NTEST; _++){
        string id;          // id of current test
        stringstream ss;
        ss << _;
        ss >> id;
       // cerr << _ << ' '  << endl;
        cout << "Making test: " << id << endl;
        string input, output, program = NAME;

        if (TestType == "CMS")
            input  = NAME + id + ".in",
            output = NAME + id + ".out";
        else
            system(("MKDIR " + NAME + "\\Test" + id).c_str()),
            input  = NAME+"\\Test" + id + '\\' + NAME + ".INP",
            output = NAME+"\\Test" + id + '\\' + NAME + ".OUT";
       

        ofstream inputFile(input.c_str());
        
        // create input
        makeTest(inputFile, _);
        inputFile.close();

        // create output
        system((program + ".exe < " + input + " > " + output).c_str());
    }
}
