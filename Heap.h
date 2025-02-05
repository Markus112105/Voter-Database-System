#ifndef _H_Heap_
#define _H_Heap_ 

#include "Voter.h"
#include "BST.h"
#include <vector>

class Heap {
    private:
        struct hNode {
            BST::tNode* tree_voter;
            Voter* voter;
            hNode(Voter* v) : tree_voter(nullptr), voter(v) {}
        };

        vector<hNode> heap;
        
    public:
        Heap();

        int insert(Voter* voter);//should call prec_Up, returns index of the node inserted
        Voter* extract_max(); //should call prec_down
        hNode* get(int index);

        //we pass the index in as a reference because we need to know how it changes
        //inorder to go back to that element and update the tNode after insert
        void perc_up(int& index);
        void perc_down(int index);
        void swap_nodes(int index1, int index2);
};

#endif 