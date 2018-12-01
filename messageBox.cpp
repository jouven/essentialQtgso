#include "messageBox.hpp"

#include <QMessageBox>

void plainQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox* informationMessageBoxPtrTmp(new QMessageBox(parent_par));
    informationMessageBoxPtrTmp->setAttribute(Qt::WA_DeleteOnClose);
    informationMessageBoxPtrTmp->setWindowTitle(title_par_con);
    informationMessageBoxPtrTmp->setText(message_par_con);
    informationMessageBoxPtrTmp->setModal(Qt::WindowModal);

    informationMessageBoxPtrTmp->show();
}

void informationQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox* informationMessageBoxPtrTmp(new QMessageBox(parent_par));
    informationMessageBoxPtrTmp->setAttribute(Qt::WA_DeleteOnClose);
    informationMessageBoxPtrTmp->setWindowTitle(title_par_con);
    informationMessageBoxPtrTmp->setText(message_par_con);
    informationMessageBoxPtrTmp->setIcon(QMessageBox::Information);
    informationMessageBoxPtrTmp->setModal(Qt::WindowModal);

    informationMessageBoxPtrTmp->show();
}

void errorQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox* errorMessageBoxPtrTmp(new QMessageBox(parent_par));
    errorMessageBoxPtrTmp->setAttribute(Qt::WA_DeleteOnClose);
    errorMessageBoxPtrTmp->setWindowTitle(title_par_con);
    errorMessageBoxPtrTmp->setText(message_par_con);
    errorMessageBoxPtrTmp->setIcon(QMessageBox::Critical);
    errorMessageBoxPtrTmp->setModal(Qt::WindowModal);

    errorMessageBoxPtrTmp->show();
}

QMessageBox* warningQMessageBox_f(
        const QString& message_par_con
        , const QString& title_par_con
        , QWidget* parent_par
)
{
    QMessageBox* warningMessageBoxPtrTmp(new QMessageBox(parent_par));
    //don't delete on close since the results are checked after
    //warningMessageBoxPtrTmp->setAttribute(Qt::WA_DeleteOnClose);
    warningMessageBoxPtrTmp->setWindowTitle(title_par_con);
    warningMessageBoxPtrTmp->setText(message_par_con);
    warningMessageBoxPtrTmp->setIcon(QMessageBox::Warning);
    warningMessageBoxPtrTmp->setModal(Qt::WindowModal);
    warningMessageBoxPtrTmp->setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    return warningMessageBoxPtrTmp;
}
