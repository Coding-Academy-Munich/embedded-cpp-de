// -*- coding: utf-8 -*-
// %% [markdown]
// <!--
// clang-format off
// -->
//
// <div style="text-align:center; font-size:200%;">
//  <b>SOLID: Dependency-Inversions-Prinzip</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 12 SOLID Dependency-Inversions-Prinzip.cpp -->
// <!-- slides/module_500_solid_grasp/topic_400_solid_dip.cpp -->

// %% [markdown]
//
// # Abhängigkeiten
//
// - Wir müssen zwei Arten von Abhängigkeiten unterscheiden:
//   - Daten- und Kontrollfluss
//   - Quellcode-Abhängigkeiten
// - Daten- und Kontrollfluss-Abhängigkeiten sind inhärent in der Logik
// - Quellcode-Abhängigkeiten können wir durch die Architektur kontrollieren

// %% [markdown]
//
// ## Beispiel
//
// - Modul `MyModule.cpp` schreibt Daten in eine Datenbank
// - Datenfluss: von `MyModule.cpp` zur Datenbank
// - Quellcode-Abhängigkeit: `MyModule.cpp` hängt von der Datenbank (`Database.h`) ab

// %% [markdown]
//
// Modul `MyModule.cpp`:

// %%
#include <string>
#include <vector>
#include <xcpp/xdisplay.hpp>

#include "Database.h"

// %%
class MyDomainClassV1
{
public:
    void PerformWork(std::string data)
    {
        data = "Processed: " + data;
        db.Execute("INSERT INTO my_table VALUES (?)", data);
    }

    std::vector<std::string> RetrieveResult()
    {
        return db.Execute("SELECT * FROM my_table");
    }

private:
    Database db;
};

// %%
MyDomainClassV1 myDomainObjectV1{};

// %%
myDomainObjectV1.PerformWork("Hello World");

// %%
xcpp::display(myDomainObjectV1.RetrieveResult());

// %% [markdown]
//
// Die Quellcode-Abhängigkeit geht in die gleiche Richtung wie der Datenfluss:
//
// `MyModule.cpp` ⟹ `Database.h`
//
// <img src="img/db-example-01.svg"
//      style="display:block;margin:auto;width:75%"/>

// %% [markdown]
//
// Wir würden derartige Abhängigkeiten im Kern unsere Anwendung gerne vermeiden
//
// - Einfacher zu testen
// - Einfacher zu erweitern
// - Einfacher externe Abhängigkeiten zu ersetzen
// - Einfacher den Code zu verstehen
// - ...

// %% [markdown]
//
// <img src="img/db-example-02.svg"
//      style="display:block;margin:auto;width:75%"/>

// %% [markdown]
//
// - Modul `MyModule.cpp`:
//   - Keine Abhängigkeit mehr zu `Database.h`
//   - Adapter Pattern

// %%
class AbstractDatabaseAdapter
{
public:
    AbstractDatabaseAdapter() = default;
    virtual ~AbstractDatabaseAdapter() = default;

    virtual void SaveObject(std::string data) = 0;
    virtual std::vector<std::string> RetrieveData() = 0;
};

// %%
class MyDomainClassV2
{
public:
    MyDomainClassV2(std::unique_ptr<AbstractDatabaseAdapter> db) : db_{std::move(db)} {}

    void PerformWork(std::string data)
    {
        data = "Processed: " + data;
        db_->SaveObject(data);
    }

    std::vector<std::string> RetrieveResult() { return db_->RetrieveData(); }

private:
    std::unique_ptr<AbstractDatabaseAdapter> db_;
};

// %% [markdown]
//
// - Modul `ConcreteDatabaseAdapter.cpp/.h`:
//   - Implementiert `AbstractDatabaseAdapter` für `Database.h`
//   - Hängt von `Database.h` ab

// %%
#include "Database.h"

// %%
class ConcreteDatabaseAdapter : public AbstractDatabaseAdapter
{
public:
    void SaveObject(std::string data) override
    {
        db_.Execute("INSERT INTO my_table VALUES (?)", data);
    }

    std::vector<std::string> RetrieveData() override
    {
        return db_.Execute("SELECT * FROM my_table");
    }

private:
    Database db_;
};

// %% [markdown]
//
// - Modul `main.cpp`:

// %%
// #include "ConcreteDatabaseAdapter.h"
// #include "MyDomainClassV2.h"

