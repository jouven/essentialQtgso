#ifndef ESSENTIALQTGSO_MESSAGEBOX_HPP
#define ESSENTIALQTGSO_MESSAGEBOX_HPP

#include <QString>
#include <QWidget>

//these are just to spawn simple messages with an "OK" button
void plainQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par = Q_NULLPTR
);
void informationQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Information"
        , QWidget* parent_par = Q_NULLPTR
);
void errorQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Error"
        , QWidget* parent_par = Q_NULLPTR
);
//return value true = Ok/Continue, false = cancel
bool warningQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con = "Warning"
        , QWidget* parent_par = Q_NULLPTR
);

#endif // ESSENTIALQTGSO_MESSAGEBOX_HPP
