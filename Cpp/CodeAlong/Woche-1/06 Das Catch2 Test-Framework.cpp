// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Das Catch2 Test-Framework</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 06 Das Catch2 Test-Framework.cpp -->
// <!-- slides/module_410_unit_testing/topic_150_catch2.cpp -->

// %% [markdown]
//
// ## Was ist Catch2?
//
// - Catch2 ist ein modernes Test-Framework für C++
// - Open-Source
// - Einfach in Projekte zu integrieren
// - Viele Features
// - Andere Struktur als xUnit-Test-Frameworks

// %% [markdown]
//
// ## Features von Catch2
//
// - Verwaltung von Tests und Test-Suites
// - Assertion-Bibliothek für Testfälle
// - Ausführung von Tests (Test Runner)
// - Grundlegende Performance-Tests

// %% [markdown]
//
// ## Ein einfacher Test mit Catch2
//
// ### CMake-Projekt
//
// ```cmake
// # ...
// add_executable(catch2_basics catch2_basics.cpp)
// target_link_libraries(catch2_basics Catch2WithMain)
// # ...
// ```

// %% [markdown]
//
// ## Die Testdatei
//
// - `TEST_CASE`-Makro um Tests zu definieren
// - `REQUIRE`- und `CHECK`-Makros um Bedingungen zu prüfen
//   - `REQUIRE` beendet den Test bei einem Fehler
//   - `CHECK` führt den Test weiter aus
// - `REQUIRE_FALSE` und `CHECK_FALSE` um Bedingungen zu verneinen
//
// Siehe `code/starter_kits/catch2_intro/basics/catch2_basics.cpp`

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
