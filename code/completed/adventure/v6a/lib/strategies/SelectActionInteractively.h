// Copyright (c) 2023 Dr. Matthias Hölzl. All rights reserved.

#pragma once
#ifndef COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTACTIONINTERACTIVELY_H
#define COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTACTIONINTERACTIVELY_H

#include "SelectActionStrategy.h"
namespace adventure::v6a {

class SelectActionInteractively : public SelectActionStrategy {
public:
    SelectActionInteractively() = default;
    [[nodiscard]] ActionPtr SelectAction(
        const Player& player, const ActionVec& actions) const override;
    [[nodiscard]] bool IsInteractive() const override;
};

} // namespace adventure::v6a

#endif // COMPLETED_ADVENTURE_V6A_LIB_STRATEGIES_SELECTACTIONINTERACTIVELY_H
