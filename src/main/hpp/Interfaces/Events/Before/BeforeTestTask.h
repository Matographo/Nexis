#ifndef BEFORE_TEST_TASK_H
#define BEFORE_TEST_TASK_H


class BeforeTestTask {
public:
    virtual ~BeforeTestTask() = 0;
    virtual void beforeTest() = 0;
};


#endif