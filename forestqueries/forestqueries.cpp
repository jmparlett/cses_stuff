// Author: Jonathan Parlett
// Program Name: forestqueries.cpp
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

void printGrid(vector<vector<int>> grid, int n){
  for(int i=0; i < n; i++){
      // for(int j=0; j < n; j++){
        // cout << grid[i][j] << ' ';
      // }
      for(auto c : grid[i]) cout << c << ' ';
      cout << endl;
    }
}


int main(){

  int n, q; cin >> n >> q;

  n++; //need extra row col for zeros

  //need nxn vector
  vector<vector<int>> grid; grid.resize(n);
  vector<vector<int>> pGrid; pGrid.resize(n);

  for(auto &r : grid){
    r.resize(n);
    fill(all(r),0);
  }

  for(auto &r : pGrid){
    r.resize(n);
    fill(all(r),0);
  }
  // printGrid(grid, n);
  // printGrid(pGrid, n);

  char tmp;
  for(int i=1; i < n; i++){
      for(int j=1; j < n; j++){
       cin >> tmp;
       if(tmp == '*')
         grid[i][j]=1;
    }
  }

  // printGrid(grid, n);
  
   // build prefix grid
    for(int i=1; i < n; i++){
      for(int j=1; j < n; j++){
        pGrid[i][j] = pGrid[i-1][j] +
                        pGrid[i][j-1] -
                        pGrid[i-1][j-1] +
                        grid[i][j];
      }
    }

    // printGrid(pGrid, n);
    //now solve
    int r1, c1, r2, c2;
    for(int i=0; i < q; i++){
      cin >> r1 >> c1 >> r2 >> c2;

      int ans = pGrid[r2][c2] - pGrid[r1-1][c2] - pGrid[r2][c1-1] + pGrid[r1-1][c1-1];

      cout << ans << endl;

    }

}

/*

   Once you have the 2D prefix sum matrix, how do we calculate an arbitrary sum of squares
   of the orginal grid.

   given 2 points (r1,c1) ,(r2, c2) where (r1 < r2) and (c1 < c2) they necessairly describe
   a rectangle.

   The second point describes the bottom right corner of the rect.  So it is necessairly
   a part of the prefix sum at pGrid[r2][c2]

   So which parts of the prefix sum do we need to remove?

   The section of the grid from (0,0) to (r1-1,c2) and from (0,0) to (r2,c1-1)

   What would these be in the prefix grid? 

    (r1-1,c2) = pGrid[r1-1][c2]
    (r2,c1-1) = pGrid[r2][c1-1]

   And we cant forget the intersecting area of these 2 sums which we must add back

    pGrid[r1-1][c1-1]

   Which necessairly makes our target sum

   pGrid[r2][c2] - pGrid[r1-1][c2] - pGrid[r2][c1-1] + pGrid[r1-1][c1-1]

   Having the extra padding in the grid makes this easier
 
 */
