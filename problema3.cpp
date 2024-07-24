#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>
#include <numeric>
#include <time.h>
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define pi acos(-1.0)
#define E 2.71828182845904523536
#define long long LL
using namespace std;
 
 
bool matchAll(string Output, vector<string> Frags)
{
    int nMatched =0;
    for (int i=0; i<Frags.size(); i++)
        for (int j=0; j<Frags.size(); j++)
         
            if ( i != j && (Frags[i] + Frags[j] == Output || Frags[j] + Frags[i] == Output))  nMatched++, Frags[i] = "*", Frags[j] = "*";
    if (nMatched == Frags.size()/2) return true;
    return false;
}

int main()
{
    int N;
    char Input[10000];
 
    gets(Input);
 
    N = atoi(Input);
    for (int i=0; i<N; i++)
    {
        scanf("\n");
        int counter=0;
         
        int nFragments=0, nBits=0, OSize;
        vector<string> Frags;
        while(fgets(Input,10000,stdin))
        {
            string T;
            if (Input[0] == '\n') break;
            stringstream s(Input);
            s >> T;
            Frags.push_back(T);
            nFragments++;
            nBits += (int)T.length();
        }
         
        if (i == N-1) nBits++;
        OSize = (2*nBits)/nFragments;
 
        string FinalOutput;
        for (int i=0; i<Frags.size(); i++)
            for (int j=0; j<Frags.size(); j++)
            {
                string Output;
                if (i != j && (int)Frags[i].length() + (int)Frags[j].length() == OSize)
                {
                    Output = Frags[i] + Frags[j];
                    if (matchAll(Output, Frags))
                        {
                            FinalOutput = Output;
                            break;
                        }
                }
            }
     
            cout << FinalOutput << endl;
 
            if (i != N-1) cout << endl;    
    }
    return 0;
}