#ifndef POWERTOOLS_H
#define POWERTOOLS_H

#include <iostream>

class Tools {
 public:
  Tools();
  virtual ~Tools() = default;
  float cost;  
  float rate;
};

class Drill : public Tools {
 public:
  Drill();
  virtual ~Drill() = default;
};

class LTDrill : public Drill {
 public:
  LTDrill();
  ~LTDrill() = default; 
};

class MTDrill : public Drill {
 public:
  MTDrill();
  ~MTDrill()= default;
};

class HTDrill : public Drill {
 public:
  HTDrill();
  ~HTDrill()= default;
};

class Saw : public Tools {
 public:
  Saw();
  ~Saw()= default;
};

class LTSaw : public Saw {
 public:
  LTSaw();
  ~LTSaw()= default;
};

class MTSaw : public Saw {
 public:
  MTSaw();
  ~MTSaw()= default;
};

class HTSaw : public Saw {
 public:
  HTSaw();
  ~HTSaw()= default;
};

class Sander : public Tools {
 public:
  Sander();
  ~Sander()= default;
};

class LTSander : public Sander {
 public:
  LTSander();
  ~LTSander()= default;
};

class MTSander : public Sander {
 public:
  MTSander();
  ~MTSander() = default;
};

class HTSander : public Sander {
 public:
  HTSander();
  ~HTSander() = default; 
};

class Wrench : public Tools {
 public:
  Wrench();
  ~Wrench() = default;
};

class LTWrench : public Wrench {
 public:
  LTWrench();
  ~LTWrench() = default;
};

class MTWrench : public Wrench {
 public:
  MTWrench();
  ~MTWrench() = default;
};

class HTWrench : public Wrench {
 public:
  HTWrench();
  ~HTWrench() = default;
};

class IFactory {
 public:
  virtual Drill* createDrill() = 0;
  virtual Wrench* createWrench() = 0;
  virtual Sander* createSander() = 0;
  virtual Saw* createSaw() = 0;
  virtual ~IFactory() = default;
};

class LTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~LTFactory() = default;
};

class MTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~MTFactory() = default;
};

class HTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~HTFactory() = default;
};

class Facade {
 public:
  Facade();
  void run();

 private:
  IFactory* factory;
  std::string brand;
  std::string tool;

  void queryForBrand();
  void queryForDevice();
};

#endif