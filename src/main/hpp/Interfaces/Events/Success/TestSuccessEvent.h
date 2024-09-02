#ifndef TEST_SUCCESS_EVENT_H
#define TEST_SUCCESS_EVENT_H


class TestSuccessEvent {
public:
    virtual ~TestSuccessEvent() = 0;
    virtual int onTestSuccess() = 0;
};


#endif