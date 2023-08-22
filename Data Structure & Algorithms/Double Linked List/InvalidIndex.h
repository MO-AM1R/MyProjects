#ifndef DOUBLE_LINKED_LIST_INVALIDINDEX_H
#define DOUBLE_LINKED_LIST_INVALIDINDEX_H
# include <iostream>
using namespace std ;

class InvalidIndex : public exception{
public:
    virtual const char* what() const noexcept{
        return "Invalid Index :(" ;
    }
};

#endif //DOUBLE_LINKED_LIST_INVALIDINDEX_H