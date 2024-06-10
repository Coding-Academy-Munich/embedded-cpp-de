// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Schreiben von guten Unit-Tests</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 01 Schreiben von guten Unit-Tests.cpp -->
// <!-- slides/module_410_unit_testing/topic_165_writing_good_unit_tests.cpp -->

// %% [markdown]
//
// ## Mechanik von Unit-Tests
//
// Unit-Tests sollen
// - automatisiert sein: keine manuelle Interaktion
// - selbsttestend sein: Pass/Fail
// - feingranular sein
// - schnell sein
// - isoliert sein
// - zu jedem Zeitpunkt erfolgreich ausführbar sein

// %% [markdown]
//
// ## Einfache Struktur!
//
// <ul>
//   <li>Einfache, standardisierte Struktur<br>
//     <table style="display:inline;margin:20px 20px;">
//     <tr><td style="text-align:left;width:60px;padding-left:15px;">Arrange</td>
//         <td style="text-align:left;width:60px;padding-left:15px;border-left:1px solid
//         black;">Given</td> <td
//         style="text-align:left;width:300px;padding-left:15px;border-left:1px solid
//         black;">
//           Bereite das Test-Environment vor</td></tr>
//     <tr><td style="text-align:left;padding-left:15px;">Act</td>
//         <td style="text-align:left;width:60px;padding-left:15px;border-left:1px solid
//         black;">
//            When</td>
//         <td style="text-align:left;width:300px;padding-left:15px;border-left:1px
//         solid black;">
//            Führe die getestete Aktion aus (falls vorhanden)</td></tr>
//     <tr><td style="text-align:left;padding-left:15px;">Assert</td>
//         <td style="text-align:left;width:60px;padding-left:15px;border-left:1px solid
//         black;">
//            Then</td>
//         <td style="text-align:left;width:300px;padding-left:15px;border-left:1px
//         solid black;">
//            Überprüfe die Ergebnisse</td></tr>
//     </table>
//   </li>
//   <li>Wenig Code
//     <ul>
//       <li>Wenig Boilerplate</li>
//       <li>Factories, etc. für Tests</li>
//     </ul>
//   </li>
// </ul>

// %%
#include "check.h"

// %%
#include <vector>

// %%
void test_insert()
{
    std::vector<int> x = {1, 2, 3}; // arrange
    std::vector<int> y = {10, 20};

    x.insert(x.end(), y.begin(), y.end()); // act

    check(x == std::vector<int>{1, 2, 3, 10, 20}); // assert
}

// %% [markdown]
//
// - Wie viele Tests wollen wir haben?
// - Wie viele Werte wollen wir überprüfen?

// %% [markdown]
//
// ## Versuch: Erschöpfendes Testen
//
// - Wir schreiben erschöpfende Tests, d.h. Tests, die alle möglichen Eingaben eines
//   Programms abdecken

// %% [markdown]
//
// - Erschöpfendes Testen ist nicht möglich
// - Beispiel Passworteingabe:
//   - Angenommen, Passwörter mit maximal 20 Zeichen sind zulässig,
//     80 Eingabezeichen sind erlaubt (große und kleine Buchstaben, Sonderzeichen)
//   - Das ergibt $80^{20}$ = 115.292.150.460.684.697.600.000.000.000.000.000.000
//     mögliche Eingaben
//   - Bei 10ns für einen Test würde man ca. $10^{24}$ Jahre brauchen, um alle Eingaben
//     zu testen
//   - Das Universum ist ungefähr $1.4 \times 10^{10}$ Jahre alt

// %% [markdown]
//
// ## Effektivität und Effizienz von Tests
//
// - Unit-Tests sollen effektiv und effizient sein
//   - Effektiv: Die Tests sollen so viele Fehler wie möglich finden
//   - Effizient: Wir wollen die größte Anzahl an Fehlern mit der geringsten Anzahl
//     an möglichst einfachen Tests finden
// - Effizienz ist wichtig, da Tests selbst Code sind, der gewartet werden muss und
//   Fehler enthalten kann

// %% [markdown]
//
// ## Wie schreibt man gute Unit-Tests?
//
// - Teste beobachtbares Verhalten, nicht Implementierung
// - Bevorzuge Tests von Werten gegenüber Tests von Zuständen
// - Bevorzuge Tests von Zuständen gegenüber Tests von Interaktion
// - Verwende Test-Doubles dann (aber auch nur dann), wenn eine Abhängigkeit
//   "eine Rakete abfeuert"
// - (Diese Regeln setzen voraus, dass der Code solche Tests erlaubt)

