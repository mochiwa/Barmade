#ifndef ABSTRACTCOMPARISON_H
#define ABSTRACTCOMPARISON_H


template <class T>
class AbstractComparison
{
public:
    AbstractComparison(){}
    virtual ~AbstractComparison(){}

    virtual bool compare(const T& a,const T& b)const=0;
};

#endif // ABSTRACTCOMPARISON_H
