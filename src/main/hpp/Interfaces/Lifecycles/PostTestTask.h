#ifndef POST_TEST_TASK_H
#define POST_TEST_TASK_H


class PostTestTask {
public:
    virtual ~PostTestTask() = 0;
    virtual void postTest() = 0;
};


#endif