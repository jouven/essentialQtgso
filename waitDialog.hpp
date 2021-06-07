#ifndef ESSENTIALQTGSO_WAITDIALOG_HPP
#define ESSENTIALQTGSO_WAITDIALOG_HPP

#include "crossPlatformMacros.hpp"

#include "textQtso/text.hpp"

#include <QString>
#include <QWidget>

class QLabel;
class QTimer;

//class to create waiting dialogs, two types elapsed time and specific time
class waitDialog_c : public QWidget
{
    Q_OBJECT

public:
    enum class waitType_ec
    {
        empty = 0
        //undefined waiting, just shows how much time has passed
        , elapsed = 1
        //defined waiting
        , specific = 2
    };

    enum class waitFormat_ec
    {
        empty = 0
        //5d 24:59:59.999, milliseconds won't show up if = 000
        , time = 1
        //milliseconds and seconds require replacing waitMessage_pri just to tell the unit and if needed to translate it
        , milliSeconds = 2
        , seconds = 3
    };
private:
    waitType_ec waitType_pri = waitType_ec::empty;
    waitFormat_ec waitFormat_pri = waitFormat_ec::time;
    int_fast64_t waitTimeUpdateDisplayIntervalMs_pri = 1000;
    int_fast64_t waitTimeMs_pri = -1;
    int_fast64_t currentWaitTimeMs_pri = 0;
    //emit signal on every wait time update interval
    bool emitSignalOnUpdate_pri = false;

    //default value just shows the wait/elapsed time, "{0}" is the placeholder for the time value
    text_c waitMessage_pri = "{0}";
    //if it needs to be something else because there are other placeholder-values
    int_fast64_t replaceIndexWithWaitTimeValue_pri = 0;

    //only shows the time not the waitMessage
    bool showWaitTimeOnWindowsTitle_pri = true;

    QLabel* waitMessageLabel_pri = nullptr;
    QTimer* waitTimer_pri = nullptr;
public:
    waitDialog_c() = delete;
    //intializes the variables without changing the widget
    waitDialog_c(
            QWidget* parent_par
            , const waitType_ec waitType_par_con
            //elapsed wait type ignores this, also if it's less than the waitTimeUpdateDisplayIntervalMs_pri, waitTimeUpdateDisplayIntervalMs_pri = waitTimeMs_pri
            , const int_fast64_t waitTimeMs_par_con
    );

    //creates the label (and some layouts)
    void createWidgets_f();

    waitType_ec waitType_f() const;
    void setWaitType_f(const waitType_ec waitType_par_con);

    waitFormat_ec waitFormat_f() const;
    void setWaitFormat_f(const waitFormat_ec waitFormat_par_con);

    int_fast64_t waitTimeUpdateDisplayIntervalMs_f() const;
    //going below 1ms might block the main thread
    void setWaitTimeUpdateDisplayIntervalMs_f(const int_fast64_t& value);

    int_fast64_t waitTimeMs_f() const;
    void setWaitTimeMs_f(const int_fast64_t& value);

    text_c waitMessage_f() const;

    bool showWaitTimeOnWindowsTitle_f() const;
    void setShowWaitTimeOnWindowsTitle_f(bool value);

    int_fast64_t replaceIndexWithWaitTimeValue_f() const;
    void setReplaceIndexWithWaitTimeValue_f(const int_fast64_t& value);

    int_fast64_t currentWaitTimeMs_f() const;

    bool emitSignalOnUpdate_f() const;
    void setEmitSignalOnUpdate_f(bool value);

Q_SIGNALS:
    void waitStart_signal();
    //for specific time
    void waitFinished_signal();
    void waitUpdate_signal(int_fast64_t elapsedDurationMs_par_con);
public Q_SLOTS:
    //message should be translated prior
    void setWaitMessage_f(const text_c& message_par_con);
    //sets the wait timer interval, calls updateMessage_f once and starts the timer
    void startWaiting_f();
    void stopWaiting_f();
private Q_SLOTS:
    //updates the time displayed and then modifies the wait time value
    void updateMessage_f();
};

#endif // ESSENTIALQTGSO_WAITDIALOG_HPP