// %% [markdown]
//
// ### Warum Tests von beobachtbarem Verhalten, nicht Implementierung?
//
// Beobachtbares Verhalten
// - ist leichter zu verstehen
// - ist stabiler als Implementierung
// - entspricht eher dem Kundennutzen

// %% [markdown]
//
// ## Teste beobachtbares Verhalten, nicht Implementierung
//
// - Abstrahiere so weit wie möglich von Implementierungsdetails
//   - Auch auf Unit-Test Ebene
// - Oft testen sich verschiedene Methoden gegenseitig
// - Dies erfordert manchmal die Einführung von zusätzlichen Methoden
//     - Diese Methoden sollen für Anwender sinnvoll sein, nicht nur für Tests
//     - Oft "abstrakter Zustand" von Objekten
//     - **Nicht:** konkreten Zustand öffentlich machen

// %%
#include <vector>

// %%
class Stack
{
private:
    std::vector<int> _items;

public:
    void push(int new_item) { _items.push_back(new_item); }

    int pop();

    // Good extension: useful, doesn't expose implementation
    int size() const { return _items.size(); }

    // Bad extension: exposes implementation
    std::vector<int>& get_items() { return _items; }
};

// %%
int Stack::pop()
{
    if (_items.empty())
    {
        throw std::out_of_range("Stack is empty");
    }
    int val = _items.back();
    _items.pop_back();
    return val;
}

// %% [markdown]
//
// ### Tests, wenn nur `push()` und `pop()` verfügbar sind

// %%
void test_stack_1()
{
    Stack s;
    s.push(5);
    check(s.pop() == 5);
}

// %%
test_stack_1();

// %%
void test_stack_2()
{
    Stack s;
    s.push(5);
    s.push(10);
    check(s.pop() == 10);
    check(s.pop() == 5);
}

// %%
test_stack_2();

// %%
void test_stack_3()
{
    Stack s;
    try
    {
        s.pop();
        check(false);
    }
    catch (const std::out_of_range&)
    {
        check(true);
    }
}

// %%
test_stack_3();

// %% [markdown]
//
// ## Werte > Zustand > Interaktion
//
// - Verständlicher
// - Leichter zu testen
// - Oft stabiler gegenüber Refactorings
//
// Ausnahme: Testen von Protokollen

// %% [markdown]
//
// ### Funktionen/Werte

// %%
int add(int x, int y) { return x + y; }

// %%
check(add(2, 3) == 5);

// %% [markdown]
//
// ### Zustand

// %%
class Adder
{
public:
    void set_x(int x) { x_ = x; }
    void set_y(int y) { y_ = y; }
    void add() { result_ = x_ + y_; }
    int get_result() const { return result_; }

private:
    int x_{0};
    int y_{0};
    int result_{0};
};

// %%
Adder adder;

// %%
adder.set_x(2);
adder.set_y(3);

// %%
adder.add();

// %%
check(adder.get_result() == 5);

// %% [markdown]
//
// ### Seiteneffekt/Interaktion
//
// - Mit Interface

// %%
class AbstractAdder
{
public:
    virtual void add(int x, int y) = 0;
};

// %%
class InteractionAdder
{
public:
    InteractionAdder(AbstractAdder& adder) : adder_{adder} {}

    void add(int x, int y) { adder_.add(x, y); }

private:
    AbstractAdder& adder_;
};

// %% [markdown]
//
// Test benötigt Mock/Spy

// %%
#include <utility>
#include <vector>

// %%
struct AdderSpy : AbstractAdder
{
    std::vector<std::pair<int, int>> calls;
    void add(int x, int y) override { calls.push_back({x, y}); };
};

// %%
AdderSpy spy;

// %%
InteractionAdder adder{spy};

// %%
adder.add(2, 3);

// %%
check(spy.calls.size() == 1);

// %%
check(spy.calls[0].first == 2);
check(spy.calls[0].second == 3);

// %% [markdown]
//
// ### Seiteneffekt/Interaktion
//
// - Ohne Interface

// %%
void add_and_print(int x, int y) { std::cout << x + y << std::endl; }

// %% [markdown]
//
// - Siehe `code/completed/test_examples/fun_state_interact_test.cpp` für
//   den Test-Code

