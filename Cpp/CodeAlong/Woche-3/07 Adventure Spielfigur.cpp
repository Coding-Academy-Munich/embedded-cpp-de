// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Adventure: Spielfigur</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 Adventure Spielfigur.cpp -->
// <!-- slides/module_500_solid_grasp/topic_320_adventure_pawn.cpp -->

// %% [markdown]
// <img src="img/adv-domain-03.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Version 4a: Spielfiguren
//
// <img src="img/adventure-v4a-overview.svg" alt="Adventure Version 4a"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// Siehe `code/completed/adventure/v4a` für den vollständigen Code.

// %% [markdown]
//
// ## Version 4b: Enumeration der Aktionen
//
// - Enumeration `Action` mit allen möglichen Aktionen
// - `Pawn`-Klasse hat nur noch eine `Perform()`-Methode
// - `Perform()`-Methode bekommt eine `action` als Parameter

// %% [markdown]
//
// ## Version 4b: Spielfiguren mit Enumeration
//
// <img src="img/adventure-v4b-overview.svg" alt="Adventure Version 4b"
//      style="display:block;margin:auto;height:80%"/>

// %% [markdown]
//
// ```cpp
// enum class Action { Move, SkipTurn };
// ```
//
// ```cpp
// void Pawn::Perform(Action action, const std::string& direction)
// {
//     switch (action) {
//     case Action::Move:
//         location = &location->GetConnectedLocation(direction);
//         break;
//     case Action::SkipTurn:
//         break;
//     }
// }
// ```

// %% [markdown]
//
// ## GRASP und SOLID Prinzipien
//
// - GRASP:
//   - Geschützte Variation (Protected Variation)
//   - Indirektion
//   - Polymorphie
// - SOLID:
//   - Open-Closed Principle
