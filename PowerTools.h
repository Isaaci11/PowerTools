#ifndef POWERTOOLS_H
#define POWERTOOLS_H

#include <iostream>

class Tools {
 public:
  Tools();
  virtual ~Tools();
  float cost;  
  float rate;
};

class Drill : public Tools {
 public:
  Drill();
  virtual ~Drill();
};

class LTDrill : public Drill {
 public:
  LTDrill();
  ~LTDrill();
};

class MTDrill : public Drill {
 public:
  MTDrill();
  ~MTDrill();
};

class HTDrill : public Drill {
 public:
  HTDrill();
  ~HTDrill();
};

class Saw : public Tools {
 public:
  Saw();
  ~Saw();
};

class LTSaw : public Saw {
 public:
  LTSaw();
  ~LTSaw();
};

class MTSaw : public Saw {
 public:
  MTSaw();
  ~MTSaw();
};

class HTSaw : public Saw {
 public:
  HTSaw();
  ~HTSaw();
};

class Sander : public Tools {
 public:
  Sander();
  ~Sander();
};

class LTSander : public Sander {
 public:
  LTSander();
  ~LTSander();
};

class MTSander : public Sander {
 public:
  MTSander();
  ~MTSander();
};

class HTSander : public Sander {
 public:
  HTSander();
  ~HTSander();
};

class Wrench : public Tools {
 public:
  Wrench();
  ~Wrench();
};

class LTWrench : public Wrench {
 public:
  LTWrench();
  ~LTWrench();
};

class MTWrench : public Wrench {
 public:
  MTWrench();
  ~MTWrench();
};

class HTWrench : public Wrench {
 public:
  HTWrench();
  ~HTWrench();
};

class IFactory {
 public:
  virtual Drill* createDrill() = 0;
  virtual Wrench* createWrench() = 0;
  virtual Sander* createSander() = 0;
  virtual Saw* createSaw() = 0;
  virtual ~IFactory();
};

class LTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~LTFactory();
};

class MTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~MTFactory();
};

class HTFactory : public IFactory {
 public:
  Drill* createDrill() override;
  Wrench* createWrench() override;
  Sander* createSander() override;
  Saw* createSaw() override;
  ~HTFactory();
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