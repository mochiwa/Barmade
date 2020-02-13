#include <QtTest>
#include <QCoreApplication>

#include "models/product_model.h"
#include "business/productbusiness.h"
#include "entities/product.h"
#include "vector"

using namespace std;
class StackManagementUsecase : public QObject
{
    Q_OBJECT

public:
    StackManagementUsecase();
    ~StackManagementUsecase();
private:
    ProductBusiness *business;
    Product coca_crate;
    Product fanta_crate;
    Product whiskey_bottle;
    Product coca;
    Product fanta;
    Product whiskey_coca_fanta;

    ProductModel *model;

    void initCoca_crate();
    void initFanta_crate();
    void initWiskeyBottle();
    void initCoca();
    void initFanta();
    void initWhiskeyCocaFanta();

    void updateModel(const Product& p);

private slots:
    void test_get_stock_by_capacity_simpleProduct();
    void test_get_Product_By_Tiny_Stock();
    void test_get_stock_by_capacity_complexProduct();
    void test_get_Product_By_Tiny_Stock_Used();
    void test_get_stock_by_unity();
    void test_increase_used();
    void test_increase_the_remainder();


};


StackManagementUsecase::StackManagementUsecase()
{
    model=new ProductModel(this);
    business=new ProductBusiness(model,this);

    initCoca_crate();
    initFanta_crate();
    initWiskeyBottle();
    initCoca();
    initFanta();
    initWhiskeyCocaFanta();
}

StackManagementUsecase::~StackManagementUsecase()
{
}

void StackManagementUsecase::initCoca_crate()
{
    coca_crate.setId(51);
    coca_crate.setName("coca_crate");
    coca_crate.setCapacity(24*33);//24 bottle of 33cl
    coca_crate.setStock(5);//5 rack
    coca_crate.setUsed(2*33);//2 bottle used

    QModelIndex index=model->append(coca_crate.toVariant());
    model->setData(index,coca_crate.toVariant(),AbstractListModel::MakeEntity);
}
void StackManagementUsecase::initFanta_crate()
{
    fanta_crate.setId(52);
    fanta_crate.setName("fanta_crate");
    fanta_crate.setCapacity(24*33);//24 bottle of 33cl
    fanta_crate.setStock(2);//5 rack
    fanta_crate.setUsed(12*33);//2 bottle used

    QModelIndex index=model->append(fanta_crate.toVariant());
    model->setData(index,fanta_crate.toVariant(),AbstractListModel::MakeEntity);
}
void StackManagementUsecase::initWiskeyBottle()
{
    whiskey_bottle.setId(53);
    whiskey_bottle.setName("whiskey_bottle");
    whiskey_bottle.setCapacity(75);//1 bottle of 75cl
    whiskey_bottle.setStock(10);//10 bottle
    whiskey_bottle.setUsed(15);//15cl used from the first bottle

    QModelIndex index=model->append(whiskey_bottle.toVariant());
    model->setData(index,whiskey_bottle.toVariant(),AbstractListModel::MakeEntity);
}
void StackManagementUsecase::initCoca()
{
    coca.setId(54);
    coca.setName("coca");
    coca.setCapacity(33);//capacity sell
    coca.setStock(118);// get by business function
    coca.setUsed(0);//0 or 33

    vector<Ingredient> ingredients;
    Ingredient ingredient;
    ingredient.setProduct(coca.getId());
    ingredient.setQuantity(coca.getCapacity());
    ingredient.setIngredient(coca_crate.getId());
    ingredients.push_back(ingredient);
    coca.setIngredients(ingredients);

    QModelIndex index=model->append(coca.toVariant());
    model->setData(index,coca.toVariant(),AbstractListModel::MakeEntity);
}
void StackManagementUsecase::initFanta()
{
    fanta.setId(55);
    fanta.setName("fanta");
    fanta.setCapacity(33);//capacity sell
    fanta.setStock(36);// get by business function
    fanta.setUsed(0);//0 or 33

    vector<Ingredient> ingredients;
    Ingredient ingredient;
    ingredient.setProduct(fanta.getId());
    ingredient.setQuantity(fanta.getCapacity());
    ingredient.setIngredient(fanta_crate.getId());
    ingredients.push_back(ingredient);
    fanta.setIngredients(ingredients);

    QModelIndex index=model->append(fanta.toVariant());
    model->setData(index,fanta.toVariant(),AbstractListModel::MakeEntity);
}
void StackManagementUsecase::initWhiskeyCocaFanta()
{
    whiskey_coca_fanta.setId(56);
    whiskey_coca_fanta.setName("whiskey coca fanta");
    whiskey_coca_fanta.setCapacity(6);//get by business fucntion a+b+c+...
    whiskey_coca_fanta.setStock(142);// get by business function
    whiskey_coca_fanta.setUsed(0);//0 or all

    vector<Ingredient> ingredients;
    Ingredient cocaIngredient;
    Ingredient fantaIngredient;
    Ingredient whiskeyIngredient;

    cocaIngredient.setProduct(whiskey_coca_fanta.getId());
    fantaIngredient.setProduct(whiskey_coca_fanta.getId());
    whiskeyIngredient.setProduct(whiskey_coca_fanta.getId());

    cocaIngredient.setQuantity(12.0f); //12 cl
    fantaIngredient.setQuantity(15.0f); //15 cl
    whiskeyIngredient.setQuantity(5.0f); //5 cl

    cocaIngredient.setIngredient(coca.getId());
    fantaIngredient.setIngredient(fanta.getId());
    whiskeyIngredient.setIngredient(whiskey_bottle.getId());


    ingredients.push_back(cocaIngredient);
    ingredients.push_back(fantaIngredient);
    ingredients.push_back(whiskeyIngredient);
    whiskey_coca_fanta.setIngredients(ingredients);

    QModelIndex index=model->append(whiskey_coca_fanta.toVariant());
    model->setData(index,whiskey_coca_fanta.toVariant(),AbstractListModel::MakeEntity);
}

