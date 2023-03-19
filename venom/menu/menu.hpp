#pragma once
#include <external/imgui/imgui.h>
#include <external/imgui/imgui_internal.h>
#include <external/imgui/imgui_impl_dx9.h>
#include <external/imgui/imgui_impl_win32.h>

namespace menu {
	void setup();
	void render() noexcept;

	void cheats_page() noexcept;
	void debug_page() noexcept;

	inline bool show = true;
}

namespace cheats {
	inline bool anti_deadly = false;
	inline bool anti_bouncy = false;
	inline bool anti_damage = false;
	inline bool anti_checkpoint = false;
	inline bool anti_zombie = false;
	inline bool anti_knockback = false;

	inline bool night_vision = false;
	inline bool see_fruits = false;
	inline bool see_ghosts = false;
	inline bool fake_lag = false;
	inline bool ghost_mode = false;
	inline bool mod_zoom = false;

	inline bool walk_in_air = false;
	inline bool unlimited_jumps = false;
	inline bool super_punch = false;
	inline bool block_ads = false;
	inline bool touch_bypass = false;
	inline bool enable_pasting = false;
}
