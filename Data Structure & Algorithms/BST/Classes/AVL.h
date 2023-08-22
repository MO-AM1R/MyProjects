# ifndef ASS_3DS_AVL_H
# define ASS_3DS_AVL_H
# include "Student.h"
# include <iostream>
# include <cmath>
# include <map>
using namespace std;

class Node{
public:
    int key;
    Node* left;
    Node* right;
    int height;

   explicit Node(int value)
   {
       left = right = nullptr;
       height = 1;
       key = value;
   }
};


class AVL{
public:
    Node* root;
    AVL()
    {
        root = nullptr;
    }
    int Height(Node* node)
    {
        if(node == nullptr)
            return 0;
        else
            return node->height;
    }

    int updateHeight(int x, int y)
    {
        return ((x>y)?x:y)+1;
    }

    int getBalance(Node* node)
    {
        if(node == nullptr)
            return 0;
        else
            return Height(node->left) - Height(node->right);
    }

    Node* rightRotatoin(Node*node) //for ll case
    {
        Node* leftnode = node->left;
        Node* rightLeftnode = leftnode->right;
        leftnode->right = node;
        node->left = rightLeftnode;
         node->height = updateHeight(Height(node->left), Height(node->right));
         leftnode->height = updateHeight(Height(leftnode->left), Height(leftnode->right));
        return leftnode;

    }
    Node* updateBalance(Node*node)
    {
        int Balance = getBalance(node);

        if(Balance > 1 && getBalance(node->left) !=-1) //for LL
        {
            return rightRotatoin(node);
        }
        else if(Balance< -1 && getBalance(node->right) != 1)//for RR
        {

            return leftRotatoin(node);
        }

        else if(Balance > 1 && getBalance(node->left) == -1)//For LR
        {

            node->left = leftRotatoin(node->left);
            return rightRotatoin(node);

        }
        else if(Balance < -1 && getBalance(node->right) == 1)//For RL
        {

            node->right= rightRotatoin(node->right);
            return leftRotatoin(node);
        }
        return node;
    }


    Node* leftRotatoin(Node*node)//for rr case
    {


        Node* rightNode = node->right;
        Node* leftRightNode = rightNode->left;
        rightNode->left = node;
        node->right = leftRightNode;
        node->height = updateHeight(Height(node->left), Height(node->right)) ;
        rightNode->height = updateHeight(Height(rightNode->left), Height(rightNode->right)) ;
        return rightNode;

    }

    Node* insert(Node*node ,int key)
    {

        if(node == nullptr)
        {
            Node*newnode = new Node(key);
            node = newnode;
        }

        if(key == node->key) {
            return node;
        }
        else if(key < node->key) {
            node->left = insert(node->left, key);
        }
        else if(key > node->key)
        {
            node->right = insert(node->right, key);
        }

        node->height = updateHeight(Height(node->right), Height(node->left));

        node = updateBalance(node);
        return node;
    }

    void insert(int key)
    {
        root = insert(root, key);
    }

    Node* findMax(Node* node)
    {
        if(node == nullptr)
            return nullptr;
        else if(node->right == nullptr)
            return node;
        else
            return findMax(node->right);

    }

    Node* findMin(Node* node)
    {
        if(node == nullptr)
            return nullptr;
        else if(node->left == nullptr)
            return node;
        else
            return findMin(node->left);
    }

    Node* Delete(Node* node, int key)
    {
        if(node == nullptr)
            return nullptr;
        if(key < node->key)
            node->left = Delete(node->left, key);
        else if(key > node->key)
            node->right = Delete(node->right, key);
        else{
            if(node->right == nullptr && node->left == nullptr)
            {
                node = nullptr;
            }
            else if(node->left == nullptr &&node->right != nullptr){
                node->key = node->right->key;
                delete node->right;
                node->right = nullptr;

            }
            else if(node->left != nullptr &&node->right == nullptr){
                node->key = node->left->key;
                delete node->left;
                node->left = nullptr;
            }
            else{
                Node* pre = findMax(node->left);
                node->key = pre->key;
                node->left = Delete(node->left, pre->key);

            }
        }
        if(node == nullptr)
            return node;
        node->height = updateHeight(Height(node->right), Height(node->left));
        node = updateBalance(node);

        return node;
    }
    void Delete(int key)
    {
       root =  Delete(root, key);
    }
    int Search(Node* node , int data)
    {
        if(node == nullptr)
            return 0;
        else if(node->key == data)
            return node->key;
        else if(data < node->key)
            return Search(node->left, data);
        else
            return Search(node->right, data);
    }
    void  inorder(Node* node, map<int, Student> m){
        if(node == nullptr)
        {
            return ;
        }
        else
        {
            inorder(node->left, m);
            cout << m[node->key] ;
            inorder(node->right, m);
        }
    }
    void inorder(Node* node) {
        if (node == nullptr) {
            return;
        } else {
            inorder(node->left);
            cout << node->key << " ";
            inorder(node->right);
        }

    }

};


void avlMain(Data & data, AVL & avl){
    int check;
    here:

    cout<<"1. Add student \n"
          "2. Remove student\n"
          "3. Search student\n"
          "4. Print All (sorted by id)\n"
          "5. Return to main menu\n";

    cin >> check;
    int id;
    string department;
    string name;
    double gpa;

    while(check != 5){
        if (check == 1) {
            id:
            cout << "Enter id:";
            cin >> id;
            if (id <= 0 || id > 100) {
                goto id;
            }
            if (avl.Search(avl.root, id) != 0) {
                cout << "This id is exist before" << endl;
                goto id;
            }

            avl.insert(id);
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter GPA: ";
            cin >> gpa;
            cout << "Enter Department: ";
            cin >> department;
            Student s(id, gpa, name, department);
            data.addStudent(s) ;
            cout << "The student is added." << endl;
            goto here;
        }

        else if (check == 2) {
            cout << "Enter id: ";
            cin >> id;
            if (avl.Search(avl.root, id) != 0) {
                cout << "Student is found." << endl;
                data.printStudent(id) ;
                data.removeStudent(id) ;
                avl.Delete(id);

                cout << "Student is deleted." << endl;
            } else {
                cout << "Student is not found." << endl;
            }
            goto here;

        }

        else if (check == 3) {
            cout << "Enter id: ";
            cin >> id;
            if (avl.Search(avl.root, id) != 0) {
                cout << "Student is found." << endl;
                data.printStudent(id) ;
            }
            else {
                cout << "Student is not found." << endl;
            }
            goto here;

        }

        else if (check == 4) {
            cout << "print " << data.getStudentsNumber() << " students" << endl;
            avl.inorder(avl.root, data.getStudents());

            cout<< endl <<"Students per Departments:"<<endl;
            data.printDepartments() ;
            goto here;
        }
        else {
            cerr << "Enter correct number" << endl;
            goto here;
        }
    }
}

#endif //ASS_3DS_AVL_H
