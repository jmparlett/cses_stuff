// Author: Jonathan Parlett
// Program Name: subarraydivis.cpp
// Created: 2022-March-24
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
using vll = vector<ll>;
using vi = vector<int>;
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
  // setio("problemName");

  int n; cin >> n;

  ull ans = 0;

  ll tmp;

  ll psum = 0;

  vi mods; mods.resize(n);

  fill(all(mods),-1);

  mods[0]=1;
  
  for(int i=0; i < n; i++){
    cin >> tmp;
    psum +=  tmp;
    
    if(mods[(psum % n + n) % n] == -1){ //new entry
      mods[(psum % n + n) % n]=1;
    } else {
      ans += mods[(psum % n + n) % n];
      mods[(psum % n + n) % n]++;
    }
  }

  cout << ans << endl;
}


/*

   In this case your kinda just looking for sum collisions mod n

   M = array of mod n, it has an entry if we have seen that result

   1. Calculate the prefix sum mod n. If the result mod n is in our array
      increment our answer

      else store it in the array
   2. continue till we've look at all prefix sums.

*/
