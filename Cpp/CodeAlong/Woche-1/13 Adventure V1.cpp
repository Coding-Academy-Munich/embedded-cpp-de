// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Adventure V1</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 13 Adventure V1.cpp -->
// <!-- slides/module_500_solid_grasp/topic_150_adventure_v1.cpp -->

// %% [markdown]
//
// Wie fangen wir an?

// %% [markdown]
//
// ## Niedrige Repräsentationslücke (Low Representational Gap)
//
// - Idee: Konzepte aus der Domäne in Code übertragen
// - Implementieren Sie ein Szenario aus einem Use Case
// - Nehmen Sie die Domänen-Konzepte als Kandidaten für die ersten Klassen her

// %% [markdown]
//
// - Use Case: "Spiel initialisieren"
// - Haupterfolgsszenario ohne Laden eines Spiels

// %% [markdown]
//
// ## Domänenmodell
//
// Hier ist noch einmal der relevante Teil des Domänenmodells:

// %% [markdown]
// <img src="img/adv-domain-03-small.svg"
//      style="display:block;margin:auto;width:80%"/>

// %% [markdown]
//
// ## Statisches Designmodell

// %% [markdown]
// <img src="img/adv-world-cd-01.svg"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Implementierung
//
// - Ordner: `code/starter_kits/adventure_sk`

// %% [markdown]
//
// - Jetzt kommen wir zur ersten Entscheidung, wo uns die GRASP Patterns helfen
//   können.
// - Wer ist verantwortlich für die Erzeugung der `Location`-Instanzen?
// - Wir haben mehrere Möglichkeiten:
//   - Die `Game`-Klasse könnte die `Location`-Instanzen erzeugen und an die
//     `World`-Klasse übergeben
//   - Eine `LocationFactory`-Klasse, die auf das Erzeugen von `Locations`
//     spezialisiert ist, könnte die `Location`-Instanzen erzeugen und an die
//     `World`-Klasse übergeben
//   - Irgend eine andere Klasse könnte die `Location`-Instanzen erzeugen und an
//     die `World`-Klasse übergeben
//   - Die `World`-Klasse könnte die `Location`-Instanzen selber erzeugen
// - Das `Creator` Pattern gibt hier eine Antwort.
// - Aber nachdem das Video ohnehin schon lang genug ist, machen wir eine Pause
//   und kommen im nächsten Video darauf zurück.
// - Ich bedanke mich für Ihre Aufmerksamkeit und freue mich, Sie im nächsten
//   Video wiederzusehen.
// - Bis dann und alles Gute!
