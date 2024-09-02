#ifndef PRE_TEST_TASK_H
#define PRE_TEST_TASK_H


class PreTestTask {
public:
    virtual ~PreTestTask() = 0;
    virtual int preTest() = 0;
};


#endif