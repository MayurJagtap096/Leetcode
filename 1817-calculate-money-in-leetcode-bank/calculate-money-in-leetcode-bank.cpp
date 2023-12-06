class Solution {
public:
    int totalMoney(int n) {
        int money = 0 , day = 1 , noMonday = 0 ;
        for ( int i = 0 ; i < n ; i++ ) {

            money += day + noMonday ;
            day++ ;

            if ( day == 8 ) {
                day = 1 ; 
                noMonday++ ;
            }
        }

        return money ;
    }
};