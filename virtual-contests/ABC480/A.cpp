#include <iostream>

int main() {
    char arr[2][2]; 

    std::pair<int,int> A, D; 

    for(int i=0; i<2; i++){
        for(int j=0; j<2; j++){
            std::cin >> arr[i][j]; 
            if(arr[i][j] == 'A') {
                A = {i, j};  
            }else if (arr[i][j] == 'D'){
                D = {i, j}; 
            }
        }
    }

    if (abs(A.first - D.first) != abs(A.second - D.second)) {
        std::cout << "Yes\n"; 
    }else {
        std::cout << "No\n"; 
    }
}