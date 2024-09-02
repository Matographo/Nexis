#ifndef TEST_FAILURE_EVENT_H
#define TEST_FAILURE_EVENT_H


class TestFailureEvent {
public:
    virtual ~TestFailureEvent() = 0;
    virtual void onTestFailure() = 0;
};


#endif