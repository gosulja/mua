#pragma once

#include <unordered_map>
#include <memory>
#include <string>

class BaseType {
public:
	virtual ~BaseType() = default;

	virtual std::shared_ptr<BaseType> add(const std::shared_ptr<BaseType>& other) const = 0;
	virtual std::shared_ptr<BaseType> sub(const std::shared_ptr<BaseType>& other) const = 0;

	virtual std::string evaluate() const = 0;
};

class Registry {
private:
	std::unordered_map<std::string, std::shared_ptr<BaseType>> types;
	
public:
	void register_type(const std::string& name, std::shared_ptr<BaseType> type);

	std::shared_ptr<BaseType> get_type(const std::string& name) const;
};
