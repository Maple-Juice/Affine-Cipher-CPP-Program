using namespace std;
#include<string>
#include <iostream>
int alpha;
int beta;
string Encryption(string main_text)
{
    string CiPr = "";
    for (int X = 0; X < main_text.length(); X++)
    {
        CiPr = CiPr +
               (char) ((((alpha * (main_text[X]-'A') ) + beta) % 26) + 'A');
    }
    return CiPr;
}
string Decryption(string CiPr)
{
    string main_text = "";
    int alpha_content = 0;
    int signal = 0;
    for (int i = 0; i < 26; i++)
    {
        signal = (alpha * i) % 26;
        if (signal == 1)
        {
            alpha_content = i;
        }
    }
    for (int i = 0; i < CiPr.length(); i++)
    {
        if(CiPr[i]!=' ')
            main_text = main_text +
                        (char) (((alpha_content * ((CiPr[i]+'A' - beta)) % 26)) +
                                'A');
        else
            main_text += CiPr[i];
    }
    return main_text;
}
int main()
{
    int check = 1;
    while (check == 1){
        cout << "please enter the Alpha of the key(HAS TO BE ODD): ";
        cin >> alpha;
        cout << "Please enter the Beta of the key: ";
        cin >> beta;
        int check_alpha = alpha % 2;
        if (alpha < 1 || alpha > 25 || beta > 25 || beta < 0 || check_alpha ==
                                                                0){
            cout << "The input value is invalid..."<< endl << "Please try again..." << endl;
            check = 1;
        }
        else{
            check = 0;
        }
    }
    string main_text;
    cout << "please enter the text you want to encrypt: ";
    cin >> main_text;
    string encryptedtext = Encryption(main_text);
    cout << "The encrypted text form is: " << encryptedtext << endl;
    cout << "The decrypted text form is: " << Decryption(encryptedtext) << endl;
    if (Decryption(encryptedtext) == main_text){
        cout << "encryption was successful..." << endl;
    }
    else{
        cout << "failed to encrypt the text..." << endl;
    }
    return 0;
}
