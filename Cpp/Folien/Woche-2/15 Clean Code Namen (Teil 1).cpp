// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Clean Code: Namen (Teil 1)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 15 Clean Code Namen (Teil 1).cpp -->
// <!-- slides/module_420_clean_code/topic_130_names_part1.cpp -->

// %% [markdown]
//
// Namen sind ein mächtiges Kommunikationsmittel.
//
// - Sie sind überall im Programm zu finden
// - Sie verbinden den Code mit Domänen-Konzepten.

// %%
#include <iostream>
#include <stdexcept>

// %%
double foo(double a, double b)
{
    if (b > 40.0)
    {
        throw std::invalid_argument("Not allowed!");
    }
    return 40.0 * a + 60.0 * b;
}

// %%
std::cout << foo(40.0, 3.5);

// %%
constexpr double regular_pay_per_hour{40.0};
constexpr double overtime_pay_per_hour{60.0};
constexpr double max_allowed_overtime{40.0};

// %%
double compute_total_salary(double regular_hours_worked, double overtime_hours_worked)
{
    if (overtime_hours_worked > max_allowed_overtime)
    {
        throw std::invalid_argument("Not allowed!");
    }
    const double regular_pay{regular_hours_worked * regular_pay_per_hour};
    const double overtime_pay{overtime_hours_worked * overtime_pay_per_hour};
    return regular_pay + overtime_pay;
}

// %%
std::cout << compute_total_salary(40.0, 3.5);

// %% [markdown]
//
// ### Enumerationen

// %%
constexpr int high{0};
constexpr int medium{1};
constexpr int low{2};

// %%
int severity{high};

// %%
enum class Severity
{
    High,
    Medium,
    Low
}

// %%
Severity severity{Severity::High};

// %% [markdown]
//
// ### Klassen und Structs

// %%
#include <string>
#include <utility>

// %%
std::pair<int, std::string> analyze_review(const std::string& text)
{
    return {5, "Overall positive"};
}

// %%
struct Issue
{
    int score;
    std::string sentiment;
};

// %%
Issue analyze_review(const std::string& text) { return {5, "Overall positive"}; }

// %% [markdown]
//
// ## Was ist ein guter Name?
//
// - Präzise (sagt was er meint, meint was er sagt)
// - Beantwortet
//   - Warum gibt es diese Variable (Funktion, Klasse, Modul, Objekt...)?
//   - Was macht sie?
//   - Wie wird sie verwendet?
//
// Gute Namen sind schwer zu finden!

// %% [markdown]
//
// ## Was ist ein schlechter Name?
//
// - Braucht einen Kommentar
// - Verbreitet Disinformation
// - Entspricht nicht den Namensregeln

// %% [markdown]
//
// ## Workshop: Rezepte
//
// In `code/starter_kits/recipes_sk` ist ein Programm, mit denen sich ein
// Kochbuch verwalten lässt. Leider hat der Programmierer sehr schlechte Namen
// verwendet, dadurch ist das Programm schwer zu verstehen.
//
// Ändern Sie die Namen so, dass das Programm leichter verständlich wird.
//
// ### Hinweis
//
// Verwenden Sie die Refactoring-Tools Ihrer Entwicklungsumgebung!
