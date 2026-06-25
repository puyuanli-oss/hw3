#ifndef HEAP_H
#define HEAP_H
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T, typename PComparator = std::less<T> >
class Heap
{
private:
  std::vector<T> items;   // stores the heap elements
  int m;                  // arity of the heap
  PComparator comp;       // comparator object
public:
  /**
   * @brief Construct a new Heap object
   * 
   * @param m ary-ness of heap tree (default to 2)
   * @param c binary predicate function/functor that takes two items
   *          as an argument and returns a bool if the first argument has
   *          priority over the second.
   */
  Heap(int m=2, PComparator c = PComparator());

  /**
  * @brief Destroy the Heap object
  * 
  */
  ~Heap();

  /**
   * @brief Push an item to the heap
   * 
   * @param item item to heap
   */
  void push(const T& item);

  /**
   * @brief Returns the top (priority) item
   * 
   * @return T const& top priority item
   * @throw std::underflow_error if the heap is empty
   */
  T const & top() const;

  /**
   * @brief Remove the top priority item
   * 
   * @throw std::underflow_error if the heap is empty
   */
  void pop();

  /// returns true if the heap is empty

  /**
   * @brief Returns true if the heap is empty
   * 
   */
  bool empty() const;

    /**
   * @brief Returns size of the heap
   * 
   */
  size_t size() const;
  Heap(int m=2, PComparator c = PComparator());
  ~Heap();
};

// Add implementation of member functions here


// We will start top() for you to handle the case of 
// calling top on an empty heap
/* template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================


  }
  // If we get here we know the heap has at least 1 item
  // Add code to return the top element



}
*/
template <typename T, typename PComparator>
T const & Heap<T,PComparator>::top() const
{
  // Here we use exceptions to handle the case of trying
  // to access the top element of an empty heap
  if (empty()) {
    throw std::underflow_error("Heap is empty");
  }

  // Return the root of the heap
  return items[0];
}
//empty()
template <typename T, typename PComparator>
bool Heap<T,PComparator>::empty() const
{
    return items.empty();
}
//size()
template <typename T, typename PComparator>
size_t Heap<T,PComparator>::size() const
{
    return items.size();
}

/*// We will start pop() for you to handle the case of 
// calling top on an empty heap
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
  if(empty()){
    // ================================
    // throw the appropriate exception
    // ================================


  }



}
*/
template <typename T, typename PComparator>
void Heap<T,PComparator>::push(const T& item)
{
    // Add new item at the end
    items.push_back(item);

    // Bubble up
    int current = items.size() - 1;

    while (current > 0) {
        int parent = (current - 1) / m;

        // If current has higher priority than its parent, swap them
        if (comp(items[current], items[parent])) {
            std::swap(items[current], items[parent]);
            current = parent;
        }
        else {
            break;
        }
    }
}
template <typename T, typename PComparator>
void Heap<T,PComparator>::pop()
{
    if (empty()) {
        throw std::underflow_error("Heap is empty");
    }

    // If only one item, just remove it
    if (items.size() == 1) {
        items.pop_back();
        return;
    }

    // Move last item to the root
    items[0] = items.back();
    items.pop_back();

    // Bubble down
    int current = 0;

    while (true) {
        int best = current;

        // Check all m children
        for (int i = 1; i <= m; i++) {
            int child = current * m + i;

            if (child < static_cast<int>(items.size()) &&
                comp(items[child], items[best])) {
                best = child;
            }
        }

        // Heap property satisfied
        if (best == current) {
            break;
        }

        std::swap(items[current], items[best]);
        current = best;
    }
}
template <typename T, typename PComparator>
Heap<T, PComparator>::Heap(int m, PComparator c)
  : items(), m(m), comp(c)
{
  if (m < 2) {
    throw std::invalid_argument("Heap arity must be at least 2");
  }
}

template <typename T, typename PComparator>
Heap<T, PComparator>::~Heap() = default;

#endif

