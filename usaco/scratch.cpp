#include <bits/stdc++.h>
// #include <stdlib.h>
// #include <iostream>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int



int main(){
  freopen("teleport.in","r",stdin);
  ll a,b,x,y; cin >> a >> b >> x >> y;
  FILE *f = fopen("teleport.out","w");
  fprintf(f,"%lld\n",min(abs(a-b),(abs(a-y)+abs(b-x))));
  fclose(f);

}