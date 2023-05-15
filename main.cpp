// Authors: Mohammed Reyad
// Authors: Abdelrahman Amer
// Authors: Abdelrahman Adel
// Data Structure Assignment III :)

#include "BSTStructure.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"
int main() {
    while (true) {
        int choice;
        cout << "Choose Data Structure:\n1 - BST\n2 - AVl\n3 - Min Heap\n4 - Max Heap\n5 - Exit Program\n";
        cin >> choice;
        if (choice == 1 ) {
            int choice1;
            BST bst;
            bst=bst.readStudentsFromFile("input.txt");
            while (true) {
                cout <<  "\nChoose one of the following options:\n"
                         "\n(using BST) \n"
                         "1. Add student \n"
                         "2. Remove student\n"
                         "3. Search student\n"
                         "4. Print All (sorted by id)\n"
                         "5. Return to main menu\n";
                cin >> choice1;
                if (choice1 == 1) {
                    int id;
                    string fname, lname, department;
                    float gpa;
                    cout << "\n\nadding a student into the tree \n\n";
                    cout << "id : ";
                    cin >> id;
                    cout << "fname : ";
                    cin >> fname;
                    cout << "lname:";
                    cin >> lname;
                    cout << "gpa:";
                    cin >> gpa;
                    cout << "department : ";
                    cin >> department;
                    Student newStudent(id, fname, lname, gpa, department);
                    bst.addStudent(newStudent);
                    cout << "The student is added.\n";

                }
                else if (choice1 == 2) {
                    int deleted_id ;
                    cout <<"id: ";
                    cin >> deleted_id;
                    bst.remove(deleted_id);
                }
                else if (choice1 == 3) {
                    int searchedId;
                    cout << "enter id you search for \n";
                    cin >> searchedId;
                    bst.searchStudent(searchedId);
                }
                else if (choice1 == 4) {
                    bst.printAll(bst.getRoot());
                    bst.printPerDepart(bst.getRoot());
                }
                else break;

            }
        }

        else if (choice ==2){
//          AVL code     -> take all my code of choice1 (BST tree )  just only change my functions by yours
        }

        else if (choice ==3){
            int choice1;
            MinHeap minHeap;
            minHeap = minHeap.readStudentsFromFile("input.txt");
            while (true)
            {
                cout << "\nChoose one of the following options:\n"
                        "\n(using MinHeap) \n"
                        "1. Add student \n"
                        "2. Print All (sorted by gpa)\n";
                cin >> choice1;
                if (choice1 == 1)
                {
                    int id;
                    string fname, lname, department;
                    float gpa;
                    cout << "\n\nadding a student into the tree \n\n";
                    cout << "id : ";
                    cin >> id;
                    cout << "fname : ";
                    cin >> fname;
                    cout << "lname:";
                    cin >> lname;
                    cout << "gpa:";
                    cin >> gpa;
                    cout << "department : ";
                    cin >> department;
                    Student newStudent(id, fname, lname, gpa, department);
                    minHeap.addStudent(newStudent);
                    cout << "The student is added.\n";
                }
                else if (choice1 == 2)
                {
                    minHeap.printAll();
                }
                else
                    break;
            }
        }

        else if (choice == 4)
        {
            int choice1;
            MaxHeap maxHeap;
            maxHeap = maxHeap.readStudentsFromFile("input.txt");
            while (true)
            {
                cout << "\nChoose one of the following options:\n"
                        "\n(using MaxHeap) \n"
                        "1. Add student \n"
                        "2. Print All (sorted by gpa)\n";
                cin >> choice1;
                if (choice1 == 1)
                {
                    int id;
                    string fname, lname, department;
                    float gpa;
                    cout << "\n\nadding a student into the tree \n\n";
                    cout << "id : ";
                    cin >> id;
                    cout << "fname : ";
                    cin >> fname;
                    cout << "lname:";
                    cin >> lname;
                    cout << "gpa:";
                    cin >> gpa;
                    cout << "department : ";
                    cin >> department;
                    Student newStudent(id, fname, lname, gpa, department);
                    maxHeap.addStudent(newStudent);
                    cout << "The student is added.\n";
                }
                else if (choice1 == 2)
                {
                    maxHeap.printAll();
                }
                else
                    break;
            }
        }

        else
            break; //  return to the main menu
    }
}