# include "Classes/Data.h"
# include "Classes/BST.h"
# include "Classes/AVL.h"

void loadFromFile(Data & data, BST & bst, AVL & avl){
    fstream File ;
    File.open("Users.txt") ;

    string output ;
    getline(File, output) ;

    while (File.peek() != EOF){
        Student student ;

        getline(File, output) ;
        student.setId(stoi(output)) ;

        getline(File, output) ;
        student.setName(output) ;

        getline(File, output) ;
        student.setGpa(stod(output)) ;

        getline(File, output) ;
        student.setDepartment(output) ;

        data.addStudent(student) ;
        bst.insert(student.getId());
        avl.insert(student.getId()) ;
    }
    File.close();
}

int main() {
    Data data1 ;
    AVL avl ;
    BST bst ;
    loadFromFile(data1, bst, avl) ;

    while (true){
        cout << "1. BST\n"
                "2. AVL\n"
                "3. Min Heap\n"
                "4. Max Heap\n"
                "5. Exit Program\n";

        int option ;
        cin >> option ;

        if (option == 1){
            bstMain(data1, bst) ;
        }
        else if (option == 2){
            avlMain(data1, avl) ;
        }
        else if(option == 3){
            /*
             *  Min Heap
             */
        }
        else if(option == 3){
            /*
             *  Max Heap
             */
        }
        else if (option == 5){
            exit(0) ;
        }
        else{
            cout << "Invalid input :(\n" ;
        }
    }
}