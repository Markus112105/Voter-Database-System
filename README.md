# Voter Database Management System

## Overview
This project is a C++ implementation of a voter database that utilizes multiple data structures to efficiently manage and process voter information. The system employs:
- **Heap** for managing chauffeur assignments.
- **Binary Search Tree (BST)** for fast searching and in-order traversal of voter data.
- **Vector of Singly Linked Lists** for organizing voters by age.

## Data Structures

### **Voter**
Each voter in the system has the following attributes:
- `std::string first_name`
- `std::string last_name`
- `int age` (between 18 and 118)
- `bool voted`
- `unsigned int strength`
- `double likelihood`
- `double impact`

#### **Voter Functions**
- **Getter for voting status**: Checks whether the voter has cast their vote.
- **Calculate impact**: Computes the impact of a voter in the system.

### **Heap** (Max-Heap for Chauffeur Management)
The heap is used to prioritize voter transportation (chauffeur service). The heap consists of:

#### **Heap Object**
- Pointer to the corresponding **BST node** for the same voter.
- Pointer to the actual **Voter object**.
- Vector of **Heap Objects**.

#### **Heap Functions**
- `extract_max()` – Extracts the voter with the highest priority.
- `percolate_down(int index)` – Maintains heap order when removing an element.
- `percolate_up(int index)` – Maintains heap order when inserting an element.
- `int insert(voter)` – Inserts a new voter into the heap.

### **Heap and BST Connection**
When inserting a new voter:
1. Insert a pointer to the voter into the heap and store its index.
2. Insert the `Voter*` into the BST, storing the heap index in the tree node.
3. Update the heap object with the corresponding BST node pointer.

### **Binary Search Tree (BST)**
The BST is used for efficient lookup and ordered traversal of voter data. The tree sorts by **last name**.

#### **Tree Node**
- Left and Right child pointers.
- Pointer to actual **Voter object**.
- Index of the voter in the **heap**.

#### **BST Functions**
- `find(last_name, first_name)` – Searches for a voter by name.
- `insert(voter*, int index)` – Inserts a voter into the BST while keeping track of the heap index.

### **List (Vector of Singly Linked Lists)**
The list is used to efficiently group voters by age.

#### **List Node**
- Stores a `Voter` object.
- Pointer to the next node in the list.

#### **List Implementation**
- A **vector of singly linked lists** with indices ranging from **0 to 100** (index = `age - 18`).

#### **List Functions**
- `find(name, age)` – Searches for a voter by name and age.
- `show_impact()` – Iterates through all voters and prints their impact.
- `insert(voter)` – Inserts a voter into the list at the proper age index.

## Code Testing Instructions
This project includes a **test helper script** (`test_helper.sh`) to automate testing.

### **Running Tests**
1. Copy `test_helper.sh` and `interaction.exp` to the same directory as your executable.
2. Navigate to the executable directory:
   ```bash
   cd <path_to_executable>
   ```
3. Run a test case:
   ```bash
   bash test_helper.sh ./<executable> <testcase-number>
   ```
4. Compare your program's output with the EXPECTED OUTPUTS.
   The output doesn't have to match exactly, but it should be close.
