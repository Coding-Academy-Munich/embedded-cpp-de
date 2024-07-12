// -*- coding: utf-8 -*-
// %% [markdown]
// <!--
// clang-format off
// -->
//
// <div style="text-align:center; font-size:200%;">
//  <b>The Curiously Recurring Template Pattern (CRTP)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 05 The Curiously Recurring Template Pattern (CRTP).cpp -->
// <!-- slides/module_470_cpp_patterns/topic_210_crtp.cpp -->

// %% [markdown]
//
// # Das Curiously Recurring Template Pattern (CRTP)
//
// - Das CRTP ist ein Idiom, das die "statische Vererbung" von Verhalten
//   ermöglicht
// - Die Basisklasse ist eine Template-Klasse, die von der abgeleiteten Klasse
//   als Template-Parameter spezialisiert wird

// %% [markdown]
//
// ### Zweck des Template Method Patterns
//
// Definiere ein Verhalten oder einen Algorithmus, in dem bestimmte Schritte zur
// Implementierung oder Modifikation in Unterklassen vorgesehen sind. Die
// Unterklassen können individuelle Schritte, die vom Algorithmus ausgeführt
// werden überschreiben, haben aber keinen Einfluss auf seine Gesamtstruktur.

// %% [markdown]
//
// ### Motivation für das Template Method Pattern
//
// - Eine Anwendung, die mit verschiedenen Arten von Dokumenten umgehen muss
// - Gemeinsame Funktionalität in einer Basisklasse implementiert
// - Unterklassen spezialisieren einzelne Schritte

// %% [markdown]
//
// ### Klassendiagramm
//
// <img src="img/template_method_example.svg"
//      style="display:block;margin:auto;width:40%"/>

// %%
#include <iostream>
#include <string>

// %%
class Document {
public:
    virtual ~Document() = default;

    void Save() {
        std::cout << "Saving to existing file.\n";
        DoSave();
        std::cout << "Document saved.\n\n";
    }

    void SaveAs() {
        std::cout << "Asking user for file name.\n";
        DoSave();
        std::cout << "Document saved.\n\n";
    }

protected:
    virtual void DoSave() = 0;
};

// %%
class TextDocument : public Document {
    void DoSave() override { std::cout << "-> Saving text document in DOCX format.\n"; }
};

// %%
class SpreadsheetDocument : public Document {
    void DoSave() override { std::cout << "-> Saving spreadsheet in XLSX format.\n"; }
};

// %%
SpreadsheetDocument spreadsheet;
spreadsheet.Save();
spreadsheet.SaveAs();

// %%
TextDocument text;
text.Save();
text.SaveAs();


// %% [markdown]
//
// ### Struktur des Template Method Patterns
//
// <img src="img/pat_template_method.svg"
//      style="display:block;margin:auto;width:40%"/>

// %% [markdown]
//
// ## Implementierung mit Templates

// %%
template <typename T>
class DocumentV1 {
public:
    void Save() {
        std::cout << "Saving to existing file.\n";
        T::DoSave();
        std::cout << "Document saved.\n\n";
    }

    void SaveAs() {
        std::cout << "Asking user for file name.\n";
        T::DoSave();
        std::cout << "Document saved.\n\n";
    }
};

// %%
class TextDocumentV1 {
public:
    static void DoSave() { std::cout << "-> Saving text document in DOCX format.\n"; }
};

// %%
class SpreadsheetDocumentV1 {
public:
    static void DoSave() { std::cout << "-> Saving spreadsheet in XLSX format.\n"; }
};

// %% [markdown]
//
// - Spezialisierte Funktionen müssen `static` sein und haben keinen Zugriff auf
//   Objektdaten
// - Wir können nicht mit `TextDocumentV1` und `SpreadsheetDocumentV1` arbeiten,
//   ohne sie in ein `DocumentV1`-Objekt einzupacken

// %%
DocumentV1<TextDocumentV1> textV1;
textV1.Save();

// %%
DocumentV1<SpreadsheetDocumentV1> spreadsheetV1;
spreadsheetV1.Save();

// %% [markdown]
//
// # Implementierung mit CRTP
//
// - "Oberklasse" `Base` bekommt "abgeleitete Klasse" `Derived` als Template-Parameter
// - `Base` verwendet einen `static_cast`, um den `this`-Pointer in einen Pointer
//   auf `Derived` zu konvertieren
// - `Derived` erbt von `Base<Derived>`
// - Wir erreichen den gleichen Effekt wie mit dem Template-Method Pattern,
//   sparen aber einen virtuellen Dispatch


// %%
template <typename Derived>
class DocumentV2 {
public:
    void Save() {
        std::cout << "Saving to existing file.\n";
        static_cast<Derived*>(this)->DoSave();
        std::cout << "Document saved.\n\n";
    }

    void SaveAs() {
        std::cout << "Asking user for file name.\n";
        static_cast<Derived*>(this)->DoSave();
        std::cout << "Document saved.\n\n";
    }
};


// %%
class TextDocumentV2 : public DocumentV2<TextDocumentV2> {
public:
    void DoSave() { std::cout << "-> Saving text document in DOCX format.\n"; }
};

// %%
class SpreadsheetDocumentV2 : public DocumentV2<SpreadsheetDocumentV2> {
public:
    void DoSave() { std::cout << "-> Saving spreadsheet in XLSX format.\n"; }
};

// %% [markdown]
//
// - Jetzt können wir direkt mit `TextDocumentV2` und `SpreadsheetDocumentV2` arbeiten
// - `DoSave` ist eine normale Member-Funktion, die auf Objektdaten zugreifen kann

// %%
TextDocumentV2 textV2;
textV2.Save();

// %%
SpreadsheetDocumentV2 spreadsheetV2;
spreadsheetV2.Save();

// %% [markdown]
//
// ## CRTP in der Standardbibliothek
//
// - `std::enable_shared_from_this`
// - `ranges::view_interface`

// %% [markdown]
//
// ## Konsequenzen von CRTP
//
// - Kein virtueller Dispatch
// - Keine polymorphen Container möglich
// - Kein dynamischer Austausch von Implementierungen möglich

// %% [markdown]
//
// ## C++ 23
//
// Statt
//
// ```cpp
// template <class Derived>
// struct Base { void Fun() { (static_cast<Derived*>(this))->Impl(); } };
// ```
//
// kann die Basisklasse mit explizitem `this`-Parameter definiert werden:
//
// ```cpp
// struct Base { void Fun(this auto&& self) { self.Impl(); } };
// ```
