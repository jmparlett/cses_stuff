#include <iostream>
#include <algorithm>
#include <math.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int


int main(){
  ull q; cin >> q;
  while(q--){
    ull k; cin >> k;
    // cout << "k:" << k << "\n";
    
    ull base=0, n=1, inc=0;
    while(base+(inc=n*9*pow(10,n-1)) < k){
      base+=inc;
      n++;
    } //subbing base from k allows us to treat k as index only into its relevant dig space
    k-=(base+1);

    //k floor divided by n should give us the n multiple that denotes the start of the num containing k
    ull j = (ull)pow(10,n-1)+(k/n);//convert to ull explicitly instead of implicitly. Not sure why this makes a difference :(

    //due to integer division this is not actually just k and instead should be the start index of the target num
    ull i = n*(k/n);
  
    // printf("i: %llu\nj: %llu\nk: %llu\n",i,j,k);
    cout << to_string(j)[k-i] << '\n';

  }
}

/*
  infinite series of digits of form 123456789101112 what is the kth digit

  How does this sequence build?

  1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,171,8,19,20,21,22,23,24,25

  if n<10 than the solution is trivial
  
  if n<100 than if index is even we reference the 10s place

  which ten is it?

  How many 1 digits nums: 9
  How many 2 digits nums: 90
  How many 3 digits nums: 900 
  How many 4 digits nums: 9000
  How many 5 digits nums: 90,000
  How many 6 digits nums: 900,000
  How many n digits nums: 9*10^(n-1)

  If we can calculate the sum of the digits in each "group" we can figure out which group to start looking in.
  
  In other words we need to bound k above and below.

  1. read in k
  2. calculate the number of n digit numbers
  3. while the sum of total digits < k repeat step 2 adding to total num of digits each time
  4. start with the lowest n digit number t=10^(n-1) and set i=lower bound
  5. i+=n; t++; until i > k; Then we only have a search space of 2 numbers
  6. gen string of 2 nums; set i-=n; iter until i=k return nums[i]
  


 */
