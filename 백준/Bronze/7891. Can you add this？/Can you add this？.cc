#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count;
    vector<int> result;
    cin >> count;
    
    for(int i = 0; i < count; i++){
        int num1, num2;
        
        cin >> num1 >> num2;
        
        result.push_back(num1 + num2);
    }
    
    for(int n : result)
        cout << n << endl;
}