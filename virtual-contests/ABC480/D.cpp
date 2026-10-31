#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>

using namespace std; 

long long completed_cycles(long long i) {
    return (sqrtl(8.0L * i + 1) - 1) / 2;
}

int main () {
    int n, q; 
    cin >> n >> q; 

    vector<long long> arr(n); 
    for(int i=0; i<n; i++) cin >> arr[i]; 

    vector<long long> prefix; 

    long long sum = arr[0]; 
    prefix.push_back(sum); 

    for(int i=1; i<n; i++){
        sum += arr[i]; 
        prefix.push_back(sum); 
    }

    vector<long long> pref_of_prefix; 
    sum = prefix[0]; 
    pref_of_prefix.push_back(sum); 

    for(int i=1; i<(int)prefix.size(); i++){
        sum += prefix[i]; 
        pref_of_prefix.push_back(sum); 
    }

    // lambda function for quick answer 
    auto T = [&](long long i) -> long long {
        if (i == 0) return 0; 

        long long cycles = completed_cycles(i); 
        long long m = i - (cycles * (cycles + 1))/2; 

        long long result = 0; 

        if(cycles > 0) result += pref_of_prefix[cycles-1]; 
        if(m > 0) result += prefix[m-1]; 

        return result; 
    };

    while(q--){
        long long L, R; 
        cin >> L >> R;
        cout << T(R) - T(L-1) << endl; 
    }
    return 0; 
}

/*
int cycles = completed_cycles(L-1); 
long long TL_1 = pref_of_prefix[cycles-1] + prefix[L-2 - cycles * (cycles + 1)/2]; 

int cycles2 = completed_cycles(R); 
long long TR = pref_of_prefix[cycles2-1] + prefix[R-1 - cycles2 * (cycles2 + 1)/2]; 
*/