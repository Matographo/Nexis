#ifndef COMPILE_FAILURE_EVENT_H
#define COMPILE_FAILURE_EVENT_H


class CompileFailureEvent {
public:
    virtual ~CompileFailureEvent() = 0;
    virtual void onCompileFailure() = 0;
};


#endif