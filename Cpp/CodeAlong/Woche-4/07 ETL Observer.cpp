// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//  <b>ETL Observer</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Akademie München</div>
// <br/>
// <!-- 07 ETL Observer.cpp -->
// <!-- slides/module_470_cpp_patterns/topic_400_etl_observer.cpp -->

// %% [markdown]
//
// - Implementierung des Push-Observer Patterns
// - `etl::observer<T...>`: Interface für Observer
//    - Rein virtuelle Methode `void notification(T)` für jeden Typ `T`
// - `etl::observable<TObserver>`: Interface für Observable (Subject)
//    - `void add_observer(TObserver&)`
//    - `void remove_observer(TObserver&)`
//    - `void notify_observers(T)` für jeden Typ `T` von `TObserver`

// %% [markdown]
//
// - Beispiel:
//   - Target: `etl_observer`
//   - Dateien: `code/completed/etl_examples/etl_observer*`
