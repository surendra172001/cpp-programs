//Findingprime numbers -> Fastest method 
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void sieveEratosthenes(int n){
    int prime_count=0;
    bool prime[n+1];
    int i=0;
    //setting each value to true 
    memset(prime,true,sizeof(prime));
    int p;
    
    //setting the non-primes to false
    for(p=2;p*p<=n;p++){
        if(prime[p]==true){
            for(i=p*p;i<=n;i+=p){
                prime[i]=false;
            }
        }
    }

    for(i=2;i<n;i++){
        if(prime[i]){
            prime_count++;
            cout<<i<<"\t";
        }
    }

    cout<<endl;

    cout<<"The number of prime numbers less than or equal to "<<n<<" are\n"<<prime_count<<endl;

}

int main(){
    sieveEratosthenes(15);
    return 0;
}