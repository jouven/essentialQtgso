#ifndef ESSENTIALQTGSO_MESSAGEBOX_HPP
#define ESSENTIALQTGSO_MESSAGEBOX_HPP

#include "crossPlatformMacros.hpp"

#include <QString>
#include <QWidget>

class QMessageBox;

//all, except the warning one, "message windws" destroy themselves on close
//or if the parent is set when the parent does, don't know how Qt deals
// with the case if a windows is left open and the main function finishes (leak?)

//these are just to spawn simple messages with an "OK" button
EXPIMP_ESSENTIALQTGSO void plainQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par = nullptr
);
EXPIMP_ESSENTIALQTGSO void informationQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Information"
        , QWidget* parent_par = nullptr
);
EXPIMP_ESSENTIALQTGSO void errorQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Error"
        , QWidget* parent_par = nullptr
);
//has an "OK" and a "Cancel" buttons
//return the object so it can be connected to get the results after
//this way it doesn't block the main thread
EXPIMP_ESSENTIALQTGSO QMessageBox* warningQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Warning"
        , QWidget* parent_par = nullptr
);

#endif // ESSENTIALQTGSO_MESSAGEBOX_HPP
