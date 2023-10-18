#include <iostream>
#include <vector>

using namespace std;

int main(){
    int count;
    vector<int> results;
    
    cin >> count;
    
    for(int i = 0; i < count; i++){
        int a,b;
        
        cin >> a >> b;
        
        results.push_back(a+b);
    }
    
    for(int& n : results)
        cout << n << endl;
}