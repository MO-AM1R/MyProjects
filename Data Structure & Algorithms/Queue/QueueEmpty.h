# ifndef QUEUE_QUEUEEMPTY_H
# define QUEUE_QUEUEEMPTY_H
# include <iostream>
using namespace std ;

class QueueEmpty : public exception{
public:
    virtual const char* what() const noexcept{
        return "The Queue is empty :(" ;
    }
};

#endif //QUEUE_QUEUEEMPTY_H