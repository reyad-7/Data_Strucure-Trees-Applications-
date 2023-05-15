#include "student.cpp"
#include <vector>
#include <iomanip>
class MinHeap{
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
        MinHeap() : treeSize(0){}

        MinHeap readStudentsFromFile(string fileName);
        
        void addStudent(Student element);

        void printAll();
};

MinHeap MinHeap::readStudentsFromFile(string fileName){
        fstream fin(fileName);
        int n;
        fin >> n;
        MinHeap minHeap;
        for (int i = 0; i < n; i++) {
            int id;
            string fname, lname, department;
            float gpa;
            fin >> id >> fname >> lname >> gpa >> department;
            Student s(id, fname, lname, gpa, department);
            minHeap.addStudent(s);
        }
        fin.close();
        return minHeap;   
}

void MinHeap::heapfy(vector<Student>& arr, int size, int index)
{
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int min = index;
        // cout << "index(min): " << index << "   leftchild: " << leftChild << "   rightchild: " << rightChild <<endl; 

        if (leftChild < size && arr[min] > arr[leftChild])
            min = leftChild;
        if (rightChild < size && arr[min] > arr[rightChild])
            min = rightChild;

        // if there is change
        if (min != index)
        {
            // cout << "   #Swap" << endl;
            // swap the two elements
            // so that the arr[min] become the parent
            // and arr[index] become the child
            swap(arr[index], arr[min]);

            // heapfy the rest of suptree
            // may be when min = left child
            // or may be   min = right child
            heapfy(arr, size, min);
        }
}

void MinHeap::buildHeap(vector<Student>& arr, int size)
{
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            // heapfy all the tree
            // from down to top
            heapfy(arr, size, i);
        }
}

void MinHeap::heapSort(vector<Student>& arr, int size){

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

void MinHeap::addStudent(Student newStudent){
    // when you add an element
    // 1 - put the element at the end of the tree
    tree.push_back(newStudent); 
    treeSize++;
    // 2 - heapfy the array 
    buildHeap(tree, treeSize);
}

void MinHeap::printAll(){
    heapSort(tree, treeSize);


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