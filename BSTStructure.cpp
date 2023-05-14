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


//    Node* Findmax(Node* r)
//    {
//        if (r == NULL)
//            return NULL;
//        else if (r->right == NULL)  // there is no elements in right side of your tree so the root item is the maximum element
//            return r;
//        else
//            return Findmax(r->right);
//    }
//
//    Node* removeStudent (Node *r ,int id ){
//        if (searchStudent(id)) {
//            if (r == NULL) // Empty Tree
//                return NULL;
//            if (id < r->data.id) // Item exists in left subtree
//                r->left = removeStudent(root->left, id);
//            else if (id > r->data.id) // item exists in right subtree
//                r->right = removeStudent(r->right, id);
//            else {
//                if (r->left == NULL && r->right == NULL) // leaf node
//                    r = NULL;
//                else if (r->left != NULL && r->right == NULL) // one child on the left
//                {
//                    r->data.id = r->left->data.id;
//                    r->data.fname = r->left->data.fname;
//                    r->data.lname = r->left->data.lname;
//                    r->data.department = r->left->data.department;
//                    r->data.gpa= r->left->data.gpa;
////                    r->data.= r->left->data.gpa;
//                    delete r->left;
//                    r->left = NULL;
//                }
//                else if (r->left == NULL && r->right != NULL) // one child on the right
//                {
//                    r->data.id = r->right->data.id;
//                    r->data.fname = r->right->data.fname;
//                    r->data.lname = r->right->data.lname;
//                    r->data.department = r->right->data.department;
//                    r->data.gpa= r->right->data.gpa;
//                    delete r->right;
//                    r->right = NULL;
//                }
//                else     // has two childes
//                {
//                    Node *max = Findmax(r->left);
//                    r->data = max->data;
//                    r->left = removeStudent(r->left, max->data.id);
//                }
//
//            }
//            cout<<"Student is deleted.";
//            return r;
//
//        }
//        return nullptr;
//    }


//  traverse into the tree and write every node into the file //

//
//    void writeToFile(Node* root, ofstream& fout) {
//        if (root == nullptr) {
//            return;
//        }
//        writeToFile(root->left, fout);
//        fout << root->data.id << "\n" << root->data.fname << " " << root->data.lname << "\n" << root->data.gpa << "\n" << root->data.department << "\n";
//        writeToFile(root->right, fout);
//    }


    void addStudentToFile(string filename, Student s) {
        // Read existing data from file into BST
        BST bst = readStudentsFromFile(filename);
        // Add the new student to the BST and write to file
        bst.addStudent(s);
    }





    void printAll(Node* root) {
        if (root == nullptr) {
            return;
        }
        printAll(root->left);
        cout <<"[" <<root->data.id << ", "<< root->data.fname << " " << root->data.lname<<", " << root->data.gpa  << ", " << root->data.department<<"]" <<endl ;
        printAll(root->right);
    }


};
