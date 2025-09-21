#include <bits/stdc++.h>
using namespace std;
int main () {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //una transaccion ocurre cuando el bid >= ask
    //el precio de la transaccion es el ask price
    //se reduce la cantidad de acciones en las ordenes hasta que no quede nada por curzar o yan o hayua condiciciones para transar. 
    int i;
    if(!(cin >> i)) return 0;
    
    
    while (i--){
        int n;    
        cin >> n;

        const int P = 1000; // precio max
        vector<long long> buy(P +1, 0), sell(P +1, 0);
        
        int bid_price = 0; // el precio mas alto al que alguien esta dispuesto a comprar
        int ask_price = P+1; // el precio mas bajo al que alguien esta dispuesto a vender
        int stock_price = -1; // el precio al que se cerró al ultima transaccion (si es que hubo una)
        
        auto fixMaxBid = [&]() {
            while(bid_price > 0 && buy[bid_price] == 0) bid_price--;
        };
        auto fixMinAsk = [&]() {
            while (ask_price <= 1000 && sell[ask_price] == 0) ask_price++;
        };
        auto currentBid = [&]() -> int {
            return (bid_price >= 1 ? bid_price : -1);
        };
        auto currentAsk = [&]() -> int {
            return (ask_price <= 1000 ? ask_price : -1);
        };
        
        while(n--){
            
            long long x;
            int y;
            
            string action, shares_word, at_word;
            cin >> action >> x >> shares_word >> at_word >> y;

            //orden
            if(action == "buy") {
                //alguien quiere comprar x acciones a lo más al precio y
                buy[y] += x;
                if(y > bid_price ){
                    bid_price = y;
                }

            }
            else if (action == "sell"){
                //alguien quiere vender x acciones al menos al precio y
                sell[y] += x;
                if(y < ask_price){
                    ask_price = y;
                }
            }
            
            fixMaxBid();
            fixMinAsk();

            while(bid_price > 0 && ask_price <= P && bid_price >= ask_price){
                long long traded = min(buy[bid_price], sell[ask_price]);
                buy[bid_price]  -= traded;
                sell[ask_price] -= traded;
                stock_price = ask_price;  // la transacción ocurre al precio ask

                if (buy[bid_price] == 0) fixMaxBid();
                if (sell[ask_price] == 0) fixMinAsk();
            }

            int ask_out = currentAsk();
            int bid_out = currentBid();
            int stock_out = (stock_price == -1 ? -1 : stock_price);

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