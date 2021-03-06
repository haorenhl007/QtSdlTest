#ifndef SDLEVENTTHREAD_H
#define SDLEVENTTHREAD_H

#include <QThread>
#include <QMetaType>
#include <SDL_events.h>

Q_DECLARE_METATYPE(SDL_Event)
Q_DECLARE_METATYPE(SDL_JoyAxisEvent)
Q_DECLARE_METATYPE(SDL_JoyHatEvent)
Q_DECLARE_METATYPE(SDL_JoyButtonEvent)

class SdlEventThread : public QThread
{
    Q_OBJECT

public:
    explicit SdlEventThread(QObject *parent = 0);
    void stop();

signals:
    void axisEvent(SDL_JoyAxisEvent event);
    void hatEvent(SDL_JoyHatEvent event);
    void joyButtonEvent(SDL_JoyButtonEvent event);
    void joyDeviceAdded(SDL_JoyDeviceEvent event);
    void joyDeviceRemoved(SDL_JoyDeviceEvent event);
    void sdlEvent(SDL_Event event);

public slots:

protected:
    virtual void run();
};

#endif // SDLEVENTTHREAD_H
