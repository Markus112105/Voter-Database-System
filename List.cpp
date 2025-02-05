#include "List.h"
#include <iomanip>
using namespace std;

List::List() {
    for (int i = 0; i < 100; ++i) {
        v[i] = nullptr;
    }
}
List::~List() {
    for (int i = 0; i < 100; ++i) {
        Node* curr = v[i];
        while (curr != nullptr) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
    }
}

Voter *List::find(string lastName, string firstName, int age){
   Node* curr = v[age-18];
   while(curr!=nullptr){
        if(curr->votee->getLastName()==lastName){
            if(curr->votee->getFirstName()==firstName){
             return curr->votee;   
            }
        }
        curr=curr->next;
   }
   return nullptr;
}

void List::insert(Voter* voter){
    Node *newNode = new Node(voter);
    newNode->votee = voter;
    newNode->next = nullptr;
    Node *&head = v[voter->getAge() - 18];

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node *curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

void List::show_impact(){
    int ageIndex=0;
    Node *curr=v[ageIndex];
    while(ageIndex<=100){
    while(curr!=nullptr){
        if(curr->votee->hasVoted()==false){
        cout
            <<curr->votee->getFirstName()
            <<" "<<curr->votee->getLastName()
            <<" ("<<curr->votee->getAge()
            <<"): strength of support: "<< curr->votee->getStrength()
            <<", likelihood: "<<curr->votee->getLikelihood();
        cout
            <<fixed << setprecision(2)
            <<", Impact: "<<curr->votee->getImpact()
            <<"\n"<<defaultfloat;
        }
        curr=curr->next;
    }
    ageIndex++;
    curr=v[ageIndex];
    }
}