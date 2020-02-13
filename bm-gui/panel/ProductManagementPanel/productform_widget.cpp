#include "productform_widget.h"
#include "ui_entitywidget.h"
#include "ui_productform_widget.h"

using namespace std;
ProductFormWidget::ProductFormWidget(QWidget *parent) :
    EntityWidget(parent),
    productForm(new Ui::ProductFormWidget)
{
    productForm->setupUi(ui->frame_form);
    initIngredientTable();
    initLineEditable();
    initCalculableLine();
    setReadableOnly(true);

    connect(productForm->button_append,SIGNAL(clicked()),this,SLOT(on_createComposition()));
    connect(productForm->button_remove,SIGNAL(clicked()),this,SLOT(on_removeComposition()));
    connect(this,SIGNAL(entity_editingFinsih()),this,SLOT(on_updateStock()));
}

ProductFormWidget::~ProductFormWidget()
{
    delete productForm;
}

//------------- SLOTS -------------//

void ProductFormWidget::on_createComposition()
{
    SearchDialog *dialog=new SearchDialog(model,this);

    Product p;
    if(dialog->exec())
        ingredientTable->AppendObject(dialog->getVariant());
    delete dialog;
}

void ProductFormWidget::on_removeComposition()
{
    ingredientTable->remove();
}

void ProductFormWidget::on_updateStock()
{
    ProductBusiness business(model);
    Product p(model->data(selection->currentIndex(),AbstractListModel::VariantRole));
    business.stockManagement(p);
    business.setProductCapacity(p);
}

//------------- PRIVATE -------------//

void ProductFormWidget::initIngredientTable()
{
    ingredientTable=new IngredientTable(this);
    productForm->layout_table->addWidget(ingredientTable);
}
void ProductFormWidget::initCalculableLine()
{
    lineCalculable=new LineEditCalculable(this);
    productForm->layout_form->setWidget(3,QFormLayout::FieldRole,lineCalculable);
}

void ProductFormWidget::initLineEditable()
{
    productForm->line_name->setValidator(new QRegularExpressionValidator(QRegularExpression("^[a-zA-Z0-9 ]{1,50}$"),this));
    connect(productForm->line_name,&QLineEdit::textChanged,this,&ProductFormWidget::check_lineEdit_fields);
}

void ProductFormWidget::fillWidget()
{
    Product p;
    QModelIndex index;
    ingredientTable->clear();
    p.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));
    productForm->line_name->setText(p.getName());
    productForm->spin_price->setValue(static_cast<double>(p.getPrice().getValue()));
    lineCalculable->setText(QString::number(p.getCapacity()));
    productForm->spin_alarm->setValue(p.getAlarm());
    productForm->spin_stock->setValue(p.getStock());

    for(auto const&i:p.getIngredients())
    {
        index=model->getIndexById(i.getIngredient());
        ingredientTable->appendIngredient(model->data(index,AbstractListModel::Roles::VariantRole),i.getQuantity().getValue());
    }
}

void ProductFormWidget::fillEntity(QVariant &variant)
{
    Product p;
    vector<Ingredient> ingredients;
    QVariantList variantList;
    Ingredient ingredient;

    p.fromVariant(model->data(selection->currentIndex(),AbstractListModel::Roles::VariantRole));
    variantList=ingredientTable->build().toList();

    p.setName(productForm->line_name->text());
    p.setPrice(static_cast<float>(productForm->spin_price->value()));
    p.setCapacity(lineCalculable->text().toFloat());
    p.setAlarm(static_cast<int>(productForm->spin_alarm->value()));
    p.setPicture("null");

    for(auto const& v:variantList)
    {
        ingredient.fromVariant(v);
        ingredient.setProduct(p.getId());
        ingredients.push_back(ingredient);
    }
    p.setIngredients(ingredients);
    variant.setValue(p.toVariant());
}
void ProductFormWidget::setReadableOnly(bool value)
{
    EntityWidget::setReadableOnly(value);
    productForm->line_name->setReadOnly(value);
    productForm->spin_price->setReadOnly(value);
    lineCalculable->setReadOnly(value);
    productForm->spin_alarm->setReadOnly(value);
    productForm->frame_table->setEnabled(!value);
    productForm->frame->setEnabled(!value);
    //productForm->button_append->setEnabled(value);
    //productForm->button_remove->setEnabled(value);
}
//------------- PUBLIC -------------//
//-------- Getter & Setter ---------//
void ProductFormWidget::setSelectionModel(QItemSelectionModel *selection)
{
    EntityWidget::setSelectionModel(selection);
}





