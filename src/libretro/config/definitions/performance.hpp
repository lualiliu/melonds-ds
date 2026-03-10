/*
    Copyright 2023 Jesse Talavera-Greenberg

    melonDS DS is free software: you can redistribute it and/or modify it under
    the terms of the GNU General Public License as published by the Free
    Software Foundation, either version 3 of the License, or (at your option)
    any later version.

    melonDS DS is distributed in the hope that it will be useful, but WITHOUT ANY
    WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with melonDS DS. If not, see http://www.gnu.org/licenses/.
*/

#ifndef MELONDS_DS_PERFORMANCE_HPP
#define MELONDS_DS_PERFORMANCE_HPP

#include <libretro.h>

#include "../constants.hpp"

namespace MelonDsDs::config::definitions {
    constexpr retro_core_option_v2_definition Profile {
        config::performance::PROFILE,
        "Emulation Profile",
        nullptr,
        "Select the overall performance/accuracy profile.\n"
        "\n"
        "Accurate: prioritizes correctness.\n"
        "Speed-first: prioritizes speed and may cause major graphical, audio, timing, and save stability issues.\n"
        "\n"
        "Changes take effect immediately.",
        nullptr,
        config::performance::CATEGORY,
        {
            {config::values::ACCURATE, "Accurate"},
            {config::values::SPEED, "Speed-first"},
            {nullptr, nullptr},
        },
        config::values::ACCURATE,
    };

    constexpr retro_core_option_v2_definition Frameskip {
        config::performance::FRAMESKIP,
        "Frameskip (Present)",
        nullptr,
        "Skip presenting some frames to reduce rendering overhead.\n"
        "\n"
        "This still runs the emulation each frame, but it may not render or output audio every frame.\n"
        "Audio crackling and input feel changes are expected.\n"
        "\n"
        "Changes take effect immediately.",
        nullptr,
        config::performance::CATEGORY,
        {
            {config::values::OFF, "Off"},
            {"1", "1"},
            {"2", "2"},
            {config::values::AUTO, "Auto"},
            {nullptr, nullptr},
        },
        config::values::OFF,
    };

    constexpr retro_core_option_v2_definition AudioFastMode {
        config::performance::AUDIO_FAST_MODE,
        "Audio Fast Mode",
        nullptr,
        "Use cheaper audio settings to improve performance.\n"
        "\n"
        "May reduce audio quality or cause crackling.\n"
        "Changes take effect immediately.",
        nullptr,
        config::performance::CATEGORY,
        {
            {config::values::DISABLED, nullptr},
            {config::values::ENABLED, nullptr},
            {nullptr, nullptr},
        },
        config::values::DISABLED,
    };

    constexpr retro_core_option_v2_definition VideoFastMode {
        config::performance::VIDEO_FAST_MODE,
        "Video Fast Mode",
        nullptr,
        "Use faster rendering settings.\n"
        "\n"
        "May reduce quality or cause graphical issues.\n"
        "Changes take effect immediately.",
        nullptr,
        config::performance::CATEGORY,
        {
            {config::values::DISABLED, nullptr},
            {config::values::ENABLED, nullptr},
            {nullptr, nullptr},
        },
        config::values::DISABLED,
    };

    constexpr retro_core_option_v2_definition JitFastPreset {
        config::performance::JIT_FAST_PRESET,
        "JIT Fast Preset",
        nullptr,
        "Enable aggressive JIT defaults (if available) to maximize speed.\n"
        "\n"
        "May reduce stability.\n"
        "Changes take effect at next restart.",
        nullptr,
        config::performance::CATEGORY,
        {
            {config::values::DISABLED, nullptr},
            {config::values::ENABLED, nullptr},
            {nullptr, nullptr},
        },
        config::values::DISABLED,
    };

    constexpr std::initializer_list<retro_core_option_v2_definition> PerformanceOptionDefinitions {
        Profile,
        Frameskip,
        AudioFastMode,
        VideoFastMode,
        JitFastPreset,
    };
}

#endif // MELONDS_DS_PERFORMANCE_HPP

