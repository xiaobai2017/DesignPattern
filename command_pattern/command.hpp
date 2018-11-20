#ifndef COMMAND_HPP_
#define COMMAND_HPP_

#include<iostream>
#include<vector>
using namespace std;

class Barbecuer {
 public:
  void BakeMutton();
  void BakeChickenWing();
};

void Barbecuer::BakeMutton() {
  cout << "Bake mutton...\n";
}

void Barbecuer::BakeChickenWing() {
  cout << "Bake chicken wing...\n";
}

class Command {
 public:
  virtual ~Command() {}
  Command(Barbecuer& barbecuer);
  virtual void ExecuteCommand() = 0;

 protected:
  Barbecuer& barbecuer_;
};

Command::Command(Barbecuer& barbecuer) : barbecuer_(barbecuer) {}

class BakeMuttonCommand : public Command {
 public:
  BakeMuttonCommand(Barbecuer& barbecuer);
  void ExecuteCommand() override;
};

BakeMuttonCommand::BakeMuttonCommand(Barbecuer& barbecuer) : Command(barbecuer) {}

void BakeMuttonCommand::ExecuteCommand() {
  barbecuer_.BakeMutton();
}

class BakeChickenWingCommand : public Command {
 public:
  BakeChickenWingCommand(Barbecuer& barbecuer);
  void ExecuteCommand() override;
};

BakeChickenWingCommand::BakeChickenWingCommand(Barbecuer& barbecuer) : Command(barbecuer) {}

void BakeChickenWingCommand::ExecuteCommand() {
  barbecuer_.BakeChickenWing();
}

class Waiter {
 public:
  typedef pair<Command*, bool> Info;
  void SetOrders(Command* command);
  void Notify();
 private:
  vector<Info> infos_;
};

void Waiter::SetOrders(Command* command) {
  infos_.push_back(Info(command, false));
}

void Waiter::Notify() {
  for (auto & info : infos_)
    if (info.second == false) {
      info.first->ExecuteCommand();
      info.second = true;
    }
}

#endif //COMMAND_HPP_

/*#include"tmp.hpp"
#include<iostream>
using namespace std;

int main(int argc, char* argv[]) {
  Barbecuer barbecuer;
  BakeMuttonCommand command_a(barbecuer);
  BakeChickenWingCommand command_b(barbecuer);

  Waiter waiter;
  waiter.SetOrders(&command_a);
  waiter.SetOrders(&command_b);
  waiter.SetOrders(&command_b);
  waiter.SetOrders(&command_a);
  waiter.Notify();
  return 0;
}*/



