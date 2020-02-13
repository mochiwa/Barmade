#include "supplier_widget.h"
#include "ui_supplier_widget.h"
#include "ui_entitywidget.h"

SupplierWidget::SupplierWidget(QWidget *parent) :
    EntityWidget (parent),
    supplierUi(new Ui::SupplierWidget)
{
    supplierUi->setupUi(ui->frame_form);
    cssFilename=":/css/employee_form.css";
    initLineEditable();
    updatStyleSheet();
}

SupplierWidget::~SupplierWidget()
{
    delete supplierUi;
}

void SupplierWidget::fillWidget()
{
    Supplier s;
    s.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));

    supplierUi->label_code->setText("#"+s.getCode());
    supplierUi->line_name->setText(s.getName());
    supplierUi->line_forename->setText(s.getForename());
    supplierUi->line_street->setText(s.getStreet().getName());
    supplierUi->line_number->setText(s.getStreet().getNumber());
    supplierUi->line_city->setText(s.getCity().getName());
    supplierUi->line_cp->setText(s.getCity().getCp());
    supplierUi->line_phone->setText(s.getPhone());
    supplierUi->line_fax->setText(s.getFax());
}

void SupplierWidget::fillEntity(QVariant &variant)
{
    Supplier s;
    City city;
    Street street;

    s.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));

    city=s.getCity();
    street=s.getStreet();

    s.setName(supplierUi->line_name->text());
    s.setForename(supplierUi->line_forename->text());
    s.setPhone(supplierUi->line_phone->text());

    street.setName(supplierUi->line_street->text());
    street.setNumber(supplierUi->line_number->text());
    city.setName(supplierUi->line_city->text());
    city.setCp(supplierUi->line_cp->text());
    s.setStreet(street);
    s.setCity(city);

    s.setPicture("null");

    s.setFax(supplierUi->line_fax->text());
    variant.setValue(s.toVariant());
}

void SupplierWidget::initLineEditable()
{
    lineEdits=supplierUi->frame->findChildren<QLineEdit*>();
    foreach(auto* line,lineEdits)
    {
        if(line!=supplierUi->line_phone && line!=supplierUi->line_fax)
            line->setValidator(new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9 ]{1,50}$"),this));
        connect(line,&QLineEdit::textChanged,this,&SupplierWidget::check_lineEdit_fields);
    }
}
