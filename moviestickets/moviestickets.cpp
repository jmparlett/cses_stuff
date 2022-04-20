// Author: Jonathan Parlett
// Program Name: moviestickets.cpp
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
  
  int n; cin >> n;

  vector<pair<int,int>> I; I.resize(n);

  for(int i=0; i < n; i++){
    cin >> I[i].f;
    cin >> I[i].s;
  }

  sort(all(I));

  int i,j; i = j = 0;
  int ans = 1;

  for(; i < n; i++){
     //check for overlap
    if(I[j].s > I[i].f){
      if(I[i].s < I[j].s)
        j=i;
    } else{
      ans++;
      j=i;
    }
  }

  cout << ans << endl;

}

/*

Goal: maximize the number of non pver lapping intervals

Consider A = [(a1,b1),(a2,b2),...,(an,bn)], where a_(i-1) < a_i

i = ptr to current pair, j = ptr to previous pair
ans = count of max pairs
  1. set i = j = 0; ans = 0;
  2. iter through list of sorted pairs
    if A[j] does not overlap A[i] then
      ans++; j=i; i++;
    else we must choose between the 2 pairs
      we will select the pair with the minium end of interval

      If the input was already sorted we could avoid reading the array entirely.
      In this case the size of the array is constrained enough that we can read
      it in however.
 */
