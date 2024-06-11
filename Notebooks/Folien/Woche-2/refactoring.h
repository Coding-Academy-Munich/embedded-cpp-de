#pragma once
#ifndef REFACTORING_H
#define REFACTORING_H

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <xcpp/xdisplay.hpp>

struct OrderLine {
    std::string product;
    int quantity;
    double price;
};

inline std::vector<OrderLine> MakeOrderLines() {
    std::vector<OrderLine> orderLines;
    orderLines.push_back({"Apple", 2, 0.5});
    orderLines.push_back({"Banana", 3, 0.3});
    orderLines.push_back({"Orange", 1, 0.8});
    return orderLines;
}


inline std::ostream& operator<<(std::ostream& os, const OrderLine& ol) {
    os << "OrderLine{" << ol.quantity << " x " << ol.product << " @ $" << ol.price << "}";
    return os;
}


inline nl::json mime_bundle_repr(const OrderLine& ol) {
    std::stringstream ss{};
    ss << ol;
    auto bundle = nl::json::object();
    bundle["text/plain"] = ss.str();
    return bundle;
}

inline nl::json mime_bundle_repr(const std::vector<OrderLine>& orderLines) {
    std::stringstream ss{};
    std::string sep{" "};

    ss << "{";
    for (const auto& ol : orderLines) {
        ss << sep << ol;
        sep = ", ";
    }
    ss << " }";

    auto bundle = nl::json::object();
    bundle["text/plain"] = ss.str();
    return bundle;
}

#endif // REFACTORING_H