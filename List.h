 #ifndef MY_TEMPLATE_CLASS_H
 #define MY_TEMPLATE_CLASS_H
#include "Voter.h"
#include <vector>
class List{
    private:
        struct Node{
            Voter* votee;
            Node* next;
            Node(Voter* voter){
                votee=voter;
                next=nullptr;
            }
        };
        struct Node*v[100];
        Node *head;
    public:
        List();
        ~List();
        Voter *find(string lastName, string firstName, int age);
        void insert(Voter* voter);
        void show_impact();
};
 #endif