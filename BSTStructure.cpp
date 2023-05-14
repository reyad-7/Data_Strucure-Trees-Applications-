//
// Created by Mohamed reyad on 13/05/2023.
//

#include "student.cpp"


class Node {
public:
    Student data;
    Node* left;
    Node* right;
    Node (Student s) : data(s), left(nullptr), right(nullptr) {}
};


class BST {
private:
    Node* root;
public:
    BST() : root(nullptr) {}

    Node *getRoot() {return root;}

    BST readStudentsFromFile(string filename) {
        fstream fin(filename);
        int n ;
        fin >> n;
        BST bst;
        for (int i = 0; i < n; i++) {
            int id;
            string fname, lname, department;
            float gpa;
            fin >> id >> fname >> lname >> gpa >> department;
            Student s(id, fname, lname, gpa, department);
            bst.addStudent(s);
        }
        fin.close();
        return bst;
    }

    Node* insert(Node* root, Student s) {
        if (root == nullptr) {
            return new Node(s);
        }
        if (s.id < root->data.id) {
            root->left = insert(root->left, s);
        }
        else if (s.id > root->data.id) {
            root->right = insert(root->right, s);
        }
        return root;
    }

    void addStudent (Student s) {
        root = insert(root, s);
    }


    bool searchStudent(int id) {
        Node* current = root;
        while (current != nullptr) {
            if (current->data.id == id) {
                cout <<"Student is found\n";
                current->data.print();
                return true ;
            }
            else if (id < current->data.id) {
                current = current->left;
            }
            else {
                current = current->right;
            }
        }
        cout<<"Student is not found\n";
        return false ;

    }

    void remove(int id)
    {
        if (searchStudent(id)) {
            Node *current;  //pointer to traverse the tree
            Node *trailCurrent; //pointer behind current

            if (root == NULL) {
                cout << "Cannot delete from the empty tree." << endl;
                return;
            }
            if (root->data.id == id) {
                deleteFromTree(root);
                return;
            }

            //if you get here, then the item to be deleted is not the root
            trailCurrent = root;

            if (root->data.id > id)
                current = root->left;
            else
                current = root->right;

            //search for the item to be deleted.
            while (current != NULL) {
                if (current->data.id == id)
                    break;
                else {
                    trailCurrent = current;
                    if (current->data.id > id)
                        current = current->left;
                    else
                        current = current->right;
                }
            }// once the while is done, current points to either NULL or to the node to be deleted

            if (current == NULL)
                cout << "The delete item is not in the tree." << endl;
            else if (trailCurrent->data.id > id)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }

    }

    void deleteFromTree(Node* &p)
    {
        Node *current;    //pointer to traverse
        //the tree
        Node *trailCurrent;   //pointer behind current
        Node *temp;        //pointer to delete the node

        if(p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }
        else if(p->left == NULL)
        {
            temp = p;
            p = p->right;
            delete temp;
        }
        else if(p->right == NULL)
        {
            temp = p;
            p = p->left;
            delete temp;
        }
        else
        {
            current = p->left;
            trailCurrent = NULL;

            while(current->right != NULL)
            {
                trailCurrent = current;
                current = current->right;
            }//end while

            p->data.id = current->data.id;

            if(trailCurrent == NULL) //current did not move;
                //current == p->left; adjust p
                p->left = current->left;
            else
                trailCurrent->right = current->left;

            delete current;
        }//end else
    }//end deleteFromTree
    
    void printAll(Node* root) {
        if (root == nullptr) {
            return;
        }
        printAll(root->left);
        cout << "[" << root->data.id << ", " << root->data.fname << " " << root->data.lname << ", " << root->data.gpa
             << ", " << root->data.department << "]" << endl;
        printAll(root->right);
    }

    void printPerDepart(Node* root) {
        if (root == nullptr) {
            return;
        }

        // Create a map to store the number of students in each department
        map<string, int> deptCounts;

        // Traverse the tree in-order and count the number of students in each department
        stack<Node*> s;
        Node* curr = root;
        while (curr != nullptr || s.empty() == false) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();

            // Update the count of students in the current department
            deptCounts[curr->data.department]++;

            // Move to the right subtree
            curr = curr->right;
        }

        // Print the results
        for (auto const& [dept, count] : deptCounts) {
            cout << dept << " " << count << " Students" << endl;
        }
    }


};
