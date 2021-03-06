#include "token.h"

void Token_stream::putback(Token t){
    if (full) error("putback() into a full buffer");
    buffer=t;
    full=true;
    }

Token Token_stream::get() // memanggil token dari Token_stream
    {
        if (full) { full=false; return buffer; } // memeriksa apakah token nya sudah ready 
        char ch;
        cin >> ch; 
        switch (ch) {
            case '(': case ')': case ';': case 'q': case '+': case '-': case '*': case '/':
                return Token{ch}; 
            case '.':
            case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
                { cin.putback(ch); // memasukkan kembali data ke aliran input
                double val;
                cin >> val; // input floating-point number
                return Token{'8',val}; // ‘8’ merepresentasikan sebuah bilangan yg di input
                }
            default:
            error("Bad token");
        }
    } 
Token_stream ts;

