//hashset
#include<iostream>
#include<vector>
#include<list>
using namespace std;

//use bool table
//nhanh thao tác O(1)
//tốn bộ nhớ
class booltable{
    private:
    static const int MAX = 1'000'001;
    bool exits[MAX];
    public:
    booltable() {
        fill(begin(exits),end(exits),false);
    }
    
    void add(int key) {
        exits[key]=true;
    }
    
    void remove(int key) {
        exits[key]=false;
    }
    
    bool contains(int key) {
        return exits[key];
    }
};
//làm theo hassingtraining
class hassingchaining{
    private:
    static const int SIZE = 1009; // số nguyên tố gần 1000
    vector<list<int>> buckets;

    int hash(int key) {
        return key % SIZE;
    }
    public:
    hassingchaining() {
        buckets.resize(SIZE);
    }
    
    void add(int key) {
        int h=hash(key);
        for(int val:buckets[h]){
            if(val==key) return;
        }
        buckets[h].push_back(key);
    }
    
    void remove(int key) {
        int h=hash(key);
        buckets[h].remove(key);
    }
    
    bool contains(int key) {
        int h=hash(key);
        for(int val:buckets[h]){
            if(val==key) return true;
        }
        return false;
    }
};
//Open Addressing + Linear Probing
class Open{
    static const int SIZE = 20011; // số nguyên tố lớn
    vector<int> table;
    vector<bool> used;

    int hash(int key) {
        return key % SIZE;
    }
    public:
    Open(){
        table.assign(SIZE,-1);
        used.assign(SIZE,false);
    }
    void add( int key){
        int h=hash(key);
        while(used[h]){
            if(used[h]==key) return;
            h=(h+1)%SIZE;
        }
        table[h]=key;
        used[h]=true;
    }
    void remove(int key){
        int h=hash(key);
        while(used[h]){
            if(table[h]==key){
                table[h]=-1;
                return;
            }
            h=(h+1)%SIZE;
        }
    }
    bool contains(int key){
        int h=hash(key);
        while(used[h]){
            if(table[h]==key) return true;
            h=(h+1)%SIZE;
        }
        return false;
    }

};
int main(){
    cout<<"hello";
    return 0;
}