void StackManagementUsecase::updateModel(const Product& p)
{
    QModelIndex index=model->getIndexOf(p.toVariant());
    model->setData(index,p.toVariant(),AbstractListModel::VariantRole);
}

////////////////////////////////////////////////////////////////////////////////////////////////
void StackManagementUsecase::test_get_stock_by_capacity_simpleProduct()
{
    Capacity capacity(coca_crate.getStock() * coca_crate.getCapacity()-coca_crate.getUsed());
    QVERIFY(business->getStockCapacity(coca_crate)==(capacity));
}
void StackManagementUsecase::test_get_Product_By_Tiny_Stock()
{
    whiskey_bottle.setStock(3);
    whiskey_bottle.setUsed(1);
    updateModel(whiskey_bottle);
    QVERIFY(business->getProductByTinyStock(whiskey_coca_fanta.getIngredients()).getId()==whiskey_bottle.getId());
    whiskey_bottle.setStock(10);
    whiskey_bottle.setUsed(1);
    updateModel(whiskey_bottle);
}
void StackManagementUsecase::test_get_stock_by_capacity_complexProduct()
{
    Product p=business->getProductByTinyStock(whiskey_coca_fanta.getIngredients());
    QVERIFY(business->getStockCapacity(whiskey_coca_fanta)==business->getStockCapacity(p));
}
void StackManagementUsecase::test_get_Product_By_Tiny_Stock_Used()
{
    vector<Ingredient> ingredients=whiskey_coca_fanta.getIngredients();
    ingredients.at(0).setQuantity(10);
    Ingredient ingredient=ingredients.at(0);
    whiskey_coca_fanta.setIngredients(ingredients);

    updateModel(whiskey_coca_fanta);

    coca_crate.setStock(1); //reste 1 casier
    coca_crate.setUsed(15*33); // ou 15 bouteil sont deja partis
    updateModel(coca_crate);

    QVERIFY(business->getProductByTinyStockUsed(whiskey_coca_fanta.getIngredients())==business->getProduct(ingredient.getIngredient()));
}
void StackManagementUsecase::test_get_stock_by_unity()
{
    coca_crate.setCapacity(24*33); //24 bottle of 33cl
    coca_crate.setStock(1); //reste 1 casier
    coca_crate.setUsed(2*33); // ou 15 bouteil sont deja partis
    updateModel(coca_crate);
    updateModel(coca);
    QVERIFY(business->getStockUnity(coca_crate)==coca_crate.getStock());
}

void StackManagementUsecase::test_increase_used()
{
    coca_crate.setCapacity(24*33); //24 bottle of 33cl
    coca_crate.setStock(1); //reste 1 casier
    coca_crate.setUsed(2*33); // ou 15 bouteil sont deja partis
    updateModel(coca_crate);
    updateModel(coca);
    int cocaUnityBefore=business->getStockUnity(coca);
    qDebug()<<coca.getUsed();
    //business->increaseUsed(coca_crate,coca.getIngredients().at(0).getQuantity());
    int cocaUnityAfter=business->getStockUnity(coca);
    QVERIFY(cocaUnityBefore!=cocaUnityAfter);
}

void StackManagementUsecase::test_increase_the_remainder()
{

//Given I Have a <product> that I sell a part LESS than its <capacity>    
//AND  I Have a suffisance <stock>
//When I sell the <product>
    Capacity usedCoca_crateBefore=coca_crate.getUsed();
    int cocaStock=coca.getStock();
    business->processDebit(coca);
    int cocaStockAfter=coca.getStock();
    Capacity usedCoca_crateAfter=coca_crate.getUsed();
//Then its <remainder> is INCREMENTED by the <capacity> sell

    QVERIFY(cocaStock!=cocaStockAfter);

}


QTEST_MAIN(StackManagementUsecase)

#include "tst_stackmanagementusecase.moc"
