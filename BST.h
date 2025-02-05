#ifndef _H_BST_
#define _H_BST_

#include "Voter.h"
#include <string>

class BST {
   private:
   public:
      struct tNode {
         Voter* voter;
         tNode* left;
         tNode* right;
         int heapIndex;
         tNode(Voter* v, int index) : voter(v), left(nullptr), right(nullptr), heapIndex(index) {}
         void update_index(int index) {
            heapIndex = index;
         }
      };
       tNode* root;

      // Helper functions
      tNode* search(tNode* node, const string& first, const string& last);
      void destroy(tNode* node);
      void inorder(tNode* node);
      bool compareVoters(Voter* v1, Voter* v2) {
        if (v1->getLastName() != v2->getLastName()) {
            return v1->getLastName() < v2->getLastName();
        }
        return v1->getFirstName() < v2->getFirstName();
    }
      BST();
      ~BST();

      tNode* insert(Voter* voter, int heapIndex);
      tNode* search(const string& last, const string& first);
      void inorder();
      tNode* getRoot();
      void update_index(int index);
};

#endif
