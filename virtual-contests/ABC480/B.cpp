#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 


bool check(string v, string s){
    if(v.length() != s.length()) return false; 
    
    int diff = 0;
    for(int i=0; i<v.length(); i++){
        if(v[i] != s[i]) diff++; 
    }

    if(diff == 1) return true; 
    return false; 
}


int main () {
    int n, m; 
    cin >> n >> m; 

    vector<pair<string, int>> candi(n); 
    vector<string> votes(m); 
    
    for(int i=0; i<n; i++) {
        string c; cin >> c; 
        candi[i] = {c, 0}; 
    }

    for(int i=0; i<m; i++) {
        string c; cin >> c; 
        votes[i] = c; 
    }

    for(int i=0; i<m; i++){
        string v = votes[i]; 

        // level 1 check 
        bool level1 = false; 
        for(auto &led : candi) {
            if(led.first == v) {
                // cout << "matched!" << endl; 
                led.second += 1; 
                level1 = true; 
                // cout << led.first << " | " << led.second << endl; 
            }
        }
 
        if(!level1){
            // no exact matches found, so we check diff 1 matches
            int matchCount = 0; 
            int candiId = -1; 
            for(int j=0; j<n; j++){
                if(check(v, candi[j].first)){matchCount++; candiId = j;}
            }           

            if(matchCount == 1 && candiId != -1){
                candi[candiId].second += 1; 
            }
        }
    }   

    for(auto p : candi){
        cout << p.second << endl; 
    }
    return 0; 
}