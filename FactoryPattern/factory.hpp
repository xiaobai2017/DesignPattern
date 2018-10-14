#ifndef TMP_HPP_
#define TMP_HPP_

#include<iostream>
using namespace std;

class Operation {
 public:
  virtual ~Operation(){}
  virtual double Calculate(double a, double b) = 0;
};

class OperationAdd : public Operation {
 public:
  double Calculate(double a, double b) {
    return a + b;
  }
};

class OperationSubtract : public Operation {
 public:
  double Calculate(double a, double b) {
    return a - b;
  }
};

class OperationMultiply : public Operation {
 public:
    double Calculate(double a, double b) {
      return a * b;
    }
};

class OperationDivide : public Operation {
 public:


  double Calculate(double a, double b){
    if(b == 0) {
      throw string("除数不能为0\n");
    } else {
      return a / b;
    }
  }
};

class OperationFactory {
  public:
  static Operation* CreateOperation(char operate) {
    Operation* operation = NULL;
    switch (operate) {
      case '+' :
        operation = new OperationAdd();
        break;
      case '-' :
        operation = new OperationSubtract();
        break;
      case '*' :
        operation = new OperationMultiply();
        break;
      case '/' :
        operation = new OperationDivide();
        break;
      default :
        throw string("无效的运算符\n");
    }
    return operation;
  }
};

#if 0
#include"tmp.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
  try {
    double numberA = 0;
    double numberB = 0;
    double result = 0;
    char operate = 0;

    cin >> numberA;
    cin >> operate;
    cin >> numberB;
    Operation* operation = OperationFactory::CreateOperation(operate);
    result = operation->Calculate(numberA, numberB);
    cout << numberA << " " << operate << " " << numberB << " = " << result << endl;
    delete operation;
    operation = NULL;
  } catch (const string & str) {
    cout << str;
  } catch (exception & err) {
    cout << err.what();
  } catch (...) {
    cout << "error!\n";
  }
  return 0;
}
#endif

#endif //TMP_HPP_








