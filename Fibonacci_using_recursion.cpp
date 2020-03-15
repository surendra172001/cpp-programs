#include<iostream>
using namespace std;

void fibonacci(int a,int b,int n){
    if(b>n){
        return;
    }
    else
    {
        int c=a+b;
        cout<<c<<endl;
        fibonacci(b,c,n);
    }
}

int main(){
    int n=15;
    cout<<"Enter the number uptil which you want to print fibonacci sequence\n";
    //cin>>n;
    fibonacci(0,1,n);
    return 0;
}

/*Without Recursion
include<iostream>
using namespace std;


int main()
{
    int n,count=3;
    cin>>n;
    unsigned long long int  a=0,b=1,c=0;
    while(count<=n){
        c=a+b;
        a=b;
        b=c;
        count++;
    }
    
    cout<<c<<endl;
    
    return 0;
}
 */