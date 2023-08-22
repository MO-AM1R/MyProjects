#ifndef STACK_EMPTY_H
#define STACK_EMPTY_H

# include <iostream>
using namespace std ;

class StackEmpty : public exception{
public:
    virtual const char* what() const noexcept{
        return "The Stack is empty :(" ;
    }
};
#endif //STACK_EMPTY_H