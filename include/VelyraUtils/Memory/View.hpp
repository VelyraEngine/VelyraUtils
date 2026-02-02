#pragma once

#include <VelyraUtils/Types/Types.hpp>

namespace Velyra {

    /**
     * @brief Functions as a non owning view into a unique_ptr. This adds the benefit of being
     *        initializable with nullptr
     *
     *        The standard already includes a std::observer_ptr which closely resembles this class.
     *        Unfortunately, this is marked experimental as of writing this class
     *
     *        https://en.cppreference.com/w/cpp/experimental/observer_ptr.html
     * @tparam T
     */
    template<typename T>
    class View {
    public:
        View() = default;

        View(std::nullptr_t) : m_View(nullptr) {}

        /**
         * @brief Constructor is non-explicit to allow easy conversions from UP<T>, in this case
         *        implicit conversion is cheap so it is not bad here (and it makes sense syntactically).
         * @param ptr
         */
        View(const UP<T>& ptr) :
        m_View(ptr.get()){}

        View& operator=(std::nullptr_t) {
            m_View = nullptr;
            return *this;
        }

        T* get() const {
            return m_View;
        }

        T* operator->() const {
            return m_View;
        }

        bool operator==(std::nullptr_t) const {
            return m_View == nullptr;
        }

        bool operator!=(std::nullptr_t) const {
            return m_View != nullptr;
        }

    private:
        T* m_View = nullptr;
    };

    template<typename T>
    View<T> createView(const UP<T>& ptr) {
        return View<T>(ptr);
    }

}