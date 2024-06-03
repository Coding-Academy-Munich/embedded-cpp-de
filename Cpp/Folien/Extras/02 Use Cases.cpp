// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Use Cases</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Use Cases.cpp -->
// <!-- slides/module_500_solid_grasp/topic_140_adventure_use_cases.cpp -->

// %% [markdown]
//
// ### Use Case 1: Spiel initialisieren
//
// **Scope:** Adventure Game
//
// **Actors:** Spieler

// %% [markdown]
//
// **Kontext:** Der Spieler startet ein neues Spiel oder startet ein vorheriges
// Spiel neu.
//
// **Vorbedingung:** Die Spielsoftware ist geladen und läuft.
//
// **Trigger:** Spieler wählt "Neues Spiel" oder "Spiel laden" aus dem
// Hauptmenü.

// %% [markdown]
//
// **Hauptszenario:**
// 1. Spieler wählt "Neues Spiel".
// 2. System initialisiert eine neue Spielwelt mit Standardwerten.
// 3. System platziert den Spielstein an einem Startpunkt.
// 4. Spiel präsentiert den initialen Spielzustand dem Spieler.

// %% [markdown]
//
// **Erfolgsgarantie:** Spiel ist initialisiert und bereit für den Spieler, um
// einen Zug zu machen.
//
// **Minimale Garantie:** Spielzustand ist stabil und bereit für jede
// selektierbare Aktion des Spielers.
//
// **Stakeholders und Interessen:**
// - Spieler: Möchte eine reibungslose Erfahrung beim Starten oder Laden eines
//   Spiels.

// %% [markdown]
//
// **Erweiterungen:**
// 1a. Spieler wählt "Spiel laden".
// 1. System fordert den Spieler auf, ein gespeichertes Spiel auszuwählen.
// 2. Spiel lädt den gespeicherten Zustand.
//
// 2a. Fehler beim Laden des gespeicherten Spiels.
// 1. System zeigt eine Fehlermeldung an.
// 2. Spieler wird zum Hauptmenü zurückgebracht.

// %% [markdown]
//
// ### Use Case 2: Hauptspielschleife
//
// **Scope:** Adventure Game
//
// **Actors:** Spieler, NPCs


// %% [markdown]
//
// **Kontext:** Spieler interagiert mit dem Spiel, und NPCs handeln auf der
// Grundlage vordefinierter Logik.
//
// **Vorbedingung:** Spiel ist initialisiert.
//
// **Trigger:** Spieler beginnt seinen Zug.


// %% [markdown]
//
// **Hauptszenario:**
// 1. Spieler beginnt seinen Zug, indem er eine Aktion wählt (z.B. bewegen,
//    interagieren).
// 2. System verarbeitet die Aktion.
// 3. NPCs nehmen ihre jeweiligen Züge basierend auf der Spiellogik.
// 4. Spiel gibt dem Spieler Feedback über die Ergebnisse aller Aktionen.
// 5. System überprüft auf mögliche Game-Over-Bedingungen.
// 6. Gibt die Kontrolle an den Spieler für den nächsten Zug zurück.

// %% [markdown]
//
// **Erfolgsgarantie:** Die Spielschleife läuft reibungslos, und der Spieler
// kennt immer das Ergebnis seiner Aktionen.
//
// **Minimale Garantie:** Der Spielzustand bleibt konsistent und stürzt nicht ab.
//
// **Stakeholders und Interessen:**
// - Spieler: Erwartet eine nahtlose Spielerfahrung ohne Unterbrechungen.

// %% [markdown]
//
// **Erweiterungen:**
// 1a. Die Game-Over-Bedingung ist erfüllt (z.B. Spielerfigur erreicht ein
// bestimmtes Ziel, Spielerfigur verliert alle Lebenspunkte).
// 1. System präsentiert einen Game-Over-Bildschirm mit relevanten Informationen
// (z.B. Gewinn-/Verlustmeldung, Punktzahl).
// 2. Spieler erhält die Möglichkeit, das Spiel neu zu starten oder zum
// Hauptmenü zurückzukehren.
//
// 2a. Spieler wählt aus, das Spiel während seines Zuges zu speichern.
// 1. System pausiert die Spielschleife.
// 2. Spieler speichert das Spiel.
// 3. Die Spielschleife wird fortgesetzt.

// %% [markdown]
//
// ### Use Case 3: Spieler macht einen Zug
//
// **Scope:** Adventure Game
//
// **Actors:** Spieler


// %% [markdown]
//
// **Kontext:** Spieler entscheidet sich für eine Aktion während seines Zuges.
//
// **Vorbedingung:** Spieler ist an der Reihe in der Spielschleife.
//
// **Trigger:** System fordert den Spieler zu einer Aktion auf.


// %% [markdown]
//
// **Hauptszenario:**
// 1. Spieler wählt eine Aktion (z.B. zu einem Ort bewegen, mit einem NPC
//    interagieren, ein Objekt benutzen).
// 2. System verarbeitet die Aktion.
// 3. System gibt Feedback über das Ergebnis der Aktion.
// 4. Spielerzug endet.

// %% [markdown]
//
// **Erfolgsgarantie:** Die vom Spieler gewählte Aktion wird ausgeführt, und es
// wird Feedback gegeben.
//
// **Minimale Garantie:** Der Spielzustand bleibt konsistent.
//
// **Stakeholders und Interessen:**
// - Spieler: Erwartet, dass seine gewählten Aktionen korrekt ausgeführt werden.

// %% [markdown]
//
// **Erweiterungen:**
// 1a. Spieler wählt eine ungültige Aktion (z.B. Bewegung zu einem nicht
// zugänglichen Ort).
// 1. System gibt Feedback über die ungültige Aktion.
// 2. Spieler wird aufgefordert, eine gültige Aktion zu wählen.
//
// 2a. Spieler wählt aus, während seines Zuges auf das Spielmenü zuzugreifen.
// 1. System pausiert das Spiel.
// 2. Spieler greift auf Optionen wie Speichern, Einstellungen anpassen oder
// Beenden zu.
// 3. Spieler kehrt nach dem Verlassen des Menüs zu seinem Zug zurück.
