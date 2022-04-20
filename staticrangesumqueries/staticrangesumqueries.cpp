// Author: Jonathan Parlett
// Program Name: staticrangesumqueries.cpp
// Created: 2022-April-20
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
using vull = vector<ull>;
using vll = vector<ll>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define make_uniqe(x) sort(all(x)); x.resize(unique(all(x)) - x.begin());


void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}


int main(){

    int n, q; cin >> n >> q;

    vull psums; psums.resize(n+1);

    psums[0]=0;

    int tmp;
    for(int i=1; i < n+1; i++){
      cin >> tmp;

      psums[i] = psums[i-1] + tmp;
    }

    ull a,b;
    for(int i=0; i < q; i++){
      cin >> a >> b;

      cout << psums[b] - psums[a-1] << endl;
    }


}

/*

   This should be a simple prefix sum problem

 
 */
