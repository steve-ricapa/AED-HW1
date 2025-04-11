#include <iostream>
using namespace std;

template <typename T>
class Forward_list {
private:
    struct Node {
        T val;
        Node* next;
        Node(T x) : val(x), next(nullptr) {}
    };

    Node* head;

public:
    Forward_list() : head(nullptr) {}

    T front() const {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return T();
        }
        return head->val;
    }

    T back() const {
        if (!head) {
            cout << "La lista está vacía." << endl;
            return T();
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        return current->val;
    }

    void push_back(T x) {
        Node* newNode = new Node(x);
        if (!head) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    void push_front(T x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
    }

    void pop_back() {
        if (!head) return;

        if (!head->next) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next) {
            current = current->next;
        }

        delete current->next;
        current->next = nullptr;
    }
    void pop_front() {
        if (!head) return;
        Node* current = head;

        head = current->next;
        delete current;
        current = nullptr;
    }
    T operator[](int index) {
        Node* current = head;
        int count = 0;

        while (current != nullptr) {
            if (count == index) {
                return current->val;
            }
            count++;
            current = current->next;
        }

        cout << "Índice fuera de rango." << endl;
        return T();
    }

    bool empty() {
        return head == nullptr;
    }

    int size() {
        int k = 0;
        Node* temp = head;
        while (temp != nullptr) {
            temp = temp->next;
            k++;
        }
        return k;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Forward_list() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    Forward_list<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);

    cout << "LISTA:" << endl;
    list.print();  // 10 20 30 40
    cout << endl;

    list.push_front(5);
    cout << "Despues de push_front(5): "<<endl;
    list.print();  // 5 10 20 30 40
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.pop_back();
    list.print();
    list.pop_front();
    cout << "Despues de pop_front(): "<<endl;
    list.print();
    // cout << "Primer elemento (front): " << list.front() << endl;  // 5
    // cout << "Último elemento (back): " << list.back() << endl;    // 40
    //
    // cout << "Eliminar último elemento (pop_back): ";
    // list.pop_back();
    // list.print();  // 5 10 20 30
    //
    // cout << "Elemento en posición [2]: " << list[2] << endl;  // Debería mostrar 20
    // cout << "¿La lista está vacía? (empty): " << list.empty() << endl;
    // cout << "Size de la lista (size): " << list.size() << endl;
    //
    // list.clear();
    // cout << "Eliminar toda la lista (clear), ¿está vacía?: " << list.empty() << endl;

    return 0;
}
