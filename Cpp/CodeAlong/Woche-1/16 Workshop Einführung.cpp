// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Workshop: Einführung</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 16 Workshop Einführung.cpp -->
// <!-- slides/module_500_solid_grasp/topic_200_library_workshop_intro.cpp -->

// %% [markdown]
//
// # Bibliotheks-Verwaltungssystem: Einführung
//
// Unser Bibliotheks-Verwaltungssystem ist ein umfassendes Werkzeug, das
// entwickelt wurde, um die täglichen Abläufe von Bibliotheken zu vereinfachen
// und zu optimieren. Es erfüllt alle Anforderungen von Bibliothekaren,
// Bibliotheksbenutzern und Administratoren durch eine intuitive
// Benutzeroberfläche und effiziente Workflows.

// %% [markdown]
//
// ## Domänenmodell
//
// Das Domänenmodell für unser System umfasst mehrere Schlüsselkonzepte:
//
// - **Bücher**: Diese sind das Herzstück jeder Bibliothek. Unser System
//   verwaltet alle Bücher in der Bibliothek, einschließlich Details wie Titel,
//   Autor, Genre und Verfügbarkeitsstatus.
//
// - **Bibliotheksbenutzer**: Dies sind die Personen, die die Ressourcen der
//   Bibliothek nutzen. Sie können Mitglieder oder Besucher sein. Mitglieder
//   haben je nach Mitgliedschaftstyp bestimmte Privilegien.

// %% [markdown]
//
// - **Bibliothekare**: Dies sind die Mitarbeiter, die die Bibliothek verwalten.
//   Sie erledigen Aufgaben wie die Registrierung neuer Mitglieder, die
//   Verwaltung des Buchbestands und die Unterstützung der Benutzer bei ihren
//   Anfragen.
//
// - **Mitgliedschaftstypen**: Es gibt verschiedene Arten von Mitgliedschaften,
//   wie z.B. Erwachsene, Kinder, Studenten und Senioren. Jeder Typ hat seine
//   eigenen Vorteile und Regeln.

// %% [markdown]
//
// ## Aktivitäten
//
// Unser System unterstützt eine Vielzahl von Aktivitäten:
//
// - **Registrierung eines neuen Mitglieds**: Bibliothekare können neue
//   Mitglieder registrieren und ihnen einen bestimmten Mitgliedschaftstyp
//   zuweisen, der sich nach Alter, Beruf, etc. richtet. Dabei bekommt jedes
//   Mitglied eine eindeutige Mitgliedsnummer.
//
// - **Suche nach Mitgliedern**: Bibliothekare können nach existierenden
//   Mitgliedern suchen. Dabei ist es möglich, nach Kriterien wie Name oder
//   Mitgliedsnummer zu suchen.
//

// %% [markdown]
//
// - **Aufnehmen eines Buches**: Bibliothekare können neue Bücher in das System
//   aufnehmen.
//
// - **Löschen eines Buches**: Bibliothekare können vorhandene
//   Bücher löschen.
//
// - **Suche nach Büchern**: Benutzer können nach Büchern suchen, indem sie
//   verschiedene Kriterien wie Titel, Autor oder Genre verwenden. Das System
//   zeigt an, ob das Buch derzeit verfügbar oder ausgeliehen ist.

// %% [markdown]
//
// - **Ausleihen von Büchern**: Benutzer können Bücher ausleihen, wenn sie
//   verfügbar sind. Das System aktualisiert den Status des Buches und zeichnet
//   die Ausleihdetails auf. Die Ausleihregeln (wie z.B. maximale Anzahl von
//   Büchern oder Ausleihdauer) hängen vom Mitgliedschaftstyp des Benutzers ab.
//
// - **Rückgabe von Büchern**: Wenn ein Benutzer ein Buch zurückgibt, überprüft
//   das System, ob das Buch zu spät zurückgegeben wurde. Wenn ja, berechnet das
//   System die Strafe auf der Grundlage des Mitgliedschaftstyps des Benutzers.
//
// - **Strafzahlungen**: Wenn ein Benutzer aufgrund verspäteter Rückgaben
//   Strafen zahlen muss, kann er die Strafe mit verschiedenen Methoden wie
//   Bargeld, Karte oder Online-Zahlung bezahlen.

// %% [markdown]
//
// ## Zusammenfassung
//
// Unser Bibliotheksverwaltungssystem ist so konzipiert, dass es die
// Bibliotheksverwaltung zum Kinderspiel macht und allen Benutzern ein
// angenehmes Erlebnis bietet. Es ist eine All-in-One-Lösung für alle
// Bibliotheksbedürfnisse.

// %% [markdown]
//
// ## Das Starter Kit
//
// - `code/starter_kits/library_sk`
// - CMake-Projekt mit Bibliothek, Main-Programm und Anwendungen

// %% [markdown]
//
// ## Mini-Workshop: Bibliothekssystem
//
// - Versuchen Sie das Starter Kit zu kompilieren und auszuführen.
// - Fügen Sie eine Klasse `Book` hinzu, die ein Attribut `title` hat.
// - Fügen Sie einen Getter für das Attribut `title` hinzu.
// - Schreiben Sie einen Test, der überprüft, dass der Getter funktioniert.
// - Create a book in the main program and print its title.
// - Entfernen Sie die Dummy-Klasse `DeleteMe` und ihre Tests. Stellen Sie
//   sicher, dass Sie das Projekt immer noch bauen und das Hauptprogramm und die
//   Tests ausführen können.
//
// **Hinweis**: Das ist natürlich kein Sinnvoller Test, er dient nur dazu, dass
// Sie mit der Infrastruktur, die wir in diesem Kurs verwenden, vertraut werden.
