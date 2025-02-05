#include "Voter.h"
#include "List.h"
#include "BST.h"
#include "Heap.h"

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main() {
    BST* BinaryTree = new BST;
    List* VoterList = new List;
    Heap* heap = new Heap;
    string input;

    while (input != "quit") {
        cin >> input;

        if (input == "voter") {
            string lastName, firstName;
            int age;
            if (cin >> lastName >> firstName >> age) {
                if (BinaryTree->search(firstName, lastName)) {
                    cout << "Voter " << firstName << " " << lastName << ", age " << age << ", already exists\n";
                } else if (age < 18 || age > 118) {
                    cout << "Voter age should be between 18 and 118\n";
                } else {
                    Voter* temp = new Voter(firstName, lastName, age, false, 75, 75);
                    VoterList->insert(temp);//temp is actually in the list
                    int hIndex = heap->insert(temp);
                    BST::tNode* tLocation = BinaryTree->insert(temp, hIndex);//pointer to temp
                    heap->get(hIndex)->tree_voter = tLocation;
                    cout << "New voter " << firstName << " " << lastName << ", age " << age << ", added\n";
                }
            } else {
                cout << "Invalid input for voter command. Usage: voter <last-name> <first-name> <age>\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (input == "voted") {
            string lastName, firstName;
            int age;
            if (cin >> lastName >> firstName >> age) {
                if (BinaryTree->search(firstName, lastName) != nullptr) {
                    Voter* found = BinaryTree->search(firstName, lastName)->voter;
                    if (found->hasVoted()) {
                        cout << found->getFirstName() << " " << found->getLastName() << ", age " << found->getAge() << ", already voted\n";
                    } else {
                        found->vote();
                        heap->extract_max();
                        cout << "Voter " << found->getFirstName() << " " << found->getLastName() << ", age " << found->getAge() << ", voted\n";
                    }
                }
                else{
                        cout << "Voter does not exist\n";
                }
            } else {
                cout << "Invalid input for voted command. Usage: voted <last-name> <first-name> <age>\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (input == "support") {
            string lastName, firstName;
            int value;
            if (cin >> lastName >> firstName >> value) {
                if (BinaryTree->search(firstName, lastName) != nullptr) {
                    Voter* found = BinaryTree->search(firstName, lastName)->voter;
                    if (found->hasVoted()) {
                        cout << found->getFirstName() << " " << found->getLastName() << " already voted\n";
                    } else {
                        found->addStrength(value);
                        found->calculateImpact();
                        //after every calcImpact we need to do the following
                        //except for a new voter that is being inserted
                        BST::tNode* tn = BinaryTree->search(firstName, lastName);
                        heap->perc_up(tn->heapIndex);
                        //inside perc up we alter the indexes stored in tree with every swap
                        //to do this each object stored in the heep will have a pointer
                        //to the corresponding treeNode
                        cout << "Support from " << firstName << " " << lastName << " increased by " << value << " strength points\n";
                    }
                } else {
                    cout << "Voter does not exist\n";
                }
            } else {
                cout << "Invalid input for support command. Usage: support <last-name> <first-name> <value>\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (input == "reduce-likelihood") {
            string lastName, firstName;
            int reduction;
            if (cin >> lastName >> firstName >> reduction) {
                if (BinaryTree->search(firstName, lastName) != nullptr) {
                    Voter* found = BinaryTree->search(firstName, lastName)->voter;
                    if (found->hasVoted()) {
                        cout << found->getFirstName() << " " << found->getLastName() << " already voted\n";
                    } 
                    else{
                        found->decLikelihood(reduction);
                        found->calculateImpact();
                        BST::tNode* tn = BinaryTree->search(firstName, lastName);
                        heap->perc_up(tn->heapIndex);
                        cout << "Voting likelihood of " << firstName << " " << lastName << " decreased by " << reduction << "%\n";
                    }
                } else {
                    cout << "Voter does not exist\n";
                }
            } else {
                cout << "Invalid input for reduce-likelihood command. Usage: reduce-likelihood <last-name> <first-name> <reduction>\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        } else if (input == "chauffeur") {
            Voter* to_be_chauffeur = heap->extract_max();
            if (to_be_chauffeur != nullptr) {
                cout 
                    << "Driving " << to_be_chauffeur->getFirstName() 
                    << " " << to_be_chauffeur->getLastName() 
                    << " (" << to_be_chauffeur->getAge() 
                    << "): strength of support: " << to_be_chauffeur->getStrength() 
                    << ", likelihood: " << to_be_chauffeur->getLikelihood() 
                    <<fixed << setprecision(2)
                    << ", impact: " << to_be_chauffeur->getImpact() 
                    << "\n"<<defaultfloat;
                to_be_chauffeur->vote();
            } else {
                cout << "No one to be chauffeured\n";
            }
        } else if (input == "show-impact") {
            VoterList->show_impact();
            //this can just be a list method
            //print everything out
        }
    }
    delete BinaryTree;
    delete VoterList;
    delete heap;

    return 0;
}
