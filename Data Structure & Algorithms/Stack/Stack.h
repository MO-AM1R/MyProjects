# ifndef STACK_STACK_H
# define STACK_STACK_H

# include "DoubleLinkedList.h"
# include <iomanip>
#include <vector>

using namespace std ;

template <class T>
class Stack {
private:
    DoubleLinkedList<T> data ;

public:
    Stack() = default;

    [[nodiscard]] bool isEmpty() {return !data.doubleLinkedListSize() ;}

    [[nodiscard]] int stackSize() {return data.doubleLinkedListSize() ;}

    void push(const T value){
        data.insertAtHead(value) ;
    }

    T pop(){
        if (isEmpty()){
            cerr << "Stack is empty :(\n" ;
        }
        else {
            T element = data.retrieveAt(0);
            data.removeAtHead();
            return element;
        }
    }

    void clear(){
        if (isEmpty()){
            return;
        }
        data.clear() ;
    }

    [[nodiscard]] T top(){
        if (isEmpty()){
            cerr << "Stack is empty :(\n" ;
        }
        else {
            return data.retrieveAt(0);
        }
    }

    void print(){
        if (isEmpty()){
            cout << "[\n]" ;
            return ;
        }

        cout << setw(8) << setfill('-') << "-" ;
        cout << "\n" ;

        for (int i = 0; i < stackSize(); ++i) {
            cout << "|" << left << setw(3) << setfill(' ') << "" ;
            cout << data.retrieveAt(i) << left << setw(3 - to_string(data.retrieveAt(i)).size())
                << setfill(' ') << "";
            cout << "|\n" ;
        }
        cout << setw(8) << setfill('-') << "-" ;
        cout << '\n' ;
    }
};

int longestParentheses(const string & Expiration){
    Stack<int> S ;
    S.push(-1) ;
    int Number = 0 ;

    for (int i = 0; i < Expiration.size(); ++i) {
        if (Expiration[i] == '<'){
            S.push(i) ;
        }
        else{
            S.pop() ;
            if (S.isEmpty()){
                S.push(i) ;
            }
            else{
                Number = max(Number, i - S.top());
            }
        }
    }

    return Number ;
}

int weight(const char & oper)
{
    if(oper == '+' || oper == '-')
    return 1;
    if(oper == '*' || oper == '/')
    return 2;
    if(oper == '^')
        return 3;

    return 0;
}

void infix_to_postfix(const string &exp)
{
    Stack<char>s;
    vector<char>vec;
    for (int i = 0; i < exp.size(); ++i) {
        if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp [i] == '/' ||exp[i] == '^') {
            if (!s.isEmpty()) {
                if (weight(exp[i]) > weight(s.top()))
                    s.push(exp[i]);
                else if(weight(exp[i]) == 0)
                {
                    cerr<<"invalid expression"<<endl;
                    return;
                }
                else {
                    while(!s.isEmpty())
                    {
                        vec.push_back(s.top());
                        s.pop();
                    }
                    s.push(exp[i]);
                }
            }
            else {
                s.push(exp[i]);
            }
        }
        else if (exp[i] == '(') {
            s.push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (!s.isEmpty() && s.top() != '(') {
                vec.push_back(s.top());
                s.pop();
            }
            if (s.isEmpty()) {
                cerr << "Invalid expression" << endl;
                return;
            }
            s.pop();
        }
        else if(exp[i] == ' ')
            continue;
        else {
            vec.push_back(exp[i]);
        }
    }
    while(!s.isEmpty())
    {
        vec.push_back(s.top());
        s.pop();
    }
    for (char i : vec) {
        cout << i;
    }
}

bool checkPalindrome(Stack<char> & stack, const string & str){
    int flag = -1 ;
    if (str.size() % 2 != 0){
        flag = (int)str.size() / 2 ;
    }

    for (int i = 0; i < str.size(); ++i) {
        if (flag == i){
            continue;
        }
        if (isspace(str[i])){
            continue;
        }

        if ((!stack.isEmpty() && stack.top() == str[i])){
            stack.pop() ;
        }
        else{
            stack.push(str[i]) ;
        }
    }

    return stack.isEmpty() ;
}

#endif //STACK_STACK_H