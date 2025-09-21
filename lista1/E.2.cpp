#include <bits/stdc++.h>
using namespace std;

int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; 
        cin >> n;

        // Cantidad total por nivel de precio (1..1000)
        const int P = 1000;
        vector<long long> buy(P + 1, 0), sell(P + 1, 0);

        // Punteros al mejor bid/ask
        int maxBid = 0;        // 0 indica "no hay bid"
        int minAsk = P + 1;    // P+1 indica "no hay ask"
        int stock_price = -1;  // último precio transado

        auto fixMaxBid = [&]() {
            while (maxBid > 0 && buy[maxBid] == 0) maxBid--;
        };
        auto fixMinAsk = [&]() {
            while (minAsk <= P && sell[minAsk] == 0) minAsk++;
        };
        auto currentBid = [&]() -> int {
            return (maxBid >= 1 ? maxBid : -1);
        };
        auto currentAsk = [&]() -> int {
            return (minAsk <= P ? minAsk : -1);
        };

        for (int i = 0; i < n; i++) {
            string type, dummy; 
            long long qty; 
            int price;

            // Formato: "buy xx shares at yy" / "sell xx shares at yy"
            cin >> type >> qty >> dummy >> dummy >> price;

            if (type == "buy") {
                buy[price] += qty;
                if (price > maxBid) maxBid = price;
            } else { // "sell"
                sell[price] += qty;
                if (price < minAsk) minAsk = price;
            }

            // Antes de intentar cruzar, normalizamos punteros
            fixMaxBid();
            fixMinAsk();

            // Matching mientras haya cruce posible
            while (maxBid > 0 && minAsk <= P && maxBid >= minAsk) {
                long long traded = min(buy[maxBid], sell[minAsk]);
                buy[maxBid]  -= traded;
                sell[minAsk] -= traded;
                stock_price = minAsk;  // la transacción ocurre al precio ask

                if (buy[maxBid] == 0) fixMaxBid();
                if (sell[minAsk] == 0) fixMinAsk();
            }

            // Valores actuales para imprimir
            int ask_out = currentAsk();
            int bid_out = currentBid();
            int stock_out = (stock_price == -1 ? -1 : stock_price);

            // Impresión con "-" cuando no esté definido
            if (ask_out == -1) cout << "- ";
            else cout << ask_out << ' ';
            if (bid_out == -1) cout << "- ";
            else cout << bid_out << ' ';
            if (stock_out == -1) cout << "-\n";
            else cout << stock_out << '\n';
        }
    }
    return 0;
}
