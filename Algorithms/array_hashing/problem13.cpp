//hashmap
//ý tưởng tương tự hashset
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<list>
using namespace std;
//làm theo hassingtraining
class Bucket{
    private:
        static const int SIZE = 1009; 
        vector<list<pair<int,int>>>bucket;
        int hash(int key){
            return key % SIZE;
        }
    public:
    Bucket() {
        bucket.resize(SIZE);
    }
    
    void put(int key, int value) {
        int h=hash(key);
        for(pair<int,int> i:bucket[h]){
            if (i.first == key) {
            i.second = value; 
            return;
        }
        }
        bucket[h].push_back({key,value});
    }
    
    int get(int key) {
        int h=hash(key);
        for(auto i:bucket[h]){
            if(h==i.first) return i.second;
        }
        return -1;
    }
    
    void remove(int key) {
        int h=hash(key);
        for (auto it = bucket[h].begin(); it != bucket[h].end(); ++it) {
        if (it->first == key) {
            bucket[h].erase(it);
            return;
        }
    }
        cout<<"không có key thỏa mãn";
    }

};
int main(){
    
 
    return 0;
}
