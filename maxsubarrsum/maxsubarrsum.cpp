// Author: Jonathan Parlett
// Program Name: maxsubarrsum.cpp
// Created: 2022-April-10
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

  ll n; cin >> n;

  vll N; N.resize(n+1);

  N[0] = 0;//first prefix

  ll tmp;
  for(int i=1; i < n+1; i++){
    cin >> tmp;
    N[i] = N[i-1] + tmp; 
  }

  ll Max=N[1]; //max
  ll Min=N[0]; //initially 0

  for(int i=1; i <(n+1); i++){
    if(N[i]-Min > Max) Max = N[i]-Min;
    if(N[i] < Min) Min = N[i];
  }

  cout << Max << endl;
}


/*

   Calculate all the prefixes, then starting from the right (or left doesn't matter)
   find the min of the other sums that you can remove.

*/
