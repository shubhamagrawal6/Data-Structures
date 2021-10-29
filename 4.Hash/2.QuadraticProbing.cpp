#include <bits/stdc++.h>
using namespace std;

vector<int> QuadraticProbing(int hashSize, int arr[], int N){
    int n = hashSize;
    vector<int> v(hashSize, -1);
    for(int i=0; i<N; i++){
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
            else{
                l = (arr[i] + (j*j))%hashSize;
            }
        }
    }
    return v;
}

int main(){
	int arr[] = {21, 10, 32, 43, 53};
    int hashSize = 11;

    vector<int> hash = QuadraticProbing(hashSize, arr, 5);
    for(int i: hash){
        cout<<i<<" ";
    }
    cout<<endl;
	
    return 0;
}