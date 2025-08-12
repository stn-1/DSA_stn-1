#include <vector>
using namespace std;

class MyHashSet {
private:
    static const int SIZE = 20011; // số nguyên tố lớn
    vector<int> table;
    vector<bool> used;

    int hash(int key) {
        return key % SIZE;
    }

public:
    MyHashSet() {
        table.assign(SIZE, -1);  // -1 nghĩa là chưa có gì
        used.assign(SIZE, false);
    }

    void add(int key) {
        int h = hash(key);
        while (used[h]) {
            if (table[h] == key) return;
            h = (h + 1) % SIZE;
        }
        table[h] = key;
        used[h] = true;
    }

    void remove(int key) {
        int h = hash(key);
        while (used[h]) {
            if (table[h] == key) {
                table[h] = -1; // xoá bằng cách đánh dấu đặc biệt
                return;
            }
            h = (h + 1) % SIZE;
        }
    }

    bool contains(int key) {
        int h = hash(key);
        while (used[h]) {
            if (table[h] == key) return true;
            h = (h + 1) % SIZE;
        }
        return false;
    }
};
