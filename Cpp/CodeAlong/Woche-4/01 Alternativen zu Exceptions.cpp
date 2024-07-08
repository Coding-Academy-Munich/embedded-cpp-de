// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Alternativen zu Exceptions</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Alternativen zu Exceptions.cpp -->
// <!-- slides/module_180_error_handling/topic_300_exception_alternatives.cpp -->

// %% [markdown]
//
// - [Fehler-Codes](https://boostorg.github.io/outcome/motivation/error_codes.html)
// - [`errno`](https://en.cppreference.com/w/cpp/error/errno)
// - [`std::error_code`](https://en.cppreference.com/w/cpp/error/error_code) and
//   [`std::error_condition`](https://en.cppreference.com/w/cpp/error/error_condition)
// - [`std::expected`](https://en.cppreference.com/w/cpp/utility/expected)
// - [Boost.Outcome](https://boostorg.github.io/outcome)
// - [Boost.Leaf](https://boostorg.github.io/leaf/)

// %% [markdown]
//
// ## Vergleich der verschiedenen Ansätze
//
// [Boost.Outcome Dokumentation](https://boostorg.github.io/outcome/alternatives.html)
//
// ### Gemeinsamkeiten
//
// - Wenig bis kein Laufzeit-Overhead für Happy und Sad Path
// - Mehr Verzweigungen im Code, potentieller Einfluss auf Optimierung
// - Funktionieren ohne RTTI und Exceptions
//
// ### Unterschiede
//
// - Was passiert wenn Werte/Fehler ignoriert werden?
// - "Erfolgs-orientierte Syntax"
// - Einfluss auf Build-Zeit und Programmgröße
