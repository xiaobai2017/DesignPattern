#ifndef STRATEGY_H_
#define STRATEGY_H_

class Strategy;

class Context {
 public:
  Context();
  void SetStrategy(Strategy*);
  void Algorithm();

 private:
  Strategy* strategy_;
};


class Strategy {
 public:
  virtual ~Strategy();
  virtual void Algorithm() = 0;
};


class StrategyA : public Strategy {
 public:
  void Algorithm();
  static StrategyA* Instance();

 protected:
  StrategyA();

 private:
  static StrategyA* strategy_a_;
};


class StrategyB : public Strategy {
 public:
  void Algorithm();
  static StrategyB* Instance();

 protected:
  StrategyB();

 private:
  static StrategyB* strategy_b_;
};

#endif //STRATEGY_H_
