#ifndef FACTORY_H
#define FACTORY_H

#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>

// TODO

template< class Interface >
class Factory
{
public:
    using InterfacePtr = std::shared_ptr<Interface>;
    using TypeId = std::string;
    using Generator = std::function<InterfacePtr()>;

    static InterfacePtr newInstance(TypeId typeId)
    {
        return registry().find(typeId)->second();
    }

    static std::vector<TypeId> registeredTypes()
    {
        auto& r = registry();
        std::vector<TypeId> result(r.size());
        std::transform(r.begin(), r.end(), result.begin(), [](
                       const typename Registry::value_type& v) -> TypeId {
            return v.first;
        });
        return result;
    }

    static void registerType(TypeId typeId, Generator generator)
    {
        registry()[typeId] = generator;
    }

private:
    using Registry = std::map<TypeId, Generator>;
    static Registry& registry() {
        static Registry registry;
        return registry;
    }
};

template< class Type, class Interface >
class FactoryMixin
{
public:
    static std::shared_ptr<Interface> newInstance() {
        return std::make_shared<Type>();
    }

    class Registrator
    {
    public:
        Registrator(const typename Type::TypeId& typeId) {
            Type::registerType(
                typeId,
                &FactoryMixin<Type, Interface>::newInstance);
        }
    };
};

#define CTM_REGISTER_TYPE(Type, typeId) \
    static Type::Registrator The##Type##Registrator(typeId);

#endif // FACTORY_H
