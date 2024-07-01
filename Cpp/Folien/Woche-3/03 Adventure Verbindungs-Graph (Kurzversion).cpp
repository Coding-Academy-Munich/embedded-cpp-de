// -*- coding: utf-8 -*-
// %% [markdown]
// <!--
// clang-format off
// -->
//
// <div style="text-align:center; font-size:200%;">
//  <b>Adventure: Verbindungs-Graph (Kurzversion)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 03 Adventure Verbindungs-Graph (Kurzversion).cpp -->
// <!-- slides/module_500_solid_grasp/topic_250_adventure_connections_short.cpp -->

// %% [markdown]
//
// ## Implementierung der Verbindungen
//
// - `code/completed/adventure/v3b/`

// %% [markdown]
//
// <img src="img/adventure-v3b-overview.svg"
//      style="display:block;margin:auto;width:30%"/>

// %% [markdown]
//
// - Wie ist diese Implementierung zu bewerten?
//   - Was ist gut?
//   - Was sollten wir noch verbessern?

// %% [markdown]
//
// - Generell ist die Struktur gut
// - Ein potentielles Problem ist, dass wir sehr viel Arbeit in die
//   `World`-Klasse verlagern
// - Das ist typisch, wenn wir "Information Expert" anwenden
// - Wir brauchen einen "Gegenspieler" für dieses Pattern
