// Author: Jonathan Parlett
// Program Name: ferriswheel.cpp
// Created: 2022-March-3
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
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
  int n, x; cin >> n >> x;

  vi c; c.resize(n);
  while(--n >= 0){
    cin >> c[n];
  }

  sort(c.begin(), c.end());
  // for( auto i : c ) cout << i << ' ';

  int l=0, r=c.size()-1, g=0;

  while(l < r){
    if(c[l] + c[r] <= x){
      l++;
      r--;
    } else {
      r--;
    }
    g++;
  }
  if(l == r) g++;
  cout << g << endl;
}

/*
 
   We want to minimize the num of gondolas. This is the same as maximizing the num of valid pairs
   those less than x. 

  1. Sort the children, and set left pointer = 0, and right pointer = n - 1
  2. check is A[l] + A[r] < x
      a. true then set g++, l++, r--
      b. false we must take A[r] in its own gondola set g++, r--
  3. continue from 2 until l >= r

  sorting is O(nlogn) loop is O(n) in worst case where we take every child in their own gondola

 */
