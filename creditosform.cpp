#include "creditosform.h"
#include "ui_creditosform.h"

CreditosForm::CreditosForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CreditosForm)
{
    ui->setupUi(this);
    ui->lblUrl->setText("<a href='https://github.com/Mayerli12/Examen-POO'>https://github.com/Mayerli12/Examen-POO</a>");

    connect(ui->lblUrl, &QLabel::linkActivated, this, &CreditosForm::on_lblUrl_linkActivated);
}

CreditosForm::~CreditosForm()
{
    delete ui;
}

void CreditosForm::on_lblUrl_linkActivated(const QString &link)
{
    QDesktopServices::openUrl(QUrl(link));
}
