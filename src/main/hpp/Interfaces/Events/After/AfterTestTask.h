#ifndef AFTER_TEST_TASK_H
#define AFTER_TEST_TASK_H


class AfterTestTask {
public:
    virtual ~AfterTestTask() = 0;
    virtual int afterTest() = 0;
};


#endif