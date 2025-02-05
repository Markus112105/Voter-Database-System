#include "Heap.h"
#include <vector>

//constructor
Heap::Heap() {}

// methods =======================================================
void Heap::swap_nodes(int index1, int index2) {
    hNode temp = heap[index1];
    heap[index1] = heap[index2];
    heap[index2] = temp;

    // Update tNode pointers if they are not nullptr
    if (heap[index1].tree_voter) {
        heap[index1].tree_voter->update_index(index1);
    }
    if (heap[index2].tree_voter) {
        heap[index2].tree_voter->update_index(index2);
    }
}

void Heap::perc_up(int& index) {
    while(index > 0){
        int parent = (index-1)/2;

        if(heap[index].voter->getImpact() > heap[parent].voter->getImpact()){//swap time
            swap_nodes(index, parent);

            index = parent;
        }else{
            break;
        }
    }
}

void Heap::perc_down(int index) {
    int size = heap.size();
    while(index < size){
        int left = 2 * index + 1;
        int right = 2 * index + 1;
        int biggest = index;

        if (left < size && heap[left].voter->getImpact() > heap[biggest].voter->getImpact()){
            biggest = left;
        }
        if (right < size && heap[right].voter->getImpact() > heap[biggest].voter->getImpact()){
            biggest = right;
        }

        if(biggest != index){//swap time
            swap_nodes(index, biggest);

            index = biggest;
        }else{
            break;
        }
    }
}

int Heap::insert(Voter* voter) {
    hNode* h = new hNode(voter);
    heap.push_back(*h);

    int index = heap.size() - 1;
    perc_up(index);
    return index;
}

Voter* Heap::extract_max() {
    if(heap.empty()) {
        return nullptr;
    }

    hNode maxNode = heap[0];
    maxNode.tree_voter->update_index(-1);

    heap[0] = heap.back();
    heap.pop_back();

    heap[0].tree_voter->update_index(0);//updating the tree with the new root
    if (!heap.empty()) {
        perc_down(0);
    }

    maxNode.voter->vote();
    return maxNode.voter;
}

Heap::hNode* Heap::get(int index) {
    return &heap[index];
}