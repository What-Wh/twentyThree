#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int value, Node* next, Node* prev) : data(value), next(next), prev(prev) {}
};

class List {
    Node* head;
    Node* tail;
public:
    List()
    {
        head = tail = nullptr;
    }
    void AddToHead(int value)
    {
        Node* newNode = new Node(value, head, nullptr);
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
    }
    void AddToTail(int value)
    {
        Node* newNode = new Node(value, nullptr, tail);
        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* beforeLast = tail->prev;
        beforeLast->next = nullptr;
        delete tail;
        tail = beforeLast;
    }
    bool IsEmpty()const
    {
        return head == nullptr;
    }
    void Show()const
    {
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->data << " ";
        }cout << "\n";
    }
    void Clear() {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = tail = nullptr;
    }
    void getData() {
        cout << head << endl;
    }
    void insertAt(int sym, int position) {
        int i = 0;
        Node* newNode = new Node(sym, nullptr, nullptr);
        Node* current = head;
        while (current != nullptr) {
            if (i == position-1) {
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                break;
            }
            current = current->next;
            i++;
        }
    }
    void deleteAt(int position) {
        int i = 0;
        Node* current = head;
        while (current != nullptr) {
            if (i == position - 1) {
                current->next->prev = current->prev;
                current->prev->next = current->next;
                delete current;
                current = nullptr;
                break;
            }
            current = current->next;
            i++;
        }
    }
    void getSize() {
        int i = 0;
        Node* current = head;
        while (current != nullptr) {
            current = current->next;
            i++;
        }
        cout << i << endl;
    }
    void getAt(int position) {
        int i = 0;
        Node* current = head;
        while (current != nullptr) {
            if (i == position - 1) {
                cout << current->data << endl;
                break;
            }
            current = current->next;
            i++;
        }
    }
    void setAt(int sym, int position) {
        int i = 0;
        Node* current = head;
        while (current != nullptr) {
            if (i == position - 1) {
                current->data = sym;
                break;
            }
            current = current->next;
            i++;
        }
    }
    ~List()
    {
        Clear();
    }
};

int main()
{
    List list;
    list.AddToHead(10);
    list.AddToHead(10);
    list.AddToHead(10);
    list.AddToHead(10);
    list.Show();
    list.DeleteFromTail();
    list.AddToTail(77);
    list.AddToTail(75);
    list.AddToTail(73);
    list.Show();
    list.getData();
    list.insertAt(120, 3);
    list.Show();
    list.deleteAt(4);
    list.Show();
    list.getSize();
    list.getAt(3);
    list.setAt(19, 3);
    list.Show();
}