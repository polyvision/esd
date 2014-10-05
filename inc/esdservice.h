#ifndef ESDSERVICE_H
#define ESDSERVICE_H


#include "../qtservice/qtservice.h"

#define STATE_DAEMON 666
#define STATE_ADMIN 100

class EsdService : public QtService<QCoreApplication>
{
    Q_OBJECT
public:
    EsdService(int argc, char **argv);
    ~EsdService();

protected:

    void start();
    void stop();
    void pause();
    void resume();
    void processCommand(int code);

    int mi_state;
};

#endif // ESDSERVICE_H
