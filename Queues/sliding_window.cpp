/*
    SLIDING WINDOW (fixed window size = k)

    Core idea:
    Instead of recalculating every group of k elements from scratch, maintain
    the answer/state for the current window and update only what changes when
    the window moves one position to the right.

    Example:
        Array:  [2, 1, 5, 3, 4]
        k = 3

        Windows:
        [2, 1, 5]             -> first window
           [1, 5, 3]          -> remove 2, add 3
              [5, 3, 4]       -> remove 1, add 4

    General approach:

    1. Build the first window
       - Process indices 0 to k - 1.
       - Add their contribution to the initial state.
       - Store the first answer.

    2. Slide through the remaining elements
       For every new index i starting from k:
       - Remove the contribution of the element leaving the window.
       - Add the contribution of arr[i], which is entering the window.
       - Store/update the answer for the new window.

       The element leaving the window is at index i - k.

    -------------------------------------------------------------------------
    WHEN A QUEUE/DEQUE IS USED
    -------------------------------------------------------------------------

    Store INDICES rather than only element values.

    Why?
    An index tells us both:
       1. the element's value: arr[index]
       2. whether that element still belongs to the current window

    At current index i, the current window covers:

        [i - k + 1, i]

    Therefore, an index is expired when:

        index < i - k + 1

    This is equivalent to:

        i - index >= k

    So for the index at the front of a deque:

        if (i - dq.front() >= k)
            dq.front() is outside the window and must be removed;
        else
            dq.front() is still inside the window.

    Quick check for k = 3:
        current index i = 3
        current window indices = [1, 2, 3]

        index 0: 3 - 0 = 3  -> outside (expired)
        index 1: 3 - 1 = 2  -> inside

    Revision shortcut:

        Build the first window.
        Then, whenever the window slides:
            REMOVE the outgoing/expired element,
            ADD the incoming element,
            RECORD the new answer.

    Complexity:
    - A basic fixed-size sliding window usually takes O(n) time.
    - Extra space is O(1) for a simple running value, or up to O(k) when a
      queue/deque is needed.
*/
