#include <menu/menu.hpp>
#include <game/gt.hpp>
#include <utils/memory.hpp>

void menu::cheats_page() noexcept {
	ImGui::Columns(3, "cheat columns", false);
	ImGui::Checkbox("anti deadly", &cheats::anti_deadly);
	ImGui::Checkbox("anti bouncy", &cheats::anti_bouncy);
	ImGui::Checkbox("anti damage", &cheats::anti_damage);
	ImGui::Checkbox("anti checkpoint", &cheats::anti_checkpoint);
	ImGui::Checkbox("anti portal", &cheats::anti_portal, gt::anti_portal_address, "eb", "74");
	ImGui::Checkbox("anti slide", &cheats::anti_slide, gt::anti_slide_address, "90 90", "74 4d");
	//ImGui::Checkbox("anti water", &cheats::anti_water, gt::anti_water_address, "e9 e7 00 00 00 90", "0f 84 e6 00 00 00"); // todo: fix autoban caused by this
	ImGui::Checkbox("anti zombie", &cheats::anti_zombie);
	ImGui::Checkbox("anti ghost", &cheats::anti_ghost);
	ImGui::Checkbox("anti knockback", &cheats::anti_knockback);
	ImGui::Checkbox("anti freeze", &cheats::anti_freeze);

	ImGui::NextColumn();

	ImGui::Checkbox("night vision", &cheats::night_vision);
	ImGui::Checkbox("see fruits", &cheats::see_fruits);
	ImGui::Checkbox("see ghosts", &cheats::see_ghosts);
	ImGui::Checkbox("see locked doors", &cheats::see_locked_doors, gt::see_locked_doors_address, "eb", "74");
	ImGui::Checkbox("fake lag", &cheats::fake_lag); // todo: make this show to our client aswell
	ImGui::Checkbox("ghost mode", &cheats::ghost_mode);
	ImGui::Checkbox("mod zoom", &cheats::mod_zoom);
	ImGui::Checkbox("fast punch", &cheats::fast_punch);
	ImGui::Checkbox("show platform", &cheats::show_platform);

	ImGui::NextColumn();

	ImGui::Checkbox("click tp (CTRL)", &cheats::click_tp);
	ImGui::Checkbox("tile info (CTRL)", &cheats::tile_info); // hover mouse over a tile and press ctrl to see information about the tile
	ImGui::Checkbox("walk in air", &cheats::walk_in_air);
	ImGui::Checkbox("unlimited jumps", &cheats::unlimited_jumps);
	ImGui::Checkbox("super punch", &cheats::super_punch);
	ImGui::Checkbox("block ads", &cheats::block_ads);
	ImGui::Checkbox("touch bypass", &cheats::touch_bypass, gt::touch_bypass_address, "eb", "72");
	ImGui::Checkbox("enable pasting", &cheats::enable_pasting, gt::enable_pasting_address, "75", "74");
	ImGui::Checkbox("auto reconnect", &cheats::auto_reconnect);
	ImGui::Checkbox("skip file updates", &cheats::skip_file_updates);

	ImGui::EndColumns();
}
