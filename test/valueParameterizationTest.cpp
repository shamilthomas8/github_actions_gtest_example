#include "gtest/gtest.h"
int divFun(int numerator,int denominator){
    if(denominator==0){return 0;}
    if(denominator<0){ return -1;}

    return numerator/denominator;
}

class DivFunTestSuite:public testing::TestWithParam<std::tuple<int,int,int>>{    //numerator, denominator, expected output
  protected:
  DivFunTestSuite(){}
  ~DivFunTestSuite(){}
};

TEST_P(DivFunTestSuite,HandleValidInputs){
    int numerator=std::get<0>(GetParam());
    int denomiator=std::get<1>(GetParam());
    int expectedValue=std::get<2>(GetParam());
    int actualValue=divFun(numerator,denomiator);
    ASSERT_EQ(actualValue,expectedValue);
}
INSTANTIATE_TEST_SUITE_P(
    DivFunTestSuiteParameterExample,                        //new name 
    DivFunTestSuite,
    ::testing::Values(
        std::make_tuple(10,5,2),
        std::make_tuple(10,0,0),
        std::make_tuple(10,-5,-1)

));




