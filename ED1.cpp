#include<iostream>
using namespace std;

int main () {
    int n;
    cin>>n;
    int DigitCount = 0;
    while(n>0){
        n /= 10; // N = n divided by 10
        DigitCount++;
    }
    cout<<DigitCount<<endl;
    return 0;
}