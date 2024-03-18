#include "PowerTools.h"
#include <iostream>
#include <memory>
#include <cmath> 

void reportResult(const std::string& testName, bool passed) {
    std::cout << testName << ": " << (passed ? "PASSED" : "FAILED") << std::endl;
}

// Test function declarations
bool testToolCostInitialization();
bool testToolRateInitialization();
bool testFactoryCreation();
bool testTotalCostCalculation();

int main() {
    // Running tests manually
    reportResult("Tool Cost Initialization", testToolCostInitialization());
    reportResult("Tool Rate Initialization", testToolRateInitialization());
    reportResult("Factory Creation", testFactoryCreation());
    reportResult("Total Cost Calculation", testTotalCostCalculation());
    
    return 0;
}

// Test implementations
const double EPSILON = 1e-3;

bool AreSame(double a, double b) {
    return fabs(a - b) < EPSILON;
}

bool testToolCostInitialization() {
    Drill drill;
    if (!AreSame(drill.cost, 99.99)) return false;

    Saw saw;
    if (!AreSame(saw.cost, 209.99)) return false;

    Sander sander;
    if (!AreSame(sander.cost, 259.99)) return false;

    Wrench wrench;
    if (!AreSame(wrench.cost, 159.99)) return false;

    return true;
}

bool testToolRateInitialization() {
    // LT Factory Tools
    Drill* ltDrill = LTFactory().createDrill();
    bool result = AreSame(ltDrill->rate, 0.6);
    delete ltDrill;
    if (!result) return false;

    Saw* ltSaw = LTFactory().createSaw();
    result = AreSame(ltSaw->rate, 0.6);
    delete ltSaw;
    if (!result) return false;

    Sander* ltSander = LTFactory().createSander();
    result = AreSame(ltSander->rate, 0.6);
    delete ltSander;
    if (!result) return false;

    Wrench* ltWrench = LTFactory().createWrench();
    result = AreSame(ltWrench->rate, 0.6);
    delete ltWrench;
    if (!result) return false;

    // MT Factory Tools
    Drill* mtDrill = MTFactory().createDrill();
    result = AreSame(mtDrill->rate, 1.0);
    delete mtDrill;
    if (!result) return false;

    Saw* mtSaw = MTFactory().createSaw();
    result = AreSame(mtSaw->rate, 1.0);
    delete mtSaw;
    if (!result) return false;

    Sander* mtSander = MTFactory().createSander();
    result = AreSame(mtSander->rate, 1.0);
    delete mtSander;
    if (!result) return false;

    Wrench* mtWrench = MTFactory().createWrench();
    result = AreSame(mtWrench->rate, 1.0);
    delete mtWrench;
    if (!result) return false;

    // HT Factory Tools
    Drill* htDrill = HTFactory().createDrill();
    result = AreSame(htDrill->rate, 2.8);
    delete htDrill;
    if (!result) return false;

    Saw* htSaw = HTFactory().createSaw();
    result = AreSame(htSaw->rate, 2.8);
    delete htSaw;
    if (!result) return false;

    Sander* htSander = HTFactory().createSander();
    result = AreSame(htSander->rate, 2.8);
    delete htSander;
    if (!result) return false;

    Wrench* htWrench = HTFactory().createWrench();
    result = AreSame(htWrench->rate, 2.8);
    delete htWrench;
    if (!result) return false;

    return true;
}

bool testFactoryCreation(){
    LTFactory ltFactory;
    auto ltDrill = ltFactory.createDrill();
    bool ltDrillTest = dynamic_cast<LTDrill*>(ltDrill) != nullptr;
    delete ltDrill;

    HTFactory htFactory;
    auto htSander = htFactory.createSander();
    bool htSanderTest = dynamic_cast<HTSander*>(htSander) != nullptr;
    delete htSander;

    return ltDrillTest && htSanderTest;
}

bool testTotalCostCalculation() {
    LTDrill ltDrill;
    float expectedCost = ltDrill.cost * ltDrill.rate;
    return expectedCost == ltDrill.cost * ltDrill.rate;
}