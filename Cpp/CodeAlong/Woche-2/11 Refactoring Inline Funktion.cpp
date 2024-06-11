// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Refactoring: Inline Funktion</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 11 Refactoring Inline Funktion.cpp -->
// <!-- slides/module_550_refactoring/topic_230_refact_inline_function.cpp -->

// %% [markdown]
//
// ### Inline Function
//
// - Invers zu *Extrahiere Funktion*

// %%
#include "refactoring.h"

// %%
double OrderLinePrice(const OrderLine& orderLine) { return orderLine.price; }

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += orderLine.quantity * OrderLinePrice(orderLine);
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += orderLine.quantity * orderLine.price; // <-- inline function
    }
    return total;
}

// %%
xcpp::display(ComputeTotal(MakeOrderLines()));

// %% [markdown]
//
// #### Motivation
//
// - Manchmal ist eine Funktion nicht leichter zu verstehen als ihr Rumpf
// - Manchmal sind die von einer Funktion verwendeten Hilfsfunktionen nicht gut
//   strukturiert
// - Generell: Potentiell anwendbar, wenn man aufgrund zu vieler Indirektionen
//   den Überblick verliert

// %% [markdown]
//
// #### Mechanik
//
// - Überprüfe, dass die Funktion nicht virtuell ist
//   - Eine virtuelle Funktion, die von Unterklassen überschrieben wird, können
//     wir nicht entfernen, ohne die Semantik des Programms zu ändern
// - Finde alle Aufrufe der Funktion
// - Ersetze jeden Aufruf durch den Rumpf der Funktion
// - Test nach jedem Schritt!
// - Entferne die Funktionsdefinition
// - Brich ab, falls Schwierigkeiten wegen Rekursion, mehrerer
//   `return`-Anweisungen, etc. auftreten

// %% [markdown]
//
// #### Beispiel
//
// - Siehe `code/completed/invoice`

