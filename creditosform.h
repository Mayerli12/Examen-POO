#ifndef CREDITOSFORM_H
#define CREDITOSFORM_H

#include <QWidget>
#include <QDesktopServices>
#include <QUrl>

namespace Ui {
class CreditosForm;
}

class CreditosForm : public QWidget
{
    Q_OBJECT

public:
    explicit CreditosForm(QWidget *parent = nullptr);
    ~CreditosForm();

private:
    Ui::CreditosForm *ui;

private slots:
    void on_lblUrl_linkActivated(const QString &link);
};
#endif
