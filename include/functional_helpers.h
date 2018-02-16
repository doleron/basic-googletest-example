#ifndef FUNCTIONAL_HELPERS_H_
#define FUNCTIONAL_HELPERS_H_

#include <algorithm>
#include <stdexcept>

template <typename Collection, typename unop>
void for_each(Collection collection, unop op)
{
    std::for_each(collection.begin(), collection.end(), op);
}

template <typename Collection, typename unop>
Collection map(Collection collection, unop op)
{
    std::transform(collection.begin(), collection.end(), collection.begin(), op);
    return collection;
}

template <typename Collection, typename binop>
Collection zip(Collection first, Collection second, binop op)
{
    std::transform(first.begin(), first.end(), second.begin(), first.begin(), op);
    return first;
}

template <typename Collection, typename Condition>
bool exists(Collection collection, Condition condition)
{
    auto exist = std::find_if(collection.begin(), collection.end(), condition);
    bool result = exist != collection.end();
    return result;
}

template <typename Collection, typename Predicate>
Collection filterNot(Collection collection, Predicate predicate)
{
    auto iterator = std::remove_if(collection.begin(), collection.end(), predicate);
    collection.erase(iterator, std::end(collection));
    return collection;
}

template <typename Collection, typename Predicate>
Collection filter(Collection collection, Predicate predicate)
{
    auto result = filterNot(collection, [predicate](typename Collection::value_type i) { return !predicate(i); });
    return result;
}

template <typename Collection, typename func>
void iterativeCall(Collection first, Collection second, func afunc)
{
    unsigned int size = first.size();
	if(size == second.size()) {

        for(unsigned int index = 0; index < size; index++) {
            auto firstElement = first[index];
            auto secondElement = second[index];
            afunc(firstElement, secondElement);
        }

	} else {
        throw std::invalid_argument("It is required to pass two containers of same size to iterativeCall");
    }

}

#endif /* FUNCTIONAL_HELPERS_H_ */