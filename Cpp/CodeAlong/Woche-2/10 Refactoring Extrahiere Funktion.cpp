// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Refactoring: Extrahiere Funktion</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 10 Refactoring Extrahiere Funktion.cpp -->
// <!-- slides/module_550_refactoring/topic_220_refact_extract_function.cpp -->

// %% [markdown]
//
// ### Extrahiere Funktion
//
// - Invers zu *Inline Function*

// %%
#include "refactoring.h"

// %%
void PrintReceipt(const std::vector<OrderLine>& orderLines) {
    for (const auto& orderLine : orderLines) {
        std::cout << std::left << std::setw(12) << orderLine.product << " "
                  << std::right << std::setw(4) << orderLine.quantity << " x "
                  << std::fixed << std::setprecision(2) << std::setw(6)
                  << orderLine.price << "€\n";
    }
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += orderLine.quantity * orderLine.price;
    }
    std::cout << "Total: " << total << "€" << std::endl;
}

// %%
PrintReceipt(MakeOrderLines());

// %%
double ComputeTotal(const std::vector<OrderLine>& orderLines) {
    double total{0.0};
    for (const auto& orderLine : orderLines) {
        total += orderLine.quantity * orderLine.price;
    }
    return total;
}

// %%
void PrintReceipt(const std::vector<OrderLine>& orderLines) {
    for (const auto& orderLine : orderLines) {
        std::cout << std::left << std::setw(12) << orderLine.product << " "
                  << std::right << std::setw(4) << orderLine.quantity << " x "
                  << std::fixed << std::setprecision(2) << std::setw(6)
                  << orderLine.price << "€\n";
    }
    double total{ComputeTotal(orderLines)}; // <-- call new function
    std::cout << "Total: " << total << "€" << std::endl;
}

// %%
PrintReceipt(MakeOrderLines());

// %% [markdown]
//
// #### Motivation
//
// - Jedes Code-Fragment, das man nicht unmittelbar versteht, sollte in eine
//   Funktion extrahiert werden
// - Name der Funktion spiegelt wieder, **was** die Intention des Codes ist
// - Das kann zu Funktionen führen, die nur eine Zeile Code enthalten
// - Es ist dabei besonders wichtig, dass die Funktionen **gute** Namen haben
// - Kommentare in Funktionen, die sagen, was der nächste Code-Block macht,
//   sind ein Hinweis auf eine mögliche Extraktion


// %% [markdown]
//
// #### Mechanik
//
// - Erzeuge eine neue Funktion
//   - Benenne sie nach der Intention des Codes
// - Kopiere den extrahierten Code in die neue Funktion
// - Übergebe alle Variablen, die die Funktion benötigt, als Parameter
//   - Wenn vorher deklarierte Variablen nur in der neuen Funktion verwendet
//     werden, können sie auch als lokale Variablen in der neuen Funktion
//     deklariert werden
// - Breche die Extraktion ab, falls die Funktion zu viele Parameter bekommt
//   - Wende stattdessen andere Refactorings an, die die Extraktion einfacher
//     machen (Split Variables, Replace Temp with Query, ...)

// %% [markdown]
//
// #### Beispiel
//
// - Siehe `code/completed/invoice/v1` für ein Beispiel einer Extraktion,
// die
//   abgebrochen wird
// - Siehe `code/completed/invoice/v3` für eine erfolgreiche
//   Extraktion (nach etwas Refactoring)

// %%
