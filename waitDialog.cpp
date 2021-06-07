#include "waitDialog.hpp"

#include "essentialQtso/datetime.hpp"

#include <QVBoxLayout>
#include <QLabel>
#include <QTimer>

waitDialog_c::waitFormat_ec waitDialog_c::waitFormat_f() const
{
    return waitFormat_pri;
}

void waitDialog_c::setWaitFormat_f(const waitFormat_ec waitFormat_par_con)
{
    waitFormat_pri = waitFormat_par_con;
}

int_fast64_t waitDialog_c::waitTimeUpdateDisplayIntervalMs_f() const
{
    return waitTimeUpdateDisplayIntervalMs_pri;
}

void waitDialog_c::setWaitTimeUpdateDisplayIntervalMs_f(const int_fast64_t& value)
{
    waitTimeUpdateDisplayIntervalMs_pri = value;
}

int_fast64_t waitDialog_c::waitTimeMs_f() const
{
    return waitTimeMs_pri;
}

void waitDialog_c::setWaitTimeMs_f(const int_fast64_t& value)
{
    waitTimeMs_pri = value;
}

text_c waitDialog_c::waitMessage_f() const
{
    return waitMessage_pri;
}

void waitDialog_c::setWaitMessage_f(const text_c& value)
{
    waitMessage_pri = value;
}

void waitDialog_c::startWaiting_f()
{
    if (waitType_pri == waitDialog_c::waitType_ec::specific)
    {
        currentWaitTimeMs_pri = waitTimeMs_pri;
    }
    else
    {
        currentWaitTimeMs_pri = 0;
    }

    if (waitTimer_pri == nullptr)
    {
        waitTimer_pri = new QTimer(this);
    }
    else
    {
        waitTimer_pri->stop();
    }
    waitTimer_pri->setInterval(waitTimeUpdateDisplayIntervalMs_pri);
    QObject::connect(waitTimer_pri, &QTimer::timeout, this, &waitDialog_c::updateMessage_f, Qt::UniqueConnection);
    updateMessage_f();
    waitTimer_pri->start();
    Q_EMIT waitStart_signal();
}

void waitDialog_c::stopWaiting_f()
{
    waitTimer_pri->stop();
}

void waitDialog_c::updateMessage_f()
{
    QString valueFormatTmp;
    while (true)
    {
        if (waitFormat_pri == waitFormat_ec::time)
        {
            valueFormatTmp = formatedTime_f(currentWaitTimeMs_pri);
            break;
        }
        if (waitFormat_pri == waitFormat_ec::milliSeconds)
        {
            valueFormatTmp = QString::number(currentWaitTimeMs_pri);
            break;
        }

        if (waitFormat_pri == waitFormat_ec::seconds)
        {
            valueFormatTmp = QString::number(currentWaitTimeMs_pri / 1000);
            break;
        }

        break;
    }

    waitMessage_pri.setReplacement_f(valueFormatTmp, replaceIndexWithWaitTimeValue_pri);

    waitMessageLabel_pri->setText(waitMessage_pri.rawReplace_f());

    if (showWaitTimeOnWindowsTitle_pri)
    {
        setWindowTitle(valueFormatTmp);
    }
    else
    {
        //doesn't put anything on the windows title, setWindowTitle is public and something else can be put
    }

    if (emitSignalOnUpdate_pri)
    {
        Q_EMIT waitUpdate_signal(currentWaitTimeMs_pri);
    }

    if (waitType_pri == waitDialog_c::waitType_ec::specific)
    {
        currentWaitTimeMs_pri = currentWaitTimeMs_pri - waitTimeUpdateDisplayIntervalMs_pri;
        if (currentWaitTimeMs_pri <= 0)
        {
            Q_EMIT waitFinished_signal();
            waitTimer_pri->stop();
        }
    }
    else
    {
        currentWaitTimeMs_pri = currentWaitTimeMs_pri + waitTimeUpdateDisplayIntervalMs_pri;
    }
}

bool waitDialog_c::showWaitTimeOnWindowsTitle_f() const
{
    return showWaitTimeOnWindowsTitle_pri;
}

void waitDialog_c::setShowWaitTimeOnWindowsTitle_f(bool value)
{
    showWaitTimeOnWindowsTitle_pri = value;
}

int_fast64_t waitDialog_c::replaceIndexWithWaitTimeValue_f() const
{
    return replaceIndexWithWaitTimeValue_pri;
}

void waitDialog_c::setReplaceIndexWithWaitTimeValue_f(const int_fast64_t& value)
{
    replaceIndexWithWaitTimeValue_pri = value;
}

int_fast64_t waitDialog_c::currentWaitTimeMs_f() const
{
    return currentWaitTimeMs_pri;
}

bool waitDialog_c::emitSignalOnUpdate_f() const
{
    return emitSignalOnUpdate_pri;
}

void waitDialog_c::setEmitSignalOnUpdate_f(bool value)
{
    emitSignalOnUpdate_pri = value;
}

waitDialog_c::waitDialog_c(
        QWidget* parent_par
        , const waitDialog_c::waitType_ec waitType_par_con
        , const int_fast64_t waitTimeMs_par_con)
    : QWidget(parent_par)
    , waitType_pri(waitType_par_con)
    , waitTimeMs_pri(waitTimeMs_par_con)
{
    setObjectName("waitDialog_");
    setWindowFlag(Qt::Window, true);
    setWindowModality(Qt::WindowModal);
    setAttribute(Qt::WA_DeleteOnClose);
    if (waitType_par_con == waitDialog_c::waitType_ec::specific and waitTimeMs_pri < waitTimeUpdateDisplayIntervalMs_pri)
    {
        waitTimeUpdateDisplayIntervalMs_pri = (waitTimeMs_pri == 0 ? 1 : waitTimeMs_pri);
    }
}

void waitDialog_c::createWidgets_f()
{
    QHBoxLayout* firstRowLayoutTmp(new QHBoxLayout);

    waitMessageLabel_pri = new QLabel;
    firstRowLayoutTmp->addWidget(waitMessageLabel_pri);

    QVBoxLayout* mainLayoutTmp(new QVBoxLayout);
    mainLayoutTmp->addLayout(firstRowLayoutTmp);

    this->setLayout(mainLayoutTmp);
}

waitDialog_c::waitType_ec waitDialog_c::waitType_f() const
{
    return waitType_pri;
}

void waitDialog_c::setWaitType_f(const waitType_ec waitType_par_con)
{
    waitType_pri = waitType_par_con;
}
