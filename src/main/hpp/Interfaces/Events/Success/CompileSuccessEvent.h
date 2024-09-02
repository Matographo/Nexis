#ifndef COMPILE_SUCCESS_EVENT_H
#define COMPILE_SUCCESS_EVENT_H


class CompileSuccessEvent {
public:
    virtual ~CompileSuccessEvent() = 0;
    virtual void onCompileSuccess() = 0;
};


#endif