#pragma once
#include <string>
#include <memory>

class State;

class Property
{
    std::string name_;
    int purchasePrice_;
public:
    Property(const std::string & name, int purchasePrice);
    virtual void setState(std::shared_ptr<State>) {}
    virtual int getPriceStamp() const = 0;
    virtual int getPriceStamp(int rolls) const = 0;
};

class State
{
public:
    virtual int getPriceStamp() const {}
};

class StateRailway : public State
{
public:
    virtual int getPriceStamp() const {}
};

class OneRailway : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class TwoRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class ThreeRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class FourRailwais : public StateRailway
{
public:
    int getPriceStamp() const override;
};

class Railway : public Property
{
    std::shared_ptr<StateRailway> stateRailway_;
public:
    Railway(const std::string & name, int purchasePrice);
    void setState(std::shared_ptr<StateRailway> state);
    int getPriceStamp() const override;
    int getPriceStamp(int rolls) const override;
};
