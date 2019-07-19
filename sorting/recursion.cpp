#include<iostream>
using namespace std; 

void incPrint(int n){
    if (n == 0){
        return ;
    }
    incPrint(n-1);
    cout<<n<<" "<<endl;
}

void decPrint(int n){
    if (n == 0) {
        return  ;
    }

    cout<<n<<endl;
    decPrint(n-1);
}

int main(void){

    int n;
    cout<<"Enter value foor n : ";
    cin>>n;
    incPrint(n);
    decPrint(n);
    return 0;
}