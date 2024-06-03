// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>GRASP: Informations-Experte</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 15 GRASP Informations-Experte.cpp -->
// <!-- slides/module_500_solid_grasp/topic_170_grasp_info_expert.cpp -->

// %% [markdown]
//
// - Use Case "Spiel initialisieren"
// - Bisher:
//   - `World` und `Location` Klassen
//   - `World` erzeugt alle `Location` Objekte
// - Nächster Schritt:
//   - Speichern von Information über die Verbindung zwischen den `Location`
//     Objekten
//   - Hilfreich dazu: Finden von Locations anhand ihres Namens
// - Frage:
//   - Wer findet `Location` Objekte anhand ihres Namens?

// %% [markdown]
//
// ## Kandidaten

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <code>Player</code></li>
// <li> <code>Game</code></li>
// <li> <code>Pawn</code></li>
// <li> <code>World</code></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>

// %% [markdown]
//
// ## Informations-Experte (engl. "Information Expert", GRASP)
//
// ### Frage
//
// An welche Klasse sollen wir eine Verantwortung delegieren?
//
// ### Antwort
//
// An die Klasse, die die meisten Informationen hat, die für die Erfüllung der
// Verantwortung notwendig sind.

// %% [markdown]
//
// ## Wer ist der Informationsexperte?

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <strike><code>Player</code></strike></li>
// <li> <strike><code>Game</code></strike></li>
// <li> <strike><code>Pawn</code></strike></li>
// <li> <b><code>World</code></b></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>

// %% [markdown]
//
// - Siehe `code/completed/adventure/v2/` für den Projekt-Aufbau mit Tests der
//   unserem aktuellen Stand entspricht
// - `code/starter_kits/adventure_sk2/` enthält ein neues Starter-Kit, das den
//   gleichen Stand repräsentiert, falls Sie selber weiter an der
//   Implementierung des Adventure-Spiels arbeiten wollen

