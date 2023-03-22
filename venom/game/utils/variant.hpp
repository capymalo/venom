#pragma once
#include <utils/memory.hpp>
#include <game/utils/math.hpp>

#include <cstdint>
#include <string>

enum class variant_type : std::uint8_t {
	unused,
	float32,
	string,
	vec2,
	vec3,
	uint32,
	entity,
	component,
	rect,
	int32
};

class entity_t;
class entity_component_t;

#pragma pack(push, 1)
class variant_t {
public:
	variant_t() noexcept = default;

	variant_type get_type() const noexcept {
		return type;
	}

	float get_float() const noexcept {
		return float_value;
	}

	std::string get_string() const noexcept {
		return string_value;
	}

	vec2f_t get_vec2() const noexcept {
		return vec2_value;
	}

	vec3f_t get_vec3() const noexcept {
		return vec3_value;
	}

	std::uint32_t get_uint() const noexcept {
		return uint_value;
	}

	entity_t* get_entity() const noexcept {
		return static_cast<entity_t*>(pvoid);
	}

	entity_component_t* get_component() const noexcept {
		return static_cast<entity_component_t*>(pvoid);
	}

	vec4f_t get_rect() const noexcept {
		return rect_value;
	}

	std::uint32_t get_int() const noexcept {
		return int_value;
	}

	void set(float value) noexcept {
		float_value = value;
		type = variant_type::float32;
	}

	void set(const std::string& value) noexcept {
		string_value = value;
		type = variant_type::string;
	}

	void set(vec2f_t value) noexcept {
		vec2_value = value;
		type = variant_type::vec2;
	}

	void set(vec3f_t value) noexcept {
		vec3_value = value;
		type = variant_type::vec3;
	}

	void set(std::uint32_t value) noexcept {
		uint_value = value;
		type = variant_type::uint32;
	}

	void set(entity_t* value) noexcept {
		pvoid = static_cast<void*>(value);
		type = variant_type::entity;
	}

	void set(entity_component_t* value) noexcept {
		pvoid = static_cast<void*>(value);
		type = variant_type::component;
	}

	void set(vec4f_t value) noexcept {
		rect_value = value;
		type = variant_type::rect;
	}

	void set(std::int32_t value) noexcept {
		int_value = value;
		type = variant_type::int32;
	}

private:
	variant_type type;
	std::uint8_t unk1[7];
	void* pvoid;

	union {
		std::uint8_t value[16];
		float float_value;
		vec2f_t vec2_value;
		vec3f_t vec3_value;
		std::uint32_t uint_value;
		vec4f_t rect_value;
		std::int32_t int_value;
	};

	std::string string_value;
	std::uint8_t sig_onchanged[16];

	friend class variant_list_t;
};

class variant_list_t {
public:
	variant_list_t() noexcept = default;
	explicit variant_list_t(std::uint8_t* data) noexcept { serialize_from_mem(data); }

	void serialize_from_mem(std::uint8_t* data) noexcept {
		using enum variant_type;
		using namespace memory;

		std::uint8_t count;
		append_read(count, data);

		for (std::uint8_t i = 0; i < count; ++i) {
			std::uint8_t index;
			append_read(index, data);

			variant_t& var = variants[index];
			append_read(var.type, data);

			switch (var.type) {
			case float32:
				append_read(var.float_value, data);
				break;

			case string:
				append_read_string(var.string_value, data);
				break;

			case vec2:
				append_read(var.vec2_value, data);
				break;

			case vec3:
				append_read(var.vec3_value, data);
				break;

			case uint32:
				append_read(var.uint_value, data);
				break;

			case int32:
				append_read(var.int_value, data);
				break;

			default:
				break;
			}
		}
	}

	// needed for gt::process_call_function, todo
	std::uint8_t* serialize_to_mem(std::size_t* size_out) noexcept {
		return nullptr;
	}

	inline variant_t& get(std::size_t index) noexcept { return variants[index]; }
	inline const variant_t& get(std::size_t index) const noexcept { return variants[index]; }

	inline variant_t& operator[](std::size_t index) noexcept { return variants[index]; }
	inline const variant_t& operator[](std::size_t index) const noexcept { return variants[index]; }

	variant_t variants[7] = {};
};

#pragma pack(pop)
