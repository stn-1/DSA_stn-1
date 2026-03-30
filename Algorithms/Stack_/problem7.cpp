#include <iostream>
#include <string>
#include <vector>
#include<stack>
using namespace std;
class StockSpanner {
private:
    stack<pair<int, int>> st; 
public:
     StockSpanner() {
    }
    
    int next(int price) {
        int span = 1;  
        while(!st.empty() && st.top().first <= price){
            span += st.top().second; 
            st.pop();
        }
        st.push({price, span});  
        return span;
    }
};

int main() {
    StockSpanner x;
    cout << x.next(100) << endl; 
    cout << x.next(80)  << endl; 
    cout << x.next(60)  << endl;
    cout << x.next(70)  << endl; 
    cout << x.next(60)  << endl; 
    cout << x.next(75)  << endl; 
    cout << x.next(85)  << endl; 
    return 0;
}