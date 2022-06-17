#pragma once
#include <QObject>
#include <vector>
//#include <optional>

namespace services {
    class Service : public QObject {
        Q_OBJECT
    public:
        Service();
        ~Service() = 0;

        template <typename Func1>
        void inline broadcast(Func1 signal, const typename QtPrivate::FunctionPointer<Func2>::Object *receiver, Func2 slot) 
        {
            connect(this, signal, receiver, slot);
        }

        template <typename Func1>
        void inline listen(Func1 signal, const typename QtPrivate::FunctionPointer<Func2>::Object *sender, Func2 slot)
        {
            connect(sender, signal, this, slot);
        }

        template <typename Func1, typename Func2>
        void inline broadcastAndListen(Func1 signal, const typename QtPrivate::FunctionPointer<Func2>::Object *receiver, Func2 slot)
        {
            broadcast();
        }

    private:
        virtual void setup() = 0;

    };

} // namespace services