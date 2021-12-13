#include <iostream>
#include <algorithm>
#include <math.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

const int PATHLEN = 48; //This is one of those off by one errors to watch for. You know your done when you have made the final move, ie your past the last index,
                        //not when you are at the last index. There you still have a few moves to choose.
int path[48]; //global is faster
int grid[7][7];
int gridSize=7;


void printGrid(int grid[7][7], ull size){
  for(int i=0; i < size; i++){
    for(int j=0; j < size; j++){
      cout << grid[i][j];
    }
    cout << '\n';
  }
}

ull explore(int x,int y, int pidx){
  //we stop if we're at the end of the string
  if(x==0 && y==6){//we've reached the bottom left 
    if(pidx==PATHLEN)
      return 1;
    //else we got here early
    return 0;
  }

  if(pidx==PATHLEN)
    return 0;//we walked the whole path, but didn't get to our goal

  
  //get legal moves
  int m[4]; //U,D,L,R
  m[0]=m[1]=m[2]=m[3]=0;
  if(y > 0){
     if(grid[y-1][x]==0)m[0]=1;
   }
   if(y < 6){
     if(grid[y+1][x]==0)m[1]=1;
   }
   if(x > 0){
     if(grid[y][x-1]==0)m[2]=1;
   }
   if(x < 6){
     if(grid[y][x+1]==0)m[3]=1;
   }

  //if we can only go left or right or only up or down then we will end up running into ourselves at some point and never be able
  //to touch all tiles
  if(((m[0]&m[1])&(!(m[2]|m[3]))) | ((!(m[0]|m[1]))&(m[2]&m[3])))
      return 0;//we hit a wall

  ull pathCount=0;//path count
  //set current as explored
  grid[y][x]=1;

  if(path[pidx]<4){//check if required move is legal
    if(m[path[pidx]]){
      switch(path[pidx]){
        case 0://up
           pathCount += explore(x,y-1, pidx+1);
           break;
        case 1://down
           pathCount += explore(x,y+1, pidx+1);
           break;
        case 2://left
           pathCount += explore(x-1,y, pidx+1);
           break;
        default://right
           pathCount += explore(x+1,y, pidx+1);
           break;
      }
    }
  } else { //else we must make all moves
    if(m[0]){//up
       pathCount += explore(x,y-1, pidx+1);
    }

    if(m[1]){//down
       pathCount += explore(x,y+1, pidx+1);
    }
    if(m[2]){//left
       pathCount += explore(x-1,y, pidx+1);
    }
    if(m[3]){//right
       pathCount += explore(x+1,y, pidx+1);
    }
  }
  grid[y][x]=0;
  return pathCount;
}

int main(){
  
  string paths; cin >> paths;
  for(int i=0; i < 48; i++){
    if(paths[i]=='U') path[i]=0;
    else if(paths[i]=='D') path[i]=1;
    else if(paths[i]=='L') path[i]=2;
    else if(paths[i]=='R') path[i]=3;
    else path[i]=4;
  }

  //init grid
  for(int i=0; i < gridSize; i++){
    for(int j=0; j < gridSize; j++){
      grid[i][j]=0;
    }
  }

  
  
  ull ret=0;

  ret+= explore(0,0,0);

  cout << ret << '\n';
}
/*
 *1. in our current board state set start point = 1 grid[x][y]=1
 *2. then calculate the set of legal moves, this will be based on our position and what is already a 1 on the board
 *3. if current spot in string = ? then we must take every legal move, so call explore(x-1,y,string) etc.
 *  sum return values of recursive calls
 *4. if the position in the string is not ? then if it is not in the set of legal moves we have failed return 0
 *    if we cannot make any legal moves and we have not reached the end of the string we have failed return 0
 *
 * Board state must be copied between calls, it cannot be modified by multiple recursive calls.
 */















