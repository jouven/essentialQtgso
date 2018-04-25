#include "messageBox.hpp"

#include <QMessageBox>

void plainQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox informationMessageBoxTmp(parent_par);
    informationMessageBoxTmp.setWindowTitle(title_par_con);
    informationMessageBoxTmp.setText(message_par_con);

    informationMessageBoxTmp.exec();
}

void informationQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox informationMessageBoxTmp(parent_par);
    informationMessageBoxTmp.setWindowTitle(title_par_con);
    informationMessageBoxTmp.setText(message_par_con);
    informationMessageBoxTmp.setIcon(QMessageBox::Information);

    informationMessageBoxTmp.exec();
}

void errorQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox errorMessageBoxTmp(parent_par);
    errorMessageBoxTmp.setWindowTitle(title_par_con);
    errorMessageBoxTmp.setText(message_par_con);
    errorMessageBoxTmp.setIcon(QMessageBox::Critical);

    errorMessageBoxTmp.exec();
}

bool warningQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    bool resultTmp;
    QMessageBox warningMessageBoxTmp(parent_par);
    warningMessageBoxTmp.setWindowTitle(title_par_con);
    warningMessageBoxTmp.setText(message_par_con);
    warningMessageBoxTmp.setIcon(QMessageBox::Warning);
    warningMessageBoxTmp.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);

    auto ret(warningMessageBoxTmp.exec());

    resultTmp = (ret == QMessageBox::Ok);

    return resultTmp;
}
