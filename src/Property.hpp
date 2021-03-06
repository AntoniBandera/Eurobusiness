#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Field.hpp"
#include "Player.hpp"
#include "State.hpp"

class Property : public Field
{
    int purchasePrice_;
    std::shared_ptr<Player> owner_;
protected:
    std::shared_ptr<State> state_;
public:
    Property() = delete;
    Property(const Property &) = delete;
    Property(Property &&) = delete;
    ~Property() = default;
    Property & operator=(const Property &) = delete;
    Property & operator=(Property &&) = delete;
    Property(const std::string & name, int price = 700);

    int getPurchasePrice() const;
    void doOn(std::shared_ptr<Player> player);
    std::shared_ptr<Player> getOwner() const;
    void setOwner(std::shared_ptr<Player> player);
    int getPriceStamp() const;
};

using PropertiesPtr = std::vector<std::shared_ptr<Property>>;
