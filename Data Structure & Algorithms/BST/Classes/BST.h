# ifndef BST_BST_H
# define BST_BST_H
# include <iostream>
# include "Data.h"

using namespace std ;

struct node{
    int Id;
    node* left;
    node* right;

    explicit node(int ID) : Id(ID), left(nullptr), right(nullptr){}
};

class BST {
   node* root ;

public:
    explicit BST(){
        root = nullptr ;
    }
    
    void insert(int Id){
        node* Node=  new node(Id) ;
        Node->right = Node->left = nullptr ;

        if (!root){
            root = Node ;
            root->right = root->left = nullptr ;
        }
        else{
            node* temp = root ;
            node* temp2 = nullptr ;

            while (temp){
                temp2 = temp ;
                if (temp->Id > Id){
                    temp = temp->left ;
                }
                else{
                    temp = temp->right ;
                }
            }
            if (temp2 == nullptr){
                temp2 = Node ;
            }
            else if (temp2->Id > Id){
                temp2->left = Node ;
            }
            else if (temp2->Id < Id){
                temp2->right = Node ;
            }
        }
    }

    bool search(node* Root, int ID) {
        if (!Root){
            return false;
        }
        else if (Root->Id == ID){
            return true ;
        }
        else{
            if (Root->Id > ID){
                return search(root->left, ID) ;
            }
            else{
                return search(Root->right, ID) ;
            }
        }
    }

    node* remove(node* Root, int Id){
        if (!Root){
            return Root;
        }
        if (Root->Id < Id){
            Root->right = remove(Root->right, Id) ;
        }
        else if (Root->Id > Id){
            Root->left = remove(Root->left, Id) ;
        }
        else{
            if (!Root->right && !Root->left){
                delete Root ;
                Root = nullptr ;
                return Root ;
            }
            else if (!Root->right || !Root->left){
                if (Root->right) {
                    node* temp = Root;
                    Root = Root->right;
                    delete temp ;
                    return Root ;
                }
                else{
                    node* temp = Root;
                    Root = Root->left;
                    delete temp ;
                    return Root ;
                }
            }
            else{
                node* temp = findMinimum(Root->right) ;
                Root->Id = temp->Id ;
                Root->right = remove(Root->right, temp->Id) ;
            }
        }
        return Root ;
    }

    node* findMinimum(node* Root){
        if (!Root){
            return nullptr ;
        }
        else{
            return findMinimum(Root->left) ;
        }
    }

    void inOrder(node* Root, Data data){
        if (!Root){
            return;
        }
        else{
            inOrder(Root->left, data) ;
            data.printStudent(Root->Id) ;
            inOrder(Root->right, data) ;
        }
    }

    node* getRoot(){
        return root ;
    }
};


void clear() {
    const int NUM_BLANK_LINES = 100;
    string blankLine;

    for (int i = 0; i < 80; i++) {
        blankLine += " ";
    }
    for (int i = 0; i < NUM_BLANK_LINES; i++) {
        std::cout << blankLine << std::endl;
    }
    system("cls") ;
}


void bstMain(Data & data, BST & tree){
    int Option ;

    do{
        cout << "1. Add student \n"
                "2. Remove student\n"
                "3. Search student\n"
                "4. Print All (sorted by id)\n"
                "5. Return to main menu\n" ;

        cin >> Option ;

        switch(Option) {
            case 1: {
                int Id ;
                cout << "Id:" ;
                cin >> Id ;

                if (Id > 100 || Id < 0){
                    cout << "\nInvalid Id.\n\n";
                    break ;
                }
                if (tree.search(tree.getRoot(), Id)){
                    cout << "\nThe Id is already exist.\n\n";
                    break;
                }

                string Name ;
                cout << "Name:" ;
                cin.sync() ;
                getline(cin, Name) ;

                double GPA ;
                cout << "GPA:" ;
                cin >> GPA ;

                string Department ;
                cout << "Department:" ;
                cin >> Department ;

                Student stud = Student(Id, GPA, Name, Department) ;

                cout << "\nThe student is added.\n\n";
                tree.insert(Id);
                data.addStudent(stud);
                break;
            }
            case 2: {
                int Id;
                cout << "Id:";
                cin >> Id;

                if (tree.search(tree.getRoot(), Id)) {
                    cout << "Student is found.\n";
                    data.printStudent(Id) ;
                    cout << "\nStudent is deleted.\n\n" ;
                    tree.remove(tree.getRoot(), Id);
                    data.removeStudent(Id) ;
                }
                else {
                    cout << "Student is not found.\n\n";
                }
                break;
            }
            case 3: {
                int Id;
                cout << "Id:";
                cin >> Id;

                if (tree.search(tree.getRoot(), Id)) {
                    cout << "Student is found.\n";
                    data.printStudent(Id) ;
                    cout << '\n' ;
                }
                else {
                    cout << "Student is not found.\n\n";
                }

                break;
            }
            case 4: {
                tree.inOrder(tree.getRoot(), data) ;
                data.printDepartments() ;
                cout << '\n' ;
                break;
            }
            case 5:
                break;
            default:
                cout << "Invalid Option\n" ;
                break ;
        }
    } while (Option != 5) ;
}

# endif //BST_BST_H