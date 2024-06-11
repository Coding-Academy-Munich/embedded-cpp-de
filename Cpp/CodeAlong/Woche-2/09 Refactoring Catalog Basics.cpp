// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Refactoring Catalog: Basics</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 09 Refactoring Catalog Basics.cpp -->
// <!-- slides/module_550_refactoring/topic_210_refact_basics.cpp -->

// %% [markdown]
//
// # Refactoring-Katalog
//
// - Katalog von Refactorings
// - Beschreibung von Refactorings in standardisiertem Format
//   - Name
//   - Skizze
//   - Motivation
//   - Mechanik
//   - Beispiel

// %% [markdown]
//
// - Jeder Schritt im Mechanik-Abschnitt ist so klein wie möglich
// - Wenn man mit dem Refactoring vertraut ist, kann man mit größeren Schritten
//   arbeiten
// - Alternative Vorgehensweisen sind möglich

// %% [markdown]
//
// ## Grundlegende Refactorings
//
// - Extrahiere Funktion
// - Inline Function
// - Extrahiere Variable
// - Inline Variable
// - Ändere Funktionsdeklaration

// %% [markdown]
//
// - Kapsle Variable
// - Benenne Variable um
// - Führe Parameterobjekt ein
// - Kombiniere Funktionen zu Klasse
// - Kombiniere Funktionen zu Transformation
// - Teile in Phasen auf

// %% [markdown]
//
// ### Hilfs-Code für Beispiele
//
// Inhalt von `refactoring.h` (simplified):
//
// - Includes: `string`, `vector`, `iostream`, `iomanip`, `xcpp/display`
// - Code:
//
// ```cpp
// struct OrderLine {
//     std::string product;
//     int quantity;
//     double price;
// };
//
// inline std::vector<OrderLine> MakeOrderLines();
// ```

// %%
#include "refactoring.h"

// %%
xcpp::display(MakeOrderLines());