// %%
auto dbAdapter{std::make_unique<ConcreteDatabaseAdapter>()};
MyDomainClassV2 myDomainObjectV2{std::move(dbAdapter)};

// %%
myDomainObjectV2.PerformWork("Hello World");

// %%
xcpp::display(myDomainObjectV2.RetrieveResult());

// %% [markdown]
//
// # SOLID: Dependency Inversion Prinzip
//
// - Die Kernfunktionalität eines Systems hängt nicht von seiner Umgebung ab
//   - **Konkrete Artefakte hängen von Abstraktionen ab** (nicht umgekehrt)
//   - **Instabile Artefakte hängen von stabilen Artefakten ab** (nicht umgekehrt)
//   - **Äußere Schichten** der Architektur **hängen von inneren Schichten ab**
//     (nicht umgekehrt)
//   - Klassen/Module hängen von Abstraktionen (z. B. Schnittstellen) ab,
//     nicht von anderen Klassen/Modulen
// - Abhängigkeitsinversion (Dependency Inversion) erreicht dies durch die Einführung
//   von Schnittstellen, die "die Abhängigkeiten umkehren"

// %% [markdown]
//
// ### Vorher
// <img src="img/dependency-01.svg"
//      style="display:block;margin:auto;width:75%"/>
//
// ### Nachher
// <img src="img/dependency-02.svg"
//      style="display:block;margin:auto;width:75%"/>

// %% [markdown]
//
// <img src="img/dip-01.svg"
//      style="display:block;margin:auto;width:95%"/>

// %% [markdown]
//
// <img src="img/dip-02.svg"
//      style="display:block;margin:auto;width:95%"/>

// %% [markdown]
//
// <img src="img/dip-03.svg"
//      style="display:block;margin:auto;width:95%"/>

// %% [markdown]
//
// ## Workshop: Wetterbericht
//
// Wir haben ein Programm geschrieben, das einen Wetterbericht von einem Server
// abruft. Leider ist dabei die Abhängigkeit zum Server vom Typ
// `LegacyWeatherServer` hart kodiert. Aufgrund der Popularität des Programms
// müssen wir jedoch mit einem neuen Typ von Server `NewWeatherServer`
// kompatibel werden. Dazu refaktorisieren wir den Code nach dem
// Dependency-Inversion-Prinzip und Implementieren dann einen zusätzlichen
// Adapter für `NewWeatherServer`.
//
// - Führen Sie eine Abstraktion ein, um die Abhängigkeit umzukehren
// - Schreiben Sie eine konkrete Implementierung der Abstraktion für
//   `LegacyWeatherServer`
// - Testen Sie die Implementierung
// - Implementieren Sie einen Adapter für `NewWeatherServer`
// - Testen Sie den Adapter

// %%
#include <iostream>
#include <random>
#include <string>
#include <tuple>
#include <vector>

// %%
class WeatherReport
{
public:
    WeatherReport(double temperature, double humidity)
        : temperature_{temperature}, humidity_{humidity}
    {}

    double GetTemperature() const { return temperature_; }
    double GetHumidity() const { return humidity_; }

private:
    double temperature_;
    double humidity_;
};

// %%
class LegacyWeatherServer
{
public:
    WeatherReport GetWeatherReport()
    {
        static std::random_device rd;
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{0.0, 1.0};
        return WeatherReport{20.0 + 10.0 * dis(gen), 0.5 + 0.5 * dis(gen)};
    }
};

// %%
class NewWeatherServer
{
public:
    std::tuple<double, double> FetchWeatherData()
    {
        static std::random_device rd;
        static std::mt19937 gen{rd()};
        static std::uniform_real_distribution<> dis{0.0, 1.0};
        return {10.0 + 20.0 * dis(gen), 0.7 + 0.4 * dis(gen)};
    }
};

// %%
class WeatherReporter
{
public:
    WeatherReporter(std::shared_ptr<LegacyWeatherServer> server)
        : server{std::move(server)}
    {}

    std::string Report()
    {
        WeatherReport report{server->GetWeatherReport()};
        if (report.GetTemperature() > 25.0f)
        {
            return "It's hot";
        }
        else
        {
            return "It's not hot";
        }
    }

private:
    std::shared_ptr<LegacyWeatherServer> server;
};

// %%
std::shared_ptr<LegacyWeatherServer> server{std::make_shared<LegacyWeatherServer>()};
WeatherReporter reporter{server};

// %%
xcpp::display(reporter.Report());

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%
