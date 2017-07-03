#include <bits/stdc++.h>
using namespace std;
int gcd(int m, int n)
{
    if(m>n) swap(m,n); //m must be smaller of equal to n
    while(n%m != 0)
    {
        int temp = n%m;
        n = m; //the new value of n is m
        m = temp; // the new value of m is modulas of n%m
    }
    return m;
}
int main()
{
    cout<<gcd(36,48)<<endl;
    cout<<gcd(434,966)<<endl;;
    return 0;
}
