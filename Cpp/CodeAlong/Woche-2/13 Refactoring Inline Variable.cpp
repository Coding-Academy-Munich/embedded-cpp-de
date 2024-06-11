// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Refactoring: Inline Variable</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 13 Refactoring Inline Variable.cpp -->
// <!-- slides/module_550_refactoring/topic_250_refact_inline_variable.cpp -->

// %% [markdown]
//
// ### Inline Variable

// %%
#include "refactoring.h"

// %%
double OrderLinePrice(const OrderLine& orderLine) {
    return orderLine.quantity * orderLine.price;
}

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        const double orderLinePrice{OrderLinePrice(orderLine)};
        total += orderLinePrice;
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += OrderLinePrice(orderLine); // <-- inline variable
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %% [markdown]
//
// #### Motivation
//
// - Manchmal kommuniziert der Name der Variable nicht mehr als der Ausdruck
//   selbst
// - Manchmal verhindert eine Variable das Refactoring von anderem Code

// %% [markdown]
//
// #### Mechanik
//
// - Stelle sicher, dass der Initialisierungs-Ausdruck frei von Seiteneffekten
//   ist
// - Falls die Variable nicht schon konstant ist, mache sie konstant und teste
//   das Programm
// - Finde die erste Referenz auf die Variable
// - Ersetze die Variable durch ihren Initialisierungs-Ausdruck
// - Teste das Programm
// - Wiederhole für jede Referenz auf die Variable

// %% [markdown]
//
// #### Beispiel
//
// - Siehe `code/completed/invoice`

