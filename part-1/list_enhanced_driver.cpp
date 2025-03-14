#include "list_enhanced.hpp"
#include "utils.hpp"

int main(int argc, char **argv)
{
    auto list = Node<float>{};  // empty list, dummy node, value = 0.0, next = nullptr

    // Insert some numbers to the front of the list.
    auto last = &list;
    for (int i = 0; i < 10; ++i) {
        last = list_insert_after(last, static_cast<float>(i));  // insert: dummy -> {0, ptr(1)} -> {1, ptr(2)} -> ... -> {9, nullptr}
        print(list_to_vector(list));
    }

    // Remove the elements from the beginning of the list.
    for (int i = 0; i < 10; ++i) {
        list_delete_after(&list);
        print(list_to_vector(list));
    }
}
