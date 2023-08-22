# ifndef DOUBLE_LINKED_LIST_EMPTY_H
# define DOUBLE_LINKED_LIST_EMPTY_H
# include <iostream>
using namespace std ;

class Empty : public exception{
public:
    virtual const char* what() const noexcept{
        return "The List is empty :(" ;
    }
};

#endif //DOUBLE_LINKED_LIST_EMPTY_H