# ifndef AVL_AVL_H
# define AVL_AVL_H
# include <iostream>
using namespace std ;

template<class type>
struct Node{
    Node* right ;
    Node* left ;
    type info ;
    int height{} ;
    explicit Node() = default ;
    Node(Node* r, Node* l, type i, int h) : right(r), left(l), info(i), height(h) {}
};

template<class type>
class AVL {
private:
    Node<type>* root ;

    void inOrder(Node<type>* _root) {
        if (_root){
            inOrder(_root->left);
            cout << _root->info << " ";
            inOrder(_root->right);
        }
    }

    void preOrder(Node<type>* _root) {
        if(_root){
            cout << _root->info << " ";
            preOrder(_root->left);
            preOrder(_root->right);
        }
    }

    void postOrder(Node<type>* _root) {
        if (_root){
            postOrder(_root->left);
            postOrder(_root->right);
            cout << _root->info << " ";
        }
    }

    int getHeight(Node<type>* _root){
        if (!_root) {
            return 0;
        }
        return _root->height ;
    }

    int balanceFactor(Node<type>* _root){
        if (!_root){
            return 0 ;
        }
        return getHeight(_root->left) - getHeight(_root->right) ;
    }

    Node<type>* rightRotation(Node<type>* _root){
        Node<type>* temp = _root->left ;
        _root->left = temp->right ;
        temp->right = _root ;

        _root->height = max(getHeight(_root->left), getHeight(_root->right)) + 1 ;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1 ;

        return temp ;
    }

    Node<type>* leftRotation(Node<type>*  _root){
        Node<type>* temp = _root->right ;
        _root->right = temp->left ;
        temp->left = _root ;

        _root->height = max(getHeight(_root->left), getHeight(_root->right)) + 1 ;
        temp->height = max(getHeight(temp->left), getHeight(temp->right)) + 1 ;

        return temp ;
    }

    Node<type>* add(Node<type>* _root, type ele){
        if (!_root){
            return new Node<type> (nullptr, nullptr, ele, 1) ;
        }
        else if (ele > _root->info){
            _root->right = add(_root->right, ele) ;
        }
        else if (ele < _root->info){
            _root->left = add(_root->left, ele) ;
        }
        else{
            return _root ;
        }

        _root->height = max(getHeight(_root->right), getHeight(_root->left)) + 1 ;
        int balance = balanceFactor(_root) ;

        if (balance > 1){
            if (ele < _root->left->info){
                return rightRotation(_root) ;
            }
            else if (ele > _root->left->info){
                _root->left = leftRotation(_root->left) ;
                return rightRotation(_root) ;
            }
        }
        else if (balance < -1){
            if (ele > _root->right->info){
                return leftRotation(_root) ;
            }
            else if (ele < _root->right->info){
                _root->right = rightRotation(_root->right) ;
                return leftRotation(_root) ;
            }
        }

        return _root ;
    }

    Node<type>* findMinimum(Node<type>* _root){
        if (!_root->left){
            return _root ;
        }

        return findMinimum(_root->left) ;
    }

    Node<type>* _delete(Node<type>* _root, type ele){
        if (!_root){
            return _root ;
        }
        else if (ele > _root->info){
            _root->right = _delete(_root->right, ele) ;
        }
        else if (ele < _root->info){
            _root->left = _delete(_root->left, ele) ;
        }
        else{
            if (!_root->right ||
                !_root->left){

                Node<type>* temp = _root->left ? _root->left : _root->right ;

                if (!temp){
                    temp = _root ;
                    _root = nullptr ;
                }
                else{
                    *_root = *temp ;
                }

                delete temp ;
            }
            else{
                Node<type>* temp = findMinimum(_root->right) ;

                _root->info = temp->info ;
                _root->right = _delete(_root->right, ele) ;
            }
        }

        if (!_root){
            return _root ;
        }

        _root->height = max(getHeight(_root->right), getHeight(_root->left)) + 1 ;
        int balance = balanceFactor(_root) ;

        if (balance > 1){
            if (balanceFactor(_root->left) >= 0){
                return rightRotation(_root) ;
            }
            else{
                _root->left = leftRotation(_root->left) ;
                return rightRotation(_root) ;
            }
        }
        else if (balance < -1){
            if (balanceFactor(_root->right) <= 0){
                return leftRotation(_root) ;
            }
            else{
                _root->right = rightRotation(_root->right) ;
                return leftRotation(_root) ;
            }
        }

        return _root ;
    }

public:
    AVL() = default ;

    void insert(type ele){
        this->root = add(this->root, ele) ;
    }

    void remove(type ele){
        root = _delete(root, ele) ;
    }

    void inOrder() {
        cout << "inOrder -> " ;
        inOrder(root) ;
    }

    void preOrder() {
        cout << "preOrder -> " ;
        preOrder(root) ;
    }

    void postOrder() {
        cout << "postOrder -> " ;
        postOrder(root) ;
    }
};

# endif //AVL_AVL_H