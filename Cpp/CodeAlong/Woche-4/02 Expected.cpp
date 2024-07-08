// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>Expected</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 02 Expected.cpp -->
// <!-- slides/module_180_error_handling/topic_310_expected.cpp -->

// %% [markdown]
//
// ## Implementierungen
//
// - Standard (C++23):
// [`std::expected`](https://en.cppreference.com/w/cpp/utility/expected)
// - TartanLlama: [`tl.expected`](https://github.com/TartanLlama/expected)
// - ETL: [`etl::expected`](https://www.etlcpp.com/expected.html)

// %% [markdown]
//
// - `std::expected<T, E>` ist ein Typ, der entweder ein Objekt vom Typ `T` oder
//   ein Objekt vom Typ `E` enthält.
// - `T` repräsentiert den Erfolgsfall
// - `E` repräsentiert den Fehlerfall
// - `bool(ex)` oder `ex.has_value()`: Wahr im Erfolgsfall
// - `*ex` oder `ex.value()`: Zugriff auf den Wert
// - `ex.error()`: Zugriff auf den Fehler

// %%
#include "expected.hpp"
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>

// %%
enum class Error
{
    camera_not_available,
    lidar_not_available,
}

// %%
std::string
error_string(Error error)
{
    switch (error)
    {
    case Error::camera_not_available:
        return "Camera not available!";
    case Error::lidar_not_available:
        return "Lidar not available!";
    default:
        return "Unexpected error!";
    }
}

// %%
constexpr std::byte camera_bit{0b0001};
constexpr std::byte lidar_bit{0b0010};


// %%
int to_int(std::byte byte) { return static_cast<int>(byte); }


// %%
tl::expected<std::byte, Error> initialize_camera(bool success)
{
    std::cout << "Initializing camera..." << std::endl;
    if (success)
    {
        return camera_bit;
    }
    else
    {
        return tl::unexpected(Error::camera_not_available);
    }
}

// %%
tl::expected<std::byte, Error> initialize_lidar(bool success)
{
    std::cout << "Initializing lidar..." << std::endl;
    if (success)
    {
        return lidar_bit;
    }
    else
    {
        return tl::unexpected(Error::lidar_not_available);
    }
}

// %%
tl::expected<std::byte, Error> initialize_sensors(
    bool camera_success = true, bool lidar_success = true
)
{
    std::cout << "Initializing sensors..." << std::endl;

    auto camera = initialize_camera(camera_success);
    if (!camera.has_value())
    {
        return tl::unexpected<Error>{camera.error()};
    }

    auto lidar = initialize_lidar(lidar_success);
    if (!lidar)
    {
        return lidar;
    }

    return *camera | *lidar;
}

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Monadische Fehlerbehandlung
//
// - Es gibt Methoden, die die Fehlerbehandlung vereinfachen.
// - `and_then()` erlaubt es, eine Funktion aufzurufen, wenn der Erfolgsfall
//   eintritt.
//   - Diese Funktion bekommt den Wert übergeben.
// - `or_else()` erlaubt es, eine Funktion aufzurufen, wenn der Fehlerfall
//   eintritt.
// - Man nennt diese Funktionen `monadische Operationen`.

// %%
tl::expected<std::byte, Error> initialize_sensors_monadic(
    bool camera_success = true, bool lidar_success = true
)
{
    std::cout << "Initializing sensors (monadic)..." << std::endl;

    return initialize_camera(camera_success)
        .and_then([lidar_success](std::byte camera_bit) {
            return initialize_lidar(lidar_success)
                .and_then(
                    [camera_bit](std::byte lidar_bit
                    ) -> tl::expected<std::byte, Error> {
                        return camera_bit | lidar_bit;
                    }
                );
        });
}

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %%

// %% [markdown]
//
// ### Code Beispiele
//
// - STL
//   - Target: `expected`
//   - Dateien: `code/completed/error_handling/expected*`
// - ETL
//   - Target: `etl_expected`
//   - Dateien: `code/completed/etl_examples/etl_expected*`

// %% [markdown]
//
// ## Workshop: Kontrolle eines Motors
//
// In diesem Workshop implementieren Sie ein einfaches Motorsteuerungssystem
// unter Verwendung von `std::expected` zur Behandlung potenzieller Fehler.
//
// Das System wird eine Klasse `Motor` mit den folgenden Memberfunktionen
// enthalten:
//
// - `start_motor()`,
// - `set_speed()` und
// - `stop_motor()`.
//
// Jede Memberfunktion sollte in der Lage sein, Fehler mit aussagekräftigen
// Fehlermeldungen zu melden.

// %% [markdown]
//
// - Definieren Sie Fehlerarten: Erstellen Sie eine Enum-Klasse `MotorError`,
//   die mögliche Fehler für jede Funktion auflistet.
// - Implementieren Sie die Klasse `Motor` mit den folgenden Attributen:
//   - `double fuel_level`: Der Kraftstoffstand des Motors.
//   - `double current_speed`: Die aktuelle Geschwindigkeit des Motors.
// - Implementieren Sie die folgenden Memberfunktionen:
//   - `start_motor()`: Simuliert das Starten des Motors.
//     - Soll `tl::expected<double, MotorError>` zurückgeben
//     - Im Erfolgsfall ist der Rückgabewert die Motorgeschwindigkeit
//     - Mögliche Fehler sind `no_fuel`, `motor_already_running`.
//   - `set_speed(double speed)`: Simuliert das Einstellen der
//     Motorgeschwindigkeit.
//     - Soll `tl::expected<void, Error>` zurückgeben
//     - Erlaubte Geschwindigkeiten liegen zwischen 10,0 und 100,0.
//     - Mögliche Fehler sind `speed_too_low`, `speed_too_high`,
//       `motor_not_running`.
//   - `stop_motor()`: Simuliert das Stoppen des Motors.
//     - Soll `tl::expected<void, Error>` zurückgeben
//     - Der einzige mögliche Fehler ist `motor_not_running`.
// - Testen Sie jede Ihrer Motorsteuerungsfunktionen.

// %%

// %%
