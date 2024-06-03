// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Catch2 Sections</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Catch2 Sections.cpp -->
// <!-- slides/module_410_unit_testing/topic_152_catch2_sections.cpp -->

// %% [markdown]
//
// ## Makros
//
// - `TEST_CASE`-Makro um Tests zu definieren
// - `REQUIRE`- und `CHECK`-Makros um Bedingungen zu prüfen
//   - `REQUIRE` beendet den Test bei einem Fehler
//   - `CHECK` führt den Test weiter aus
// - `REQUIRE_FALSE` und `CHECK_FALSE` um Bedingungen zu verneinen

// %% [markdown]
//
// ## Sections
//
// - `TEST_CASE` kann
//   - mehrere Tests zusammenfassen
//   - gemeinsamen Zustand für die Tests bereitstellen
// - `SECTION`-Makro zur Gruppierung von Tests
//   - Sections können verschachtelt werden
//
// Siehe `code/starter_kits/catch2_intro/leap_year/`

// %% [markdown]
//
// ## Workshop: Catch2 Basics
//
// Wir haben in den letzten Videos beispielhafte Tests für ein sehr einfaches
// Online-Shopping-System geschrieben ohne ein Test-Framework zu verwenden.
//
// Im Ordner `code/starter_kits/catch2_intro/order/` finden Sie eine etwas
// erweiterte Version dieses Systems.
//
// Schreiben Sie dazu Tests mit Catch2.
//
// Bewerten Sie die Tests anhand der Kriterien, die wir in den letzten Videos
// besprochen haben.
