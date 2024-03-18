#include "PowerTools.h"
#include <iostream>

Tools::Tools(){ 
}

Drill::Drill() {
  cost = 99.99;
}

LTDrill::LTDrill(){ 
  rate = .6;
}

MTDrill::MTDrill(){
  rate = 1;
}

HTDrill::HTDrill(){
  rate = 2.8;
}

Saw::Saw(){
  cost = 209.99;
}

LTSaw::LTSaw(){
  rate = .6;
}

MTSaw::MTSaw(){
  rate = 1;
}

HTSaw::HTSaw(){
  rate = 2.8;
}

Sander::Sander() {
  cost = 259.99;
}

LTSander::LTSander(){
  rate = .6;
}

MTSander::MTSander(){
  rate = 1;
}

HTSander::HTSander(){
  rate = 2.8;
}

Wrench::Wrench() {
  cost = 159.99;
}

LTWrench::LTWrench(){
  rate = .6;
}

MTWrench::MTWrench(){
  rate = 1;
}

HTWrench::HTWrench(){
  rate = 2.8;
}

Drill * LTFactory::createDrill() {
  return new LTDrill();
}

Wrench * LTFactory::createWrench() {
  return new LTWrench();
}

Sander * LTFactory::createSander() {
  return new LTSander();
}

Saw * LTFactory::createSaw() {
  return new LTSaw();
}

Drill * MTFactory::createDrill() {
  return new MTDrill();
}

Wrench * MTFactory::createWrench() {
  return new MTWrench();
}

Sander * MTFactory::createSander() {
  return new MTSander();
}
Saw * MTFactory::createSaw() {
  return new MTSaw();
}

Drill * HTFactory::createDrill() {
  return new HTDrill();
}

Wrench * HTFactory::createWrench() {
  return new HTWrench();
}

Sander * HTFactory::createSander() {
  return new HTSander();
}
Saw * HTFactory::createSaw() {
  return new HTSaw();
}

void Facade::run() {
  queryForBrand();
  while (true) {
    queryForDevice();
  }
}

void Facade::queryForBrand() {
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

void Facade::queryForDevice() {
  std::cout << "What tool? (drill, wrench, sander, saw): ";
  std::cin >> tool;
  float totalCost = 0.0;
  if (tool == "drill") {
    Drill * t = factory -> createDrill();
    totalCost = t -> cost * t -> rate;
    delete t;
  } else if (tool == "wrench") {
    Wrench * t = factory -> createWrench();
    totalCost = t -> cost * t -> rate;
    delete t;
  } else if (tool == "sander") {
    Sander * t = factory -> createSander();
    totalCost = t -> cost * t -> rate;
    delete t;
  } else if (tool == "saw") {
    Saw * t = factory -> createSaw();
    totalCost = t -> cost * t -> rate;
    delete t;
  } else {
    std::cout << "Invalid tool, try again.\n";
    return;
  }
  std::cout << "Total cost: " << totalCost << std::endl;
}

// int main() {
//  Facade facade;
//   facade.run();
//   return 0;
// }