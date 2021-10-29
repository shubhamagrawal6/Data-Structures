#include <bits/stdc++.h>
using namespace std;

vector<int> linearProbing(int hashSize, int arr[], int sizeOfArray){
    int n = hashSize;
    vector<int> v(hashSize, -1);
    for(int i=0; i<sizeOfArray; i++){
        if(n==0){
            break;
        }
        int l = arr[i]%hashSize;
        for(int j=1; j<hashSize+1; j++){
            if(v[l] == -1){
                v[l] = arr[i];
                n--;
                break;
            }
            else if(v[l] == arr[i]){
                break;
            }
            else{
                l = (arr[i]+j)%hashSize;
            }
        }
    }
    return v;
}


int main() {
	int arr[] = {4, 14, 24, 44, 5};
    int hashSize = 10;
    
    vector<int> hash = linearProbing(10, arr, 5);
    for(int i: hash){
        cout<<i<<" ";
    }
    cout<<endl;
    
	return 0;
}