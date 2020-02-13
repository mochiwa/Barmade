#include "employee_widget.h"
#include "ui_employee_widget.h"
#include "ui_entitywidget.h"

EmployeeWidget::EmployeeWidget(QWidget *parent) :
    EntityWidget(parent),
    employeeUi(new Ui::EmployeeWidget)
{
    employeeUi->setupUi(ui->frame_form);
    cssFilename=":/css/employee_form.css";
    initLineEditable();
    updatStyleSheet();
    initPicture();
}

EmployeeWidget::~EmployeeWidget()
{
    delete employeeUi;
}

//------------- PRIVATE -------------//

void EmployeeWidget::initPicture()
{
    QPixmap p=*employeeUi->label_picture->pixmap();
    employeeUi->label_picture->setPixmap(p.scaled(100,100,Qt::KeepAspectRatio));
}
void EmployeeWidget::initLineEditable()
{
    lineEdits=employeeUi->frame->findChildren<QLineEdit*>();
    foreach(auto* line,lineEdits)
    {
        if(line!=employeeUi->line_phone)
            line->setValidator(new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9 ]{1,50}$"),this));
        connect(line,&QLineEdit::textChanged,this,&EmployeeWidget::check_lineEdit_fields);
    }
}

void EmployeeWidget::setReadableOnly(bool value)
{
    EntityWidget::setReadableOnly(value);
    employeeUi->comboBox_rank->setEnabled(!value);
    employeeUi->line_salary->setReadOnly(value);
    employeeUi->line_birthday->setReadOnly(value);
}



//------------- PUBLIC -------------//

void EmployeeWidget::fillWidget()
{
    Employee e;
    e.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));
    employeeUi->label_code->setText("#"+e.getCode());
    employeeUi->line_name->setText(e.getName());
    employeeUi->line_forename->setText(e.getForename());
    employeeUi->line_birthday->setDate(e.getBirthday());
    employeeUi->line_street->setText(e.getStreet().getName());
    employeeUi->line_number->setText(e.getStreet().getNumber());
    employeeUi->line_city->setText(e.getCity().getName());
    employeeUi->line_cp->setText(e.getCity().getCp());
    employeeUi->line_phone->setText(e.getPhone());
    employeeUi->line_salary->setValue(static_cast<double>(e.getSalary()));
    for(int i=0;i<employeeUi->comboBox_rank->count();++i)
        if(!employeeUi->comboBox_rank->itemText(i).compare(e.getType().getName()))
            employeeUi->comboBox_rank->setCurrentIndex(i);
}

void EmployeeWidget::fillEntity(QVariant &variant)
{
    Employee e;
    City city;
    Street street;
    TypeEmployee type;

    e.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));
    city=e.getCity();
    street=e.getStreet();
    type=e.getType();

    e.setName(employeeUi->line_name->text());
    e.setForename(employeeUi->line_forename->text());
    e.setPhone(employeeUi->line_phone->text());
    e.setBirthday(employeeUi->line_birthday->date());

    street.setName(employeeUi->line_street->text());
    street.setNumber(employeeUi->line_number->text());
    city.setName(employeeUi->line_city->text());
    city.setCp(employeeUi->line_cp->text());
    e.setStreet(street);
    e.setCity(city);

    e.setPicture("null");

    e.setSalary(static_cast<float>(employeeUi->line_salary->value()));
    type.setName(employeeUi->comboBox_rank->currentText());
    e.setType(type);
    variant.setValue(e.toVariant());
}
//-------- Getter & Setter ---------//
