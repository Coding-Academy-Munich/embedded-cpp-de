// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Refactoring: Extrahiere Variable</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 Refactoring Extrahiere Variable.cpp -->
// <!-- slides/module_550_refactoring/topic_240_refact_extract_variable.cpp -->

// %% [markdown]
//
// ### Extrahiere Variable

// %%
#include "refactoring.h"

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += orderLine.quantity * orderLine.price;
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        const double orderLinePrice{orderLine.quantity * orderLine.price};
        //           ^^^^^^^^^^^^^^ new variable
        total += orderLinePrice;
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %% [markdown]
//
// #### Motivation
//
// - Hilft dabei, komplexe Ausdrücke zu verstehen
//   - Erklärende Variablen/Konstanten
// - Debugging oft einfacher

// %% [markdown]
//
// #### Mechanik
//
// - Stelle sicher, dass der Ausdruck frei von Seiteneffekten ist
// - Erzeuge eine neue konstante Variable
// - Initialisiere sie mit dem Ausdruck
// - Ersetze den Ausdruck durch die Variable
// - Teste das Programm

// %% [markdown]
//
// #### Beispiel
//
// - Siehe `code/completed/invoice`

