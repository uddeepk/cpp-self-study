#include <iostream>
/*
 * This is a program to check for Kaprekar's numbers.
 * Kaprekar number for a given base is a non-negative integer, the representation of whose
 * square in that base can be split into two parts that add up to the original number again.
 */
bool check_Kaprekar( int num ) {
    // Use loop to check Kaprekar value
    // define numSquared = num * num
    // define a = 10
    // r = get remainder of num%10
    // q = r / 10
    // check r == q if yes return true, if no continue
    // a * = 10
    // check (num / 10 ) > 0. if yes continue, if no exit loop
    // return false
    int numSquared = num * num;
    int a = 10;

    do {
        int r = numSquared % a;
        int q = numSquared / a;
        if (r == 0) {
            a *= 10;
            continue;
        }
        if ((r + q) == num)
            return true;
        a *= 10;
    } while( (numSquared/ a) > 0 ) ;
    return false;
}
int main() {
    // Prompt user to input a range
    std::cout << "Please enter two non-negative integers : " << std::endl;
    int n1 = 0 , n2 = 0 ;
    if ( std::cin >> n1 >> n2 && n1 >= 0 && n2 >= 0) {
        if (n1 > n2 ) {
            int temp = n2;
            n2 = n1;
            n1 = temp;
        }
        for( int i = n1 ; i <= n2 ; ++i ) {
            if( check_Kaprekar(i) )
                std::cout << i << " " ;
        }
        std::cout << std::endl;
    }
    else if ( n1< 0 || n2 < 0) {
        std::cerr << "Error" "! Please ensure the integers are non-negative." << std::endl;
        return -1;
    }
    else {
        std::cerr << "Error! Invalid input. Please enter non-negative integers." << std::endl;
        return -1;
    }
    return 0;
}
