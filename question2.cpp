// Question 2. Linked Lists
// Given there is a singly linked lists that may or may not have circularity. This implies that the direction of the node 
//from the list may be pointing towards a node previous to it, or itself. Please provide a function that checks for circularity 
// given the following restrictions: the minimum amount of storage should be used (give priority to minimize space complexity over 
// time complexity).  

#include <iostream> 

using namespace std;

emplate <class T>
class Node;
class List;

// Definition of linked list
template <class T>
class Node {
public:
    T instance;
    Node* next_link;

    Node(T n) : instance(n), next_link(nullptr) {}
};

class List {
private:
    Node* Head_List;

public:
    List() : Head_List(nullptr) {}

    ~List() {
        while (Head_List != nullptr) {
            Node* temp = Head_List;
            Head_List = Head_List->next_link;
            delete temp;
        }
    }

    void push_front(const T& name) {
        Node* newNode = new Node(name);
        newNode->next_link = Head_List;
        Head_List = newNode;
    }

    void pop_front() {
        if (Head_List == nullptr) {
            cout << "No elements inside the list" << '\n';
        } else {
            Node* temp = Head_List->next_link;
            delete Head_List;
            Head_List = temp;
        }
    }

    void push_back(const T& name) {
        if (Head_List == nullptr) {
            Head_List = new Node(name);
        } else {
            Node* tail = Head_List;
            while (tail->next_link != nullptr) {
                tail = tail->next_link;
            }
            tail->next_link = new Node(name);
        }
    }

    void pop_back() {
        if (Head_List == nullptr) {
            cout << "No elements inside the list" << '\n';
            return;
        } else if (Head_List->next_link == nullptr) {
            delete Head_List;
            Head_List = nullptr;
            return;
        } else {
            Node* tail = Head_List;
            while (tail->next_link->next_link != nullptr) {
                tail = tail->next_link;
            }
            delete tail->next_link;
            tail->next_link = nullptr;
        }
    }

    int size() const {
        int counter = 0;
        Node* temp = Head_List;
        while (temp != nullptr) {
            temp = temp->next_link;
            counter++;
        }
        return counter;
    }

    int capacity() const {
        // If capacity means the same as size in your context, this is correct.
        // Otherwise, you'll need to define how capacity is determined for your list.
        return size();
    }

    void print() const {
        Node* temp = Head_List;
        while (temp != nullptr) {
            temp->instance.print();
            temp = temp->next_link;
        }
    }

    T& operator[](int i) {
        Node* iterator = Head_List;
        for (int j = 0; j < i; j++) {
            iterator = iterator->next_link;
        }
        return iterator->instance;
    }

    const T& operator[](int i) const {
        Node* iterator = Head_List;
        for (int j = 0; j < i; j++) {
            iterator = iterator->next_link;
        }
        return iterator->instance;
    }

    bool empty() const {
        return Head_List == nullptr;
    }

    T front() const {
        if (Head_List == nullptr) {
            cout << "No objects inside the list" << '\n';
            throw runtime_error("List is empty");
        } else {
            return Head_List->instance;
        }
    }

    T back() const {
        if (Head_List == nullptr) {
            cout << "No objects inside the list" << '\n';
            throw runtime_error("List is empty");
        } else {
            Node* temp = Head_List;
            while (temp->next_link != nullptr) {
                temp = temp->next_link;
            }
            return temp->instance;
        }
    }


  bool circularity() {
    if (front() == nullptr) // Assuming front() returns the head of the linked list
        return false;
    
    Node* temp = Head_List;

    for (int i = 0; i < size(); i++) {
        Node* temp2 = temp->next_link;

        for (int j = 0; j < size(); j++) {
            if (temp2 == nullptr)
                return false; // Reached end of the list, no circularity
            else if (temp2 == temp)
                return true; // Found a cycle

            temp2 = temp2->next_link;
        }

        temp = temp->next_link; // Move to the next node in the outer loop
    }

    return false; // No circularity found
}



//FUNCTION USED TO TEST THE CIRCULARITY FUNCTION
   void makeCircular() {
        // Make the last node point to the first node to create a cycle
        if (Head_List == nullptr)
            return;
        
        Node<T>* tail = Head_List;
        while (tail->next_link != nullptr) {
            tail = tail->next_link;
        }
        tail->next_link = Head_List;
    }

};


int main {

    List<int> a;

    // Test case 1: Non-circular list
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    cout << "Circularity detected? " << (a.circularity() ? "Yes" : "No") << endl;

    // Test case 2: Circular list
    a.makeCircular();
    cout << "Circularity detected? " << (a.circularity() ? "Yes" : "No") << endl;

    return 0;

}