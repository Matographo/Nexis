#ifndef TEST_TASK_H
#define TEST_TASK_H


class TestTask {
public:
    virtual ~TestTask() = 0;
    virtual int test() = 0;
};


#endif