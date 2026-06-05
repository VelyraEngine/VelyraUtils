#pragma once

#include <VelyraUtils/DevUtils/Conditions.hpp>
#include <VelyraUtils/Types/Types.hpp>
#include <vector>
#include <unordered_map>

namespace Velyra::Utils {

template<typename K, typename D>
    class KeyVector {
    public:
        KeyVector() = default;

        explicit KeyVector(std::size_t size) {
            m_Data.reserve(size);
        }

        ~KeyVector() = default;

        void insert(const K &key, const D &data) {
            VL_PRECONDITION(!m_KeyIndexMap.contains(key), "[KeyVector]: Key {} already exists", key)

            m_Data.push_back(data);
            m_KeyIndexMap.insert({key, m_Data.size() - 1});
        }

        template<typename... Args>
        void emplace(const K &key, Args &&... args) {
            VL_PRECONDITION(!m_KeyIndexMap.contains(key), "[KeyVector]: Key {} already exists", key)

            m_Data.emplace_back(std::forward<Args>(args)...);
            m_KeyIndexMap.insert({key, m_Data.size() - 1});
        }

        const D &get(const K &key) const {
            VL_PRECONDITION(m_KeyIndexMap.contains(key), "[KeyVector]: cannot retrieve element, key "
                                                                            "{} does not exists", key);

            return m_Data[m_KeyIndexMap.at(key)];
        }

        D &get(const K &key) {
            VL_PRECONDITION(m_KeyIndexMap.contains(key), "[KeyVector]: cannot retrieve element, "
                                                                            "key {} does not exists", key);

            return m_Data[m_KeyIndexMap.at(key)];
        }

        const D &operator[](const K &key) const {
            VL_PRECONDITION(m_KeyIndexMap.contains(key), "[KeyVector]: cannot retrieve element, key {} does not exists", key);

            return m_Data[m_KeyIndexMap.at(key)];
        }

        D &operator[](const K &key) {
            VL_PRECONDITION(m_KeyIndexMap.contains(key), "[KeyVector]: cannot retrieve element, key {} does not exists", key);

            return m_Data[m_KeyIndexMap.at(key)];
        }

        void remove(const K &key) {
            VL_PRECONDITION(m_KeyIndexMap.contains(key), "[KeyVector]: cannot remove element, key {} does not exists", key);

            auto it = m_KeyIndexMap.find(key);

            size_t indexToRemove = it->second;
            size_t lastIndex = m_Data.size() - 1;

            if (indexToRemove != lastIndex) {
                // Move last element to the spot to remove
                m_Data[indexToRemove] = std::move(m_Data[lastIndex]);

                // Find the key of the last element
                for (auto& pair : m_KeyIndexMap) {
                    if (pair.second == lastIndex) {
                        pair.second = indexToRemove;
                        break;
                    }
                }
            }

            m_Data.pop_back();
            m_KeyIndexMap.erase(it);
        }

        auto begin() {
            return m_Data.begin();
        }

        auto begin() const {
            return m_Data.begin();
        }

        auto end() {
            return m_Data.end();
        }

        auto end() const {
            return m_Data.end();
        }

        bool has(const K &key) const {
            return m_KeyIndexMap.find(key) != m_KeyIndexMap.end();
        }

        [[nodiscard]] size_t getSize() const {
            return m_Data.size();
        }

        const std::vector<D> &getData() const {
            return m_Data;
        }

    private:
        std::vector<D> m_Data;
        std::unordered_map<K, Size> m_KeyIndexMap;
    };


}