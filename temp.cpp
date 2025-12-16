#include <iostream>
#include <vector>
using namespace std;

void deletefromHeap()
    {   
        int arr[100];
        int size = 0;
        if(size==0)
        {
            cout<<"No element present"<<endl;
            return ;
        }
        
        arr[1] = arr[size];

        size = size - 1;
        int i = 1;
        int leftIndex,rightIndex;
        while(i<size) {
            leftIndex = 2 * i;
            rightIndex = 2*i + 1;
            if(leftIndex <= size && rightIndex <= size && (arr[leftIndex]>arr[i] || arr[rightIndex]>arr[i])) {
                if(arr[leftIndex]>arr[rightIndex]) {
                    swap(arr[leftIndex],arr[i]);
                    i = leftIndex;
                } 
                else {
                    swap(arr[rightIndex],arr[i]);
                    i = rightIndex;
                }
            }
            else return;
        }
    }