#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};
class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    // Thêm node vào cuối danh sách
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // In từ đầu đến cuối
    void printForward() {
        Node* temp = head;
        cout << "Forward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // In từ cuối về đầu
    void printBackward() {
        Node* temp = tail;
        cout << "Backward: ";
        while (temp) {
            cout << temp->data << " ";
            temp = temp->prev;
        }
        cout << endl;
    }

    // Xóa toàn bộ danh sách
    void deleteList() {
        Node* temp = head;
        while (temp) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }
        head = tail = nullptr;
    }

    // Hủy khi ra khỏi scope
    ~DoublyLinkedList() {
        deleteList();
    }
};

int main() {
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.printForward();
    list.printBackward();

    return 0;
}
