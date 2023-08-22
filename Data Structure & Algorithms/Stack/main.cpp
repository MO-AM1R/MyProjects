# include "Stack.h"

int main() {
//    {
//        Stack<int> S1;
//        cout << S1.isEmpty() << endl;
//
//        S1.push(1);
//        S1.push(2);
//        S1.push(3);
//        S1.push(10);
//        S1.push(5);
//        S1.push(9);
//        S1.push(4);
//        S1.push(5);
//        S1.print();
//        S1.pop();
//        S1.pop();
//        S1.pop();
//        S1.print();
//        cout << S1.top() << endl;
//    }
//
//    {
//        Stack<char> S2;
//        /*
//         * MaM
//         * Abc def ghi jklm
//         * too hot to hoot
//         * ABCDCBA
//         * was it a car or a cat i saw
//       */
//
//        cout << checkPalindrome(S2, "was it a car or a cat i saw") << endl;
//    }
//
//    {
//        /*
//          * X^Y / (5*Z) + 2 -> XY^5Z* /2+
//          * A + B * C + D -> A B C * + D +
//          * (A + B) * (C + D) -> A B + C D + *
//          * K + L - M*N + (O^P) * W/U/V * T + Q -> KL+MN*-OP^W*U/V/T*+Q+
//        */
//
//        infix_to_postfix("X^Y / (5*Z) + 2") ;
//        cout << endl ;
//    }

    {
        /*
          * (() -> 2
          * )()()) -> 4
          * ()(()) -> 6
          * ()(() -> 2
          * <<<><< ->
        */
        cout << longestParentheses("<<<><<") << endl;
    }
    return 0;
}