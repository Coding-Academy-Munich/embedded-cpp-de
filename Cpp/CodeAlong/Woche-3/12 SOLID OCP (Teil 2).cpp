// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>SOLID: OCP (Teil 2)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 SOLID OCP (Teil 2).cpp -->
// <!-- slides/module_500_solid_grasp/topic_340_solic_ocp_part2.cpp -->

// %% [markdown]
//
// ## Wiederholung: OCP-Verletzung
//
// <img src="img/movie_v0.svg" alt="MovieV0"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Lösungsversuch 1: Vererbung
//
// <img src="img/movie_v2.svg" alt="MovieV2"
//      style="display:block;margin:auto;width:70%"/>

// %% [markdown]
//
// - OCP ist erfüllt
// - Großer Scope der Vererbung
//   - Preisberechnung ist das wichtigste an Filmen?
// - Nur eindimensionale Klassifikation
// - Keine Möglichkeit, Preisschema zu wechseln

// %% [markdown]
//
// ## Lösungsversuch 2: Strategie-Muster
//
// <img src="img/movie_v3.svg" alt="MovieV3"
//      style="display:block;margin:auto;width:80%"/>

// %% [markdown]
//
// - OCP ist erfüllt
// - Vererbung ist auf die Preisberechnung beschränkt
// - Mehrdimensionale Klassifikation ist einfach
// - Preisschema kann zur Laufzeit gewechselt werden

// %% [markdown]
//
// ## Implementierung

// %%
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %%
class Movie;

// %%
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double ComputePrice(const Movie&) const = 0;
};

// %%
class RegularPriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 4.99; }
};


// %%
class ChildrenPriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 5.99; }
};

// %%
class NewReleasePriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 6.99; }
};

// %%
class Movie {
public:
    Movie(std::string title, std::unique_ptr<PricingStrategy> pricing_strategy)
        : title_(std::move(title)), pricing_strategy_(std::move(pricing_strategy)) {}

    double ComputePrice() const { return pricing_strategy_->ComputePrice(*this); }

    void PrintInfo() const {
        std::cout << title_ << " costs " << ComputePrice() << std::endl;
    }

private:
    std::string title_;
    std::unique_ptr<PricingStrategy> pricing_strategy_;
};

// %%
std::vector<Movie> movies;
movies.emplace_back("Casablanca", std::make_unique<RegularPriceStrategy>());
movies.emplace_back("Shrek", std::make_unique<ChildrenPriceStrategy>());
movies.emplace_back("Brand New", std::make_unique<NewReleasePriceStrategy>());

// %%
for (const auto& movie : movies) {
    movie.PrintInfo();
}

// %% [markdown]
//
// ## Workshop: Berechnung von ÖPNV-Fahrpreisen
//
// In einer modernen Stadt stehen verschiedene öffentliche Verkehrsmittel zur
// Verfügung – Busse, U-Bahnen, Züge, Boote, etc. Jedes dieser Verkehrsmittel
// hat seine eigene Methode zur Fahrpreisberechnung. Zum Beispiel können
// Bustarife auf Pauschalpreisen basieren, U-Bahnen können auf
// Entfernungstarifen basieren und Boote können Premiumtarife für
// landschaftlich reizvolle Strecken haben.

// %% [markdown]
//
// Sie haben ein rudimentäres Fahrpreisberechnungssystem, das den Fahrpreis
// basierend auf dem Verkehrsmittel bestimmt. Leider verstößt dieses System
// gegen das OCP, da es ohne Modifikation nicht für die Erweiterung geöffnet
// ist. Jedes Mal, wenn ein neues Verkehrsmittel hinzugefügt werden muss, muss
// das Kernsystem geändert werden.
//
// Ihre Aufgabe ist es, das System so zu refaktorisieren, dass es dem OCP
// entspricht. Genauer gesagt, werden Sie die `switch`-Anweisung aus der
// Fahrpreisberechnungslogik entfernen. Das Ziel ist es, das System leicht
// erweiterbar zu machen, so dass neue Verkehrsmittel hinzugefügt werden können,
// ohne den vorhandenen Code zu ändern.

// %%
#include <iostream>

// %%
enum class TransportType
{
    BUS,
    SUBWAY,
    TRAIN,
    BOAT
};

// %%
class Transport {
public:
    Transport(TransportType type) : type_(type) {}

    double CalculateFare(double distance) {
        switch (type_) {
        case TransportType::BUS: return 2.50; // flat rate
        case TransportType::SUBWAY:
            return 1.50 + (distance * 0.20); // base rate + per km
        case TransportType::TRAIN:
            return 5.00 + (distance * 0.15);    // base rate + per km
        case TransportType::BOAT: return 10.00; // premium rate
        default: return 0.0;
        }
    }

private:
    TransportType type_;
};


// %%
Transport bus(TransportType::BUS);
std::cout << "Bus fare: $" << bus.CalculateFare(10) << "\n";

// %%
Transport subway(TransportType::SUBWAY);
std::cout << "Subway fare: $" << subway.CalculateFare(10) << "\n";

// %%
Transport train(TransportType::TRAIN);
std::cout << "Train fare: $" << train.CalculateFare(10) << "\n";

// %%
Transport boat(TransportType::BOAT);
std::cout << "Boat fare: $" << boat.CalculateFare(10) << "\n";

// %% [markdown]
//
// ## Extra-Workshop: Smart Home Device Control System mit Strategy
//
// In einem früheren Workshop haben wir ein System zur Kontrolle von Smart Home
// Devices implementiert.
//
// Lösen Sie das OCP-Problem für dieses System mit dem Strategy-Muster.

// %%
