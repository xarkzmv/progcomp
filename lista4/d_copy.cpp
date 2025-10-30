#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * @brief Calculates the maximum discount Lindsay can get.
 * * The strategy is to sort the prices in descending order and
 * apply the "buy three, pay for two" offer repeatedly, as the
 * offer always makes the cheapest of the three items free.
 * By sorting descendingly, the third item in every group of three
 * is the most expensive item that can be obtained for free.
 * * @param n The number of items.
 * @param prices A vector of item prices.
 * @return The maximum possible discount.
 */
long long maxDiscount(int n, std::vector<int>& prices) {
    // 1. Sort the prices in descending order.
    // This ensures that for every group of three items (p[i], p[i+1], p[i+2]),
    // the item p[i+2] (which is the minimum price in the group) 
    // is the highest possible price we can get as a discount.
    std::sort(prices.begin(), prices.end(), std::greater<int>());

    long long total_discount = 0;

    // 2. Iterate through the prices, grouping them in threes.
    // The indices will be 0, 1, 2, 3, 4, 5, 6, 7, 8, ...
    // The items at indices 2, 5, 8, ... will be the cheapest 
    // in their respective groups of three and will be the free items.
    for (int i = 0; i < n; ++i) {
        // The pattern for the free items is: i = 2, 5, 8, 11, ...
        // This is equivalent to checking if (i + 1) is a multiple of 3.
        // E.g., for i=2, (2+1)=3, 3 % 3 = 0.
        // For i=5, (5+1)=6, 6 % 3 = 0.
        if ((i + 1) % 3 == 0) {
            // 3. Add the price of the free item to the total discount.
            total_discount += prices[i];
        }
        // Items at indices 0, 1, 3, 4, 6, 7, ... are paid for.
    }

    return total_discount;
}

int main() {
    // Fast I/O
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    // Read the number of items
    if (!(std::cin >> n)) return 0;

    // Read the prices
    std::vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        if (!(std::cin >> prices[i])) return 0;
    }

    // Calculate and output the maximum discount
    long long result = maxDiscount(n, prices);
    std::cout << result << "\n";

    return 0;
}