#ifndef PROXY_HPP_
#define PROXY_HPP_

#include<iostream>
using namespace std;

class Subject {
 public:
  virtual ~Subject() {};
  virtual void Request() = 0;
};

class ConcreteSubject : public Subject {
 public:
  void Request() override;
};

void ConcreteSubject::Request() {
  cout << "ConcreteSubject::Request...\n";
}

class Proxy : public Subject {
 public:
  Proxy();
  ~Proxy();
  void Request() override;

 private:
  void PreRequest();
  void AfterRequest();

  ConcreteSubject* subject_;
};

Proxy::Proxy() {
  subject_ = new ConcreteSubject;
}

Proxy::~Proxy() {
  delete subject_;
}

void Proxy::PreRequest() {
  cout << "PreRequest...\n";
}

void Proxy::AfterRequest() {
  cout << "AfterRequest...\n";
}

void Proxy::Request() {
  PreRequest();
  subject_->Request();
  AfterRequest();
}

#endif //PROXY_HPP_

/*
#include"tmp.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
  Proxy proxy;
  proxy.Request();
  return 0;
}
*/






