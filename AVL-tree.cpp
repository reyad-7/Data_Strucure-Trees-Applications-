#include<bits/stdc++.h>
#include "student.cpp"

using namespace std;


class Node {
public:
    Student *info;
    Node *left;
    Node *right;
    int height;

    Node() {};

    Node(Student *s) : info(s), height(1), left(nullptr), right(nullptr) {};
};

class AVL {
private:
    Node *root;
public:
    AVL() {
        root = nullptr;
    }


    void addStudent(Student *s) {
        root = insert(root, s);
    }

    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    void removeStudent(int d) {
        root = deleteStudent(root, d);
    }

    Node *deleteStudent(Node *node, int id) {
        if (node == nullptr) {
            return node;
        }

        if (id < node->info->id) {
            node->left = deleteStudent(node->left, id);
        } else if (id > node->info->id) {
            node->right = deleteStudent(node->right, id);
        } else {
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                node = nullptr;
            } else if (node->left == nullptr) {
                Node *temp = node;
                node = node->right;
                delete temp;
            } else if (node->right == nullptr) {
                Node *temp = node;
                node = node->left;
                delete temp;
            } else {
                Node *pred = node->left;
                while (pred->right != nullptr) {
                    pred = pred->right;
                }

                node->info = pred->info;

                node->left = deleteStudent(node->left, pred->info->id);
            }
        }

        if (node == nullptr) {
            return node;
        }

        node->height = 1 + max(height(node->left), height(node->right));
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }


    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left),
                        height(y->right)) + 1;
        x->height = max(height(x->left),
                        height(x->right)) + 1;

        return x;
    }

    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left),
                        height(x->right)) + 1;
        y->height = max(height(y->left),
                        height(y->right)) + 1;

        return y;
    }

    int getBalance(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) - height(N->right);
    }

    bool isempty() {
        return root == NULL ? 1 : 0;
    }

    Node *insert(Node *node, Student *key) {
        if (node == nullptr) {
            return new Node(key);
        }

        if (key->id < node->info->id) {
            node->left = insert(node->left, key);
        } else if (key->id > node->info->id) {
            node->right = insert(node->right, key);
        } else {
            cout << "Duplicate keys are not allowed in AVL tree\n";
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));

        int balance = getBalance(node);

        if (balance > 1 && key->id < node->left->info->id) {
            return rightRotate(node);
        }

        if (balance < -1 && key->id > node->right->info->id) {
            return leftRotate(node);
        }

        if (balance > 1 && key->id > node->left->info->id) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && key->id < node->right->info->id) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node *getroot() {
        return root;
    }

    void searchStudent(Node *node, int id) {
        if (node == nullptr) {
            cout << "Student with ID " << id << " not found." << endl;
            return;
        }

        if (id < node->info->id) {
            searchStudent(node->left, id);
        } else if (id > node->info->id) {
            searchStudent(node->right, id);
        } else {
            cout << "Student found:" << endl;
            cout << "ID: " << node->info->id << endl;
            cout << "Name: " << node->info->fname << " " << node->info->lname << endl;
            cout << "GPA: " << node->info->gpa << endl;
            cout << "Department: " << node->info->department << endl;
        }
    }

    AVL ReadStudentsFromFile() {
        fstream fin;
        fin.open("input.txt");
        int n;
        fin >> n;
        AVL avl;
        for (int i = 0; i < n; i++) {
            int id;
            string fname, lname, department;
            float gpa;
            fin >> id >> fname >> lname >> gpa >> department;
            Student s(id, fname, lname, gpa, department);
            avl.addStudent(&s);
        }
        fin.close();
        return avl;
    }

    void printAllAndDepartmentReport(Node *node) {
        if (node == nullptr) {
            return;
        }

        static map<string, int> departmentCounts;
        printAllAndDepartmentReport(node->left);
        cout << "[" << node->info->id << ", " << node->info->fname << " " << node->info->lname << ", "
             << node->info->gpa << ", " << node->info->department << "]" << endl;

        // Increment the department count for the current student's department
        departmentCounts[node->info->department]++;

        printAllAndDepartmentReport(node->right);

        // Print the department report if we've reached the end of the tree
        if (node->right == nullptr) {
            cout << "Department Report:" << endl;
            for (auto it = departmentCounts.begin(); it != departmentCounts.end(); ++it) {
                cout << it->first << " " << it->second << " students" << endl;
            }
        }
    }

    void printAll(Node *node) {
        if (node == nullptr) {
            return;
        }
        printAll(node->left);
        cout << "[" << node->info->id << ", " << node->info->fname << " " << node->info->lname << ", "
             << node->info->gpa << ", " << node->info->department << "]" << endl;
//node->info->print();
        printAll(node->right);
    }

    void print() {
        printAll(root);
    }
    AVL rreadStudentsFromFile(string filename) {
        fstream fin(filename);
        int n ;
        fin >> n;
        AVL avl;
        for (int i = 0; i < n; i++) {
            int id;
            string fname, lname, department;
            float gpa;
            fin >> id >> fname >> lname >> gpa >> department;
            Student s(id, fname, lname, gpa, department);
            avl.addStudent(&s);
        }
        fin.close();
        return avl;
    }
};