// %% [markdown]
//
// ## Wie schreibt man testbaren Code?
//
// - Umwandeln von weniger testbarem in besser testbaren Stil
//   - Beobachtbarkeit (`state_machine.h`)
//   - Keine globalen oder statischen Daten
//   - Unveränderliche Datenstrukturen (Werte)
// - Gutes objektorientiertes Design
//   - Hohe Kohäsion
//   - Geringe Kopplung, Management von Abhängigkeiten
// - Etc.

// %% [markdown]
//
// ## Prozess
//
// - Iteratives Vorgehen
//   - Kleine Schritte mit Tests
// - Test-Driven Development (TDD)
//   - Schreiben von Tests vor Code

// %% [markdown]
//
// ## Mini-Workshop: Bessere Testbarkeit
//
// - Wie können Sie Tests für die folgenden Funktionen/Klassen schreiben?
// - Wie können Sie die folgenden Funktionen/Klassen verbessern, um sie besser
//   testbar zu machen?
// - Was für Nachteile ergeben sich dadurch?

// %%
#include <iostream>

// %%
int count()
{
    static int c = 0;
    return c++;
}

// %%
for (int i = 0; i < 3; ++i)
{
    std::cout << count() << std::endl;
}

// %%
class Counter
{
public:
    int operator()() { return c_++; }

private:
    int c_{};
};

// %%
Counter counter;

// %%
for (int i = 0; i < 3; ++i)
{
    std::cout << counter() << std::endl;
}

// %%
enum class State
{
    OFF,
    ON
};

// %%
class Switch
{
public:
    void toggle()
    {
        state_ = state_ == State::OFF ? State::ON : State::OFF;
        std::cout << "Switch is " << (state_ == State::OFF ? "OFF" : "ON") << std::endl;
    }

private:
    State state_{State::OFF};
};

// %%
Switch s;

// %%
for (int i = 0; i < 3; ++i)
{
    s.toggle();
}

// %%
class SwitchWithGetter
{
public:
    void toggle()
    {
        state_ = state_ == State::OFF ? State::ON : State::OFF;
        std::cout << "Switch is " << (state_ == State::OFF ? "OFF" : "ON") << std::endl;
    }

    State get_state() const { return state_; }

private:
    State state_{State::OFF};
};

// %%
SwitchWithGetter sg;

// %%
for (int i = 0; i < 3; ++i)
{
    sg.toggle();
}

// %%
std::cout << "Switch is " << (sg.get_state() == State::OFF ? "OFF" : "ON") << std::endl;


// %%
class ObservableSwitch
{
public:
    void toggle()
    {
        state_ = state_ == State::OFF ? State::ON : State::OFF;
        notify(state_);
    }

    void register_observer(std::function<void(State)> f) { observers_.push_back(f); }

private:
    void notify(State s)
    {
        for (auto& f : observers_)
        {
            f(s);
        }
    }

    State state_{State::OFF};
    std::vector<std::function<void(State)>> observers_;
};

// %%
ObservableSwitch os;

// %%
os.register_observer([](State s) {
    std::cout << "Switch is " << (s == State::OFF ? "OFF" : "ON") << std::endl;
});

// %%
for (int i = 0; i < 3; ++i)
{
    os.toggle();
}

// %%
void print_fib(int n)
{
    int a{0};
    int b{1};
    for (int i{0}; i < n; ++i)
    {
        std::cout << "fib(" << i << ") = " << b << std::endl;
        int tmp{a};
        a = b;
        b = tmp + b;
    }
}

// %%
print_fib(5);

// %%
int fib1(int n)
{
    int a{0};
    int b{1};
    for (int i{0}; i < n; ++i)
    {
        int tmp{a};
        a = b;
        b = tmp + b;
    }
    return b;
}

// %%
void print_fib1(int n)
{
    for (int i{0}; i < n; ++i)
    {
        std::cout << "fib(" << i << ") = " << fib1(i) << std::endl;
    }
}

// %%
print_fib1(5);

// %%
void fib_gen(int n, std::function<void(int, int)> f)
{
    int a{0};
    int b{1};
    for (int i{0}; i < n; ++i)
    {
        f(i, b);
        int tmp{a};
        a = b;
        b = tmp + b;
    }
}

// %%
void print_fib2(int n)
{
    fib_gen(n, [](int i, int x) {
        std::cout << "fib(" << i << ") = " << x << std::endl;
    });
}

// %%
print_fib2(5);

// %%
