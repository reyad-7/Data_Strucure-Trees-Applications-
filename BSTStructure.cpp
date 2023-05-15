//
// Created by Mohamed reyad on 13/05/2023.
//

#include "student.cpp"


class node {
public:
    Student data;
    node* left;
    node* right;
    node (Student s) : data(s), left(nullptr), right(nullptr) {}
};


class BST {
private:
    node* root;
public:
    BST() : root(nullptr) {}

    node *getRoot() {return root;}

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

    node* insert(node* root, Student s) {
        if (root == nullptr) {
            return new node(s);
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
        node* current = root;
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
            node *current;
            node *trailCurrent;

            if (root == NULL) {
                cout << "Cannot delete from the empty tree." << endl;
                return;
            }
            if (root->data.id == id) {
                deleteFromTree(root);
                cout<<"Student is deleted.\n";
                return;
            }

            trailCurrent = root;

            if (root->data.id > id)
                current = root->left;
            else
                current = root->right;

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
            }

            if (current == NULL)
                cout << "The delete item is not in the tree." << endl;
            else if (trailCurrent->data.id > id)
                deleteFromTree(trailCurrent->left);
            else
                deleteFromTree(trailCurrent->right);
        }

    }

    void deleteFromTree(node* &p)
    {
        node *current;
        //the tree
        node *trailCurrent;
        node *temp;

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

            if(trailCurrent == NULL)

                p->left = current->left;
            else
                trailCurrent->right = current->left;

            delete current;
        }
    }

    void printAll(node* root) {
        if (root == nullptr) {
            return;
        }
        printAll(root->left);
        cout << "[" << root->data.id << ", " << root->data.fname << " " << root->data.lname << ", " << root->data.gpa
             << ", " << root->data.department << "]" << endl;
        printAll(root->right);
    }

    void printPerDepart(node* root) {
        if (root == nullptr) {
            return;
        }
        // Create a map to store the number of students in each department
        map<string, int> deptCounts;
        // Traverse the tree in-order and count the number of students in each department
        stack<node*> s;
        node* curr = root;
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
