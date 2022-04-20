// Author: Jonathan Parlett
// Program Name: restaurantCustomers.cpp
// Created: 2022-March-22
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

typedef struct {
  int a;
  int b;
} person;

bool atime(person p1, person p2){
  return p1.a < p2.a;
}

bool ltime(person p1, person p2){
  return p1.b < p2.b;
}

int main(){

  int n; cin >> n;

  vector<person> A; A.resize(n);
  vector<person> L; L.resize(n);

  for(int i=0; i < n; i++){
    cin >> A[i].a;
    cin >> A[i].b;
    L[i] = A[i];
  }

  //sort A by arrival time
  sort(all(A), atime);
  //sort L by leaving time
  sort(all(L), ltime);

  int c, m; c = m = 0;
  int i,j; i = j = 0;
  for(; i < n; i++){
    while(A[i].a > L[j].b){
      c--;
      j++;
    }
    c++;
    m = max(c,m);
  }
  cout << m << endl;
}


/* NEW PLAN (totally gonna work)
 
  Have a person struct which stores the starting and leaving time.

  Have 2 arrays that hold the structs

  sort A by leaving time and L by arrival time

  set i = j = 0; i = A ptr, j = L ptr;

  maxC = 0 -> max customer count

  cur = 0 -> current customer count

  So in the first array we now have customers ordered by arrival
  and in the second we have them ordered by departure.

  We can view A[i].a as the "current time"

  if L[j].b < A[i].a then that customer has left
 
  So step through array A
    if A[i].a > L[j].b then
    maxC = max(maxC, cur)
    while(A[i].a > L[j].b) cur--;
    else cur++;

*/

/*
 *
 *
 * of all of that was a terrible idea

   If someone arrived before you left than the count increases.
    If someone arrived before they left then the count increases.

  Given (s,e) find all (sx,ex) s.t (sx >= s && se <= e)

  We want to find (s,e) s.t that the pairs that fall within (s,e)
  are maximized

  You basically have a bunch of intervals and you want to find the largest
  intersection of these intervals

  1-7
  1-6
  8-9
  
  here intersection would be 2

  What if sort by first element?

  Then we have pairs that may or may not be adjacent

  given 2 pairs (x1,y1) and (x2,y2) if x2 > y1 then there is no overlap
  further more nothing ahead of the second pair in the list can overlap
  with (x1,y1)

  else there is overlap, then is we must take min(y1,y2) to be the new end
  of our interval


 */
