#include<iostream>

using namespace std;

//to divide whole array based on provided new start and end point 
int partition(int *a, int s, int e){
    

    int i = s - 1; 
    int j = s;
    int pivotElement = a[e];
    for(;j<e;j++){
        if (a[j] <= pivotElement) {
            
            //to increment pointer for bringing it inside region 1
            i++;
            
            //to bring larger element from region 2 to region one if it is larger than pivot element
            swap(a[j], a[i]);
        }
    }

    //once whole array is sorted to bring pivot element to it's legit position
    swap(a[i+1], a[e]);

    //position of pivot element in next sort 
    return i+1;

}


//to sort to halves of array
void quickSort(int *a, int s, int e){
    if (s >= e) {
        return ;
    }

    int pivotElement = partition(a, s, e);

    quickSort(a, s, pivotElement-1);
    quickSort(a, pivotElement+1, e);
}



int main(void){
    int a[] = {10, 8, 6, 7, 2, 5, 11, 45, 02, 67, 22, 33, 82};
    cout<<"Array before sorting.."<<endl;
    for(auto el : a){
        cout<<el<<" ";
    }
    cout<<endl;

    int n = sizeof(a) / sizeof(int);
    quickSort(a, 0, n-1);
    
    cout<<"Array after sorting..."<<endl;
    for (auto el : a) {
        cout<<el<<" ";
    }
    cout<<endl;


    return 0;
}

