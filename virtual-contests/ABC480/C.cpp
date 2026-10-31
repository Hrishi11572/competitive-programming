#include<iostream>
#include<algorithm>
#include<vector>

using namespace std; 
using ll = long long; 
#define f first
#define s second 

ll ceil(ll a, ll b) {
    return (a  + b - 1)/b; 
}

int main() {
    int n; 
    cin >> n; 

    ll K, T; 
    cin >> K >> T; 

    vector<ll> A(n); 
    for(int i=0; i<n; i++){
        cin >> A[i]; 
    }

    sort(A.begin(), A.end());

    ll cnt = 0; 
    ll pos = 0; 

    for(int i=0; i<n; i++) {
        if(A[i] >= T) break; 
        if(pos < A[i]) {
            cnt += ceil(A[i] - pos, K); 
        }

        pos = A[i] + K; 
    }

    if(pos < T) {
        cnt += ceil(T - pos, K); 
    }

    cout << cnt << endl; 
}

// the code below did not work and i have to find out why it was erroneous 

// int main () {
//     int n; 
//     ll K, T; 
//     cin >> n >> K >> T; 

//     vector<ll>arr(n); 
//     for(int i=0; i<n; i++){
//         cin >> arr[i]; 
//     }

//     ll current = 0; 
//     ll count = 0; 

//     while(current < T){
//         int id = upper_bound(arr.begin(), arr.end(), current)-arr.begin() - 1;

//         if(current >= T) break;

//         // cout << current << " "; 

//         if(id >= 0 && current < arr[id] + K){
//             current = arr[id] + K; 
//           //  cout << "Aoki presses at : " << arr[id] << endl; 
//         }else{
//         //    cout << "Takahashi presses at : " << current << endl; 
//             count++; 
//             current += K; 
//         }
//     }

//     cout << count << endl; 
//     return 0; 
// }