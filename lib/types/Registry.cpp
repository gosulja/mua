#include "Registry.h"

void Registry::register_type(const std::string& name, const std::shared_ptr<BaseType> type) {
	types[name] = type;
}

std::shared_ptr<BaseType> Registry::get_type(const std::string& name) const {
	auto it = types.find(name);
	if (it != types.end()) return it->second;

	return nullptr;
}
