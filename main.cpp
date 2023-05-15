// Authors: Mohammed Reyad
// Authors: Abdelrahman Amer
// Authors: Abdelrahman Adel
// Data Structure Assignment III :)

#include "BSTStructure.cpp"
#include "MaxHeap.cpp"
#include "MinHeap.cpp"
#include"AVL-tree.cpp"

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
            int choice2;
            AVL avl ;

            Student s1(1, "Mohamed", "Ali", 3.4, "CS");
            Student s2(2, "Mona", "Samir", 3.2, "IT");
            Student s3(3, "Ola", "Maher", 1.2, "CS");
            Student s4(4, "Magy", "Magdy", 2.3, "DS");
            Student s5(5, "Omnia", "osama", 3.6, "IS");
            Student s6(6, "Bob", "Johnson", 3.2, "CS");
            Student s7(7, "Bob", "Johnson", 3.2, "IT");
            Student s8(8, "Bob", "Johnson", 3.2, "IT");
            Student s9(9, "Bob", "Johnson", 3.2, "IS");
            Student s10(10,"Bob", "Johnson", 3.2, "CS");
            avl.addStudent(&s1);
            avl.addStudent(&s2);
            avl.addStudent(&s3);
            avl.addStudent(&s4);
            avl.addStudent(&s5);
            avl.addStudent(&s6);
            avl.addStudent(&s7);
            avl.addStudent(&s8);
            avl.addStudent(&s9);
            avl.addStudent(&s10);

            while (true) {
                cout <<  "\nChoose one of the following options:\n"
                         "\n(using AVL) \n"
                         "1. Add student \n"
                         "2. Remove student\n"
                         "3. Search student\n"
                         "4. Print All (sorted by id)\n"
                         "5. Return to main menu\n";
                cin >> choice2;
                if (choice2 == 1) {
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
                    avl.addStudent(&newStudent);
                    cout << "The student is added.\n";

                }
                else if (choice2 == 2) {
                    int deleted_id ;
                    cout <<"id: ";
                    cin >> deleted_id;
                    avl.removeStudent(deleted_id);
                }
                else if (choice2 == 3) {
                    int searchedId;
                    cout << "enter id you search for \n";
                    cin >> searchedId;
                    avl.searchStudent(avl.getroot(),searchedId);
                }
                else if (choice2 == 4) {
                    avl.printAllAndDepartmentReport(avl.getroot());
                }
                else break;

            }
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