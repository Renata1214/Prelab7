// Question 2. Linked Lists
// Given there is a singly linked lists that may or may not have circularity. This implies that the direction of the node 
//from the list may be pointing towards a node previous to it, or itself. Please provide a function that checks for circularity 
// given the following restrictions: the minimum amount of storage should be used (give priority to minimize space complexity over 
// time complexity).  


#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

bool circularity(ListNode* head) {
    if (head == nullptr || head->next == nullptr){
        return false;}
    ListNode* one = head;
    ListNode* two = head->next;
    while (two != nullptr && two->next != nullptr) {
        if (one == two){
            return true;} // Found cycle
        one = one->next;
        two = two->next->next;
    }

    return false; // No cycle found
}

void deleteLinkedList(ListNode* head, int number) {
    ListNode* current = head;
    for (int i =0; i< number; i++) {
        ListNode* temp = current;
        current = current->next;
        delete temp;
    }
}

int main() {
    ListNode* head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    // Cycle 
    head->next->next->next->next = head->next;

    if (circularity(head)){
         cout << "Does the list have a cycle? " << "Yes" << endl;
    }
    else
    {
         cout << "Does the list have a cycle? " << "No" << endl;
    }

    deleteLinkedList(head, 4);

    return 0;
}

// Another potential solution would require to use the previously coded at other labs, and the correspondent function would look 
// similar to the following:

//   bool circularity() {
//     if (front() == nullptr) // 
//         return false;
    
//     Node* temp = Head_List;

//     for (int i = 0; i < size(); i++) {
//         Node* temp2 = temp->next_link;

//         for (int j = 0; j < size(); j++) {
//             if (temp2 == nullptr)
//                 return false; // Reached end of the list, no circularity
//             else if (temp2 == temp)
//                 return true; // Found a cycle

//             temp2 = temp2->next_link;
//         }

//         temp = temp->next_link; // Move to the next node in the outer loop
//     }

//     return false; // No circularity found
// }


// This solution would have O(n^2) time, similar to solution number one, nonetheless, due to the lower number of comparisons
// and the general order of the solution, solution number 1 results superior to the latter solution. Additionally, 
// the implementation of the singly linked list appears to be more compact and efficient such that the final goal is achieved
// through less code. 