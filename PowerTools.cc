#include <iostream>

class Tools {
 public:
  Tools() {}
  ~Tools() {}
  float cost;  
  float rate;

};

class Drill : public Tools {
 public:
  Drill() { cost = 99.99; }
  ~Drill() {}
};

class LTDrill : public Drill {
 public:
  LTDrill() {  
    rate = .6;
  }
  ~LTDrill() {}
};

class MTDrill : public Drill {
 public:
  MTDrill() { rate = 1; }
  ~MTDrill() {}
};

class HTDrill : public Drill {
 public:
  HTDrill() { rate = 2.8; }
  ~HTDrill() {}
};

class Saw : public Tools {
 public:
  Saw() { cost = 209.99; }
  ~Saw() {}
};

class LTSaw : public Saw {
 public:
  LTSaw() { rate = .6; }
  ~LTSaw() {}
};

class MTSaw : public Saw {
 public:
  MTSaw() { rate = 1; }
  ~MTSaw() {}
};

class HTSaw : public Saw {
 public:
  HTSaw() { rate = 2.8; }
  ~HTSaw() {}
};

class Sander : public Tools {
 public:
  Sander() { cost = 259.99; }
  ~Sander() {}
};

class LTSander : public Sander {
 public:
  LTSander() { rate = .6; }
  ~LTSander() {}
};

class MTSander : public Sander {
 public:
  MTSander() { rate = 1; }
  ~MTSander() {}
};

class HTSander : public Sander {
 public:
  HTSander() { rate = 2.8; }
  ~HTSander() {}
};

class Wrench : public Tools {
 public:
  Wrench() { cost = 159.99; }
  ~Wrench() {}
};

class LTWrench : public Wrench {
 public:
  LTWrench() { rate = .6; }
  ~LTWrench() {}
};

class MTWrench : public Wrench {
 public:
  MTWrench() { rate = 1; }
  ~MTWrench() {}
};

class HTWrench : public Wrench {
 public:
  HTWrench() { rate = 2.8; }
  ~HTWrench() {}
};

class IFactory {
 public:
  virtual Drill *createDrill() = 0;
  virtual Wrench *createWrench() = 0;
  virtual Sander *createSander() = 0;
  virtual Saw *createSaw() = 0;
  virtual ~IFactory() {}
};

class LTFactory : public IFactory {
 public:
  Drill *createDrill() override { return new LTDrill(); }

  Wrench *createWrench() override { return new LTWrench(); }

  Sander *createSander() override { return new LTSander(); }
  Saw *createSaw() override { return new LTSaw(); }
  ~LTFactory() {}
};

class MTFactory : public IFactory {
 public:
  Drill *createDrill() override { return new MTDrill(); }

  Wrench *createWrench() override { return new MTWrench(); }

  Sander *createSander() override { return new MTSander(); }
  Saw *createSaw() override { return new MTSaw(); }
  ~MTFactory() {}
};

class HTFactory : public IFactory {
 public:
  Drill *createDrill() override { return new HTDrill(); }

  Wrench *createWrench() override { return new HTWrench(); }

  Sander *createSander() override { return new HTSander(); }
  Saw *createSaw() override { return new HTSaw(); }
  ~HTFactory() {}
};

class Facade {
 public:
  Facade() {}

  void run() {
    queryForBrand();
    while (true) {
      queryForDevice();
    }
  }

 private:
  IFactory *factory;
  std::string brand;
  std::string tool;

  void queryForBrand() {
    while (true) {
      std::cout << "What tier? (ht, mt, lt): ";
      std::cin >> brand;
      if (brand == "ht") {
        factory = new HTFactory();
        break;
      } else if (brand == "mt") {
        factory = new MTFactory();
        break;
      } else if (brand == "lt") {
        factory = new LTFactory();
        break;
      } else {
        std::cout << "Invalid tier, try again.\n";
      }
    }
  }

  void queryForDevice() {
    std::cout << "What tool? (drill, wrench, sander, saw): ";
    std::cin >> tool;
    float totalCost = 0.0;
    if (tool == "drill") {
      Drill *t = factory->createDrill();
      totalCost = t->cost * t->rate;
      delete t;
    } else if (tool == "wrench") {
      Wrench *t = factory->createWrench();
      totalCost = t->cost * t->rate;
      delete t;
    } else if (tool == "sander") {
      Sander *t = factory->createSander();
      totalCost = t->cost * t->rate;
      delete t;
    } else if (tool == "saw") {
      Saw *t = factory->createSaw();
      totalCost = t->cost * t->rate;
      delete t;
    } else {
      std::cout << "Invalid tool, try again.\n";
      return;
    }
    std::cout << "Total cost: " << totalCost << std::endl;
  }
};

int main() {
  Facade facade;
  facade.run();
  return 0;
}