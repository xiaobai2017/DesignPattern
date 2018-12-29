#ifndef STATE_H_
#define STATE_H_

class State;
class Context {
 public:
  Context();
  virtual ~Context();
  void ChangeState(State*);
  void request();

 private:
  State* state_;
};

class State {
 public:
  virtual ~State();
  virtual void Handle(Context*) = 0;
};

class ConcreteStateA : public State {
 public:
  virtual void Handle(Context*) override;
  static State* Instance();

 protected:
  ConcreteStateA();

 private:
  static ConcreteStateA* state_a_;
};

class ConcreteStateB : public State {
 public:
  virtual void Handle(Context*) override;
  static State* Instance();

 protected:
  ConcreteStateB();

 private:
  static ConcreteStateB* state_b_;
};

#endif //STATE_H_
