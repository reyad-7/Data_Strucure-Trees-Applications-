#include "student.cpp"
#include <vector>
#include <iomanip>
class MaxHeap{
    private:
        // is a simple static array
        vector<Student> tree;

        // to store the size of the tree 
        int treeSize;

        // it's heapfy in some position 
        void heapfy(vector<Student>& arr, int size, int index);

        // heapfy function is subProcess of it
        // so that it heapfy all of the tree 
        void buildHeap(vector<Student>& arr, int size);

        void heapSort(vector<Student>& arr, int size);


    public:
        MaxHeap() : treeSize(0){}
        MaxHeap readStudentsFromFile(string fileName);
        
        void addStudent(Student element);

        void printAll();
};

MaxHeap MaxHeap::readStudentsFromFile(string fileName){
        fstream fin(fileName);
        int n;
        fin >> n;
        MaxHeap maxHeap;
        for (int i = 0; i < n; i++) {
            int id;
            string fname, lname, department;
            float gpa;
            fin >> id >> fname >> lname >> gpa >> department;
            Student s(id, fname, lname, gpa, department);
            maxHeap.addStudent(s);
        }
        fin.close();
        return maxHeap;   
}

void MaxHeap::heapfy(vector<Student>& arr, int size, int index)
{
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int max = index;
        // cout << "index(max): " << index << "   leftchild: " << leftChild << "   rightchild: " << rightChild <<endl; 

        if (leftChild < size && arr[leftChild] > arr[max])
            max = leftChild;
        if (rightChild < size && arr[rightChild] > arr[max])
            max = rightChild;

        // if there is change
        if (max != index)
        {
            // cout << "   #Swap" << endl;
            // swap the two elements
            // so that the arr[max] become the parent
            // and arr[index] become the child
            swap(arr[index], arr[max]);

            // heapfy the rest of suptree
            // may be when max = left child
            // or may be   max = right child
            heapfy(arr, size, max);
        }
}

void MaxHeap::buildHeap(vector<Student>& arr, int size)
{
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            // heapfy all the tree
            // from down to top
            heapfy(arr, size, i);
        }
}

void MaxHeap::heapSort(vector<Student>& arr, int size){

    // first we have to make heap
    buildHeap(arr, size);

    for(int i = size - 1; i >= 0; i--){
        // swap first index with last index
        swap(arr[0], arr[i]);

        // then heapfy the tree again
        // note that we give the size paramener(second parameter)
        // we give it i, because we're ignoreing the last swaped digit 
        heapfy(arr, i, 0);
    }
}

void MaxHeap::addStudent(Student newStudent){
    // when you add an element
    // 1 - put the element at the end of the tree
    tree.push_back(newStudent); 
    treeSize++;
    // 2 - heapfy the array 
    buildHeap(tree, treeSize);
}

void MaxHeap::printAll(){
    heapSort(tree, treeSize);
    int maxIdDigits = 0;


    cout << setw(5) << "GPA"
         << "  "
         << setw(5) << "ID"
         << "  "
         << setw(10) << "First Name"
         << "  "
         << setw(10) << "Last Name"
         << "  "
         << setw(10) << "Department" << endl;

    for (int i = 0; i < treeSize; i++)
    {
        cout << setw(5) << setfill(' ')  << left << tree[i].gpa << "  "
             << setw(5) << setfill(' ')  << left << tree[i].id << "  "
             << setw(10) << setfill(' ') << left << tree[i].fname << "  "
             << setw(10) << setfill(' ') << left << tree[i].lname << "  "
             << setw(10) << setfill(' ') << left << tree[i].department << endl;
    }
}