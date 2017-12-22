#include<bits/stdc++.h>
#define lli long long int
#define MOD 1000000007

using namespace std;

void mul(lli A[2][2], lli B[2][2]);
void pow(lli A[2][2], lli n);

lli moduFibo(lli n)
{
    lli A[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    pow(A, n-1);
    return A[0][0];
}

void pow(lli A[2][2], lli n)
{
    if(n == 1 || n == 0)
        return;
    lli B[2][2] = {{1,1},{1,0}};
    pow(A, n/2);
    mul(A, A);
    if(n%2 != 0)
        mul(A, B);
}

void mul(lli A[2][2], lli B[2][2])
{
  lli w =  (((A[0][0]%MOD)*(B[0][0]%MOD))%MOD + ((A[0][1]%MOD)*(B[1][0]%MOD))%MOD)%MOD;
  lli x =  (((A[0][0]%MOD)*(B[0][1]%MOD))%MOD + ((A[0][1]%MOD)*(B[1][1]%MOD))%MOD)%MOD;
  lli y =  (((A[1][0]%MOD)*(B[0][0]%MOD))%MOD + ((A[1][1]%MOD)*(B[1][0]%MOD))%MOD)%MOD;
  lli z =  (((A[1][0]%MOD)*(B[0][1]%MOD))%MOD + ((A[1][1]%MOD)*(B[1][1]%MOD))%MOD)%MOD;

  A[0][0] = w;
  A[0][1] = x;
  A[1][0] = y;
  A[1][1] = z;
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      lli n;
      cin>>n;
      cout<<moduFibo(n+2)<<endl;
  }
  return 0;
}
