// Author: Jonathan Parlett
// Program Name: subarrysum1.cpp
// Created: 2022-March-23
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
using vull = vector<ull>;
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
  int ans = 0;

  int n, x; cin >> n >> x;

  map<ull,int> mymap;

  ull sum=0, tmp;
  mymap[0]=1;
  for(int i = 0; i < n; i++){
    cin >> tmp;
    sum += tmp;
    if(mymap.count(sum-x)){
      ans++;
    }
    mymap[sum]=1;
  }


  cout << ans << endl;
}


/*

   S subarray is a contigious subset of indices, it is not a subsequence

   Given the prefix sums can we just solve S1 - S2 = x

   If everything is in a map this just means for a given sum

   check if S1 - x = S2 is in our map

   this may result in duplicates
*/
