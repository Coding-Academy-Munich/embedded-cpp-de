// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Adventure: Verbindungs-Graph</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 18 Adventure Verbindungs-Graph.cpp -->
// <!-- slides/module_500_solid_grasp/topic_250_adventure_connections.cpp -->

// %% [markdown]
//
// - Wir wollen jetzt die Verbindungen zwischen den Räumen implementieren

// %% [markdown]
//
// - `code/completed/adventure/v3b/`
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

// %% [markdown]
//
// ## Workshop: Bibliotheksverwaltung
//
// - Implementieren Sie die ersten beiden Aktivitäten des Bibliotheksbeispiels
//   unter Verwendung der bisher gehörten Patterns, d.h. implementieren Sie
//   "Neuen Benutzer registrieren" und "Nach Benutzern suchen" unter Anwendung
//   von Creator und Information Expert (und unter Berücksichtigung des Prinzips
//   der niedrigen Repräsentationslücke).
//
// - Machen Sie das gleiche für die Aktivitäten "Buch hinzufügen" und "Nach
//   Büchern suchen".
//
// Sie können sich auf die Kernfunktionalität der Aktivitäten konzentrieren, d.h.
// auf die Objekte im Domänenmodell, die von den Aktivitäten betroffen sind, und
// Aspekte wie Zugriffskontrolle oder Benutzeroberfläche ignorieren.
