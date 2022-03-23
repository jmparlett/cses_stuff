// Author: Jonathan Parlett
// Program Name: apartments.cpp
// Created: 2022-March-5
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
  
  int n,m,k; cin >> n >> m >> k;

  vi A; A.resize(n);
  vi R; R.resize(m);

  for(int i = 0; i < n; i++) cin >> A[i];
  for(int i = 0; i < m; i++) cin >> R[i];

  sort(A.begin(), A.end());
  sort(R.begin(), R.end());

  int i,j; i = j = 0;

  int ans = 0;

  while( i < n && j < m){

     if( abs(A[i] - R[j]) <= k){
       i++; j++; ans++;

     } else if(A[i] > R[j]){
        j++;  
     } else {//(A[i] < R[j])
        i++;
     }
  }

  cout << ans << endl;
}


/*

  This is a greedy problem

  A = arr of applicatants (desired size)

  k = max diff 

  R = arr of rooms (size)

  ans = count of apartments assigned

  constraints to assign a room abs(A[i] - R[j]) <= k

  1. sort A and R
  2. set i = j = 0, i = A ptr and j = R ptr
  3. check abs(A[i] - R[j]) <= k
    a. True. We assign this room to the applicant. Set ans++; i++; j++; then continue.
    b. False. Two cases (A[i] - R[j] < 0) or (A[i] - R[j] > 0) 



  If the check is false then either (A[i] - R[j] < 0) or (A[i] - R[j] > 0) 
 
  --case 1
  (A[i] - R[j] < 0) -> (A[i] < R[j]) also we know (A[i+1] >= A[i])
  In this case the check may be true for A[i+1] so we can set i++; and continue
  
  --case 2
 (A[i] - R[j] > 0) -> (A[i] > R[j])
 In this case the check may be true for R[j+1] so we can set j++; and continue
*/
